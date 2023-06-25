#include "AsanteCombatInterface.h"


UAsanteCombatInterface::UAsanteCombatInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
IAsanteCombatInterface::IAsanteCombatInterface() {}

bool IAsanteCombatInterface::GetIsAlive() const
{
	return GetHealth() > 0;
}

int32 IAsanteCombatInterface::GetTeamId() const
{
	return 0;
}

bool IAsanteCombatInterface::GetCanBeHealed(AActor* Source) const
{
	return GetIsAlive() && GetHealth() < GetHealthMax();
}

bool IAsanteCombatInterface::GetIsTargetable() const
{
	return GetIsAlive();
}

float IAsanteCombatInterface::Heal(float Healing, AActor* Source)
{
	if (Healing <= 0 || !GetCanBeHealed(Source))
		return 0.f;

	const float PreviousHealth = GetHealth();
	SetHealth(FMath::Min(GetHealthMax(), GetHealth() + Healing));
	return GetHealth() - PreviousHealth;
}

float IAsanteCombatInterface::Hurt(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	const float PreviousHealth = GetHealth();
	SetHealth(FMath::Max(0.f, GetHealth() - DamageAmount));
	return PreviousHealth - GetHealth();
}

float IAsanteCombatInterface::GetHealthRatio() const
{
	const float HealthMax = GetHealthMax();

	if (HealthMax <= 0)
		return 0.f;

	return GetHealth()/HealthMax;
}
