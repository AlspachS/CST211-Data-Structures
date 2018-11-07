/***********************************************************************
* 	 Class: PlayCells
* Filename: PlayCells.h
*
*		Represents the play area of a FreeCell game.
*
* Constructors:
*		PlayCells(  )
*			Creates an instance of the PlayCells class.  Deals all cards
*			from the play deck to the cells.
*
*	  Mutators:
*		void StackCard( Card card, int index )
*			Puts a card on the top of the 'index' stack.
*
*		void MoveStack( int numCards, int start, int dest )
*			Moves 'numCards' of cards from 'start' stack to 'dest' stack.
*
*		Card GetCard( int index )
*			Removes and returns the top card from 'index' stack.
*
*	   Methods:
*		Card ViewCard( int index )
*			Returns, but doesn't remove, a the top card of 'index' stack.
*
*		int CalcPowerMove( int emptyFC, int dest )
*			Returns the most cards a player can move at once.
*
*		bool isValid( Card card, int start, int dest, int numCards = 1 )
*			Determines if 'card' can go on 'dest' stack.
*
*		bool checkColor( Card card, int dest )
*			Determines if the top card of 'dest' stack is the alternate
*			color of 'card'.
*
*		bool checkRank( Card card, int dest )
*			Determines if the top card of 'dest' stack is one higher in
*			rank than 'card'.
*
*		bool checkStack( int start, int numCards )
*			Determines if the cards to be moved are a cohesive stack,
*			that is, the colors alternate and the rank descends.
*
*		void Display(  )
*			Displays the play cell area.
*
*
***********************************************************************/
#ifndef PLAYCELLS_H
#define PLAYCELLS_H

#include "Array.h"
#include "LinkedStack.h"
#include "Deck.h"
#include "Card.h"

#include <math.h>
	using std::pow;

#include <ctype.h>

#include "WindowsManip.h"
	using WindowsManip::CursorToPosition;
	using WindowsManip::ChangeText;
	using WindowsManip::Black;
	using WindowsManip::LGrayBack;

class PlayCells
{
	public:

	// Manager functions

		// No argument constructor
		PlayCells(  );

		// Copy constructor
		PlayCells( const PlayCells & copy );

		// Assignment operator
		PlayCells & operator=( const PlayCells & rhs );

		// Destructor
		~PlayCells(  );

	// Accessor methods

		// Returns, but doesn't remove, the top card of a stack
		Card ViewCard( int index );

	// Mutator methods

		// Returns and removes the top card of a stack
		Card GetCard( int index );

		// Puts a card on the top of a stack
		void StackCard( Card card, int index );

		// Moves 'numCards' of cards from one stack to another
		void MoveStack( int numCards, int start, int dest );

	// Member functions

		// Calculates the max number of cards that can be moved at once
		int CalcPowerMove( int emptyFC, int dest );

		// Determines if a card placement is valid
		bool isValid( Card card, int start, int dest, int numCards = 1 );

		// Checks the color of a card placement
		bool checkColor( Card card, int dest );

		// Checks the rank of a card placement
		bool checkRank( Card card, int dest );

		// Checks a stack for cohesiveness
		bool checkStack( int start, int numCards );

		// Displays the play area cells
		void Display(  );

	private:
		Array< LinkedStack< Card > > mPlayCells;		// Stacks of cards to play with
		Deck mPlayDeck;									// The deck the cards are dealt from.
};
#endif