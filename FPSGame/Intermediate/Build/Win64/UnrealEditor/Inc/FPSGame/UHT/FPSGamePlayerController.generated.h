// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "FPSGamePlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AFPSGameCharacter;
class APlayerState;
struct FHitResult;
#ifdef FPSGAME_FPSGamePlayerController_generated_h
#error "FPSGamePlayerController.generated.h already included, missing '#pragma once' in FPSGamePlayerController.h"
#endif
#define FPSGAME_FPSGamePlayerController_generated_h

#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_SPARSE_DATA
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Client_Respawn_Implementation(); \
	virtual void Server_SetName_Implementation(const FString& PlayerName); \
	virtual void Client_OnDeath_Implementation(APlayerState* Killer); \
	virtual void Server_OnHit_Implementation(AFPSGameCharacter* DamageInstigator, AFPSGameCharacter* DamagedActor, float Damage, FHitResult const& Hit); \
	virtual void Client_OnEndRound_Implementation(int32 Winner); \
	virtual void Client_OnHit_Implementation(FVector Location); \
	virtual void Client_OnKill_Implementation(APlayerState* Victim); \
 \
	DECLARE_FUNCTION(execTogglePaused); \
	DECLARE_FUNCTION(execClient_Respawn); \
	DECLARE_FUNCTION(execServer_SetName); \
	DECLARE_FUNCTION(execClient_OnDeath); \
	DECLARE_FUNCTION(execServer_OnHit); \
	DECLARE_FUNCTION(execClient_OnEndRound); \
	DECLARE_FUNCTION(execClient_OnHit); \
	DECLARE_FUNCTION(execClient_OnKill);


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_ACCESSORS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_CALLBACK_WRAPPERS
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSGamePlayerController(); \
	friend struct Z_Construct_UClass_AFPSGamePlayerController_Statics; \
public: \
	DECLARE_CLASS(AFPSGamePlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSGame"), NO_API) \
	DECLARE_SERIALIZER(AFPSGamePlayerController) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		CurrentRespawnTimer=NETFIELD_REP_START, \
		NETFIELD_REP_END=CurrentRespawnTimer	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSGamePlayerController(AFPSGamePlayerController&&); \
	NO_API AFPSGamePlayerController(const AFPSGamePlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSGamePlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSGamePlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSGamePlayerController) \
	NO_API virtual ~AFPSGamePlayerController();


#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_16_PROLOG
#define FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_SPARSE_DATA \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_ACCESSORS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_CALLBACK_WRAPPERS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_INCLASS_NO_PURE_DECLS \
	FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSGAME_API UClass* StaticClass<class AFPSGamePlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UnrealProjects_GDW_FPSGame_FPSGame_Source_FPSGame_FPSGamePlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
