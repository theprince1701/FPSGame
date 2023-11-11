// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FPSGameCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSGAME_FPSGameCharacter_generated_h
#error "FPSGameCharacter.generated.h already included, missing '#pragma once' in FPSGameCharacter.h"
#endif
#define FPSGAME_FPSGameCharacter_generated_h

#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_SPARSE_DATA
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Server_SetInput_Implementation(float VerticalMove, float HorizontalMove, float VertLook, float HorLook); \
 \
	DECLARE_FUNCTION(execServer_SetInput);


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_CALLBACK_WRAPPERS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSGameCharacter(); \
	friend struct Z_Construct_UClass_AFPSGameCharacter_Statics; \
public: \
	DECLARE_CLASS(AFPSGameCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSGameCharacter) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		VerticalMovement=NETFIELD_REP_START, \
		HorizontalMovement, \
		VerticalLook, \
		HorizontalLook, \
		IsSliding, \
		SlideTimer, \
		IsSprinting, \
		NETFIELD_REP_END=IsSprinting	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSGameCharacter(AFPSGameCharacter&&); \
	NO_API AFPSGameCharacter(const AFPSGameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSGameCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSGameCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSGameCharacter) \
	NO_API virtual ~AFPSGameCharacter();


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_21_PROLOG
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_SPARSE_DATA \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_CALLBACK_WRAPPERS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSGAME_API UClass* StaticClass<class AFPSGameCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
