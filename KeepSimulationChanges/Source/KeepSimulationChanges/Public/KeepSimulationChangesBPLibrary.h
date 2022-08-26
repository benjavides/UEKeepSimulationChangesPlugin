// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "KeepSimulationChangesBPLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(Simulation, Log, All);

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UKeepSimulationChangesBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	// Expose to blueprints the original Engine function defined in "...\Engine\Source\Editor\LevelEditor\Private\LevelEditor"
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Keep Selected Actors Simulated Changes", Keywords = "KeepSimulatedChanges save selected actors keep"), Category = "Simulation")
	static void KeepSelectedActorsSimulatedChanges();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Keep Actor Simulated Changes", Keywords = "KeepActorSimulatedChanges  save keep actor simulated changes"), Category = "Simulation")
	static void KeepActorSimulatedChanges(AActor* actor);

	/**
	 * Copied from ...\Engine\Source\Editor\LevelEditor\Private\LevelEditor
	 * Create and apply animation to the SkeletalMeshComponent if Simulating
	 *
	 * @param EditorActor	Editor Counterpart Actor
	 * @param SimActor		Simulating Actor in PIE or SIE
	 */
	static bool SaveAnimationFromSkeletalMeshComponent(AActor* EditorActor, AActor* SimActor, TArray<class USkeletalMeshComponent*>& OutEditorComponents);
};
