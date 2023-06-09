// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/PlayerCharacter.h"
#include "Character/PlayerStateBase.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"

APlayerCharacter::APlayerCharacter()
{
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitializeActorInfo();

}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitializeActorInfo();
}

void APlayerCharacter::InitializeActorInfo()
{
	APlayerStateBase* PS = GetPlayerState<APlayerStateBase>();
	check(PS);
	PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
	AbilitySystemComp = PS->GetAbilitySystemComponent();
	AttributeSet = PS->GetAttributeSet();
}
