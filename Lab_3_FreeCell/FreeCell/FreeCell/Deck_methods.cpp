#include "Deck.h"

// Constants
	const int Deck::DECK_MAX = 52;


// Statics
	Random Deck::Random;
	int Deck::m_dealt = 0;

//
// Manager Functions
//

	/**********************************************************************
	*	Deck::Deck(  )
	*
	*	  Purpose:  Creates a deck object and fills it with 52 cards.
	*
	*       Entry:  When a deck object is created.
	*
	*        Exit:  After all 52 cards are created.
	*
	**********************************************************************/
	Deck::Deck(  ) : m_current_card( 0 )
	{
		for( int suit( 0 ); suit < 4; suit++ )
		{
			for( int rank( 0 ); rank < 13; rank++ )
			{
				// Rank requires a +3 offset for ASCII suit characters
				m_deck[ suit * 13 + rank ].SetRank( static_cast< Card::Rank >( rank + 1 ) );
				m_deck[ suit * 13 + rank ].SetSuit( static_cast< Card::Suit >( suit + 3 ) ); 
			}
		}
		Shuffle(  );
	}
	
	/**********************************************************************
	*	Deck::Deck( const Deck & source )
	*
	*	  Purpose:  Copies one deck object into another deck object.  
	*				If a deck has been shuffled, the shuffled order is
	*				preserved.
	*
	*       Entry:  When one deck is copied into another deck.
	*
	*        Exit:  Once the copy is complete
	*
	**********************************************************************/
	Deck::Deck( const Deck & source ) : m_current_card( 0 )
	{
		cout << "Deck Copy Constructor.\n";

	//	m_deck = new Card*[ DECK_MAX ];

		for( int i( 0 ); i < DECK_MAX; i++ )
		{
			m_deck[ i ] =  source.m_deck[ i ];
		}
	}

	/**********************************************************************
	*	Deck & Deck::operator=( const Deck & source )
	*
	*	  Purpose:	Assigns one deck to another deck.  If the source deck
	*				is shuffled, the shuffled order is preserved.
	*
	*       Entry:  When one deck is assigned the value of a different
	*				deck.
	*
	*        Exit:  Once the assignment has finished.
	*
	**********************************************************************/
	Deck & Deck::operator=( const Deck & source )
	{
		cout << "Operator Equals.\n";

		if( this != &source )
		{
		//	m_deck = new Card*[ DECK_MAX ];

			for( int i( 0 ); i < DECK_MAX; i++ )
			{
				m_deck[ i ] = source.m_deck[ i ];
			}
		}
		this->m_current_card = source.m_current_card;
		return *this;
	}
	
	/**********************************************************************
	*	Deck::~Deck(  )
	*
	*	  Purpose:	Deck destructor.
	*
	*       Entry:  When a deck object goes out of scope.
	*
	*        Exit:  Once the deck object has been destroyed.
	*
	**********************************************************************/
	Deck::~Deck(  ) {  }

//	
// Static Methods
//

	/**********************************************************************
	*	void Deck::NumberDealt(  )
	*
	*	  Purpose:	Returns the value in the static variable m_dealt.
	*
	*       Entry:  Called when the number of cards that have been dealt
	*				needs to be known.
	*
	*        Exit:  Once m_dealt has been displayed.
	*
	**********************************************************************/
	void Deck::NumberDealt(  )
	{
		cout << "The current number of cards dealt is " << m_dealt << ".\n";
	}

//
// Methods
//

	/**********************************************************************
	*	void Deck::Shuffle(  )
	*
	*	  Purpose:	Shuffles the cards in a deck to create a random draw
	*				order.  Also sets m_dealt and m_current_card to zero.
	*
	*       Entry:  Called when the deck needs to be shuffled.  Usually
	*				after a deck has been created, or after the last card
	*				has been dealt.
	*
	*        Exit:  After the cards have all been shuffled.
	*
	**********************************************************************/
	void Deck::Shuffle(  )
	{
		Card temp;
		int number( 0 );

		m_current_card = 0;
		m_dealt = 0;

		for( int cur( 0 ); cur < DECK_MAX; cur++ )
		{
			number = Random.GetRandom( DECK_MAX );  
			temp = m_deck[ cur ];
			m_deck[ cur ] = m_deck[ number ];
			m_deck[ number ] = temp;
		}
	}
  
	/**********************************************************************
	*	Card Deck::Deal(  )
	*
	*	  Purpose:	Deals the card with the index of m_current_card - 1.
	*				The minus one is to offset the incrementing that must
	*				happen before the return statement.
	*
	*       Entry:  When a card needs to be dealt from the deck.
	*
	*        Exit:  After the card has been dealt.
	*
	**********************************************************************/
	Card Deck::Deal(  )
	{
		m_current_card++;
		m_dealt++;

		if( m_current_card - 1 > 51)
		{
			cout << "The last card has been dealt.\n";
			cout << "The deck will now be shuffled\n";
			cout << "and the top card will be dealt.\n";
			Shuffle(  );
			Deal(  );
		}
		return m_deck[ m_current_card - 1 ];
	}