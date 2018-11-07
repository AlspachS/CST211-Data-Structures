#include "PlayCells.h"

//
// Manager functions
//

	/**********************************************************************
	*	PlayCells::PlayCells(  )
	*
	*	   Purpose: Creates an instance of the PlayCells class.
	*				For a cheat game, uncomment the top section and 
	*				comment the bottom section, then comment the call to 
	*				the shuffle method in the Deck constructor.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	PlayCells::PlayCells(  ) :
						mPlayCells( 8 ), mPlayDeck(  )
	{ 
		//LinkedStack< Card > temp;
		//for( int i( 0 ); i < 52; ++i )
		//	temp.Push( mPlayDeck.Deal(  ) );
		//
		//for( int i( 0 ); i < 52; )
		//{
		//	for( int j( 0 ); j < 4 && i < 52; ++j, ++i )
		//	{
		//		mPlayCells[ j ].Push( temp.Pop(  ) );
		//	}
		//}

		for( int i( 0 ); i < 52; )
		{
			for( int j( 0 ); j < 8 && i < 52; ++j, ++i )
			{
				mPlayCells[ j ].Push( mPlayDeck.Deal(  ) );
			}
		}
	}

	/**********************************************************************
	*	PlayCells::PlayCells( const PlayCells & copy )
	*
	*	   Purpose: Creates a PlayCells object that is a copy of an 
	*				existing PlayCells object.
	*
	*		 Entry:	'copy' is some existing PlayCells object.
	*
	*		  Exit:	'this' is now a replica of 'copy'.
	*
	**********************************************************************/
	PlayCells::PlayCells( const PlayCells & copy ) :
						mPlayCells( copy.mPlayCells )
	{  }

	/**********************************************************************
	*	PlayCells & PlayCells::operator=( const PlayCells & rhs )
	*
	*	   Purpose:	Overwrites one PlayCell object with the data of another.
	*
	*		 Entry:	'this' has unimportant data that will be overwritten,
	*				and 'rhs' is the source of the data.
	*
	*		  Exit:	'this' will be the same as 'rhs'.
	*
	**********************************************************************/
	PlayCells & PlayCells::operator=( const PlayCells & rhs )
	{
		if( this != &rhs )
		{
			mPlayCells = rhs.mPlayCells;
		}
		return * this;
	}

	/**********************************************************************
	*	PlayCells::~PlayCells(  )
	*
	*	   Purpose: Destroys a PlayCells object.
	*
	*		 Entry:	'this' is some object.
	*
	*		  Exit: 'this' is no longer an object.
	*
	**********************************************************************/
	PlayCells::~PlayCells(  )
	{  }

//
// Member functions
//

	/**********************************************************************
	*	Card PlayCells::GetCard( int index )
	*
	*	   Purpose: Returns the top card of the 'index' stack.
	*
	*		 Entry: 'index' is the stack to remove a card from.
	*
	*		  Exit:	The top card is removed and returned.
	*
	**********************************************************************/
	Card PlayCells::GetCard( int index )
	{
		return mPlayCells[ index ].Pop(  );
	}

	/**********************************************************************
	*	Card PlayCells::ViewCard( int index )
	*
	*	   Purpose: Returns the top card of 'index' stack, but doesn't
	*				remove it.
	*
	*		 Entry:	'index' is the stack to look at.
	*
	*		  Exit:	The top card is returned.
	*
	**********************************************************************/
	Card PlayCells::ViewCard( int index )
	{
		Card blank;

		if( !mPlayCells[ index ].isEmpty(  ) )
			blank = mPlayCells[ index ].Peek(  );

		return blank;
	}

	/**********************************************************************
	*	void PlayCells::StackCard( Card card, int index )
	*	
	*	   Purpose: Puts 'card' on the stack 'index'.
	*
	*		 Entry: 'index' is the stack the card is moving to.
	*
	*		  Exit:	'card' is now the top card of 'index' stack.
	*
	**********************************************************************/
	void PlayCells::StackCard( Card card, int index )
	{
		mPlayCells[ index ].Push( card );
	}

	/**********************************************************************
	*	void PlayCells::MoveStack( int numCards, int start, int dest )
	*	
	*	   Purpose: Moves 'numCards' of cards from 'start' stack to 'dest'
	*				stack.
	*
	*		 Entry:	'numCards' is the number of cards to move, 'start' is 
	*				the array element stack to move from, and 'dest' is
	*				the array element stack to move to.
	*
	*		  Exit:	'numCards' number of cards are moved from 'start' stack
	*				to 'dest' stack.
	*
	**********************************************************************/
	void PlayCells::MoveStack( int numCards, int start, int dest )
	{
		LinkedStack< Card > moveTemp;

		//if( checkStack( start, numCards ) )
		//{
			for( int i( 0 ); i < numCards; ++i )
				moveTemp.Push( mPlayCells[ start ].Pop(  ) );

			for( int i( 0 ); i < numCards; ++i )
				mPlayCells[ dest ].Push( moveTemp.Pop(  ) );
		//}
	}

	/**********************************************************************
	*	int PlayCells::CalcPowerMove( int emptyFC, int dest )
	*
	*	   Purpose: Calculates the total number of cards a player can move
	*				at once.
	*
	*		 Entry:	'emptyFC' is some value and 'dest' is the destination
	*				stack.
	*
	*		  Exit:	The max number of card the player can move is returned.
	*
	**********************************************************************/
	int PlayCells::CalcPowerMove( int emptyFC, int dest )
	{
		int emptyPC = 0;
		
		for( int i( 0 ); i < 8; ++i )
		{
			if( mPlayCells[ i ].isEmpty(  ) )
				++emptyPC;
		}

		if( mPlayCells[ dest ].isEmpty(  ) )
			--emptyPC;

		return( ( 1 + emptyFC ) * static_cast< int >( pow( 2, emptyPC ) ) );
	}

	/**********************************************************************
	*	bool PlayCells::isValid( Card card, int start, int dest, int numCards )
	*
	*	   Purpose: Checks to see if a move is a valid move.  (This function
	*				and checkStack got a little hack-y.  If you're going to
	*				break the game, it will be with these two functions.)
	*
	*		 Entry:	'card' is the card to move if only one card is being 
	*				moved.  'start' is the starting stack if more than one
	*				card is being moved.  'numCards' is the number of cards
	*				to move to 'dest' stack
	*
	*		  Exit: The move has been validated, and whether or not it can 
	*				be done is returned.
	*
	**********************************************************************/
	bool PlayCells::isValid( Card card, int start, int dest, int numCards )
	{
		bool valid( false );
		LinkedStack< Card > temp;

		if( card.GetSuit(  ) != card.BLANK )
		{
			if( numCards == 1 )
			{
				if( checkColor( card, dest ) && checkRank( card, dest ) )
					valid = true;
			}
			else
			{
				if( checkStack( start, numCards ) )
				{
					int i( 0 );
					for( ; i < numCards; ++i )
						temp.Push( mPlayCells[ start ].Pop(  ) );

					if( checkColor( temp.Peek(  ), dest ) && checkRank( temp.Peek(  ), dest ) )
						valid = true;

					for( ; i > 0; --i )
						mPlayCells[ start ].Push( temp.Pop(  ) );
				}
			}
		}
		return valid;
	}

	/**********************************************************************
	*	bool PlayCells::checkColor( Card card, int dest )
	*
	*	   Purpose: Checks the color of 'card' against the card it's going
	*				to be placed on.
	*
	*		 Entry:	'card' is some card, 'dest' is the stack to put this
	*				card on.
	*
	*		  Exit:	Whether or not 'card' can go on 'dest' is returned.
	*
	**********************************************************************/
	bool PlayCells::checkColor( Card card, int dest )
	{
		bool valid( false );

		if( mPlayCells[ dest ].isEmpty(  ) )
		{
			valid = true;
		}
		else if( ( ( card.GetSuit(  ) == card.HEART || 
				 card.GetSuit(  ) == card.DIAMOND ) &&
				 ( mPlayCells[ dest ].Peek(  ).GetSuit(  ) == card.SPADE ||
				 mPlayCells[ dest ].Peek(  ).GetSuit(  ) == card.CLUB ) ) )
		{
			valid = true;
		}
		else if( ( ( card.GetSuit(  ) == card.SPADE ||
				 card.GetSuit(  ) == card.CLUB ) &&
				 ( mPlayCells[ dest ].Peek(  ).GetSuit(  ) == card.HEART ||
				 mPlayCells[ dest ].Peek(  ).GetSuit(  ) == card.DIAMOND ) ) )
		{
			valid = true;
		}

		return valid;
	}

	/**********************************************************************
	*	bool PlayCells::checkRank( Card card, int dest )
	*
	*	   Purpose: Checks the rank of 'card' and determines if it can be
	*				placed on 'dest'.
	*
	*		 Entry:	'card' is some card, 'dest' is the stack to put this
	*				card on.
	*
	*		  Exit:	Whether or not 'card' can go on 'dest' is returned.
	*
	**********************************************************************/
	bool PlayCells::checkRank( Card card, int dest )
	{
		bool valid( false );
		Card blank;

		if( mPlayCells[ dest ].isEmpty(  ) )
		{
			valid = true;
		}
		else if( mPlayCells[ dest ].Peek(  ).GetRank(  ) == card.GetRank(  ) + 1 )
		{
			valid = true;
		}

		return valid;
	}

	/**********************************************************************
	*	bool PlayCells::checkStack( int start, int numCards )
	*
	*	   Purpose: Checks a stack for cohesiveness before moving.  (This 
	*				function got a little hack-y, validating a stack before
	*				moving will probably be where there are logic errors.)
	*
	*		 Entry:	'start' is the starting stack, and 'numCards' is the
	*				number of cards to move.  This unstacks them, verifies
	*				the stack is alternating colors and descending rank.
	*
	*		  Exit: Whether the stack can be moved is returned.
	*
	**********************************************************************/
	bool PlayCells::checkStack( int start, int numCards )
	{
		bool valid( false );
		LinkedStack< Card > temp;

		if( numCards == 1 )
		{
			valid = true;
		}
		else
		{
			int i( 0 );
			for( ; i < numCards && !valid; ++i )
			{
				temp.Push( mPlayCells[ start ].Pop(  ) );

				if( checkColor( temp.Peek(  ), start ) )
				{
					if( temp.Peek(  ).GetRank(  ) == mPlayCells[ start ].Peek(  ).GetRank(  ) - 1 )
						valid = true;
					else 
						valid = false;
				}
			}

			for( ; i > 0; --i )
				mPlayCells[ start ].Push( temp.Pop(  ) );
		}
		return valid;
	}

	/**********************************************************************
	*	void PlayCells::Display(  )
	*
	*	   Purpose: Displays the PlayCell object.
	*
	*		 Entry: 'this' is some PlayCell object.
	*
	*		  Exit:	'this' is displayed.
	*
	**********************************************************************/
	void PlayCells::Display(  )
	{
		Array< LinkedStack< Card > > displayTemp( 8 );
		
		
		for( int i( 0 ); i < 8; ++i )
		{
			while( !mPlayCells[ i ].isEmpty(  ) )
			{
				displayTemp[ i ].Push( mPlayCells[ i ].Pop(  ) );
			}
		}

		for( int i( 0 ); i < 8; ++i )
		{
			ChangeText( Black, LGrayBack );
			CursorToPosition( ( i + 2 ) * 7, 22 );
			cout << "   P" << ( i + 1 );
		}
		ChangeText(  );
		CursorToPosition(  );

		for( int i( 0 ); i < 8; ++i )
		{
			int row( 0 );
			while( !displayTemp[ i ].isEmpty(  ) )
			{
				mPlayCells[ i ].Push( displayTemp[ i ].Pop(  ).Display( ( i + 2 ) * 7, 23 + row ) );
				++row;
			}
		}
	}
