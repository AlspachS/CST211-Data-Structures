#include "Board.h"


	/**********************************************************************
	*	Board::Board(  )
	*
	*	   Purpose: Creates the default board for Alchemy.
	*
	*		 Entry:	When the game first starts and the board needs to be 
	*				laid out.
	*
	*		  Exit:	After the board is laid out and the game is ready to
	*				play.
	*
	**********************************************************************/
	Board::Board(  )
	{
		m_board = Array2D< Tile >( 8, 9 );

		Symbol temp( 8, 6 );
		
		m_board[ 3 ][ 4 ].StoreSymbol( temp );
	}

	/**********************************************************************
	*	Board::Board( const Board & copy )
	*
	*	   Purpose:	Copies a board into another on initialization.
	*
	*		 Entry:	When a board needs to be copied into another board.
	*
	*		  Exit:	After the copy is created.
	*
	**********************************************************************/
	Board::Board( const Board & copy ) :
					m_board( copy.m_board )
	{  }

	/**********************************************************************
	*	Board & Board::operator=( const Board & rhs )
	*
	*	   Purpose: Assigns one board to another board.
	*
	*		 Entry:	Called when an existing board needs to be copied into
	*				another existing board.
	*
	*		  Exit:	After the assignment is complete.
	*
	**********************************************************************/
	Board & Board::operator=( const Board & rhs )
	{
		if( this != &rhs )
		{
			m_board = rhs.m_board;
		}
		return *this;
	}

	/**********************************************************************
	*	Board::~Board(  )
	*
	*	   Purpose:	Destroys a board object.
	*
	*		 Entry:	When a board goes out of scope.
	*
	*		  Exit:	After the board is destroyed.
	*
	**********************************************************************/
	Board::~Board(  )
	{  }

	/**********************************************************************
	*	void Board::DisplayBoard(  )
	*
	*	   Purpose: Displays the board surrounded with numbers to reference
	*				rows an columns
	*
	*		 Entry:	When the board needs to be display.
	*
	*		  Exit:	After the board is displayed.
	*
	**********************************************************************/
	void Board::DisplayBoard(  )
	{
		cout << " 123456789" << endl;
		for( int row( 0 ); row < m_board.getRow(  ); ++row )
		{
			cout << row + 1;
			for( int col( 0 ); col < m_board.getColumn(  ); ++col )
			{
				m_board[ row ][ col ].DisplayTile(  );
			}
			cout << row + 1 << endl;
		}
		cout << " 123456789" << endl;
	}

	/**********************************************************************
	*	void Board::StoreSymbol( int row, int col, Symbol next )
	*
	*	   Purpose: Path to tile's StoreSymbol method.
	*
	*		 Entry:	When a symbol needs to be stored.
	*
	*		  Exit:	After a symbol is stored.
	*
	**********************************************************************/
	void Board::StoreSymbol( int row, int col, Symbol next )
	{
		m_board[ row ][ col ].StoreSymbol( next );
	}

	/**********************************************************************
	*	void Board::RemoveSymbol( int row, int col )
	*
	*	   Purpose:	Path to tile's RemoveSymbol method.
	*
	*		 Entry:	When a symbol needs to be removed.
	*
	*		  Exit:	After the symbol is removed.
	*
	**********************************************************************/
	void Board::RemoveSymbol( int row, int col )
	{
		m_board[ row ][ col ].RemoveSymbol(  );
	}

	/**********************************************************************
	*	bool Board::isFull( int row, int col )
	*
	*	   Purpose: Returns if a tile is full.
	*
	*		 Entry:	When it needs to be known if a tile is full.
	*
	*		  Exit:	After the full status of the tile is returned.
	*
	**********************************************************************/
	bool Board::isFull( int row, int col )
	{
		return m_board[ row ][ col ].isFull(  );
	}

	/**********************************************************************
	*	bool Board::rowFull( int row )
	*
	*	   Purpose:	Checks to see if all tiles in a row are full.
	*
	*		 Entry:	Called as part of checking the board after a round.
	*
	*		  Exit:	After the row is checked.
	*
	**********************************************************************/
	bool Board::rowFull( int row )
	{
		bool fullrow = true;

		for( int i( 0 ); i < m_board.getColumn(  ); ++i )
		{
			if( !m_board[ row ][ i ].isFull(  ) )
				fullrow = false;
		}
		return fullrow;
	}

	/**********************************************************************
	*	void Board::ClearRow( int row )
	*
	*	   Purpose:	Clears all the symbols out of a full row.
	*
	*		 Entry:	Called when a row is full.
	*
	*		  Exit:	After a row is cleared.
	*
	**********************************************************************/
	void Board::ClearRow( int row )
	{
		for( int i( 0 ); i < m_board.getColumn(  ); ++i )
			m_board[ row ][ i ].RemoveSymbol(  );
	}
	
	/**********************************************************************
	*	void Board::CheckRows(  )
	*
	*	   Purpose:	Checks to see if any rows in the board are full.
	*
	*		 Entry:	Called as part of checking the board after a round.
	*
	*		  Exit:	After all rows are checked.
	*
	**********************************************************************/
	void Board::CheckRows(  )
	{
		bool full( false );

		for( int i( 0 ); i < m_board.getRow(  ); ++i )
		{
			if( rowFull( i ) )
				ClearRow( i );
		}
	}

	/**********************************************************************
	*	bool Board::colFull( int col )
	*
	*	   Purpose:	Checks to see if all tiles in a column are full.
	*
	*		 Entry:	Called as part of checking the board after a round.
	*
	*		  Exit:	After the column is checked.
	*
	**********************************************************************/
	bool Board::colFull( int col )
	{
		bool fullcol = true;

		for( int i( 0 ); i < m_board.getRow(  ); ++i )
		{
			if( !m_board[ i ][ col ].isFull(  ) )
				fullcol = false;
		}
		return fullcol;
	}

	/**********************************************************************
	*	void Board::ClearCol( int col )
	*
	*	   Purpose:	Clears all the symbols out of a full column.
	*
	*		 Entry:	Called when a column is full.
	*
	*		  Exit:	After a column is cleared.
	*
	**********************************************************************/
	void Board::ClearCol( int col )
	{
		for( int i( 0 ); i < m_board.getRow(  ); ++i )
			m_board[ i ][ col ].RemoveSymbol(  );
	}
	
	/**********************************************************************
	*	void Board::CheckCols(  )
	*
	*	   Purpose:	Checks to see if any columns in the board are full.
	*
	*		 Entry:	Called as part of checking the board after a round.
	*
	*		  Exit:	After all columns are checked.
	*
	**********************************************************************/
	void Board::CheckCols(  )
	{
		bool full( false );

		for( int i( 0 ); i < m_board.getColumn(  ); ++i )
		{
			if( colFull( i ) )
				ClearCol( i );
		}
	}

	/**********************************************************************
	*	bool Board::CheckBoard(  )
	*
	*	   Purpose: Checks the board for full rows, full columns, and if
	*				all tiles are gold after the end of a round.
	*
	*		 Entry:	Called after the end of the round.
	*
	*		  Exit:	After the board is checked and the next round is
	*				starting.
	*
	**********************************************************************/
	bool Board::CheckBoard(  )
	{
		bool allgold( true );

		CheckRows(  );
		CheckCols(  );

		for( int rows( 0 ); rows < m_board.getRow(  ); ++rows )
		{
			for( int cols( 0 ); cols < m_board.getColumn(  ); ++cols )
			{
				if( !m_board[ rows ][ cols ].isGold(  ) )
					allgold = false;
			}
		}
		return allgold;
	}

	/**********************************************************************
	*	int Board::isValid( int row, int col, Symbol next )
	*
	*	   Purpose:	Runs the necessary validations to determine if a 
	*				move the player wants to make is a valid one.
	*				In the course of this, the score for a valid 
	*				placement is also determined.  The checks happen from
	*				most specific circumstances to least specific 
	*				circumstances.
	*
	*		 Entry:	Called when after a player give a row and column to
	*				place a symbol.
	*
	*		  Exit:	After all the validations occur and a valid is returned.
	*
	**********************************************************************/
	int Board::isValid( int row, int col, Symbol next )
	{
		int valid( 0 );


		if( !m_board[ row ][ col ].isFull(  ) )
		{
			if( row == 0 && col == 0 )
			{
				if( m_board[ row + 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col + 1 ].isFull(  ) )
				{	
					if( CheckDown( row, col, next ) && 
						CheckRight( row, col, next ) )
					{
						if( m_board[ row + 1 ][ col ].isFull(  ) )
						{
							if( CheckDown( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col + 1 ].isFull(  ) )
						{
							if( CheckRight( row, col, next ) )
								valid += 5;
						}
					}
				}
			}
			else if( row == 0 && col == m_board.getColumn(  ) - 1 )
			{
				if( m_board[ row + 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col - 1 ].isFull(  ) )
				{	
					if( CheckDown( row, col, next ) &&
						CheckLeft( row, col, next ) )
					{
						if( m_board[ row + 1 ][ col ].isFull(  ) )
						{
							if( CheckDown( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col - 1 ].isFull(  ) )
						{
							if( CheckLeft( row, col, next ) )
								valid += 5;
						}
					}
				}
			}
			else if( row == m_board.getRow(  ) - 1 && col == 0 )
			{
				if( m_board[ row - 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col + 1 ].isFull(  ) )
				{	
					if( CheckUp( row, col, next ) &&
						CheckRight( row, col, next ) )
					{
						if( m_board[ row - 1 ][ col ].isFull(  ) )
						{
							if( CheckUp( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col + 1 ].isFull(  ) )
						{
							if( CheckRight( row, col, next ) )
								valid += 5;
						}
					}
				}
			}
			else if( row == m_board.getRow(  ) - 1 && col == m_board.getColumn(  ) - 1 )
			{
				if( m_board[ row - 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col - 1 ].isFull(  ) )
				{	
					if( CheckUp( row, col, next ) &&
						CheckLeft( row, col, next ) )
					{
						if( m_board[ row - 1 ][ col ].isFull(  ) )
						{
							if( CheckUp( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col - 1 ].isFull(  ) )
						{
							if( CheckLeft( row, col, next ) )
								valid += 5;
						}
					}
				}
			}
			else if( row == 0 )
			{
				if( m_board[ row + 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col + 1 ].isFull(  ) ||
					m_board[ row ][ col - 1 ].isFull(  ) )
				{			
					if( CheckDown( row, col, next ) &&
						CheckRight( row, col, next ) &&
						CheckLeft( row, col, next ) )
					{
						if( m_board[ row + 1 ][ col ].isFull(  ) )
						{
							if( CheckDown( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col + 1 ].isFull(  ) )
						{
							if( CheckRight( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col - 1 ].isFull(  ) )
						{
							if( CheckLeft( row, col, next ) )
								valid += 5;
						}
					}
				}
			}
			else if( row == m_board.getRow(  ) - 1 )
			{
				if( m_board[ row - 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col + 1 ].isFull(  ) ||
					m_board[ row ][ col - 1 ].isFull(  ) )
				{	
					if( CheckUp( row, col, next ) &&
						CheckLeft( row, col, next ) && 
						CheckRight( row, col, next ) )
					{
						if( m_board[ row - 1 ][ col ].isFull(  ) )
						{
							if( CheckUp( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col + 1 ].isFull(  ) )
						{
							if( CheckRight( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col - 1 ].isFull(  ) )
						{
							if( CheckLeft( row, col, next ) )
								valid += 5;
						}
					}
				}
			}
			else if( col == 0 )
			{
				if( m_board[ row + 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col + 1 ].isFull(  ) ||
					m_board[ row - 1 ][ col ].isFull(  ) )
				{	
					if( CheckDown( row, col, next ) &&
						CheckUp( row, col, next ) && 
						CheckRight( row, col, next ) )
					{
						if( m_board[ row + 1 ][ col ].isFull(  ) )
						{
							if( CheckDown( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col + 1 ].isFull(  ) )
						{
							if( CheckRight( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row - 1 ][ col ].isFull(  ) )
						{
							if( CheckUp( row, col, next ) )
								valid += 5;
						}
					}
				}
			}
			else if( col == m_board.getColumn(  ) - 1 )
			{
				if( m_board[ row + 1 ][ col ].isFull(  ) ||
					m_board[ row - 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col - 1 ].isFull(  ) )
				{	
					if( CheckUp( row, col, next) && 
						CheckDown( row, col, next ) && 
						CheckLeft( row, col, next ) )
					{
						if( m_board[ row + 1 ][ col ].isFull(  ) )
						{
							if( CheckDown( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row - 1 ][ col ].isFull(  ) )
						{
							if( CheckUp( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col - 1 ].isFull(  ) )
						{
							if( CheckLeft( row, col, next ) )
								valid += 5;
						}
					}
				}
			}
			else
			{
				if( m_board[ row + 1 ][ col ].isFull(  ) ||
					m_board[ row - 1 ][ col ].isFull(  ) ||
					m_board[ row ][ col - 1 ].isFull(  ) ||
					m_board[ row ][ col + 1 ].isFull(  ) )
				{

					if( CheckUp( row, col, next ) &&
						CheckRight( row, col, next ) &&
						CheckDown( row, col, next ) &&
						CheckLeft( row, col, next ) )
					{
						if( m_board[ row + 1 ][ col ].isFull(  ) )
						{
							if( CheckDown( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row - 1 ][ col ].isFull(  ) )
						{
							if( CheckUp( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col - 1 ].isFull(  ) )
						{
							if( CheckLeft( row, col, next ) )
								valid += 5;
						}
						if( m_board[ row ][ col + 1 ].isFull(  ) )
						{
							if( CheckRight( row, col, next ) )
								valid += 5;						
						}
					}
				}
			}
		}
		return valid;
	}

	/**********************************************************************
	*	bool Board::CheckUp( int row, int col, Symbol next )
	*
	*	   Purpose: Checks the tile above the desired tile to determine if
	*				the desired tile is, in part, a valid move.
	*
	*		 Entry:	When there is a tile above the tile the user wants to
	*				place a symbol in.
	*
	*		  Exit:	After the check has run and returned a value.
	*
	**********************************************************************/
	bool Board::CheckUp( int row, int col, Symbol next )
	{
		bool upcolor = false;
		bool upchar = false;
		bool valid = false;

	
		if( m_board[ row - 1 ][ col ].isFull(  ) )
		{
			if( m_board[ row - 1 ][ col ].GetSymbol(  ).GetSymbol(  ) == ALL_SYMBOLS[ 8 ] )
			{
				valid = true;
			}
			else
			{
				if( m_board[ row - 1 ][ col ].GetSymbol(  ).GetColor(  ) == next.GetColor(  ) )
					upcolor = true;
				if( m_board[ row - 1 ][ col ].GetSymbol(  ).GetSymbol(  ) == next.GetSymbol(  ) )
					upchar = true;

				if( upcolor == true || upchar == true )
					valid = true;
			}
		}
		else
			valid = true;

		return valid;
	}

	/**********************************************************************
	*	bool Board::CheckRight( int row, int col, Symbol next )
	*
	*	   Purpose: Checks the tile to the right of the desired tile to 
	*				determine if the desired tile is, in part, a valid move.
	*
	*		 Entry:	When there is a tile to the right the tile the user 
	*				wants to place a symbol in.
	*
	*		  Exit:	After the check has run and returned a value.
	*
	**********************************************************************/
	bool Board::CheckRight( int row, int col, Symbol next )
	{
		bool rightcolor = false;
		bool rightchar = false;
		bool valid = false;

		
		if( m_board[ row ][ col + 1 ].isFull(  ) )
		{
			if( m_board[ row ][ col + 1 ].GetSymbol(  ).GetSymbol(  ) == ALL_SYMBOLS[ 8 ] )
			{
				valid = true;
			}
			else
			{
				if( m_board[ row ][ col + 1 ].GetSymbol(  ).GetColor(  ) == next.GetColor(  ) )
					rightcolor = true;
				if( m_board[ row ][ col + 1 ].GetSymbol(  ).GetSymbol(  ) == next.GetSymbol(  ) )
					rightchar = true;

				if( rightcolor == true || rightchar == true )
					valid = true;
			}
		}
		else
			valid = true;

		return valid;
	}

	/**********************************************************************
	*	bool Board::CheckDown( int row, int col, Symbol next )
	*
	*	   Purpose: Checks the tile below the desired tile to determine if
	*				the desired tile is, in part, a valid move.
	*
	*		 Entry:	When there is a tile below the tile the user wants to
	*				place a symbol in.
	*
	*		  Exit:	After the check has run and returned a value.
	*
	**********************************************************************/
	bool Board::CheckDown( int row, int col, Symbol next )
	{
		bool downcolor = false;
		bool downchar = false;
		bool valid = false;

		if( m_board[ row + 1 ][ col ].isFull(  ) )
		{
			if( m_board[ row + 1 ][ col ].GetSymbol(  ).GetSymbol(  ) == ALL_SYMBOLS[ 8 ] )
			{
				valid = true;
			}
			else
			{
				if( m_board[ row + 1 ][ col ].GetSymbol(  ).GetColor(  ) == next.GetColor(  ) )
					downcolor = true;
				if( m_board[ row + 1 ][ col ].GetSymbol(  ).GetSymbol(  ) == next.GetSymbol(  ) )
					downchar = true;

				if( downcolor == true || downchar == true )
					valid = true;
			}
		}
		else
			valid = true;

		return valid;
	}

	/**********************************************************************
	*	bool Board::CheckLeft( int row, int col, Symbol next )
	*
	*	   Purpose: Checks the tile to the left of the desired tile to 
	*				determine if the desired tile is, in part, a valid move.
	*
	*		 Entry:	When there is a tile to the left the tile the user 
	*				wants to place a symbol in.
	*
	*		  Exit:	After the check has run and returned a value.
	*
	**********************************************************************/
	bool Board::CheckLeft( int row, int col, Symbol next )
	{
		bool leftcolor = false;
		bool leftchar = false;
		bool valid = false;

		
		if( m_board[ row ][ col - 1 ].isFull(  ) )
		{
			if( m_board[ row ][ col - 1 ].GetSymbol(  ).GetSymbol(  ) == ALL_SYMBOLS[ 8 ] )
			{
				valid = true;
			}
			else
			{
				if( m_board[ row ][ col - 1 ].GetSymbol(  ).GetColor(  ) == next.GetColor(  ) )
					leftcolor = true;
				if( m_board[ row ][ col - 1 ].GetSymbol(  ).GetSymbol(  ) == next.GetSymbol(  ) )
					leftchar = true;

				if( leftcolor == true || leftchar == true )
					valid = true;
			}
		}
		else
			valid = true;

		return valid;
	}