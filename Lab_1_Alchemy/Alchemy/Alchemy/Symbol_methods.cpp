#include "Symbol.h"

//
// Manager functions
//
	
	/**********************************************************************
	*	Symbol::Symbol(  )
	*
	*	   Purpose: Creates a default symbol to store in a tile.
	*
	*		 Entry: Called initially when the board is created.
	*
	*		  Exit: After all the tiles are "filled" with symbols.
	*
	**********************************************************************/
	Symbol::Symbol(  ) :
					m_symbol( ALL_SYMBOLS[ 9 ] ), m_color( ALL_COLORS[ 7 ] )
	{  }

	/**********************************************************************
	*	Symbol::Symbol( int symbol, int color )
	*
	*	   Purpose:	Creates a specific tile.  This is used to access the
	*				special characters and colors for the freespace block 
	*				and the solvent.
	*
	*		 Entry: Used when the Alchemy class determines that a special
	*				character has been created.
	*
	*		  Exit:	After the special character has been created.
	*
	**********************************************************************/
	Symbol::Symbol( int symbol, int color ) :
					m_symbol( ALL_SYMBOLS[ symbol ] ), m_color( ALL_COLORS[ color ] )
	{  }

	/**********************************************************************
	*	Symbol::Symbol( Symbols symbol, Colors color )
	*
	*	   Purpose:	Creates a normal symbol with the values of 'symbol' and
	*				'color'.
	*
	*		 Entry:	When the Alchemy class has determined that a normal
	*				tile has been created.
	*
	*		  Exit:	After the normal character is created.
	*
	**********************************************************************/
	Symbol::Symbol( Symbols symbol, Colors color ) :
					m_symbol( ALL_SYMBOLS[ symbol ] ), m_color( ALL_COLORS[ color ] )
	{  }

	/**********************************************************************
	*	Symbol::Symbol( const Symbol & copy )
	*
	*	   Purpose: Copies one Symbol to another.
	*
	*		 Entry:	Called when a Symbol is initialized with another symbol.
	*
	*		  Exit:	After the new Symbol is created.
	*
	**********************************************************************/
	Symbol::Symbol( const Symbol & copy ) :
					m_symbol( copy.m_symbol ), m_color( copy.m_color )
	{  }

	/**********************************************************************
	*	Symbol & Symbol::operator=( const Symbol & rhs )
	*
	*	   Purpose: Assigns one Symbol to another.
	*
	*		 Entry:	Called when one symbol needs to be equal to another.
	*
	*		  Exit: After the assignment is finished.
	*
	**********************************************************************/
	Symbol & Symbol::operator=( const Symbol & rhs )
	{
		if( this != &rhs )
		{
			m_symbol = rhs.m_symbol;
			m_color = rhs.m_color;
		}
		return *this;
	}

	/**********************************************************************
	*	Symbol::~Symbol(  )
	*
	*	   Purpose:	Destroys a Symbol object.
	*
	*		 Entry:	When a symbol goes out of scope.
	*
	*		  Exit:	After the symbol is destroyed.
	*
	**********************************************************************/
	Symbol::~Symbol(  )
	{  }

//
// Accessor methods
//

	/**********************************************************************
	*	char Symbol::GetSymbol(  )
	*
	*	   Purpose: Returns the character in the Symbol.
	*
	*		 Entry:	When the Symbol's character needs to be known.
	*
	*		  Exit: After the Symbol's character is returned.
	*
	**********************************************************************/
	char Symbol::GetSymbol(  )
	{
		return m_symbol;
	}

	/**********************************************************************
	*	int Symbol::GetColor(  )
	*
	*	   Purpose: Returns the color in the Symbol.
	*
	*		 Entry:	When the Symbol's color needs to be known.
	*
	*		  Exit:	After the Symbol's color is returned.
	*
	**********************************************************************/
	int Symbol::GetColor(  )
	{
		return m_color;
	}

//
// Mutator methods
//

	/**********************************************************************
	*	void Symbol::SetSymbol( char symbol )
	*
	*	   Purpose: Changes the character stored in the Symbol.
	*
	*		 Entry:	When the Symbol's character needs to be changed.
	*
	*		  Exit:	After the Symbol's character is changed.
	*
	**********************************************************************/
	void Symbol::SetSymbol( char symbol )
	{
		m_symbol = symbol;
	}

	/**********************************************************************
	*	void Symbol::SetColor( int color )
	*
	*	   Purpose:	Changes the color stored in the Symbol.
	*
	*		 Entry:	When the Symbol's color needs to be changed.
	*
	*		  Exit:	After the Symbol's color is changed.
	*
	**********************************************************************/
	void Symbol::SetColor( int color )
	{
		m_color = color;
	}

//
// Member functions
//

	/**********************************************************************
	*	void Symbol::Display(  )
	*
	*	   Purpose:	Displays the Symbol on a Dark Gray background, which
	*				is the same color as an empty tile.
	*
	*		 Entry:	After a symbol has been generated and it needs to be
	*				displayed for the user to play.
	*
	*		  Exit:	After the Symbol is displayed.
	*
	**********************************************************************/
	void Symbol::Display(  )
	{
		HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );
		
		SetConsoleTextAttribute( handle, m_color | DGrayBack );
		cout << m_symbol;
		SetConsoleTextAttribute( handle, 7 );

	}

	/**********************************************************************
	*	Symbol Symbol::GenerateSymbol( int level, Random rand )
	*
	*	   Purpose: Creates a random Symbol.
	*
	*		 Entry:	When the Alchemy class has determined that a normal
	*				Symbol needs to be created.
	*
	*		  Exit:	After the normal Symbol is generated.
	*
	**********************************************************************/
	Symbol Symbol::GenerateSymbol( int level, Random rand )
	{
		return Symbol( static_cast< Symbols >( rand.GetRandom(  ) % ( 5 + level ) ),
					   static_cast< Colors >( rand.GetRandom(  ) % ( 5 + level ) ) );
	}

