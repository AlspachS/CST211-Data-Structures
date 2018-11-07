/***********************************************************************
* Class: Deck.h
*
* Constructors:	Deck(  )
*					No argument constructor.  Sets m_current_card to 
*					zero.
*
* Mutators: 	No mutators available in this class.
*
* Methods:		void NumberDealt(  )
*					Displays the value stored in the m_dealt data
*					member, which indicates how many cards have been
*					dealt from the deck so far.
*
*				void Shuffle(  )
*					Uses the Random member to get a random number from
*					the Random class, then uses this number to switch
*					the position of two cards, effectively shuffling
*					the deck.  Resets the m_current_card and m_dealt
*					data member to zero.
*
*				Card Deal(  )
*					Returns the card in the card array at the location
*					of m_current_card.  If the deck is out of cards, 
*					the Shuffle(  ) method is called and the top card
*					is returned.
*
*
*
***********************************************************************/
#ifndef DECK_H
#define DECK_H

#include <iostream>
	using std::cout;

#include "Card.h"
#include "Random.h"

class Deck
{
	public:

	// Manager functions

		// No argument constructor
		Deck(  );

		// Copy constructor
		Deck( const Deck & source );

		// Operator Equals
		Deck & operator=( const Deck & source );

		// Destructor
		~Deck(  );
		
	// Static Methods

		// Displays the number of cards dealt
		static void NumberDealt(  );

	// Methods 

		// Randomizes the order of the pointers in the card array
		void Shuffle(  );

		// Returns a card, starting at index zero and goes up
		Card Deal(  );



	private:

		static Random Random;		// Random number object
		static int m_dealt;			// Number of cards that have been dealt since the last shuffle
		static const int DECK_MAX;	// Max size of the deck, current value is 52
		
		Card m_deck[52];			// Array of card data
		int m_current_card;			// Used for dealing out cards
};
#endif