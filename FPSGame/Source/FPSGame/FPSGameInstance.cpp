#include "FPSGameInstance.h"
#include "OnlineSubsystemUtils.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlinePartyInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Online/OnlineSessionNames.h"

void UFPSGameInstance::Init()
{
	Super::Init();

	if(!bSubsystemInitialized)
	{
		InitSubsystems();
	}

	UserIdentity->OnLoginCompleteDelegates->AddUObject(this, &UFPSGameInstance::OnLoginCompleted);

	if(Session == nullptr)
	{
		Session = OnlineSubSystem->GetSessionInterface();
	}
	
	Session->AddOnCreateSessionCompleteDelegate_Handle(FOnCreateSessionComplete::FDelegate::CreateUObject(
	this,
	&UFPSGameInstance::OnCreateSessionCompleted));

	Session->AddOnJoinSessionCompleteDelegate_Handle(FOnJoinSessionComplete::FDelegate::CreateUObject(
	this,
	&UFPSGameInstance::OnJoinSessionCompleted));
	
}

void UFPSGameInstance::StartMatchMaking()
{
	if(Session == nullptr)
	{
		Session = OnlineSubSystem->GetSessionInterface();
	}
	

	TSharedRef<FOnlineSessionSearch> SessionSearch = MakeShared<FOnlineSessionSearch>();
	
	SessionSearch->MaxSearchResults = 20;
	SessionSearch->QuerySettings.Set(
		SEARCH_KEYWORDS,
		FString("GameplaySession"),
		EOnlineComparisonOp::Equals);

	Session->OnFindSessionsCompleteDelegates.Clear();
	Session->AddOnFindSessionsCompleteDelegate_Handle(FOnFindSessionsComplete::FDelegate::CreateUObject(
		this,
		&UFPSGameInstance::OnFindSessionCompleted, SessionSearch));


	if (!Session->FindSessions(0, SessionSearch))
	{
	//	OnJoinSessionComplete.Broadcast(false);
	}
}

void UFPSGameInstance::DestroySession()
{
}

bool UFPSGameInstance::TryAutoLogin()
{
	FOnlineAccountCredentials UserAccount;
	UserAccount.Id = FString();
	UserAccount.Token = FString();
	UserAccount.Type = "persistentauth";
	
	return  UserIdentity->Login(0, UserAccount);
}

void UFPSGameInstance::Login(FString ID, FString Token, FString LoginType)
{
	if(OnlineSubSystem == nullptr || UserIdentity == nullptr)
	{
		InitSubsystems();
	}
    
	FOnlineAccountCredentials UserAccount;
	UserAccount.Id = ID;
	UserAccount.Token = Token;
	UserAccount.Type = LoginType;
	if(LoginType.IsEmpty())
	{
		UserAccount.Type = "accountportal";
	}
	
	UserIdentity->Login(0, UserAccount);
}

void UFPSGameInstance::LogOut()
{
	if(UserIdentity != nullptr)
	{
		UserIdentity->Logout(0);
	}
}

FString UFPSGameInstance::GetPlayerUsername()
{
	if(OnlineSubSystem == nullptr || UserIdentity == nullptr)
	{
		InitSubsystems();
	}

	if(UserIdentity->GetLoginStatus(0) == ELoginStatus::LoggedIn)
	{
		return UserIdentity->GetPlayerNickname(0);
	}

	const FString RandomPlayerName = TEXT("PLAYER") + FString::FromInt(FMath::RandRange(0, 1000));
	return RandomPlayerName;
}

void UFPSGameInstance::OnLoginCompleted(int32 LocalUser, bool bWasSuccess, const FUniqueNetId& UserID,
                                        const FString& Error)
{
	OnLoginComplete.Broadcast(bWasSuccess);

}

void UFPSGameInstance::OnJoinSessionCompleted(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if(Result == EOnJoinSessionCompleteResult::Success)
	{
		if(APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
		{
			ShowLoadingScreen();
			FString ServerAddress;
			Session->GetResolvedConnectString(SessionName, ServerAddress);
			PlayerController->ClientTravel(ServerAddress, ETravelType::TRAVEL_Absolute);
		}
	}
}

void UFPSGameInstance::OnFindSessionCompleted(bool bWasSuccess, TSharedRef<FOnlineSessionSearch> Search)
{
	if(Search->SearchResults.Num() <= 0 || !bWasSuccess)
	{
		CreateSession();
		return;
	}

	if(bWasSuccess)
	{
		Session->JoinSession(0, "GameplaySession", Search->SearchResults[0]);
	}
}

void UFPSGameInstance::OnCreateSessionCompleted(FName SessionName, bool bSuccess)
{
	if(bSuccess)
	{
		ShowLoadingScreen();
		GetWorld()->ServerTravel("Map_Demo?listen");
	}
}

void UFPSGameInstance::InitSubsystems()
{
	if(IOnlineSubsystem* SubSystem = Online::GetSubsystem(GetWorld()); SubSystem != nullptr)
	{ 
		OnlineSubSystem = SubSystem;

		const IOnlineIdentityPtr Identity = SubSystem->GetIdentityInterface();
		
		if(Identity != nullptr)
		{
			UserIdentity = Identity;
		}
	}

	bSubsystemInitialized = true;
}

void UFPSGameInstance::FindSessions()
{
}

void UFPSGameInstance::CreateSession()
{
	FOnlineSessionSettings SessionSettings;

	SessionSettings.bIsDedicated = false;
	SessionSettings.bAllowInvites = false;
	SessionSettings.NumPublicConnections = 2;
	SessionSettings.bUseLobbiesIfAvailable = false;
	SessionSettings.bUsesPresence = false;
	SessionSettings.bShouldAdvertise = true;
	SessionSettings.bAllowJoinViaPresenceFriendsOnly = false;
	SessionSettings.bAllowJoinViaPresence = false;
	SessionSettings.bAntiCheatProtected = false;
	
	SessionSettings.Settings.Add(
		SEARCH_KEYWORDS,
		FOnlineSessionSetting(FString(TEXT("GameplaySession")), EOnlineDataAdvertisementType::ViaOnlineService));

	
	const FName SessionName = FName(FString::FromInt(FMath::RandRange(0, 10000)));
	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();

	if(!Session->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(),SessionName, SessionSettings))
	{
		//OnCreateSessionComplete.Broadcast(false);
	}
}
