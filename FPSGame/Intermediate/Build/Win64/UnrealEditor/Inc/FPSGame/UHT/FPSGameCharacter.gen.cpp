// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPSGame/FPSGameCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSGameCharacter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGameCharacter();
	FPSGAME_API UClass* Z_Construct_UClass_AFPSGameCharacter_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_UPlayerMovementComponent_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_UWeaponController_NoRegister();
	FPSGAME_API UClass* Z_Construct_UClass_UWeaponManager_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FPSGame();
// End Cross Module References
	DEFINE_FUNCTION(AFPSGameCharacter::execServer_SetInput)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_VerticalMove);
		P_GET_PROPERTY(FFloatProperty,Z_Param_HorizontalMove);
		P_GET_PROPERTY(FFloatProperty,Z_Param_VertLook);
		P_GET_PROPERTY(FFloatProperty,Z_Param_HorLook);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SetInput_Implementation(Z_Param_VerticalMove,Z_Param_HorizontalMove,Z_Param_VertLook,Z_Param_HorLook);
		P_NATIVE_END;
	}
	struct FPSGameCharacter_eventServer_SetInput_Parms
	{
		float VerticalMove;
		float HorizontalMove;
		float VertLook;
		float HorLook;
	};
	static FName NAME_AFPSGameCharacter_OnSlideEnd = FName(TEXT("OnSlideEnd"));
	void AFPSGameCharacter::OnSlideEnd()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFPSGameCharacter_OnSlideEnd),NULL);
	}
	static FName NAME_AFPSGameCharacter_OnSlideStart = FName(TEXT("OnSlideStart"));
	void AFPSGameCharacter::OnSlideStart()
	{
		ProcessEvent(FindFunctionChecked(NAME_AFPSGameCharacter_OnSlideStart),NULL);
	}
	static FName NAME_AFPSGameCharacter_Server_SetInput = FName(TEXT("Server_SetInput"));
	void AFPSGameCharacter::Server_SetInput(float VerticalMove, float HorizontalMove, float VertLook, float HorLook)
	{
		FPSGameCharacter_eventServer_SetInput_Parms Parms;
		Parms.VerticalMove=VerticalMove;
		Parms.HorizontalMove=HorizontalMove;
		Parms.VertLook=VertLook;
		Parms.HorLook=HorLook;
		ProcessEvent(FindFunctionChecked(NAME_AFPSGameCharacter_Server_SetInput),&Parms);
	}
	void AFPSGameCharacter::StaticRegisterNativesAFPSGameCharacter()
	{
		UClass* Class = AFPSGameCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Server_SetInput", &AFPSGameCharacter::execServer_SetInput },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFPSGameCharacter_OnSlideEnd_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGameCharacter_OnSlideEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGameCharacter_OnSlideEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGameCharacter, nullptr, "OnSlideEnd", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameCharacter_OnSlideEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGameCharacter_OnSlideEnd_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AFPSGameCharacter_OnSlideEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGameCharacter_OnSlideEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGameCharacter_OnSlideStart_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGameCharacter_OnSlideStart_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGameCharacter_OnSlideStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGameCharacter, nullptr, "OnSlideStart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameCharacter_OnSlideStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGameCharacter_OnSlideStart_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AFPSGameCharacter_OnSlideStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGameCharacter_OnSlideStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalMove;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HorizontalMove;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VertLook;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HorLook;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::NewProp_VerticalMove = { "VerticalMove", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGameCharacter_eventServer_SetInput_Parms, VerticalMove), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::NewProp_HorizontalMove = { "HorizontalMove", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGameCharacter_eventServer_SetInput_Parms, HorizontalMove), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::NewProp_VertLook = { "VertLook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGameCharacter_eventServer_SetInput_Parms, VertLook), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::NewProp_HorLook = { "HorLook", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPSGameCharacter_eventServer_SetInput_Parms, HorLook), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::NewProp_VerticalMove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::NewProp_HorizontalMove,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::NewProp_VertLook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::NewProp_HorLook,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFPSGameCharacter, nullptr, "Server_SetInput", nullptr, nullptr, Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::PropPointers), sizeof(FPSGameCharacter_eventServer_SetInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00280C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::PropPointers) < 2048);
	static_assert(sizeof(FPSGameCharacter_eventServer_SetInput_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFPSGameCharacter);
	UClass* Z_Construct_UClass_AFPSGameCharacter_NoRegister()
	{
		return AFPSGameCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AFPSGameCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FirstPersonCameraComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FirstPersonCameraComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SprintAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SprintAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CrouchAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CrouchAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AimAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AimAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReloadAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReloadAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InspectAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InspectAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FireAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FireAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VerticalMovement_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalMovement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HorizontalMovement_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HorizontalMovement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VerticalLook_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalLook;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HorizontalLook_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HorizontalLook;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsSliding_MetaData[];
#endif
		static void NewProp_IsSliding_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSliding;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlideTimer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SlideTimer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsSprinting_MetaData[];
#endif
		static void NewProp_IsSprinting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSprinting;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalVerticalMovement_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LocalVerticalMovement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalHorizontalMovement_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LocalHorizontalMovement;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalHorizontalLook_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LocalHorizontalLook;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LocalVerticalLook_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LocalVerticalLook;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PlayerMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerMovementComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponController_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WeaponManager_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponManager;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh1P_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh1P;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPSGameCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_FPSGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AFPSGameCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFPSGameCharacter_OnSlideEnd, "OnSlideEnd" }, // 3409538063
		{ &Z_Construct_UFunction_AFPSGameCharacter_OnSlideStart, "OnSlideStart" }, // 1997333008
		{ &Z_Construct_UFunction_AFPSGameCharacter_Server_SetInput, "Server_SetInput" }, // 1786061223
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "FPSGameCharacter.h" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FirstPersonCameraComponent = { "FirstPersonCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, FirstPersonCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FirstPersonCameraComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_JumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_JumpAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_JumpAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_MoveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_MoveAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_MoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SprintAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SprintAction = { "SprintAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, SprintAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SprintAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SprintAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_CrouchAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_CrouchAction = { "CrouchAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, CrouchAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_CrouchAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_CrouchAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_AimAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_AimAction = { "AimAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, AimAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_AimAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_AimAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_ReloadAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_ReloadAction = { "ReloadAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, ReloadAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_ReloadAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_ReloadAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_InspectAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_InspectAction = { "InspectAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, InspectAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_InspectAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_InspectAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FireAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FireAction = { "FireAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, FireAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FireAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FireAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalMovement_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalMovement = { "VerticalMovement", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, VerticalMovement), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalMovement_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalMovement_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalMovement_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalMovement = { "HorizontalMovement", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, HorizontalMovement), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalMovement_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalMovement_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalLook_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalLook = { "VerticalLook", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, VerticalLook), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalLook_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalLook_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalLook_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalLook = { "HorizontalLook", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, HorizontalLook), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalLook_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalLook_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSliding_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSliding_SetBit(void* Obj)
	{
		((AFPSGameCharacter*)Obj)->IsSliding = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSliding = { "IsSliding", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFPSGameCharacter), &Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSliding_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSliding_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSliding_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SlideTimer_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SlideTimer = { "SlideTimer", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, SlideTimer), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SlideTimer_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SlideTimer_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSprinting_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	void Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSprinting_SetBit(void* Obj)
	{
		((AFPSGameCharacter*)Obj)->IsSprinting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSprinting = { "IsSprinting", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AFPSGameCharacter), &Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSprinting_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSprinting_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSprinting_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalMovement_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalMovement = { "LocalVerticalMovement", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, LocalVerticalMovement), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalMovement_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalMovement_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalMovement_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalMovement = { "LocalHorizontalMovement", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, LocalHorizontalMovement), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalMovement_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalMovement_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalLook_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalLook = { "LocalHorizontalLook", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, LocalHorizontalLook), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalLook_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalLook_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalLook_MetaData[] = {
		{ "Category", "FPSGameCharacter" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalLook = { "LocalVerticalLook", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, LocalVerticalLook), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalLook_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalLook_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_PlayerMovementComponent_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_PlayerMovementComponent = { "PlayerMovementComponent", nullptr, (EPropertyFlags)0x002008000009001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, PlayerMovementComponent), Z_Construct_UClass_UPlayerMovementComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_PlayerMovementComponent_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_PlayerMovementComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponController_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Weapons" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponController = { "WeaponController", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, WeaponController), Z_Construct_UClass_UWeaponController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponController_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponController_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponManager_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Weapons" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponManager = { "WeaponManager", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, WeaponManager), Z_Construct_UClass_UWeaponManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponManager_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponManager_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_Mesh1P_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "FPSGameCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_Mesh1P = { "Mesh1P", nullptr, (EPropertyFlags)0x00100000000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AFPSGameCharacter, Mesh1P), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_Mesh1P_MetaData), Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_Mesh1P_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFPSGameCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FirstPersonCameraComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_JumpAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SprintAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_CrouchAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_AimAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_ReloadAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_InspectAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_FireAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalMovement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalMovement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_VerticalLook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_HorizontalLook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSliding,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_SlideTimer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_IsSprinting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalMovement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalMovement,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalHorizontalLook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LocalVerticalLook,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_PlayerMovementComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_WeaponManager,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFPSGameCharacter_Statics::NewProp_Mesh1P,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPSGameCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSGameCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AFPSGameCharacter_Statics::ClassParams = {
		&AFPSGameCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFPSGameCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AFPSGameCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFPSGameCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AFPSGameCharacter()
	{
		if (!Z_Registration_Info_UClass_AFPSGameCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFPSGameCharacter.OuterSingleton, Z_Construct_UClass_AFPSGameCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AFPSGameCharacter.OuterSingleton;
	}
	template<> FPSGAME_API UClass* StaticClass<AFPSGameCharacter>()
	{
		return AFPSGameCharacter::StaticClass();
	}

	void AFPSGameCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_VerticalMovement(TEXT("VerticalMovement"));
		static const FName Name_HorizontalMovement(TEXT("HorizontalMovement"));
		static const FName Name_VerticalLook(TEXT("VerticalLook"));
		static const FName Name_HorizontalLook(TEXT("HorizontalLook"));
		static const FName Name_IsSliding(TEXT("IsSliding"));
		static const FName Name_SlideTimer(TEXT("SlideTimer"));
		static const FName Name_IsSprinting(TEXT("IsSprinting"));

		const bool bIsValid = true
			&& Name_VerticalMovement == ClassReps[(int32)ENetFields_Private::VerticalMovement].Property->GetFName()
			&& Name_HorizontalMovement == ClassReps[(int32)ENetFields_Private::HorizontalMovement].Property->GetFName()
			&& Name_VerticalLook == ClassReps[(int32)ENetFields_Private::VerticalLook].Property->GetFName()
			&& Name_HorizontalLook == ClassReps[(int32)ENetFields_Private::HorizontalLook].Property->GetFName()
			&& Name_IsSliding == ClassReps[(int32)ENetFields_Private::IsSliding].Property->GetFName()
			&& Name_SlideTimer == ClassReps[(int32)ENetFields_Private::SlideTimer].Property->GetFName()
			&& Name_IsSprinting == ClassReps[(int32)ENetFields_Private::IsSprinting].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AFPSGameCharacter"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSGameCharacter);
	AFPSGameCharacter::~AFPSGameCharacter() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AFPSGameCharacter, AFPSGameCharacter::StaticClass, TEXT("AFPSGameCharacter"), &Z_Registration_Info_UClass_AFPSGameCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFPSGameCharacter), 311155535U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_3465312397(TEXT("/Script/FPSGame"),
		Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
