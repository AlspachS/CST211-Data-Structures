#include "FreeCellGame.h"

//
// Manager functions
//

	/**********************************************************************
	*	FreeCellGame::FreeCellGame(  )
	*
	*	   Purpose: Creates an instance of the FreeCellGame class.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	FreeCellGame::FreeCellGame(  ) : 
								FreeCellGroup(  ), HomeCellGroup(  ), PlayCellGroup(  )
	{  }

	/**********************************************************************
	*	FreeCellGame::FreeCellGame( const FreeCellGame & copy )
	*
	*	   Purpose: Creates a FreeCellGame object that is a copy of an 
	*				existing FreeCellGame object.
	*
	*		 Entry:	'copy' is some existing FreeCellGame object.
	*
	*		  Exit:	'this' is now a replica of 'copy'.
	*
	**********************************************************************/
	FreeCellGame::FreeCellGame( const FreeCellGame & copy ) :
								FreeCellGroup( copy.FreeCellGroup ), 
								HomeCellGroup( copy.HomeCellGroup ),
								PlayCellGroup( copy.PlayCellGroup )
	{  }

	/**********************************************************************
	*	FreeCellGame & FreeCellGame::operator=( const FreeCellGame & rhs )
	*
	*	   Purpose:	Overwrites one FreeCellGame object with the data of 
	*				another.
	*
	*		 Entry:	'this' has unimportant data that will be overwritten,
	*				and 'rhs' is the source of the data.
	*
	*		  Exit:	'this' will be the same as 'rhs'.
	*
	**********************************************************************/
	FreeCellGame & FreeCellGame::operator=( const FreeCellGame & rhs )
	{ 
		if( this != &rhs )
		{
			FreeCellGroup = rhs.FreeCellGroup;
			HomeCellGroup = rhs.HomeCellGroup;
			PlayCellGroup = rhs.PlayCellGroup;
		}
		return * this;
	}

	/**********************************************************************
	*	FreeCellGame::~FreeCellGame(  )
	*
	*	   Purpose: Destroys a FreeCellGame object.
	*
	*		 Entry:	'this' is some object.
	*
	*		  Exit: 'this' is no longer an object.
	*
	**********************************************************************/
	FreeCellGame::~FreeCellGame(  )
	{  }
	
//
// Member functions
//

	/**********************************************************************
	*	void FreeCellGame::GameDriver(  )
	*
	*	   Purpose: Runs the game loop of the FreeCellGame object.
	*
	*		 Entry:	Called when the game starts.
	*
	*		  Exit:	After the game ends.
	*
	**********************************************************************/
	void FreeCellGame::GameDriver(  )
	{
		char startgroup = { '\0' };
		char destgroup = { '\0' };
		int startpile = 0;
		int destpile = 0;

		Display(  );

		while( !WinCheck(  ) )
		{
			Display(  );
			TakeUserInput( startgroup, destgroup, startpile, destpile );
			MoveCards( startgroup, destgroup, startpile, destpile );
			AutoMoveUp(  );
		}
		
		Display(  );

		cout << "Congratulations, you win!" << endl;
		system( "pause" );
	}

	/**********************************************************************
	*	void FreeCellGame::TakeUserInput( char & startgroup, char & destgroup, int & startpile, int & destpile )
	*
	*	   Purpose: Takes input from the user.
	*
	*		 Entry:	The value of each of the variables is unimportant since
	*				they will be overwritten.
	*
	*		  Exit: The variables now have a valid moveset.
	*
	**********************************************************************/
	void FreeCellGame::TakeUserInput( char & startgroup, char & destgroup, int & startpile, int & destpile )
	{ 
		char buffer[ 50 ] = { '\0' };
		char tempstartpile = { '\0' };
		char tempdestpile = { '\0' };
		bool startdata( true );
		bool destdata( true );

		while( startdata || destdata )
		{
			cout << "Format of move entry is: AreaPile AreaPile.\n" << 
					"For example, P7 F1 will move a card \n" <<
					"from PlayCell 7 to FreeCell 1.\n";

			cout << "\nPlease enter your move: ";
			cin.getline( buffer, 50 );

			startgroup = toupper( buffer[ 0 ] );
			tempstartpile = buffer[ 1 ];

			destgroup = toupper( buffer[ 3 ] );
			tempdestpile = buffer[ 4 ];

			if( startgroup == 'P' || startgroup == 'F' &&
				destgroup == 'P' || destgroup == 'F' || destgroup == 'H' )
			{
				if( ( startpile = atoi( &tempstartpile ) ) && ( destpile = atoi( &tempdestpile ) ) )
				{  
					if( startgroup == 'P' )
					{
						if( startpile >= 1 && startpile <= 8 )
						{
							startdata = false;// good data
						}
						else
						{ 
							startdata = true;
							destdata = true;
							Display(  );
						} // number not in range
					}
					else // startgroup == 'F"
					{
						if( startpile >= 1 && startpile <= 4 )
						{
							startdata = false;// Good data
						}
						else
						{
							startdata = true;
							destdata = true;
							Display(  );
						} // number not in range
					}

					if( destgroup == 'P' )
					{
						if( destpile >= 1 && destpile <= 8 )
						{
							destdata = false;// good data
						}
						else
						{  
							startdata = true;
							destdata = true;
							Display(  );
						} // number not in range
					}
					else // destgroup == 'F' || destgroup == 'H'
					{
						if( destpile >= 1 && destpile <= 4 )
						{
							destdata = false;// good data
						}
						else
						{ 
							startdata = true;
							destdata = true;
							Display(  );
						} // number not in range
					}
				}
				else
				{ 
					startdata = true;
					destdata = true;
					Display(  );
				} // non-numeric info
			}
			else
			{
				startdata = true;
				destdata = true;
				Display(  );
			} //bad group input
		}
		--startpile;
		--destpile;
	}

	/**********************************************************************
	*	void FreeCellGame::AutoMoveUp(  )
	*
	*	   Purpose: Checks the game board to see if any cards can be moved
	*				up to the HomeCells area.  Alleviates the tedium of the
	*				game toward the end.
	*
	*		 Entry:	Called after every time a player makes a move.
	*
	*		  Exit:	No more cards can be moved to the HomeCells.
	*
	**********************************************************************/
	void FreeCellGame::AutoMoveUp(  )
	{
		bool changed( true );

		while( changed )
		{
			changed = false;
			for( int i( 0 ); i < 4; ++i )
			{
				for( int j( 0 ); j < 8; ++j )
				{
					if( HomeCellGroup.isValid( PlayCellGroup.ViewCard( j ), i ) )
					{
						HomeCellGroup.MoveUp( PlayCellGroup.GetCard( j ), i );	
						changed = true;
					}
				}

				for( int j( 0 ); j < 4; ++j )
				{
					if( HomeCellGroup.isValid( FreeCellGroup.ViewCard( j ), i ) )
					{
						HomeCellGroup.MoveUp( FreeCellGroup.GetCard( j ), i );	
						changed = true;
					}
				}
			}
		}
	}

	/**********************************************************************
	*	void FreeCellGame::MoveCards( char startgroup, char destgroup, int startpile, int destpile )
	*
	*	   Purpose:	Takes the values given in TakeUserInput and makes the 
	*				indicated move, if possible.  If moving from PlayCell
	*				to PlayCell, the user is prompted for the number of 
	*				cards to move.
	*
	*		 Entry: The four variables are values given in TakeUserInput.
	*				If they made it here, the variables hold some 
	*				combination of feasible move, but the move hasn't been
	*				validated yet.
	*
	*		  Exit:	The move has been validated, and performed if it was
	*				a legal move.
	*
	**********************************************************************/
	void FreeCellGame::MoveCards( char startgroup, char destgroup, int startpile, int destpile )
	{
		int numCards( 0 );

		if( startgroup == 'P' )
		{
			switch( destgroup )
			{
			case 'P':

				do{
					cin.clear(  );
					cin.sync(  );
					numCards = 0;

					cout << "Enter the number of cards you want to move: ";
					cin >> numCards;


				}while( cin.fail(  ) );
				
				if( numCards <= PlayCellGroup.CalcPowerMove( FreeCellGroup.GetFullCount(  ), destpile )
					&& PlayCellGroup.isValid( PlayCellGroup.ViewCard( startpile ), startpile, destpile, numCards ) )
				{
					PlayCellGroup.MoveStack( numCards, startpile, destpile );
				}

				break;

			case 'H':
				if( HomeCellGroup.isValid( PlayCellGroup.ViewCard( startpile ), destpile ) )
					HomeCellGroup.MoveUp( PlayCellGroup.GetCard( startpile ), destpile );
				break;

			case 'F':
				if( FreeCellGroup.isValid( destpile ) )
					FreeCellGroup.PutCard( PlayCellGroup.GetCard( startpile ), destpile );
				break;
			}
		}
		else
		{
			switch( destgroup )
			{
			case 'P':
				if( PlayCellGroup.isValid( FreeCellGroup.ViewCard( startpile ), startpile, destpile ) )
					PlayCellGroup.StackCard( FreeCellGroup.GetCard( startpile ), destpile );
				break;

			case 'H':
				if( HomeCellGroup.isValid( FreeCellGroup.ViewCard( startpile ), destpile ) )
					HomeCellGroup.MoveUp( FreeCellGroup.GetCard( startpile ), destpile );
				break;

			case 'F':
				if( FreeCellGroup.isValid( destpile ) )
					FreeCellGroup.PutCard( FreeCellGroup.GetCard( startpile ), destpile );
				break;

			}
		}
	}

	/**********************************************************************
	*	bool FreeCellGame::WinCheck(  )
	*
	*	   Purpose: Checks to see if the game is over by seeing how many 
	*				cards are in the HomeCells area.
	*
	*		 Entry:	Called as a loop condition in the GameDriver.
	*
	*		  Exit: Whether there are 52 cards in the HomeCells area is 
	*				returned.
	*
	**********************************************************************/
	bool FreeCellGame::WinCheck(  )
	{
		return( HomeCellGroup.GetTotalCards(  ) == 52 );
	}

	/**********************************************************************
	*	void FreeCellGame::Display(  )
	*
	*	   Purpose: Displays the FreeCellGame object.
	*
	*		 Entry: 'this' is some FreeCellGame object.
	*
	*		  Exit:	'this' is displayed.
	*
	**********************************************************************/
	void FreeCellGame::Display(  )
	{
		SetConsoleTitle( TEXT( "FreeCell" ) );
		SizeConsoleAbsolute( 81, 57 );
		ClearWindow( GreenBack );

		FreeCellGroup.Display(  );
		HomeCellGroup.Display(  );
		PlayCellGroup.Display(  );
	}