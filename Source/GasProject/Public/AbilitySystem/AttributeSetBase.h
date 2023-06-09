// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

/**
 * 
 */
UCLASS()
class GASPROJECT_API UAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAttributeSetBase();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes")
		FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes")
		FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_AbilityStrength, Category = "Attributes")
		FGameplayAttributeData AbilityStrength;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxAbilityStrength, Category = "Attributes")
		FGameplayAttributeData MaxAbilityStrength;

	UFUNCTION()
		void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
		void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
		void OnRep_AbilityStrength(const FGameplayAttributeData& OldAbilityStrength) const;

	UFUNCTION()
		void OnRep_MaxAbilityStrength(const FGameplayAttributeData& OldMaxAbilityStrength) const;
};
