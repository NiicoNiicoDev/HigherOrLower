#include "Deck.h"
#include "Algo/RandomShuffle.h"

//Iterates over each suit and each card value and adds each card to the deck variable starting
// with the 2 of Spades and ending with the Ace of Hearts.
Deck::Deck()
{
	for (int suit = Card::Spades; suit <= Card::Hearts; suit++) {
		for (int value = Card::Two; value <= Card::Ace; value++) {
			deck.Add(Card(value, suit));
		}
	}
}

Deck::~Deck()
{
}

TArray<Card>& Deck::getDeck()
{
	return deck;
}

void Deck::shuffleDeck()
{
	Algo::RandomShuffle(deck);
}

//Prints out each card in the deck for debugging purposes
void Deck::printDeck()
{
	for (Card card : deck)
		GLog->Log(card.GetValueString() + " of " + card.GetSuitString() + "\n");
}