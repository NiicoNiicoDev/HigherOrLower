#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "Card.h"
#include "Deck.h"
#include "HigherLowerInterface.h"

#include "Test.generated.h"


UCLASS()
class HIGHERORLOWER_API ATest : public AActor, public IHigherLowerInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void LowerGuess() override;
	UFUNCTION()
	virtual void HigherGuess() override;
	UFUNCTION()
	virtual void SameGuess() override;

	

private:
	// Widget component for in-world widget
	UPROPERTY(VisibleAnywhere, Category = "UI")
	UWidgetComponent* WidgetComponent;

	// Widget class for viewport attachment
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY()
	class UUW_GUI* CreatedWidget;

	Deck* deck;

	Card currentCard;

	UPROPERTY(VisibleAnywhere)
	int currentScore = 0;

	UFUNCTION()
	void ShuffleDeck();

	void IncreaseScore(int scoreIncrease);

	void ShowNextCardAndDelay();

	void GoToNextCard();

	UFUNCTION()
	void RestartGame();
};
