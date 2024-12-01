#pragma once

#include "CoreMinimal.h"
#include "Card.h"

/**
 * 
 */
class HIGHERORLOWER_API Deck
{
public:
	Deck();
	~Deck();

	TArray<Card>& getDeck();
	void shuffleDeck();
	void printDeck();

private:
	TArray<Card> deck;
};
