/***********************************************************************
* 	 Class: Tile
* Filename: Tile.h
*
*		A tile of a board in an Alchemy game.  Stores symbols and
*		"goldness" of a tile.
*
* Constructors:
*			Tile(  );
*				Generates a blank Tile.  
*
*	  Mutators:
*			void StoreSymbol( Symbol symbol )
*				Stores a Symbol in a Tile.
*			
*			void RemoveSymbol(  )
*				Removes a Symbol from a Tile, keeps the tile gold.
*
*	   Methods:
*			void DisplayTile(  )
*				Displays a tile with the correct background and 
*				the Symbol inside it.
*
*			bool isGold(  );
*				Returns whether a tile is gold, or not.
*	
*			bool isFull(  );
*				Returns whether a tile is full, or not.
*
*			Symbol GetSymbol(  );
*				Returns the Symbol stored in the tile.
*
***********************************************************************/
#ifndef TILE_H
#define TILE_H

#include <Windows.h>
#include <iostream>
	using std::cout;

#include "Windows_Console_Manipulation.h"
	using ColorStuff::DGrayBack;
	using ColorStuff::GoldBack;

#include "Symbol.h"

class Tile
{
	public:

	// Manger functions

		// No argument constructor
		Tile(  );

		// Copy constructor
		Tile( const Tile & copy );

		// Assignment operator
		Tile & operator=( const Tile & rhs );
		
		// Destructor
		~Tile(  );


	// Mutator functions

		// Stores a Symbol in a tile
		void StoreSymbol( Symbol store );

		// Removes a Symbol from a tile
		void RemoveSymbol(  );

	// Member functions

		// Displays a tile
		void DisplayTile(  );

		// Returns whether a tile is gold or not
		bool isGold(  );

		// Returns whether a tile is full or not
		bool isFull(  );

		// Returns the Symbol stored in a tile
		Symbol GetSymbol(  );


	private:
		bool m_gold;		// Whether a tile is gold
		bool m_full;		// Whether a tile is full
		int m_background;	// The background of the tile
		Symbol m_stored;	// The Symbol stored in the tile
};
#endif