#include "FreeCells.h"

//
// Manager functions
//


	/**********************************************************************
	*	FreeCells::FreeCells(  )
	*
	*	   Purpose: Creates an instance of the FreeCells class.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	FreeCells::FreeCells(  ) :
						mFreeCells(  ), mFullCount( 0 )
	{ 
		mFreeCells.SetLength( 4 );
	}

	/**********************************************************************
	*	FreeCells::FreeCells( const FreeCells & copy )
	*
	*	   Purpose: Creates a FreeCells object that is a copy of an 
	*				existing FreeCells object.
	*
	*		 Entry:	'copy' is some existing FreeCells object.
	*
	*		  Exit:	'this' is now a replica of 'copy'.
	*
	**********************************************************************/
	FreeCells::FreeCells( const FreeCells & copy ) :
						mFreeCells( copy.mFreeCells ), mFullCount( copy.mFullCount )
	{  }

	/**********************************************************************
	*	FreeCells & FreeCells::operator=( const FreeCells & rhs )
	*
	*	   Purpose:	Overwrites one FreeCell object with the data of another.
	*
	*		 Entry:	'this' has unimportant data that will be overwritten,
	*				and 'rhs' is the source of the data.
	*
	*		  Exit:	'this' will be the same as 'rhs'.
	*
	**********************************************************************/
	FreeCells & FreeCells::operator=( const FreeCells & rhs ) 
	{
		if( this != &rhs )
		{
			mFreeCells = rhs.mFreeCells;
			mFullCount = rhs.mFullCount;
		}
		return * this;
	}

	/**********************************************************************
	*	FreeCells::~FreeCells(  )
	*
	*	   Purpose: Destroys a FreeCells object.
	*
	*		 Entry:	'this' is some object.
	*
	*		  Exit: 'this' is no longer an object.
	*
	**********************************************************************/
	FreeCells::~FreeCells(  )
	{  }

//
// Member functions
//

	/**********************************************************************
	*	void FreeCells::PutCard( Card store, int index )
	*
	*	   Purpose: Puts 'store' in the array element 'index' and increments
	*				the number of full cells.
	*
	*		 Entry:	'store' is some card.  'index' is the element to store
	*				it in.
	*
	*		  Exit:	'store' is stored in element 'index'.
	*
	**********************************************************************/	
	void FreeCells::PutCard( Card store, int index )
	{
		mFreeCells[ index ] = store;
		++mFullCount;
	}

	/**********************************************************************
	*	Card FreeCells::GetCard( int index )
	*
	*	   Purpose: Checks to see if a card is in a FreeCell, and if one is
	*				returns that card, deletes it from the array, and 
	*				decrements the number of full FreeCells.
	*
	*		 Entry:	'index' is the array element to get a card from.
	*
	*		  Exit:	Card at 'index' is returned.  If there is no card there
	*				the returned card is blank, and does nothing.
	*
	**********************************************************************/
	Card FreeCells::GetCard( int index )
	{
		Card toReturn;
		Card blank;

		if( mFreeCells[ index ].GetRank(  ) != toReturn.GetRank(  ) )
		{
			toReturn = mFreeCells[ index ];
			mFreeCells[ index ] = blank;
			--mFullCount;
		}

		return toReturn;
	}

	/**********************************************************************
	*	Card FreeCells::ViewCard( int index )
	*
	*	   Purpose: Returns the value of the card stored in element 'index'.
	*				Does not remove it from the array.
	*
	*		 Entry:	'index' is the element of the array with the card to
	*				look at.
	*
	*		  Exit:	The card at 'index' is returned.
	*
	**********************************************************************/
	Card FreeCells::ViewCard( int index )
	{
		return mFreeCells[ index ];
	}

	/**********************************************************************
	*	int FreeCells::GetFullCount(  )
	*
	*	   Purpose:	Returns the number of empty FreeCells.  (Yes, the name
	*				is backward, I just realized...)
	*
	*		 Entry:	'mFullCount' is some value between 0 and 4.
	*
	*		  Exit: 'mFullCount' is returned.
	*
	**********************************************************************/
	int FreeCells::GetFullCount(  )
	{
		return 4 - mFullCount;
	}

	/**********************************************************************
	*	bool FreeCells::isValid( int index )
	*
	*	   Purpose: Verifies that a card can be stored at 'index'.  In
	*				other words, checks to see if 'index' is empty.
	*
	*		 Entry: 'index' is the element to check.
	*
	*		  Exit:	'index' has been checked, and whether a card can be 
	*				stored there is returned.
	*
	**********************************************************************/
	bool FreeCells::isValid( int index )
	{
		bool valid( false );
		Card blank;

		if( mFullCount != 4 )
		{
			if( mFreeCells[ index ].GetRank(  ) == blank.GetRank(  ) )
			{
				valid = true;
			}
		}
		
		return valid;
	}

	/**********************************************************************
	*	void FreeCells::Display(  )
	*
	*	   Purpose: Displays the FreeCell object.
	*
	*		 Entry: 'this' is some FreeCell object.
	*
	*		  Exit:	'this' is displayed.
	*
	**********************************************************************/
	void FreeCells::Display(  )
	{
		Card blank;

		for( int i( 0 ); i < 4; ++i )
		{

			ChangeText( Black, LGrayBack );
			CursorToPosition( ( i + 1 ) * 7, 12 );
			cout << "   F" << ( i + 1 );

			if( mFreeCells[ i ].GetRank(  ) != blank.GetRank(  ) )
			{
				mFreeCells[ i ].Display( ( i + 1 ) * 7, 13 );
			}
		}
		CursorToPosition(  );
		ChangeText(  );
	}