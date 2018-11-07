/***********************************************************************
* 	 Class: FreeCellGame
* Filename: FreeCellGame.h
*
*		The main driver of the game FreeCell
*
* Constructors:
*		FreeCellGame(  )
*			Constructs an instance of the FreeCellGame class.
*
*	  Mutators:
*		No mutators available for this class.
*
*	   Methods:
*		void GameDriver(  )
*			The main game loop.
*
*		void TakeUserInput( char & startgroup, char & destgroup, int & startpile, int & destpile )
*			Has the user type in their desired move in the form "p1 f1"
*			where the first two characters are the pile the user is 
*			moving cards from, and the second two characters are the pile
*			the user is moving cards to.
*
*		void MoveCards( char startgroup, char destgroup, int startpile, int destpile )
*			Moves one card from the pile the user is moving from to the
*			pile the user is moving to.  In the case of a playcell-to-
*			playcell move, the user is prompted for how many cards they
*			want to move.
*
*		void AutoMoveUp(  )
*			Checks the top card of the playcell stacks and the cards in
*			the freecells to see if any can be moved to the homecell 
*			area.  If they can, they are moved.
*
*		bool WinCheck(  )
*			Checks to see if all 52 cards have been moved to the homecell
*			area, if they have, the game is over and a win message is 
*			displayed.
*
*		void Display(  )
*			Displays the Freecell game.  Changes the console size, 
*			background, and title text, then calls the display functions
*			of the freecells, homecells, and playcells.
*
***********************************************************************/
#ifndef FREECELLGAME_H
#define FREECELLGAME_H

#include <iostream>
	using std::cout;
	using std::cin;

#include <ctype.h>

#include "FreeCells.h"
#include "HomeCells.h"
#include "PlayCells.h"

#include "WindowsManip.h"
	using WindowsManip::SizeConsoleAbsolute;
	using WindowsManip::ClearWindow;
	using WindowsManip::GreenBack;

class FreeCellGame
{
	public:

	// Manager functions

		// No argument constructor
		FreeCellGame(  );

		// Copy constructor
		FreeCellGame( const FreeCellGame & copy );

		// Assignment operator
		FreeCellGame & operator=( const FreeCellGame & rhs );

		// Destructor
		~FreeCellGame(  );

	// Member functions

		// Main game loop
		void GameDriver(  );

		// Gets input from the user
		void TakeUserInput( char & startgroup, char & destgroup, int & startpile, int & destpile );

		// Moves the cards indicated by the user
		void MoveCards( char startgroup, char destgroup, int startpile, int destpile );

		// Moves the cards to the homecells
		void AutoMoveUp(  );

		// Checks to see if the game is over
		bool WinCheck(  );

		// Displays the game
		void Display(  );


	private:
		FreeCells FreeCellGroup;		// FreeCells in a FreeCell game
		HomeCells HomeCellGroup;		// HomeCells in a FreeCell game
		PlayCells PlayCellGroup;		// PlayCells in a FreeCell game


};
#endif