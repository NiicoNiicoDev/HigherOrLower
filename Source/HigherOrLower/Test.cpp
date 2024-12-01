#include "Test.h"
#include "Deck.h"
#include "UW_GUI.h"

// Sets default values
ATest::ATest()
{
	PrimaryActorTick.bCanEverTick = true;

	// Initialize Widget Component
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(RootComponent);
    WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);

    //Setting the GUI widget class value here so that even if it resets when manually assigned 
    // the reference persists. Safety First 
    static ConstructorHelpers::FClassFinder<UUserWidget> GUIWidgetClass(TEXT("/Game/MyUW_GUI"));
    if (GUIWidgetClass.Succeeded()) {
        WidgetClass = GUIWidgetClass.Class;
    }
}


// Called when the game starts or when spawned
void ATest::BeginPlay()
{
    Super::BeginPlay();

    RestartGame();
}

// Called every frame
void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATest::ShuffleDeck()
{
    deck->shuffleDeck();
}

//Checks if the current cards value is lower than that of the next card in the deck.
void ATest::HigherGuess()
{
    if (currentCard < deck->getDeck()[0]) 
    {
        IncreaseScore(1);
    }

    ShowNextCardAndDelay();
}

//Checks if the current cards value is higher than that of the next card in the deck.
void ATest::LowerGuess()
{
    if (currentCard > deck->getDeck()[0]) 
    {
        IncreaseScore(1);
    }

    ShowNextCardAndDelay();
}

//Checks if the current cards value is the same as that of the next card in the deck.
void ATest::SameGuess()
{
    if (currentCard == deck->getDeck()[0]) 
    {
        IncreaseScore(3);
    }

    ShowNextCardAndDelay();
}

void ATest::RestartGame()
{
    if (CreatedWidget) 
    {
        currentScore = 0;
        CreatedWidget->setScoreText(currentScore);
        CreatedWidget->HideGameOverPanel();
        CreatedWidget->RemoveFromParent();
        CreatedWidget = nullptr;
    }

    // Attach widget to viewport if class is set
    if (WidgetClass)
    {
        CreatedWidget = Cast<UUW_GUI>(CreateWidget<UUserWidget>(GetWorld(), WidgetClass));
        if (CreatedWidget)
        {
            CreatedWidget->AddToViewport();
            //binding widget event calls to funct
            CreatedWidget->shuffleButtonClickedDelegate.AddDynamic(this, &ATest::ShuffleDeck);
            CreatedWidget->lowerButtonClickedDelegate.AddDynamic(this, &ATest::LowerGuess);
            CreatedWidget->higherButtonClickedDelegate.AddDynamic(this, &ATest::HigherGuess);
            CreatedWidget->sameButtonClickedDelegate.AddDynamic(this, &ATest::SameGuess);
            CreatedWidget->restartButtonClickedDelegate.AddDynamic(this, &ATest::RestartGame);
        }
    }

    // Alternatively, to use the in-world widget component:
    if (WidgetComponent)
    {
        WidgetComponent->SetWidgetClass(WidgetClass);
        WidgetComponent->InitWidget();
    }

    //Creating a new deck because we don't have any card references yet.
    deck = new Deck();

    ShuffleDeck();
    GoToNextCard();
}

void ATest::IncreaseScore(int scoreIncrease)
{
    currentScore += scoreIncrease;
    CreatedWidget->setScoreText(currentScore);
}

//Disables each of the buttons in the GUI, Shows the next cards correct images and starts a timer that will
// call the 'GoToNextCard' function after a one second delay.
void ATest::ShowNextCardAndDelay()
{
    CreatedWidget->DisableButtons();
    CreatedWidget->SetNextCardImage(&deck->getDeck()[0]);

    FTimerHandle UnusedHandle;
    GetWorldTimerManager().SetTimer(
        UnusedHandle, this, &ATest::GoToNextCard, 1 , false);
}

//If the number of the cards in the deck is greater than one;
// Sets the current card to next card in the deck for both the variables and relevant
// GUI elements. Also re-enables the GUI buttons.
void ATest::GoToNextCard()
{
    if (deck->getDeck().Num() > 1) {
        currentCard = deck->getDeck()[0];
        deck->getDeck().RemoveAt(0);

        CreatedWidget->SetCurrentCardImage(&currentCard);
        CreatedWidget->SetNextCardImage();

        CreatedWidget->EnableButtons();
    }
    else 
    {
        CreatedWidget->ShowGameOverPanel();
    }
}

