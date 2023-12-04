// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPSGame/FPSGamePlayerController.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSGamePlayerController() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerState_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ASpectatorPawn_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGameCharacter_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGamePlayerController();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGamePlayerController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FPSGame();
// End Cross Module References
	DEFINE_FUNCTION(AFPSGamePlayerController::execTogglePaused)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TogglePaused();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFPSGamePlayerController::execClient_Respawn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Client_Respawn_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFPSGamePlayerController::execServer_SetName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_PlayerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SetName_Implementation(Z_Param_PlayerName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFPSGamePlayerController::execClient_OnDeath)
	{
		P_GET_OBJECT(APlayerState,Z_Param_Killer);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Client_OnDeath_Implementation(Z_Param_Killer);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFPSGamePlayerController::execServer_OnHit)
	{
		P_GET_OBJECT(AFPSGameCharacter,Z_Param_DamageInstigator);
		P_GET_OBJECT(AFPSGameCharacter,Z_Param_DamagedActor);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Damage);
		P_GET_STRUCT(FHitResult,Z_Param_Hit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_OnHit_Implementation(Z_Param_DamageInstigator,Z_Param_DamagedActor,Z_Param_Damage,Z_Param_Hit);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFPSGamePlayerController::execClient_OnEndRound)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Winner);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Client_OnEndRound_Implementation(Z_Param_Winner);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFPSGamePlayerController::execClient_OnHit)
	{
		P_GET_STRUCT(FVector,Z_Param_Location);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Client_OnHit_Implementation(Z_Param_Location);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AFPSGamePlayerController::execClient_OnKill)
	{
		P_GET_OBJECT(APlayerState,Z_Param_Victim);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Client_OnKill_Implementation(Z_Param_Victim);
		P_NATIVE_END;
	}
	struct FPSGamePlayerController_eventClient_OnDeath_Parms
	{
		APlayerState* Killer;
	};
	struct FPSGamePlayerController_eventClient_OnEndRound_Parms
	{
		int32 Winner;
	};
	struct FPSGamePlayerController_eventClient_OnHit_Parms
	{
		FVector Location;
	};
	struct FPSGamePlayerController_eventClient_OnKill_Parms
	{
		APlayerState* Victim;
	};
	struct FPSGamePlayerController_eventServer_OnHit_Parms
	{
		AFPSGameCharacter* DamageInstigator;
		AFPSGameCharacter* DamagedActor;
		float Damage;
		FHitResult Hit;
	};
	struct FPSGamePlayerController_eventServer_SetName_Parms
	{
		FString PlayerName;
	};
	static FName NAME_AFPSGamePlayerController_Client_OnDeath = FName(TEXT("Client_OnDeath"));
	void AFPSGamePlayerController::Client_OnDeath(APlayerState* Killer)
	{
		FPSGamePlayerController_eventClient_OnDeath_Parms Parms;
		Parms.Killer=Killer;
		ProcessEvent(FindFunctionChecked(NAME_AFPSGamePlayerController_Client_OnDeath),&Parms);
	}
	static FName NAME_AFPSGamePlayerController_Client_OnEndRound = FName(TEXT("Client_OnEndRound"));
	void AFPSGamePlayerController::Client_OnEndRound(int32 Winner)
	{
		FPSGamePlayerController_eventClient_OnEndRound_Parms Parms;
		Parms.Winner=Winner;
		ProcessEvent(FindFunctionChecked(NAME_AFPSGamePlayerController_Client_OnEndRound),&Parms);
	}
	static FName NAME_AFPSGamePlayerController_Client_OnHit = FName(TEXT("Client_OnHit"));
	void AFPSGamePlayerController::Client_OnHit(FVector Location)
	{
		FPSGamePlayerController_eventClient_OnHit_Parms Parms;
		Parms.Location=Location;
		ProcessEvent(FindFunctionChecked(NAME_AFPSGamePlayerController_Client_OnHit),&Parms);
	}
	static FName NAME_AFPSGamePlayerController_Client_OnKill = FName(TEXT("Client_OnKill"));
	void AFPSGamePlayerController::Client_OnKill(APlayerState* Victim)
	{
		FPSGamePlayerController_eventClient_OnKill_Parms Parms;
		Parms.Victim=Victim;
		ProcessEvent(FindFunctionChecked(NAME_AFPSGamePlayerController_Client_OnKill),&Parms);
	}
	static FName NAME_AFPSGamePlayerController_Client_Respawn = FName(TEXT("Client_Respawn"));
	void AFPSGamePlayerController::Client_Respawn()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFPSGamePlayerController_Client_Respawn),NULL);
	}
	static FName NAME_AFPSGamePlayerController_Server_OnHit = FName(TEXT("Server_OnHit"));
	void AFPSGamePlayerController::Server_OnHit(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor, float Damage, FHitResult const& Hit)
	{
		FPSGamePlayerController_eventServer_OnHit_Parms Parms;
		Parms.DamageInstigator=DamageInstigator;
		Parms.DamagedActor=DamagedActor;
		Parms.Damage=Damage;
		Parms.Hit=Hit;
		ProcessEvent(FindFunctionChecked(NAME_AFPSGamePlayerController_Server_OnHit),&Parms);
	}
	static FName NAME_AFPSGamePlayerController_Server_SetName = FName(TEXT("Server_SetName"));
	void AFPSGamePlayerController::Server_SetName(const FString& PlayerName)
	{
		FPSGamePlayerController_eventServer_SetName_Parms Parms;
		Parms.PlayerName=PlayerName;
		ProcessEvent(FindFunctionChecked(NAME_AFPSGamePlayerController_Server_SetName),&Parms);
	}
	void AFPSGamePlayerController::StaticRegisterNativesAFPSGamePlayerController()
	{
		UClass* Class = AFPSGamePlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Client_OnDeath", &AFPSGamePlayerController::execClient_OnDeath },
			{ "Client_OnEndRound", &AFPSGamePlayerController::execClient_OnEndRound },
			{ "Client_OnHit", &AFPSGamePlayerController::execClient_OnHit },
			{ "Client_OnKill", &AFPSGamePlayerController::execClient_OnKill },
			{ "Client_Respawn", &AFPSGamePlayerController::execClient_Respawn },
			{ "Server_OnHit", &AFPSGamePlayerController::execServer_OnHit },
			{ "Server_SetName", &AFPSGamePlayerController::execServer_SetName },
			{ "TogglePaused", &AFPSGamePlayerController::execTogglePaused },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Killer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::NewProp_Killer = { "Killer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventClient_OnDeath_Parms, Killer), Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::NewProp_Killer,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGamePlayerController, nullptr, "Client_OnDeath", nullptr, nullptr, Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::PropPointers), sizeof(FPSGamePlayerController_eventClient_OnDeath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01080CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::PropPointers) < 2048);
	static_assert(sizeof(FPSGamePlayerController_eventClient_OnDeath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_Winner;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::NewProp_Winner = { "Winner", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventClient_OnEndRound_Parms, Winner), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::NewProp_Winner,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGamePlayerController, nullptr, "Client_OnEndRound", nullptr, nullptr, Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::PropPointers), sizeof(FPSGamePlayerController_eventClient_OnEndRound_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::PropPointers) < 2048);
	static_assert(sizeof(FPSGamePlayerController_eventClient_OnEndRound_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventClient_OnHit_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::NewProp_Location,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGamePlayerController, nullptr, "Client_OnHit", nullptr, nullptr, Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::PropPointers), sizeof(FPSGamePlayerController_eventClient_OnHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01820CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::PropPointers) < 2048);
	static_assert(sizeof(FPSGamePlayerController_eventClient_OnHit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Victim;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::NewProp_Victim = { "Victim", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventClient_OnKill_Parms, Victim), Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::NewProp_Victim,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGamePlayerController, nullptr, "Client_OnKill", nullptr, nullptr, Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::PropPointers), sizeof(FPSGamePlayerController_eventClient_OnKill_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::PropPointers) < 2048);
	static_assert(sizeof(FPSGamePlayerController_eventClient_OnKill_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGamePlayerController_Client_Respawn_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Client_Respawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGamePlayerController_Client_Respawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGamePlayerController, nullptr, "Client_Respawn", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01080CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Client_Respawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGamePlayerController_Client_Respawn_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AFPSGamePlayerController_Client_Respawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGamePlayerController_Client_Respawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamageInstigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DamagedActor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Damage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_DamageInstigator = { "DamageInstigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventServer_OnHit_Parms, DamageInstigator), Z_Construct_UClass_AFPSGameCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_DamagedActor = { "DamagedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventServer_OnHit_Parms, DamagedActor), Z_Construct_UClass_AFPSGameCharacter_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventServer_OnHit_Parms, Damage), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventServer_OnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_Hit_MetaData), Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_Hit_MetaData) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_DamageInstigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_DamagedActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_Damage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::NewProp_Hit,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGamePlayerController, nullptr, "Server_OnHit", nullptr, nullptr, Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::PropPointers), sizeof(FPSGamePlayerController_eventServer_OnHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00280CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::PropPointers) < 2048);
	static_assert(sizeof(FPSGamePlayerController_eventServer_OnHit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_PlayerName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::NewProp_PlayerName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::NewProp_PlayerName = { "PlayerName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGamePlayerController_eventServer_SetName_Parms, PlayerName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::NewProp_PlayerName_MetaData), Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::NewProp_PlayerName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::NewProp_PlayerName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGamePlayerController, nullptr, "Server_SetName", nullptr, nullptr, Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::PropPointers), sizeof(FPSGamePlayerController_eventServer_SetName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00280CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::PropPointers) < 2048);
	static_assert(sizeof(FPSGamePlayerController_eventServer_SetName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGamePlayerController_TogglePaused_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGamePlayerController_TogglePaused_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGamePlayerController_TogglePaused_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGamePlayerController, nullptr, "TogglePaused", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGamePlayerController_TogglePaused_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGamePlayerController_TogglePaused_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AFPSGamePlayerController_TogglePaused()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGamePlayerController_TogglePaused_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFPSGamePlayerController);
	UClass* Z_Construct_UClass_AFPSGamePlayerController_NoRegister()
	{
		return AFPSGamePlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AFPSGamePlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpectatorPawnSubclass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_SpectatorPawnSubclass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RespawnTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RespawnTimer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentRespawnTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentRespawnTimer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MouseSensitivity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MouseSensitivity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FPS_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FPS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Ping_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Ping;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PacketLoss_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PacketLoss;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerPawnActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerPawnActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPSGamePlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_FPSGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AFPSGamePlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFPSGamePlayerController_Client_OnDeath, "Client_OnDeath" }, // 3152093726
		{ &Z_Construct_UFunction_AFPSGamePlayerController_Client_OnEndRound, "Client_OnEndRound" }, // 2155572119
		{ &Z_Construct_UFunction_AFPSGamePlayerController_Client_OnHit, "Client_OnHit" }, // 1317269909
		{ &Z_Construct_UFunction_AFPSGamePlayerController_Client_OnKill, "Client_OnKill" }, // 4256680412
		{ &Z_Construct_UFunction_AFPSGamePlayerController_Client_Respawn, "Client_Respawn" }, // 2802431119
		{ &Z_Construct_UFunction_AFPSGamePlayerController_Server_OnHit, "Server_OnHit" }, // 223248319
		{ &Z_Construct_UFunction_AFPSGamePlayerController_Server_SetName, "Server_SetName" }, // 1353789188
		{ &Z_Construct_UFunction_AFPSGamePlayerController_TogglePaused, "TogglePaused" }, // 2725551066
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "FPSGamePlayerController.h" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_SpectatorPawnSubclass_MetaData[] = {
		{ "Category", "FPSGamePlayerController" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_SpectatorPawnSubclass = { "SpectatorPawnSubclass", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, SpectatorPawnSubclass), Z_Construct_UClass_UClass, Z_Construct_UClass_ASpectatorPawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_SpectatorPawnSubclass_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_SpectatorPawnSubclass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_RespawnTimer_MetaData[] = {
		{ "Category", "FPSGamePlayerController" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_RespawnTimer = { "RespawnTimer", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, RespawnTimer), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_RespawnTimer_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_RespawnTimer_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_CurrentRespawnTimer_MetaData[] = {
		{ "Category", "FPSGamePlayerController" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_CurrentRespawnTimer = { "CurrentRespawnTimer", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, CurrentRespawnTimer), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_CurrentRespawnTimer_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_CurrentRespawnTimer_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_MouseSensitivity_MetaData[] = {
		{ "Category", "FPSGamePlayerController" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_MouseSensitivity = { "MouseSensitivity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, MouseSensitivity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_MouseSensitivity_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_MouseSensitivity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_FPS_MetaData[] = {
		{ "Category", "FPSGamePlayerController" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_FPS = { "FPS", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, FPS), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_FPS_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_FPS_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_Ping_MetaData[] = {
		{ "Category", "FPSGamePlayerController" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_Ping = { "Ping", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, Ping), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_Ping_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_Ping_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PacketLoss_MetaData[] = {
		{ "Category", "FPSGamePlayerController" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PacketLoss = { "PacketLoss", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, PacketLoss), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PacketLoss_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PacketLoss_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_InputMappingContext_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_InputMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PlayerPawnActor_MetaData[] = {
		{ "ModuleRelativePath", "FPSGamePlayerController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PlayerPawnActor = { "PlayerPawnActor", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGamePlayerController, PlayerPawnActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PlayerPawnActor_MetaData), Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PlayerPawnActor_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFPSGamePlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_SpectatorPawnSubclass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_RespawnTimer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_CurrentRespawnTimer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_MouseSensitivity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_FPS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_Ping,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PacketLoss,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_InputMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGamePlayerController_Statics::NewProp_PlayerPawnActor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPSGamePlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSGamePlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFPSGamePlayerController_Statics::ClassParams = {
		&AFPSGamePlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFPSGamePlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AFPSGamePlayerController_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGamePlayerController_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AFPSGamePlayerController()
	{
		if (!Z_Registration_Info_UClass_AFPSGamePlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFPSGamePlayerController.OuterSingleton, Z_Construct_UClass_AFPSGamePlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFPSGamePlayerController.OuterSingleton;
	}
	template<> FPSGAME_API UClass* StaticClass<AFPSGamePlayerController>()
	{
		return AFPSGamePlayerController::StaticClass();
	}

	void AFPSGamePlayerController::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_CurrentRespawnTimer(TEXT("CurrentRespawnTimer"));

		const bool bIsValid = true
			&& Name_CurrentRespawnTimer == ClassReps[(int32)ENetFields_Private::CurrentRespawnTimer].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AFPSGamePlayerController"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSGamePlayerController);
	AFPSGamePlayerController::~AFPSGamePlayerController() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFPSGamePlayerController, AFPSGamePlayerController::StaticClass, TEXT("AFPSGamePlayerController"), &Z_Registration_Info_UClass_AFPSGamePlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFPSGamePlayerController), 875722951U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_2688886936(TEXT("/Script/FPSGame"),
		Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
