// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "FPSGameInstance.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoginCompleted, bool, bWasSuccess);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStartSessionComplete, bool, bWasSuccess);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEndSessionComplete, bool, bWasSuccess);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDestroySessionComplete, bool, bWasSuccess);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJoinSessionComplete, bool, bWasSuccess);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreateSessionComplete, bool, bWasSuccess);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreateLobbyComplete, bool, bWasSuccess);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNetworkError, FName, ErrorName, FString, ErrorDescription);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTravelError, FName, ErrorName, FString, ErrorDescription);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMatchmakingFailed);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionAcceptedResult, bool, bWasSuccess);


UCLASS()
class FPSGAME_API UFPSGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	IOnlineSubsystem* OnlineSubSystem;
	IOnlineIdentityPtr UserIdentity;
	IOnlineSessionPtr Session;
	
public:
	virtual void Init() override;

	UPROPERTY(BlueprintAssignable) FOnLoginCompleted OnLoginComplete;

	
	UFUNCTION(BlueprintCallable) void StartMatchMaking();
	UFUNCTION(BlueprintCallable) void DestroySession();
	UFUNCTION(BlueprintCallable) bool TryAutoLogin();
	UFUNCTION(BlueprintCallable) void Login(FString ID, FString Token, FString LoginType);
	UFUNCTION(BlueprintCallable) void LogOut();

	UFUNCTION(BlueprintCallable, BlueprintPure) FString GetPlayerUsername();

protected:
	void OnLoginCompleted(int32 LocalUser, bool bWasSuccess, const FUniqueNetId& UserID, const FString& Error);
	void OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result);
	void OnFindSessionCompleted(bool bWasSuccess, TSharedRef<FOnlineSessionSearch> Search);
	void OnCreateSessionCompleted(FName SessionName, bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent) void ShowLoadingScreen();


private:
	void InitSubsystems();
	void FindSessions();
	void CreateSession();
	bool bSubsystemInitialized;
};
