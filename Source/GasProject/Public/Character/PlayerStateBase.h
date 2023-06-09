// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "PlayerStateBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
/**
 * 
 */
UCLASS()
class GASPROJECT_API APlayerStateBase : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	APlayerStateBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComp;
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

};
