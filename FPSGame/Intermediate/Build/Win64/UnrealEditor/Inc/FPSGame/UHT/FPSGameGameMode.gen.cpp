// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPSGame/FPSGameGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSGameGameMode() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGameCharacter_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGameGameMode();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGameGameMode_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_UWeaponData_NoRegister();
	FPSGAME_API UScriptStruct* Z_Construct_UScriptStruct_FRoundWeapons();
	UPackage* Z_Construct_UPackage__Script_FPSGame();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RoundWeapons;
class UScriptStruct* FRoundWeapons::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RoundWeapons.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RoundWeapons.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRoundWeapons, (UObject*)Z_Construct_UPackage__Script_FPSGame(), TEXT("RoundWeapons"));
	}
	return Z_Registration_Info_UScriptStruct_RoundWeapons.OuterSingleton;
}
template<> FPSGAME_API UScriptStruct* StaticStruct<FRoundWeapons>()
{
	return FRoundWeapons::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRoundWeapons_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Round_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Round;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRoundWeapons_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRoundWeapons>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_Round_MetaData[] = {
		{ "Category", "RoundWeapons" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_Round = { "Round", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoundWeapons, Round), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_Round_MetaData), Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_Round_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_WeaponData_MetaData[] = {
		{ "Category", "RoundWeapons" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_WeaponData = { "WeaponData", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoundWeapons, WeaponData), Z_Construct_UClass_UWeaponData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_WeaponData_MetaData), Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_WeaponData_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRoundWeapons_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_Round,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewProp_WeaponData,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRoundWeapons_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FPSGame,
		nullptr,
		&NewStructOps,
		"RoundWeapons",
		Z_Construct_UScriptStruct_FRoundWeapons_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoundWeapons_Statics::PropPointers),
		sizeof(FRoundWeapons),
		alignof(FRoundWeapons),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoundWeapons_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRoundWeapons_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoundWeapons_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FRoundWeapons()
	{
		if (!Z_Registration_Info_UScriptStruct_RoundWeapons.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RoundWeapons.InnerSingleton, Z_Construct_UScriptStruct_FRoundWeapons_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RoundWeapons.InnerSingleton;
	}
	DEFINE_FUNCTION(AFPSGameGameMode::execBeginNextRound)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginNextRound();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFPSGameGameMode::execSpawnPlayer)
	{
		P_GET_OBJECT(APlayerController,Z_Param_NewPlayer);
		P_GET_PROPERTY(FIntProperty,Z_Param_TeamID);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnPlayer(Z_Param_NewPlayer,Z_Param_TeamID);
		P_NATIVE_END;
	}
	void AFPSGameGameMode::StaticRegisterNativesAFPSGameGameMode()
	{
		UClass* Class = AFPSGameGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginNextRound", &AFPSGameGameMode::execBeginNextRound },
			{ "SpawnPlayer", &AFPSGameGameMode::execSpawnPlayer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFPSGameGameMode_BeginNextRound_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGameGameMode_BeginNextRound_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGameGameMode_BeginNextRound_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGameGameMode, nullptr, "BeginNextRound", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameGameMode_BeginNextRound_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGameGameMode_BeginNextRound_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AFPSGameGameMode_BeginNextRound()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGameGameMode_BeginNextRound_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics
	{
		struct FPSGameGameMode_eventSpawnPlayer_Parms
		{
			APlayerController* NewPlayer;
			int32 TeamID;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NewPlayer;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TeamID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::NewProp_NewPlayer = { "NewPlayer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGameGameMode_eventSpawnPlayer_Parms, NewPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::NewProp_TeamID = { "TeamID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGameGameMode_eventSpawnPlayer_Parms, TeamID), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::NewProp_NewPlayer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::NewProp_TeamID,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGameGameMode, nullptr, "SpawnPlayer", nullptr, nullptr, Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::PropPointers), sizeof(Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::FPSGameGameMode_eventSpawnPlayer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::FPSGameGameMode_eventSpawnPlayer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFPSGameGameMode);
	UClass* Z_Construct_UClass_AFPSGameGameMode_NoRegister()
	{
		return AFPSGameGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AFPSGameGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Player_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_Player;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TeamSize_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_TeamSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumRounds_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumRounds;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoundBeginDelay_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RoundBeginDelay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoundEndDelay_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RoundEndDelay;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RoundWeapons_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoundWeapons_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RoundWeapons;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStartWithOnePlayer_MetaData[];
#endif
		static void NewProp_bStartWithOnePlayer_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStartWithOnePlayer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPSGameGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_FPSGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AFPSGameGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFPSGameGameMode_BeginNextRound, "BeginNextRound" }, // 461941104
		{ &Z_Construct_UFunction_AFPSGameGameMode_SpawnPlayer, "SpawnPlayer" }, // 1821989059
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "FPSGameGameMode.h" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_Player_MetaData[] = {
		{ "Category", "FPSGameGameMode" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameGameMode, Player), Z_Construct_UClass_UClass, Z_Construct_UClass_AFPSGameCharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_Player_MetaData), Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_Player_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_TeamSize_MetaData[] = {
		{ "Category", "FPSGameGameMode" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_TeamSize = { "TeamSize", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameGameMode, TeamSize), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_TeamSize_MetaData), Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_TeamSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_NumRounds_MetaData[] = {
		{ "Category", "FPSGameGameMode" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_NumRounds = { "NumRounds", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameGameMode, NumRounds), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_NumRounds_MetaData), Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_NumRounds_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundBeginDelay_MetaData[] = {
		{ "Category", "FPSGameGameMode" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundBeginDelay = { "RoundBeginDelay", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameGameMode, RoundBeginDelay), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundBeginDelay_MetaData), Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundBeginDelay_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundEndDelay_MetaData[] = {
		{ "Category", "FPSGameGameMode" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundEndDelay = { "RoundEndDelay", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameGameMode, RoundEndDelay), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundEndDelay_MetaData), Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundEndDelay_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundWeapons_Inner = { "RoundWeapons", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FRoundWeapons, METADATA_PARAMS(0, nullptr) }; // 3244574920
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundWeapons_MetaData[] = {
		{ "Category", "FPSGameGameMode" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundWeapons = { "RoundWeapons", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameGameMode, RoundWeapons), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundWeapons_MetaData), Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundWeapons_MetaData) }; // 3244574920
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_bStartWithOnePlayer_MetaData[] = {
		{ "Category", "FPSGameGameMode" },
		{ "ModuleRelativePath", "FPSGameGameMode.h" },
	};
#endif
	void Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_bStartWithOnePlayer_SetBit(void* Obj)
	{
		((AFPSGameGameMode*)Obj)->bStartWithOnePlayer = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_bStartWithOnePlayer = { "bStartWithOnePlayer", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFPSGameGameMode), &Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_bStartWithOnePlayer_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_bStartWithOnePlayer_MetaData), Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_bStartWithOnePlayer_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFPSGameGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_Player,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_TeamSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_NumRounds,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundBeginDelay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundEndDelay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundWeapons_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_RoundWeapons,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameGameMode_Statics::NewProp_bStartWithOnePlayer,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPSGameGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSGameGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFPSGameGameMode_Statics::ClassParams = {
		&AFPSGameGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFPSGameGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AFPSGameGameMode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameGameMode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AFPSGameGameMode()
	{
		if (!Z_Registration_Info_UClass_AFPSGameGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFPSGameGameMode.OuterSingleton, Z_Construct_UClass_AFPSGameGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFPSGameGameMode.OuterSingleton;
	}
	template<> FPSGAME_API UClass* StaticClass<AFPSGameGameMode>()
	{
		return AFPSGameGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSGameGameMode);
	AFPSGameGameMode::~AFPSGameGameMode() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_Statics::ScriptStructInfo[] = {
		{ FRoundWeapons::StaticStruct, Z_Construct_UScriptStruct_FRoundWeapons_Statics::NewStructOps, TEXT("RoundWeapons"), &Z_Registration_Info_UScriptStruct_RoundWeapons, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRoundWeapons), 3244574920U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFPSGameGameMode, AFPSGameGameMode::StaticClass, TEXT("AFPSGameGameMode"), &Z_Registration_Info_UClass_AFPSGameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFPSGameGameMode), 53418173U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_4052827543(TEXT("/Script/FPSGame"),
		Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
