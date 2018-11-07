/***********************************************************************
* 	 Class: HomeCells
* Filename: HomeCells.h
*
*		Represents the area to store cards in a game of FreeCell.
*
* Constructors:
*		HomeCells(  )
*			Constructs an instance of a HomeCell object.  'mHomeCells'
*			is set to be an array of four stack objects that are 13 
*			elements in size.
*
*	  Mutators:
*		void MoveUp( Card card, int index )
*			Receives a card and stores it in the stack numbered 'index'.
*
*	   Methods:
*		int GetTotalCards(  )
*			Returns the number of cards stored in all four stacks.
*
*		bool isValid( Card card, int index )
*			Verifies that 'card' can go on the stack numbered 'index'.
*
*		bool checkSuit( Card card, int index )
*			Checks that the suit of 'card' matches the suit of the other
*			cards on the stack numbered 'index'.
*
*		bool checkRank( Card card, int index )
*			Checks that the face-value of 'card' is one greater than
*			the card on the top of the stack numbered 'index'.
*
*		void Display(  );
*			Displays the top card of each of the stacks in the 
*			mHomeCells array.
*
***********************************************************************/
#ifndef HOMECELLS_H
#define HOMECELLS_H

#include "Array.h"
#include "Stack.h"
#include "Card.h"

#include "WindowsManip.h"
	using WindowsManip::CursorToPosition;
	using WindowsManip::ChangeText;
	using WindowsManip::Black;
	using WindowsManip::LGrayBack;

class HomeCells
{
	public:

	// Manager functions

		// No argument constructor
		HomeCells(  );

		// Copy constructor
		HomeCells( const HomeCells & copy );

		// Assignment operator
		HomeCells & operator=( const HomeCells & rhs );

		// Destructor
		~HomeCells(  );

	// Mutator methods

		// Stores a card in the homecells
		void MoveUp( Card card, int index );

	// Accessor methods

		// Returns total cards in homecells
		int GetTotalCards(  );

	// Member functions

		// Verifies a card can be stored
		bool isValid( Card card, int index );

		// Checks the suit of the card to be stored
		bool checkSuit( Card card, int index );

		// Checks the face-value of the card to be stored
		bool checkRank( Card card, int index );

		// Displays the homecells area
		void Display(  );

	private:
		Array< Stack< Card > > mHomeCells;	// A stack to store cards
		int mTotalCards;					// The total number of cards stored

};
#endif