// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "KeepSimulationChanges/Public/KeepSimulationChangesBPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKeepSimulationChangesBPLibrary() {}
// Cross Module References
	KEEPSIMULATIONCHANGES_API UClass* Z_Construct_UClass_UKeepSimulationChangesBPLibrary_NoRegister();
	KEEPSIMULATIONCHANGES_API UClass* Z_Construct_UClass_UKeepSimulationChangesBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_KeepSimulationChanges();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UKeepSimulationChangesBPLibrary::execKeepActorSimulatedChanges)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		UKeepSimulationChangesBPLibrary::KeepActorSimulatedChanges(Z_Param_actor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKeepSimulationChangesBPLibrary::execKeepSelectedActorsSimulatedChanges)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UKeepSimulationChangesBPLibrary::KeepSelectedActorsSimulatedChanges();
		P_NATIVE_END;
	}
	void UKeepSimulationChangesBPLibrary::StaticRegisterNativesUKeepSimulationChangesBPLibrary()
	{
		UClass* Class = UKeepSimulationChangesBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "KeepActorSimulatedChanges", &UKeepSimulationChangesBPLibrary::execKeepActorSimulatedChanges },
			{ "KeepSelectedActorsSimulatedChanges", &UKeepSimulationChangesBPLibrary::execKeepSelectedActorsSimulatedChanges },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics
	{
		struct KeepSimulationChangesBPLibrary_eventKeepActorSimulatedChanges_Parms
		{
			AActor* actor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_actor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(KeepSimulationChangesBPLibrary_eventKeepActorSimulatedChanges_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::NewProp_actor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::Function_MetaDataParams[] = {
		{ "Category", "Simulation" },
		{ "DisplayName", "Keep Actor Simulated Changes" },
		{ "Keywords", "KeepActorSimulatedChanges  save keep actor simulated changes" },
		{ "ModuleRelativePath", "Public/KeepSimulationChangesBPLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeepSimulationChangesBPLibrary, nullptr, "KeepActorSimulatedChanges", nullptr, nullptr, sizeof(KeepSimulationChangesBPLibrary_eventKeepActorSimulatedChanges_Parms), Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepSelectedActorsSimulatedChanges_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepSelectedActorsSimulatedChanges_Statics::Function_MetaDataParams[] = {
		{ "Category", "Simulation" },
		{ "Comment", "// Expose to blueprints the original Engine function defined in \"...\\Engine\\Source\\Editor\\LevelEditor\\Private\\LevelEditor\"\n" },
		{ "DisplayName", "Keep Selected Actors Simulated Changes" },
		{ "Keywords", "KeepSimulatedChanges save selected actors keep" },
		{ "ModuleRelativePath", "Public/KeepSimulationChangesBPLibrary.h" },
		{ "ToolTip", "Expose to blueprints the original Engine function defined in \"...\\Engine\\Source\\Editor\\LevelEditor\\Private\\LevelEditor\"" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepSelectedActorsSimulatedChanges_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeepSimulationChangesBPLibrary, nullptr, "KeepSelectedActorsSimulatedChanges", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepSelectedActorsSimulatedChanges_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepSelectedActorsSimulatedChanges_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepSelectedActorsSimulatedChanges()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepSelectedActorsSimulatedChanges_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UKeepSimulationChangesBPLibrary_NoRegister()
	{
		return UKeepSimulationChangesBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_KeepSimulationChanges,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepActorSimulatedChanges, "KeepActorSimulatedChanges" }, // 3674187252
		{ &Z_Construct_UFunction_UKeepSimulationChangesBPLibrary_KeepSelectedActorsSimulatedChanges, "KeepSelectedActorsSimulatedChanges" }, // 214751561
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
		{ "IncludePath", "KeepSimulationChangesBPLibrary.h" },
		{ "ModuleRelativePath", "Public/KeepSimulationChangesBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKeepSimulationChangesBPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics::ClassParams = {
		&UKeepSimulationChangesBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UKeepSimulationChangesBPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UKeepSimulationChangesBPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UKeepSimulationChangesBPLibrary, 2864014618);
	template<> KEEPSIMULATIONCHANGES_API UClass* StaticClass<UKeepSimulationChangesBPLibrary>()
	{
		return UKeepSimulationChangesBPLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UKeepSimulationChangesBPLibrary(Z_Construct_UClass_UKeepSimulationChangesBPLibrary, &UKeepSimulationChangesBPLibrary::StaticClass, TEXT("/Script/KeepSimulationChanges"), TEXT("UKeepSimulationChangesBPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UKeepSimulationChangesBPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
