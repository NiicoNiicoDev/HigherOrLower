#include "UW_GUI.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"

//Binds each of the button events to their respective functions
void UUW_GUI::NativeConstruct()
{
	lowerButton->OnClicked.AddDynamic(this, &UUW_GUI::lowerButtonOnClicked);
	higherButton->OnClicked.AddDynamic(this, &UUW_GUI::HigherButtonOnClicked);
	shuffleButton->OnClicked.AddDynamic(this, &UUW_GUI::ShuffleButtonOnClicked);
	sameButton->OnClicked.AddDynamic(this, &UUW_GUI::SameButtonOnClicked);
	exitButton->OnClicked.AddDynamic(this, &UUW_GUI::ExitButtonOnClicked);

	restartButton->OnClicked.AddDynamic(this, &UUW_GUI::restartButtonOnClicked);
	quitButton->OnClicked.AddDynamic(this, &UUW_GUI::ExitButtonOnClicked);
}

//Gets the image file location for the given card and sets the current 
// card imagine in the GUI to said image file
void UUW_GUI::SetCurrentCardImage(Card* card)
{
	//'/Game/cards/ace_of_clubs.ace_of_clubs'
	FString cardReference = card->GetValueString().ToLower() + FString("_of_") + card->GetSuitString().ToLower();
	FString path = FString("/Game/cards/") + cardReference + FString(".") + cardReference;

	UTexture2D* cardTexture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), 
		nullptr, *path));

	if (cardTexture) 
	{
		FSlateBrush brush;
		brush.SetResourceObject(cardTexture);
		currentCardImage->SetBrush(brush);
	}
	
}

//Gets the image file location for the given card and sets the next 
// card imagine in the GUI to said image file
void UUW_GUI::SetNextCardImage(Card* card)
{
	FString cardReference = card->GetValueString().ToLower() + FString("_of_") + card->GetSuitString().ToLower();
	FString path = FString("/Game/cards/") + cardReference + FString(".") + cardReference;

	UTexture2D* cardTexture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(),
		nullptr, *path));

	if (cardTexture)
	{
		FSlateBrush brush;
		brush.SetResourceObject(cardTexture);
		nextCardImage->SetBrush(brush);
	}
}

//Same as above but instead sets the next card image to the backing image for the card
void UUW_GUI::SetNextCardImage()
{
	UTexture2D* cardTexture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(),
		nullptr, *cardBackPath));

	if (cardTexture)
	{
		FSlateBrush brush;
		brush.SetResourceObject(cardTexture);
		nextCardImage->SetBrush(brush);
	}
}

void UUW_GUI::setScoreText(int score)
{
	currentScoreText->SetText(FText::FromString(FString("Current Score: ") + FString::FromInt(score)));
}

//Function that enables each of the buttions in the GUI
void UUW_GUI::EnableButtons()
{
	higherButton->SetIsEnabled(true);
	lowerButton->SetIsEnabled(true);
	shuffleButton->SetIsEnabled(true);
	sameButton->SetIsEnabled(true);
}

//Function that disables each of the buttions in the GUI
void UUW_GUI::DisableButtons()
{
	higherButton->SetIsEnabled(false);
	lowerButton->SetIsEnabled(false);
	shuffleButton->SetIsEnabled(false);
	sameButton->SetIsEnabled(false);
}

//Event broadcast functions
void UUW_GUI::lowerButtonOnClicked()
{
	lowerButtonClickedDelegate.Broadcast();
}

void UUW_GUI::HigherButtonOnClicked()
{
	higherButtonClickedDelegate.Broadcast();
}

void UUW_GUI::SameButtonOnClicked()
{
	sameButtonClickedDelegate.Broadcast();
}

void UUW_GUI::ShuffleButtonOnClicked()
{
	shuffleButtonClickedDelegate.Broadcast();
}

void UUW_GUI::restartButtonOnClicked()
{
	restartButtonClickedDelegate.Broadcast();
}
// End of event broadcast functions


void UUW_GUI::ExitButtonOnClicked()
{
	FPlatformMisc::RequestExit(false);
}

void UUW_GUI::ShowGameOverPanel()
{
	if (gameOverCanvas)
		gameOverCanvas->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

void UUW_GUI::HideGameOverPanel()
{
	if (gameOverCanvas)
		gameOverCanvas->SetVisibility(ESlateVisibility::Hidden);
}


