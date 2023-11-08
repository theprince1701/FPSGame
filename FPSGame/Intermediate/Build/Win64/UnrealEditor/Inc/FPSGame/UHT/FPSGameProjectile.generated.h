// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FPSGameProjectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef FPSGAME_FPSGameProjectile_generated_h
#error "FPSGameProjectile.generated.h already included, missing '#pragma once' in FPSGameProjectile.h"
#endif
#define FPSGAME_FPSGameProjectile_generated_h

#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_SPARSE_DATA
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSGameProjectile(); \
	friend struct Z_Construct_UClass_AFPSGameProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSGameProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSGameProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSGameProjectile(AFPSGameProjectile&&); \
	NO_API AFPSGameProjectile(const AFPSGameProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSGameProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSGameProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSGameProjectile) \
	NO_API virtual ~AFPSGameProjectile();


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_12_PROLOG
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_SPARSE_DATA \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSGAME_API UClass* StaticClass<class AFPSGameProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGameProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
