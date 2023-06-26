// Fill out your copyright notice in the Description page of Project Settings.


#include "AsanteCharacterBase.h"

AAsanteCharacterBase::AAsanteCharacterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	Health = HealthMax = 1;
	TeamId = 0;
}

float AAsanteCharacterBase::GetHealth() const
{
	return Health;
}

float AAsanteCharacterBase::GetHealthMax() const
{
	return HealthMax;
}

float AAsanteCharacterBase::GetHealthRatio() const
{
	return IAsanteCombatInterface::GetHealthRatio();
}

int32 AAsanteCharacterBase::GetTeamId() const
{
	return TeamId;
}

float AAsanteCharacterBase::Hurt(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
                                 AActor* DamageCauser)
{
	return IAsanteCombatInterface::Hurt(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
}

void AAsanteCharacterBase::SetHealth(float Value)
{
	const bool bHadHealth = Health > 0;
	Health = FMath::Clamp(Value, 0.f, HealthMax);
	
	if (bHadHealth && Value <= 0.f)
	{
		OnDeath();
	}
}

void AAsanteCharacterBase::SetHealthMax(float Value)
{
	HealthMax = FMath::Max(Value, 1.f);
	Health = FMath::Min(Health, HealthMax);
}

float AAsanteCharacterBase::Heal(float Healing, AActor* Source)
{
	return IAsanteCombatInterface::Heal(Healing, Source);
}

bool AAsanteCharacterBase::ShouldTakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser) const
{
	if (!Super::ShouldTakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser))
		return false;

	if (const auto CombatUnit = Cast<IAsanteCombatInterface>(DamageCauser))
		return CombatUnit->GetTeamId() != GetTeamId();
	
	if (const auto CombatUnit = Cast<IAsanteCombatInterface>(EventInstigator))
		return CombatUnit->GetTeamId() != GetTeamId();

	return true;
}

float AAsanteCharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	const float RemainingDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	return IAsanteCombatInterface::Hurt(RemainingDamage, DamageEvent, EventInstigator, DamageCauser);
}

void AAsanteCharacterBase::OnDeath()
{
	BP_OnDeath();
}
