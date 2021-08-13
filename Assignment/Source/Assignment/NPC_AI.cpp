// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_AI.h"
#include "Engine/GameEngine.h"

ANPC_AI::ANPC_AI()
{
	TeamId = FGenericTeamId(1);
}

ETeamAttitude::Type ANPC_AI::GetTeamAttitudeTowards(AActor& Other)
{
	//Check if Actor is a pawn.
	auto OtherPawn = Cast<APawn>(&Other);
	if (OtherPawn == nullptr)
		return ETeamAttitude::Neutral;

	//Check if actor (bot or player) implements IGenericTeamAgentInterface
	auto igtalActorBot = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController());
	auto igtalActorPlayer = Cast<IGenericTeamAgentInterface>(&Other);
	if (igtalActorBot == nullptr && igtalActorPlayer == nullptr)
		return ETeamAttitude::Neutral;

	
	/*
	if (igtalActorBot != nullptr) //Prints this actors ID and the bots ID
	{
		FGenericTeamId fgtiActorBotTeamId = igtalActorBot->GetGenericTeamId();
		int iActorBotTeamID = (int)fgtiActorBotTeamId;
		FString fstrActorBotTeamID = FString::FromInt(iActorBotTeamID);
		FGenericTeamId fthisActorTeamID = this->GetGenericTeamId();
		int thisActorTeamID = (int)fthisActorTeamID;
		FString fstrThisActorTeamID = FString::FromInt(thisActorTeamID);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Bots team ID is  " + fstrActorBotTeamID + ". My team ID is " + fstrThisActorTeamID);
	}

	if (igtalActorPlayer != nullptr) //Print this actors ID and the players ID
	{
		FGenericTeamId fgtiActorPlayerTeamId = igtalActorPlayer->GetGenericTeamId();
		int iActorPlayerTeamID = (int)fgtiActorPlayerTeamId;
		FString fstrActorPlayerTeamID = FString::FromInt(iActorPlayerTeamID);
		FGenericTeamId fthisActorTeamID = this->GetGenericTeamId();
		int thisActorTeamID = (int)fthisActorTeamID;
		FString fstrThisActorTeamID = FString::FromInt(thisActorTeamID);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Players team ID is  " + fstrActorPlayerTeamID + ". My team ID is " + fstrThisActorTeamID);
		
	}*/

	//Get TeamID of the Actor (Both bot and player) 
	FGenericTeamId fgtIOtherActorTeamId = NULL;
	if (igtalActorBot != nullptr)
	{
		fgtIOtherActorTeamId = igtalActorBot->GetGenericTeamId();
	}
	else if (igtalActorPlayer != nullptr)
	{
		fgtIOtherActorTeamId = igtalActorPlayer->GetGenericTeamId();
	}

	//Determines the attitude towards the OtherActor as neutral/friendly/hostile
	FGenericTeamId fgtiThisBotTeamId = this->GetGenericTeamId();
	if (fgtIOtherActorTeamId == 255) //Not on the same team
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Neutral");

		return ETeamAttitude::Hostile;
		
	}
	else if (fgtiThisBotTeamId == fgtIOtherActorTeamId) //On the same team
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Friendly");



		return ETeamAttitude::Hostile;

	}
	else //Different teams
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Hostile");


		return ETeamAttitude::Hostile;
	}
}