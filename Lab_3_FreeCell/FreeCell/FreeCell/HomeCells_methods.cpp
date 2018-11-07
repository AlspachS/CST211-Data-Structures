#include "HomeCells.h"

//
// Manager functions
//

	/**********************************************************************
	*	HomeCells::HomeCells(  )
	*
	*	   Purpose: Creates an instance of the HomeCells class.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	HomeCells::HomeCells(  ) :
						mHomeCells( 4 ), mTotalCards( 0 )
	{
		for( int i( 0 ); i < 4; ++i )
		{
			mHomeCells[ i ].Resize( 13 );
		}
	}

	/**********************************************************************
	*	HomeCells::HomeCells( const HomeCells & copy )
	*
	*	   Purpose: Creates a HomeCells object that is a copy of an 
	*				existing HomeCells object.
	*
	*		 Entry:	'copy' is some existing HomeCells object.
	*
	*		  Exit:	'this' is now a replica of 'copy'.
	*
	**********************************************************************/

	HomeCells::HomeCells( const HomeCells & copy ) :
						mHomeCells( copy.mHomeCells ), mTotalCards( copy.mTotalCards )
	{  }

	/**********************************************************************
	*	HomeCells & HomeCells::operator=( const HomeCells & rhs )
	*
	*	   Purpose:	Overwrites one HomeCell object with the data of another.
	*
	*		 Entry:	'this' has unimportant data that will be overwritten,
	*				and 'rhs' is the source of the data.
	*
	*		  Exit:	'this' will be the same as 'rhs'.
	*
	**********************************************************************/
	HomeCells & HomeCells::operator=( const HomeCells & rhs )
	{
		if( this != &rhs )
		{
			mHomeCells = rhs.mHomeCells;
			mTotalCards = rhs.mTotalCards;
		}
		return * this;
	}

	/**********************************************************************
	*	HomeCells::~HomeCells(  )
	*
	*	   Purpose: Destroys a HomeCells object.
	*
	*		 Entry:	'this' is some object.
	*
	*		  Exit: 'this' is no longer an object.
	*
	**********************************************************************/
	HomeCells::~HomeCells(  )
	{  }

//
// Member functions
//

	/**********************************************************************
	*	int HomeCells::GetTotalCards(  )
	*
	*	   Purpose: Returns the total number of cards in the HomeCells 
	*				area.
	*
	*		 Entry:	'mTotalCards' is some value corresponding to the number
	*				of cards moved into the HomeCells thus far.
	*
	*		  Exit:	The value of 'mTotalCards' is returned.
	*
	**********************************************************************/
	int HomeCells::GetTotalCards(  )
	{
		return mTotalCards;
	}

	/**********************************************************************
	*	void HomeCells::MoveUp( Card card, int index )
	*
	*	   Purpose: Moves 'card' from some other area to the HomeCells
	*				area, placing it on 'index'.
	*
	*		 Entry: 'card' is some card value, and 'index' is the stack to
	*				place the card on.
	*
	*		  Exit:	'card' is placed on 'index', making it the top card.
	*
	**********************************************************************/
	void HomeCells::MoveUp( Card card, int index )
	{
		mHomeCells[ index ].Push( card );
		++mTotalCards;
	}

	/**********************************************************************
	*	bool HomeCells::isValid( Card card, int index )
	*	
	*	   Purpose: Checks rank and suit of 'card' to see if it can be
	*				placed on 'index'.
	*
	*		 Entry:	'card' is some card, and 'index' is the stack to place
	*				'card' on.
	*
	*		  Exit: Whether or not 'card' can be placed on 'index' is 
	*				returned.
	*
	**********************************************************************/
	bool HomeCells::isValid( Card card, int index )
	{
		return( checkSuit( card, index ) && checkRank( card, index ) );
	}

	/**********************************************************************
	*	bool HomeCells::checkSuit( Card card, int index )
	*
	*	   Purpose: Checks the suit of 'card' against the card it's going
	*				to be placed on.
	*
	*		 Entry:	'card' is some card, 'index' is the stack to put this
	*				card on.
	*
	*		  Exit:	Whether or not 'card' can go on 'index' is returned.
	*
	**********************************************************************/
	bool HomeCells::checkSuit( Card card, int index )
	{
		Card blank;
		bool valid( false );


		if( mHomeCells[ index ].isEmpty(  ) )
		{
			valid = true;
		}
		else if( !mHomeCells[ index ].isEmpty(  ) &&
				 mHomeCells[ index ].Peek(  ).GetSuit(  ) == card.GetSuit(  ) )
		{
			valid = true;
		}

		
		return valid;
	}

	/**********************************************************************
	*	bool HomeCells::checkRank( Card card, int dest )
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
	bool HomeCells::checkRank( Card card, int index )
	{
		Card blank;
		bool valid( false );

		if( mHomeCells[ index ].isEmpty(  ) &&
				 card.GetRank(  ) == blank.ACE )
		{
			valid = true;
		}
		else if( !mHomeCells[ index ].isEmpty(  ) && 
				 mHomeCells[ index ].Peek(  ).GetRank(  ) == card.GetRank(  ) - 1 )
		{
			valid = true;
		}
		
		return valid;
	}

	/**********************************************************************
	*	void HomeCells::Display(  )
	*
	*	   Purpose: Displays the HomeCell object.
	*
	*		 Entry: 'this' is some HomeCell object.
	*
	*		  Exit:	'this' is displayed.
	*
	**********************************************************************/
	void HomeCells::Display(  )
	{
		Card blank;

		for( int i( 0 ); i < 4; ++i )
		{
			ChangeText( Black, LGrayBack );
			CursorToPosition( ( i + 7 ) * 7, 12 );
			cout << "   H" << ( i + 1 );

			if( !mHomeCells[ i ].isEmpty(  ) )
			{
				mHomeCells[ i ].Peek(  ).Display( ( i + 7 ) * 7, 13 );
			}
		}
		ChangeText(  );
		CursorToPosition(  );
	}