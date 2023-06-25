#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AsanteCombatInterface.generated.h"

UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint), BlueprintType)
class UAsanteCombatInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class IAsanteCombatInterface
{
	GENERATED_IINTERFACE_BODY()
public:
	IAsanteCombatInterface();
	
	virtual bool GetIsAlive() const;
	virtual int32 GetTeamId() const;
	
	virtual float GetHealth() const = 0;
	virtual float GetHealthMax() const = 0;
	virtual float GetHealthRatio() const;

	virtual void SetHealth(float Value) = 0;
	virtual void SetHealthMax(float Value) = 0;

	virtual bool GetIsTargetable() const;
	
	virtual bool GetCanBeHealed(AActor* Source) const;
	virtual float Heal(float Healing, AActor* Source);
	
	virtual float Hurt(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
};