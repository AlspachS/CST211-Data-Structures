/***********************************************************************
* Class: Card.h
*
* Constructors:	Card( Rank rank = ACE, Suit suit = SPADE )
*					Two argument constructor receives values that are
*					used to create a Card object with the corresponding
*					Suit and Rank.  Since Suit and Rank are Enum 
*					variables, so values passed to this constructor
*					must be static_cast	beforehand.
*
* Mutators: 	void SetRank( Rank rank );
*					Receives a Rank value and sets m_rank to this value.
*					Rank is an Enum value, so the value passed to this
*					function must be static_cast beforehand.
*
*				void SetSuit( Suit suit );
*					Receives a Suit value and sets m_suit to this value.
*					Suit is an Enum value, so the value passed to this
*					function must be static_cast beforehand.
*
* Methods:		Rank GetRank(  )
*					Returns the integer value associated with the Rank
*					value stored in m_rank.
*
*				Suit GetSuit(  )
*					Returns the integer value associated with the Suit
*					value stored in m_suit.
*
*				void Display(  )
*					Formats the output stream so all suit symbols appear
*					in the same column, then prints the Rank and Suit,
*					in the form "Rank of Suit".
*
*				void SetRank( Rank rank )
*					Sets a card's face value to 'rank'.  This will be an
*					integer value from 1 to 13.
*
*				void SetSuit( Suit suit )
*					Sets a card's suit to 'suit'.  The ASCII character
*					codes for the playing card suits are 3 through 6.
*
***********************************************************************/  
#ifndef CARD_H
#define CARD_H

#include <iostream>
	using std::cout;
	using std::endl;

#include <iomanip>
	using std::setw;
	using std::left;
	using std::right;

#include "WindowsManip.h"
	using WindowsManip::LRed;
	using WindowsManip::Black;
	using WindowsManip::WhiteBack;
	using WindowsManip::ChangeText;
	
class Card
{
	public:
		enum Rank { NONE= 56, ACE = 1, DEUCE, TREY, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
		enum Suit { BLANK, HEART = 3, DIAMOND, CLUB, SPADE };  // ASCII suit characters start at three and go to six
														// in the listed order

	// Manager Functions

		// Two argument constructor with default values
		Card( Rank rank = NONE, Suit suit = BLANK );	

		// Card Destructor
		~Card(  );

	// Operator overloads

		// Unequal operator
		bool operator!=( Card rhs )
		{
			return !( m_rank == rhs.m_rank && m_suit == rhs.m_suit );
		}
	
	// Member Functions
		
		// Displays the Rank and Suit of a card
		Card Display( int x, int y );
		
		// Allows the Rank of a card to be changed
		void SetRank( Rank rank );						
		
		// Allows the Suit of a card to be changed
		void SetSuit( Suit suit );						
		
		// Retreives the Rank value of a card
		Rank GetRank(  ) const;								
		
		// Retreives the Suit value of a card
		Suit GetSuit(  ) const;								

	private:
		Rank m_rank;	// The face value of a card
		Suit m_suit;	// The suit of a card.
};
#endif