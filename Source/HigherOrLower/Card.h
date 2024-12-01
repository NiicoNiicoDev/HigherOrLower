#pragma once

#include "CoreMinimal.h"
/**
 * 
 */
class HIGHERORLOWER_API Card
{
public:
	UENUM(BlueprintType)
		enum CardValue
	{
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace,
	};

	UENUM(BlueprintType)
		enum CardSuit
	{
		Spades,
		Diamonds,
		Clubs,
		Hearts
	};

	Card();
	Card(CardValue cardValue, CardSuit cardSuit);
	Card(int cardValueEnumIndex, int cardSuitEnumIndex);
	~Card();

	CardValue GetValue();
	CardSuit GetSuit();

	FString GetSuitString();
	FString GetValueString();

	//Operator overrides for direct card comparisons.
	inline bool operator< (const Card& card) { return (int)card.value > (int)value; }
	inline bool operator> (const Card& card) { return (int)card.value < (int)value; }
	inline bool operator== (const Card& card) const { return (int)card.value == (int)value; }
	inline bool operator!= (const Card& card) const { return (int)card.value != (int)value; }

private:
	CardSuit suit;
	CardValue value;
};

