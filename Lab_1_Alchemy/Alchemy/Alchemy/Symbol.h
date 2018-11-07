/***********************************************************************
*    Class: Symbol
* Filename: Symbol.h
*
*		Represents a symbol in a game of Alchemy.  These symbols have a
*		color and a character (symbol).
*
* Constructors:
*			Symbol(  );
*				Creates a blank symbol.
*
*			Symbol( int symbol, int color )
*				Used to create a more specific symbol.  Also allows
*				access to symbols and characters outside the Symbols
*				enum.
*
*			Symbol( Symbol symbols, Colors color )
*				Used to generate a symbol from the Symbols and Colors
*				enums.  This is used for random generation of normal
*				symbols.
*
*	  Mutators:
*			void SetSymbol( char symbol )
*				Changes the character of a symbol to be 'symbol'.
*
*			void SetColor( int color )
*				Changes the color of a symbol to be 'color'.
*
*	   Methods:
*			char GetSymbol(  );
*				Returns the character stored in a symbol.
*
*			int GetColor(  );
*				Returns the color stored in a symbol.
*	
*			void Display(  );
*				Displays a symbol on Dark Gray background for the user
*				to see before it's placed on the board.
*
*			Symbol GenerateSymbol( int level, Random rand )
*				Generates a random normal symbol for the user to play.
*
***********************************************************************/
#ifndef SYMBOL_H
#define SYMBOL_H

#include "Random.h"
#include "Windows_Console_Manipulation.h"
	using ColorStuff::Black;
	using ColorStuff::Brick;
	using ColorStuff::LGray;
	using ColorStuff::Blue;
	using ColorStuff::Green;
	using ColorStuff::LRed;
	using ColorStuff::Yellow;
	using ColorStuff::DGray;
	using ColorStuff::DGrayBack;

#include <Windows.h>
#include <iostream>
	using std::cout;


const int ALL_COLORS[  ] = { Black, Brick, LGray, Blue, Green, LRed, Yellow, DGray };
const char ALL_SYMBOLS[  ] = { 20, 21, 35, 36, 38, -24, -9, -80, -37, 32 };
	// PILCROW = 20, HURRICANE = 21, POUND = 35, DOLLAR = 36
	// AMPERSAND = 38, THORN = 232, CEDILLA = 247
	// SOLVENT = 176, FREEBLOCK = 219, BLANK = 32

enum Symbols{ PILCROW, HURRICANE, POUND, DOLLAR, AMPERSAND, THORN, CEDILLA };

enum Colors{ BLACK, BRICK, LGRAY, DBLUE, GREEN, LRED, YELLOW };

class Symbol
{
	public:

	// Manager functions

		// No argument constructor
		Symbol(  );

		// Two argument constructor
		Symbol( int symbol, int color );

		// Two argument constructor
		Symbol( Symbols symbols, Colors color );

		// Copy constructor
		Symbol( const Symbol & copy );

		// Assignment operator
		Symbol & operator=( const Symbol & rhs );

		// Destructor
		~Symbol(  );

	// Accessor functions

		// m_symbol accessor
		char GetSymbol(  );

		// m_color accessor
		int GetColor(  );

	// Mutator functions

		// m_symbol mutator
		void SetSymbol( char symbol );

		// m_color mutator
		void SetColor( int color );

	// Member functions

		// Display symbol
		void Display(  );

		// Randomly generate symbol
		Symbol GenerateSymbol( int level, Random rand );

	private:
		char m_symbol;			// The character the symbol is
		int m_color;			// The color the symbol is
};
#endif