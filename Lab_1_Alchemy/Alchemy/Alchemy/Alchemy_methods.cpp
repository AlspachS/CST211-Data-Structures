#include "Alchemy.h"


	Random Alchemy::m_rand;


	/**********************************************************************
	*	Alchemy::Alchemy(  )
	*
	*	   Purpose: Constructs an alchemy game.
	*
	*		 Entry:	When a game wants to be played.
	*
	*		  Exit:	After a game is created.
	*
	**********************************************************************/
	Alchemy::Alchemy(  ) : 
						m_board(  ), m_symbol(  ), m_level( 0 ),
						m_score( 0 ), m_cauldron( 0 ), m_over( false )
	{  }

	/**********************************************************************
	*	Alchemy::Alchemy( const Alchemy & copy )
	*
	*	   Purpose: Copies one game into another.
	*
	*		 Entry:	When a game needs to be copied.
	*
	*		  Exit:	After the game is copied.
	*
	**********************************************************************/
	Alchemy::Alchemy( const Alchemy & copy ) :
						m_board( copy.m_board ), m_symbol( copy.m_symbol ), 
						m_level( copy.m_level ), m_score( copy.m_score ), 
						m_cauldron( copy.m_cauldron ), m_over( copy.m_over )
	{  }

	/**********************************************************************
	*	Alchemy & Alchemy::operator=( const Alchemy & rhs )
	*
	*	   Purpose:	Assigns one game into another.
	*
	*		 Entry:	When one game needs to be assigned to another game.
	*
	*		  Exit:	After the assignment ends.
	*
	**********************************************************************/
	Alchemy & Alchemy::operator=( const Alchemy & rhs )
	{
		if( this != &rhs )
		{
			m_board = rhs.m_board;
			m_symbol = rhs.m_symbol;
			m_level = rhs.m_level;
			m_score = rhs.m_score;
			m_cauldron = rhs.m_cauldron;
			m_over = rhs.m_over;
		}
		return *this;
	}

	/**********************************************************************
	*	Alchemy::~Alchemy(  )
	*
	*	   Purpose:	Destroys a game after it ends.
	*
	*		 Entry:	When a player loses or quits.
	*
	*		  Exit:	After the game is destroyed.
	*
	**********************************************************************/
	Alchemy::~Alchemy(  )
	{  }

	/**********************************************************************
	*	int Alchemy::GetLevel(  )
	*
	*	   Purpose:	Returns the level the player is currently on.
	*
	*		 Entry:	When the level needs to be known.
	*
	*		  Exit:	After the level is returned.
	*
	**********************************************************************/
	int Alchemy::GetLevel(  )
	{
		return m_level + 1;
	}	

	/**********************************************************************
	*	int Alchemy::GetScore(  )
	*
	*	   Purpose:	Returns the players current score.
	*
	*		 Entry:	When the score needs to be known.
	*
	*		  Exit: After the score is returned.
	*
	**********************************************************************/
	int Alchemy::GetScore(  )
	{
		return m_score;
	}

	/**********************************************************************
	*	int Alchemy::GetCauldron(  )
	*
	*	   Purpose:	Returns the number of symbols in the cauldron.
	*
	*		 Entry:	When the number of symbols in the cauldron needs to be
	*				known.
	*
	*		  Exit:	After the value of m_cauldron is returned.
	*
	**********************************************************************/
	int Alchemy::GetCauldron(  )
	{
		return m_cauldron;
	}

	/**********************************************************************
	*	void Alchemy::SetLevel( int level )
	*
	*	   Purpose: Changes the games level.
	*
	*		 Entry:	When the player wants a harder game.
	*
	*		  Exit: After the level is set.
	*
	**********************************************************************/
	void Alchemy::SetLevel( int level )
	{
		m_level = level;
	}

	/**********************************************************************
	*	void Alchemy::SetScore( int score )
	*
	*	   Purpose: Changes the current score.
	*
	*		 Entry:	When someone wants to cheat.
	*
	*		  Exit:	After the player has cheated.
	*
	**********************************************************************/
	void Alchemy::SetScore( int score )
	{
		m_score = score;
	}

	/**********************************************************************
	*	void Alchemy::SetCauldron( int cauldron )
	*
	*	   Purpose:	Changes the number of symbols in the cauldron.
	*
	*		 Entry:	When someone wants to cheat again.
	*
	*		  Exit:	After the player has cheated.
	*
	**********************************************************************/
	void Alchemy::SetCauldron( int cauldron )
	{
		m_cauldron = cauldron;
	}

	/**********************************************************************
	*	void Alchemy::Display(  )
	*
	*	   Purpose:	Displays the board and information related to the 
	*				current game.
	*
	*		 Entry:	When the game needs to be displayed.
	*
	*		  Exit:	After the game is displayed.
	*
	**********************************************************************/
	void Alchemy::Display(  )
	{
		m_board.DisplayBoard(  );
	}

	/**********************************************************************
	*	void Alchemy::GameDriver(  )
	*
	*	   Purpose:	Runs the bulk of the game logic.
	*
	*		 Entry:	When someone plays a game.
	*
	*		  Exit:	After a game ends.
	*
	**********************************************************************/
	void Alchemy::GameDriver(  )
	{
		int row( 0 );
		int col( 0 );
		int symbolsit( 0 );
		int roundscore( 0 );

		bool valid( false );

		while( !m_over )
		{
			Display(  );
			cout << endl;
			cout << "Your current score is:  " << m_score << endl;
			cout << "The cauldron is currently at:  " << m_cauldron << endl;

			symbolsit = GenerateSymbolSituation(  );
			cout << "\nThe symbol this round is:  ";
			m_symbol.Display(  );

			cout << endl;
						
			

			switch( symbolsit )
			{
				case Normal:
					valid = Discard(  );					
					while( !valid )
					{
						UserInput( row, col );
						roundscore = m_board.isValid( row, col, m_symbol );

						if( roundscore )
						{
							m_board.StoreSymbol( row, col, m_symbol );
							m_score += roundscore;
							roundscore = 0;
							valid = true;
							if( m_cauldron )
								m_cauldron--;
						}
						else
						{
							cout << "That is an invalid move." << endl;
						}
					}
					system( "CLS" );
					valid = false;
				break;

				case Solvent:
					cout << "This tile removes any tile from the board.\n";
					UserInput( row, col );
					m_board.RemoveSymbol( row, col );
					if( m_cauldron )
						m_cauldron--;

					system( "CLS" );
				break;

				case FreeSpace:
					cout << "This tile will match any adjacent symbol.\n";
					UserInput( row, col );
					if( !m_board.isFull( row, col ) )
						m_board.StoreSymbol( row, col, m_symbol );
					if( m_cauldron )
						m_cauldron--;

					system( "CLS" );
				break;

			}
			IncrementLevel(  );
		}
		cout << "Game Over\n";
	}

	/**********************************************************************
	*	int Alchemy::GenerateSymbolSituation(  )
	*
	*	   Purpose: Determines if the current round's symbol is a normal
	*				symbol or a special symbol.
	*
	*		 Entry:	As the game progresses.
	*
	*		  Exit:	After a symbol is generated and the player is deciding
	*				what to do with it.
	*
	**********************************************************************/
	int Alchemy::GenerateSymbolSituation(  )
	{
		Symbol next;
		int sit = m_rand.GetRandom(  );
		int symbolsit( 0 );

		if( sit % 120 <= 95 )
			next = next.GenerateSymbol( m_level, m_rand );
		else if( sit % 120 >= 96 && sit % 120 <= 114 )
		{
			next.SetSymbol( ALL_SYMBOLS[ 7 ] );
			next.SetColor( ALL_COLORS[ 6 ] );
			symbolsit = 1;
		}
		else if( sit % 120 >= 115 )
		{
			next.SetSymbol( ALL_SYMBOLS[ 8 ] );
			next.SetColor( ALL_COLORS[ 6 ] );
			symbolsit = 2;
		}
		m_symbol = next;
		return symbolsit;
	}

	/**********************************************************************
	*	void Alchemy::UserInput( int & row, int & col )
	*
	*	   Purpose:	Gets row and column information from the user.
	*
	*		 Entry:	When the player has decided to keep a tile and wants to
	*				place it.
	*
	*		  Exit: After the user enters their play.
	*
	**********************************************************************/
	void Alchemy::UserInput( int & row, int & col )
	{
		do
		{
			cout << "What row would you like to play this symbol in?  ";
			cin >> row;

			if( row < 1 || row > 8 )
			{
				cout << "That is an invalid row." << endl;
				row = 0;
			}

		} while( !( row >= 1 && row <= 8 ) );
		row--;

		do
		{
			cout << "What column would you like to play this symbol in?  ";
			cin >> col;

			if( col < 1 || col > 9 )
			{	
				cout << "That is an invalid column." << endl;
				col = 0;
			}

		} while( !( col >= 1 && col <= 9 ) );
		col--;
	}

	/**********************************************************************
	*	bool Alchemy::Discard(  )
	*
	*	   Purpose:	Sends a tile to the cauldron.
	*
	*		 Entry:	When the player discards a symbol.
	*
	*		  Exit: After the symbol is discarded.
	*
	**********************************************************************/
	bool Alchemy::Discard(  )
	{
		bool yes( false );
		int confirm( 0 );

		cout << "Would you like to keep this piece?\n";
		cout << "(1/Keep) (2/Discard)\n";
		cin >> confirm;
		confirm--;

		if( confirm )
		{
			m_cauldron++;
			yes = true;
			if( m_cauldron == 4 )
				m_over = true;
		}
		return yes;
	}

	/**********************************************************************
	*	void Alchemy::IncrementLevel(  )
	*
	*	   Purpose:	Checks the board at the end of a round and if all the
	*				tiles are gold, resets the board and increments the
	*				level.
	*
	*		 Entry:	At the end of each round.
	*	
	*		  Exit: Once the board is checked.
	*
	**********************************************************************/
	void Alchemy::IncrementLevel(  )
	{
		bool done = m_board.CheckBoard(  );

		if( done )
		{
			Board next;
			m_board = next;
			m_level++;
			m_cauldron = 0;
		}
	}