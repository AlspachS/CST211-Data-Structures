/***********************************************************************
* 	 Class: FreeCells
* Filename: FreeCells.h
*
*		Represents the freecell area in a game of Freecell.
*
* Constructors:
*		FreeCells(  );
*			Constructs an instance of a FreeCell object.  The 'mFreeCells'
*			array is filled with blank cards and 'mFullCount' is set to 
*			zero.
*
*	  Mutators:
*		void PutCard( Card store, int index )
*			Stores a card in the 'mFreeCells' array at element 'index'.
*
*		Card GetCard( int index )
*			Returns the card in the element 'index' and removes it from
*			the array.
*
*	   Methods:
*		Card ViewCard( int index )
*			Returns the value of the card in the element 'index' but 
*			doesn't remove it from the array.
*
*		int GetFullCount(  )
*			Returns 'mFullCount' subtracted from four.
*
*		bool isValid( int index )
*			Verifies that a card can be stored in the element 'index'.
*
*		void Display(  )
*			Displays the 'mFreeCells' array.  Shows a blank card if the
*			element is empty.
*
***********************************************************************/
#ifndef FREECELLS_H
#define FREECELLS_H

#include "Array.h"
#include "Card.h"

#include "WindowsManip.h"
	using WindowsManip::CursorToPosition;
	using WindowsManip::ChangeText;
	using WindowsManip::Black;
	using WindowsManip::LGrayBack;

class FreeCells
{
	public:

	// Manager functions

		// No argument constructor
		FreeCells(  );

		// Copy Constructor
		FreeCells( const FreeCells & copy );

		// Assignment operator
		FreeCells & operator=( const FreeCells & rhs );

		// Destructor
		~FreeCells(  );

	// Mutator functions

		// Stores a card in the mFreeCells array
		void PutCard( Card store, int index );

		// Returns a card and removes it from the array
		Card GetCard( int index );

	// Accessor Functions

		// Returns a card and doesn't remove it from the array
		Card ViewCard( int index );

		// Returns the number of empty elements in 'mFreeCells'
		int GetFullCount(  );


	// Member functions

		// Verifies a card can be stored in an array element
		bool isValid( int index );

		// Displays the FreeCell area
		void Display(  );

	private:
		Array< Card > mFreeCells;		// Array to store cards
		int mFullCount;					// The number of full elements
};
#endif