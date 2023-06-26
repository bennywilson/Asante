// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AsanteCombatInterface.h"
#include "GameFramework/Character.h"
#include "AsanteCharacterBase.generated.h"

UCLASS(Blueprintable)
class ASANTE_API AAsanteCharacterBase : public ACharacter, public IAsanteCombatInterface
{
	GENERATED_BODY()

public:
	AAsanteCharacterBase(const FObjectInitializer & ObjectInitializer = FObjectInitializer::Get());

	UFUNCTION(BlueprintCallable)
	virtual void SetHealth(float Value) override;

	UFUNCTION(BlueprintCallable)
	virtual void SetHealthMax(float Value) override;

	UFUNCTION(BlueprintPure)
	virtual float GetHealth() const override;

	UFUNCTION(BlueprintPure)
	virtual float GetHealthMax() const override;

	UFUNCTION(BlueprintPure)
	virtual float GetHealthRatio() const override;

	UFUNCTION(BlueprintPure)
	virtual int32 GetTeamId() const override;

	UFUNCTION(BlueprintCallable)
	virtual float Hurt(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable)
	virtual float Heal(float Healing, AActor* Source) override;

	virtual bool ShouldTakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Stats")
	float Health;
	
	UPROPERTY(EditDefaultsOnly, Category = "Stats")
	float HealthMax;

	UPROPERTY(EditDefaultsOnly, Category = "Stats")
	int32 TeamId;

	virtual void OnDeath();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Death"))
	void BP_OnDeath();
};
