// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FPSGameGameMode.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APlayerController;
#ifdef FPSGAME_FPSGameGameMode_generated_h
#error "FPSGameGameMode.generated.h already included, missing '#pragma once' in FPSGameGameMode.h"
#endif
#define FPSGAME_FPSGameGameMode_generated_h

#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FRoundWeapons_Statics; \
	FPSGAME_API static class UScriptStruct* StaticStruct();


template<> FPSGAME_API UScriptStruct* StaticStruct<struct FRoundWeapons>();

#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_SPARSE_DATA
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBeginNextRound); \
	DECLARE_FUNCTION(execSpawnPlayer);


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSGameGameMode(); \
	friend struct Z_Construct_UClass_AFPSGameGameMode_Statics; \
public: \
	DECLARE_CLASS(AFPSGameGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSGame"), FPSGAME_API) \
	DECLARE_SERIALIZER(AFPSGameGameMode)


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	FPSGAME_API AFPSGameGameMode(AFPSGameGameMode&&); \
	FPSGAME_API AFPSGameGameMode(const AFPSGameGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(FPSGAME_API, AFPSGameGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSGameGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSGameGameMode) \
	FPSGAME_API virtual ~AFPSGameGameMode();


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_35_PROLOG
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_SPARSE_DATA \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSGAME_API UClass* StaticClass<class AFPSGameGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
