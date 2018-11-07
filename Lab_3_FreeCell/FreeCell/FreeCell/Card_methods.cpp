#include "Card.h"
//#include <Windows.h>


//
// Manager Functions
//

	/**********************************************************************
	*	Card::Card( Rank rank, Suit suit )
	*
	*	  Purpose:	Creates a card object with a rank and suit value.  If no
	*			 	arguments are received, the default value for the card
	*				is "Ace" and "Spade"
	*
	*       Entry:  Upon creating a card object.
	*
	*        Exit:  The card object is successfully created.
	*
	**********************************************************************/
	Card::Card( Rank rank, Suit suit ) : m_rank( rank ), m_suit( suit ) 
	{  }


	/**********************************************************************
	*	Card::~Card(  )
	*
	*	  Purpose:	Card destructor.
	*
	*       Entry:  A card object is destroyed.
	*
	*        Exit:  The card object is successfully destroyed.
	*
	**********************************************************************/
	Card::~Card(  ) {  }

//
// Member Functions
//

	/**********************************************************************
	*	void Card::Display(  )
	*
	*	  Purpose:	Formats the output stream so that the Rank has five
	*				columns and makes sure the Rank is left-aligned, this 
	*				is done so the Suit symbols of each card align to the
	*				same column.
	*
	*       Entry:  When a Card object's value wants to be known. 
	*
	*        Exit:  The card was displayed successfully.
	*
	**********************************************************************/
	Card Card::Display( int x, int y )
	{
		const char rank_txt[ 13 ] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
		
		HANDLE wHand = GetStdHandle( STD_OUTPUT_HANDLE );
		COORD start = { 0, 0 };
		COORD cardBufferSize = { 5, 5 };
		SMALL_RECT area = { x, y, x + 4, y + 4 };
		CHAR_INFO * cardBuffer = new CHAR_INFO[ 5 * 5 ];

		if( m_suit == CLUB || m_suit == SPADE )
		{
			cardBuffer[ 0 ].Attributes = Black | WhiteBack;
			cardBuffer[ 1 ].Attributes = Black | WhiteBack;
			cardBuffer[ 23 ].Attributes = Black | WhiteBack;
			cardBuffer[ 24 ].Attributes = Black | WhiteBack;
		}
		else
		{
			cardBuffer[ 0 ].Attributes = LRed | WhiteBack;
			cardBuffer[ 1 ].Attributes = LRed | WhiteBack;
			cardBuffer[ 23 ].Attributes = LRed | WhiteBack;
			cardBuffer[ 24 ].Attributes = LRed | WhiteBack;
		}

		cardBuffer[ 0 ].Char.AsciiChar = rank_txt[ m_rank - 1 ];
		cardBuffer[ 1 ].Char.AsciiChar = static_cast< char >( m_suit );
		for( int i( 2 ); i <= 22; ++i )
		{
			cardBuffer[ i ].Char.AsciiChar = ' ';
			cardBuffer[ i ].Attributes = WhiteBack;
		}
		cardBuffer[ 23 ].Char.AsciiChar = static_cast< char >( m_suit );
		cardBuffer[ 24 ].Char.AsciiChar = rank_txt[ m_rank - 1 ];

		WriteConsoleOutputA( wHand, cardBuffer, cardBufferSize, start, &area );

		delete [  ] cardBuffer;
		ChangeText(  );
		
		return *this;
	}


	/**********************************************************************
	*	void Card::SetRank( Rank rank )
	*
	*	  Purpose:	Allows the changing of a cards numerical value.
	*
	*       Entry:  When someone wants to cheat.
	*
	*        Exit:  After the person successfully cheated.
	*
	**********************************************************************/
	void Card::SetRank( Rank rank )
	{
		m_rank = rank;
	}


	/**********************************************************************
	*	void Card::SetSuit( Suit suit )
	*
	*	  Purpose:	Allows a cards suit value to be changed.
	*
	*       Entry:  When someone wants to cheat again.
	*
	*        Exit:  After the cheating has successfully finished.
	*
	**********************************************************************/
	void Card::SetSuit( Suit suit )
	{
		m_suit = suit;
	}


	/**********************************************************************
	*	Card::Rank Card::GetRank(  )
	*
	*	  Purpose:  Returns the integer value of a card's Rank.
	*
	*       Entry:  When a card's face value must be known.
	*
	*        Exit:  After the card's value was returned.
	*
	**********************************************************************/
	Card::Rank Card::GetRank(  ) const
	{
		return m_rank;
	}


	/**********************************************************************
	*	Card::Suit Card::GetSuit(  )
	*
	*	  Purpose: Returns the integer value of a card's suit. Suit values
	*			   range from 3 to 6 in the order of hearts, diamonds, 
	*			   clubs, spades.
	*
	*       Entry: When a card's suit must be known.
	*
	*        Exit: After the card's suit value was returned.
	*
	**********************************************************************/
	Card::Suit Card::GetSuit(  ) const
	{
		return m_suit;
	}