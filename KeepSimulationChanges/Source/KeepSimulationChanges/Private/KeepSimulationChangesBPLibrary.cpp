// Copyright Epic Games, Inc. All Rights Reserved.

#include "KeepSimulationChangesBPLibrary.h"
#include "KeepSimulationChanges.h"

#include "LevelEditorActions.h"
#include "LevelEditor.h"

#include "Misc/MessageDialog.h"
#include "CoreMinimal.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"

#define LOCTEXT_NAMESPACE "SimulationChangesKeep"
DEFINE_LOG_CATEGORY(Simulation);

UKeepSimulationChangesBPLibrary::UKeepSimulationChangesBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


void UKeepSimulationChangesBPLibrary::KeepSelectedActorsSimulatedChanges()
{
	FLevelEditorActionCallbacks::OnKeepSimulationChanges();
}


void UKeepSimulationChangesBPLibrary::KeepActorSimulatedChanges(AActor* actor)
{
	TArray<class USkeletalMeshComponent*> ComponentsToReinitialize;

	auto* SimWorldActor = CastChecked<AActor>(actor);

	// Find our counterpart actor
	AActor* EditorWorldActor = EditorUtilities::GetEditorWorldCounterpartActor(SimWorldActor);
	if (EditorWorldActor != NULL)
	{
		int32 UpdatedActorCount = 0;
		int32 TotalCopiedPropertyCount = 0;
		FString FirstUpdatedActorLabel;
		SaveAnimationFromSkeletalMeshComponent(EditorWorldActor, SimWorldActor, ComponentsToReinitialize);

		// We only want to copy CPF_Edit properties back, or properties that are set through editor manipulation
		// NOTE: This needs to match what we're doing in the BuildSelectedActorInfo() function
		const auto CopyOptions = (EditorUtilities::ECopyOptions::Type)(
			EditorUtilities::ECopyOptions::CallPostEditChangeProperty |
			EditorUtilities::ECopyOptions::CallPostEditMove |
			EditorUtilities::ECopyOptions::OnlyCopyEditOrInterpProperties |
			EditorUtilities::ECopyOptions::FilterBlueprintReadOnly);
		const int32 CopiedPropertyCount = EditorUtilities::CopyActorProperties(SimWorldActor, EditorWorldActor, CopyOptions);

		if (CopiedPropertyCount > 0)
		{
			++UpdatedActorCount;
			TotalCopiedPropertyCount += CopiedPropertyCount;

			if (FirstUpdatedActorLabel.IsEmpty())
			{
				FirstUpdatedActorLabel = EditorWorldActor->GetActorLabel();
			}
		}

		// Let the user know what happened
		{
			FNotificationInfo NotificationInfo(FText::GetEmpty());
			NotificationInfo.bFireAndForget = true;
			NotificationInfo.FadeInDuration = 0.25f;
			NotificationInfo.FadeOutDuration = 1.0f;
			NotificationInfo.ExpireDuration = 1.0f;
			NotificationInfo.bUseLargeFont = false;
			NotificationInfo.bUseSuccessFailIcons = true;
			NotificationInfo.bAllowThrottleWhenFrameRateIsLow = false;	// Don't throttle as it causes distracting hitches in Simulate mode
			SNotificationItem::ECompletionState CompletionState;
			if (UpdatedActorCount > 0)
			{
				if (UpdatedActorCount > 1)
				{
					FFormatNamedArguments Args;
					Args.Add(TEXT("UpdatedActorCount"), UpdatedActorCount);
					Args.Add(TEXT("TotalCopiedPropertyCount"), TotalCopiedPropertyCount);
					NotificationInfo.Text = FText::Format(NSLOCTEXT("LevelEditorCommands", "KeepSimulationChanges_MultipleActorsUpdatedNotification", "Saved state for {UpdatedActorCount} actors  ({TotalCopiedPropertyCount} properties)"), Args);
				}
				else
				{
					FFormatNamedArguments Args;
					Args.Add(TEXT("FirstUpdatedActorLabel"), FText::FromString(FirstUpdatedActorLabel));
					Args.Add(TEXT("TotalCopiedPropertyCount"), TotalCopiedPropertyCount);
					NotificationInfo.Text = FText::Format(NSLOCTEXT("LevelEditorCommands", "KeepSimulationChanges_ActorUpdatedNotification", "Saved state for {FirstUpdatedActorLabel} ({TotalCopiedPropertyCount} properties)"), Args);
				}
				CompletionState = SNotificationItem::CS_Success;
			}
			else
			{
				NotificationInfo.Text = NSLOCTEXT("LevelEditorCommands", "KeepSimulationChanges_NoActorsUpdated", "No properties were copied");
				CompletionState = SNotificationItem::CS_Fail;
			}
			const auto Notification = FSlateNotificationManager::Get().AddNotification(NotificationInfo);
			Notification->SetCompletionState(CompletionState);
		}
	}

	// need to reinitialize animation
	for (auto MeshComp : ComponentsToReinitialize)
	{
		if (MeshComp->SkeletalMesh)
		{
			MeshComp->InitAnim(true);
		}
	}
}

// Copied from ...\Engine\Source\Editor\LevelEditor\Private\LevelEditor.cpp
bool UKeepSimulationChangesBPLibrary::SaveAnimationFromSkeletalMeshComponent(AActor* EditorActor, AActor* SimActor, TArray<class USkeletalMeshComponent*>& OutEditorComponents)
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));

	// currently blueprint actors don't work because their property can't get copied over. 
	if (Cast<UBlueprintGeneratedClass>(EditorActor->GetClass()) != nullptr)
	{
		return false;
	}

	// find all skel components
	TInlineComponentArray<class USkeletalMeshComponent*> SimSkelComponents;
	SimActor->GetComponents<USkeletalMeshComponent>(SimSkelComponents);

	if (SimSkelComponents.Num() > 0)
	{
		// see if simulating, 
		bool bSimulating = false;
		for (auto& Comp : SimSkelComponents)
		{
			bSimulating |= (Comp->SkeletalMesh && Comp->SkeletalMesh->GetSkeleton() && Comp->IsSimulatingPhysics());
		}

		// if any of them are legitimately simulating
		if (bSimulating)
		{
			// ask users if you'd like to make an animation
			FFormatNamedArguments Args;
			Args.Add(TEXT("ActorName"), FText::FromString(GetNameSafe(EditorActor)));
			FText AskQuestion = FText::Format(LOCTEXT("KeepSimulationChanges_AskSaveAnimation", "Would you like to save animations from simulation for {ActorName} actor"), Args);
			if (EAppReturnType::Yes == FMessageDialog::Open(EAppMsgType::YesNo, AskQuestion))
			{
				for (auto& Comp : SimSkelComponents)
				{
					if (Comp->SkeletalMesh && Comp->SkeletalMesh->GetSkeleton() && Comp->IsSimulatingPhysics())
					{
						// now record to animation
						class UAnimSequence* Sequence = LevelEditorModule.OnCaptureSingleFrameAnimSequence().IsBound() ? LevelEditorModule.OnCaptureSingleFrameAnimSequence().Execute(Comp) : nullptr;
						if (Sequence)
						{
							Comp->SetAnimationMode(EAnimationMode::AnimationSingleNode);
							Comp->AnimationData.AnimToPlay = Sequence;
							Comp->SetAnimation(Sequence);
							Comp->SetSimulatePhysics(false);

							// add the matching component to EditorCompoennts
							class USkeletalMeshComponent* MatchingComponent = Cast<USkeletalMeshComponent>(EditorUtilities::FindMatchingComponentInstance(Comp, EditorActor));
							if (MatchingComponent)
							{
								OutEditorComponents.Add(MatchingComponent);
							}
							else
							{
								UE_LOG(Simulation, Warning, TEXT("Matching component could not be found %s(%s)"), *GetNameSafe(Comp), *GetNameSafe(EditorActor));
							}
						}
					}
				}

				return true;
			}
		}
	}

	return false;
}
