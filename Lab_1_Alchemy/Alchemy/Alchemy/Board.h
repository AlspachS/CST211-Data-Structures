/***********************************************************************
* 	 Class: Board
* Filename: Board.h
*
*		A board in a game of Alchemy.  Stores tiles.
*
* Constructors:
*			Board(  );
*				Creates a blank board with a starting block.
*
*	  Mutators:
*			No mutators are available for this class.  
*
*	   Methods:
*			void Display Board(  );
*				Displays the board.
*
*			void StoreSymbol( int row, int col, Symbol next )
*				Path to Tile's StoreSymbol method.
*
*			void RemoveSymbol( int row, int col )
*				Path to Tile's RemoveSymbol method.
*
*			bool isFull( int row, int col );
*				Path to Tile's isFull method.
*
*			bool rowFull( int row )
*				Returns whether a row is full, or not.
*		
*			void ClearRow( int row )
*				Empties a full row.
*
*			void CheckRows(  )
*				Checks to see if a row is full, if it is, it empties it.
*
*			bool colFull( int col )
*				Returns whether a column is full, or not.
*
*			void ClearCol( int col )
*				Empties a full column.
*
*			void CheckCols(  )
*				Checks to see if a column is full, if it is, it empties
*				it.
*
*			bool CheckBoard(  )
*				Checks for full rows and full columns, then checks to 
*				see if all the tiles on the board are gold.
*
*			int isValid( int row, int col, Symbol next )
*				Runs validations between the current symbol and the tiles
*				surrounding the location the user wants to place the
*				symbol.
*
*			bool CheckUp( int row, int col, Symbol next )
*				Checks to see if the current symbol matches the Symbol
*				above it.
*
*			bool CheckRight( int row, int col, Symbol next )
*				Checks to see if the current symbol matches the Symbol
*				to the right of it.
*
*			bool CheckDown( int row, int col, Symbol next )
*				Checks to see if the current symbol matches the Symbol
*				below it.
*
*			bool CheckLeft( int row, int col, Symbol next )
*				Checks to see if the current symbol matches the Symbol
*				to the left of it.					
*
***********************************************************************/
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
	using std::cout;
	using std::endl;

#include "Tile.h"
#include "Array2D.h"

class Board
{
	public:
		Board(  );
		Board( const Board & copy );
		Board & operator=( const Board & rhs);
		~Board(  );

		void DisplayBoard(  );
		void StoreSymbol( int row, int col, Symbol next );
		void RemoveSymbol( int row, int col );
		bool isFull( int row, int col );
		bool rowFull( int row );
		void ClearRow( int row );
		void CheckRows(  );
		bool colFull( int col );
		void ClearCol( int col );
		void CheckCols(  );
		bool CheckBoard(  );

		
		int isValid( int row, int col, Symbol next );
		bool CheckUp( int row, int col, Symbol next );
		bool CheckRight( int row, int col, Symbol next );
		bool CheckDown( int row, int col, Symbol next );
		bool CheckLeft( int row, int col, Symbol next );

	private:
		
		Array2D< Tile > m_board;		// Array2D object of tiles
};
#endif