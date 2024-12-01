// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Card.h"
#include "UW_GUI.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShuffleButtonClickedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLowerButtonClickedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHigherButtonClickedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSameButtonClickedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRestartButtonClickedSignature);

/**
 * 
 */
UCLASS()
class HIGHERORLOWER_API UUW_GUI : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetCurrentCardImage(Card* card);
	void SetNextCardImage(Card* card);
	void SetNextCardImage();

	FShuffleButtonClickedSignature shuffleButtonClickedDelegate;
	FLowerButtonClickedSignature lowerButtonClickedDelegate;
	FHigherButtonClickedSignature higherButtonClickedDelegate;
	FSameButtonClickedSignature sameButtonClickedDelegate;
	FRestartButtonClickedSignature restartButtonClickedDelegate;

	void EnableButtons();
	void DisableButtons();

	UFUNCTION()
	void setScoreText(int score);

	void ShowGameOverPanel();
	void HideGameOverPanel();

protected:
	//UPROPERTY(meta = (BindWidget))
	//class UTextBlock* currentCardText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* currentScoreText;

	UPROPERTY(meta = (BindWidget))
	class UImage* currentCardImage;

	//UPROPERTY(meta = (BindWidget))
	//class UTextBlock* nextCardText;

	//Main Window Widgets
	UPROPERTY(meta = (BindWidget))
	class UImage* nextCardImage;

	UPROPERTY(meta = (BindWidget))
	class UButton* higherButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* lowerButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* sameButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* shuffleButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* exitButton;


	// Game Over Screen Widgets
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel *gameOverCanvas;

	UPROPERTY(meta = (BindWidget))
	class UButton* restartButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* quitButton;

	
	FString cardBackPath = "/Game/cards/card_back.card_back";

	virtual void NativeConstruct() override;

	UFUNCTION()
	void lowerButtonOnClicked();

	UFUNCTION()
	void HigherButtonOnClicked();

	UFUNCTION()
	void SameButtonOnClicked();

	UFUNCTION()
	void ShuffleButtonOnClicked();

	UFUNCTION()
	void ExitButtonOnClicked();

	UFUNCTION()
	void restartButtonOnClicked();



};
