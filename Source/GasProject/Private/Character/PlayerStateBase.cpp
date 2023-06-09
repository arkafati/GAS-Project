// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerStateBase.h"
#include "AbilitySystem/CharacterAbilitySystemComponent.h"
#include "AbilitySystem/AttributeSetBase.h"

APlayerStateBase::APlayerStateBase()
{
	AbilitySystemComp = CreateDefaultSubobject<UCharacterAbilitySystemComponent>("AbilitySystemComp");
	AbilitySystemComp->SetIsReplicated(true);
	AbilitySystemComp->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UAttributeSetBase>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* APlayerStateBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}
