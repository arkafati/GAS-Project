// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UAttributeSetBase::UAttributeSetBase()
{
}

void UAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UAttributeSetBase::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, Health, OldHealth);
}

void UAttributeSetBase::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, MaxHealth, OldMaxHealth);

}

void UAttributeSetBase::OnRep_AbilityStrength(const FGameplayAttributeData& OldAbilityStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, AbilityStrength, OldAbilityStrength);

}

void UAttributeSetBase::OnRep_MaxAbilityStrength(const FGameplayAttributeData& OldMaxAbilityStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, MaxAbilityStrength, OldMaxAbilityStrength);

}
