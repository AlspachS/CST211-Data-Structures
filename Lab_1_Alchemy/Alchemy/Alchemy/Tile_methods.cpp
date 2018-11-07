#include "Tile.h"

//
// Manager functions
//

	/**********************************************************************
	*	Tile::Tile(  ) 
	*
	*	   Purpose: Creates a blank Tile to fill a board.
	*
	*		 Entry:	When a Tile is created.
	*
	*		  Exit:	When the Tile is created.
	*
	**********************************************************************/
	Tile::Tile(  ) :
				m_gold( false ), m_full( false ), m_background( DGrayBack ), m_stored(  )
	{  }

	/**********************************************************************
	*	Tile::Tile( const Tile & copy )
	*
	*	   Purpose:	Copies a tile to another tile.
	*
	*		 Entry:	When a tile is created as a copy of another tile.
	*
	*		  Exit:	After the new tile is created.
	*
	**********************************************************************/
	Tile::Tile( const Tile & copy ) :
				m_gold( copy.m_gold ), m_full( copy.m_full ),
				m_background( copy.m_background ), m_stored( copy.m_stored )
	{  }

	/**********************************************************************
	*	Tile & Tile::operator=( const Tile & rhs )
	*
	*	   Purpose:	Assigns a tile to another tile.
	*
	*		 Entry:	When a tile is assigned to another tile.
	*
	*		  Exit:	After the assignment happens
	*
	**********************************************************************/
	Tile & Tile::operator=( const Tile & rhs )
	{
		if( this != &rhs )
		{
			m_gold = rhs.m_gold;
			m_full = rhs.m_full;
			m_background = rhs.m_background;
			m_stored = rhs.m_stored;
		}
		return *this;
	}

	/**********************************************************************
	*	Tile::~Tile(  )
	*
	*	   Purpose:	Destroys a tile.
	*	
	*		 Entry: When a tile goes out of scope.
	*
	*		  Exit:	After the tile is destroyed.
	*
	**********************************************************************/
	Tile::~Tile(  )
	{  }

//
// Mutator methods
//

	/**********************************************************************
	*	void Tile::StoreSymbol( Symbol store )
	*	
	*	   Purpose: Stores a symbol in a tile.
	*
	*		 Entry:	When a symbol needs to be stored in a tile.
	*
	*		  Exit:	After the symbol is stored in a tile.
	*
	**********************************************************************/
	void Tile::StoreSymbol( Symbol store )
	{
		m_stored = store;
		m_gold = true;
		m_full = true;
	}

	/**********************************************************************
	*	void Tile::RemoveSymbol(  )
	*
	*	   Purpose: Removes a symbol from a tile.  Preserves "goldness".
	*
	*		 Entry:	When a symbol needs to be removed from a tile.
	*
	*		  Exit:	After the symbol is removed.
	*
	**********************************************************************/
	void Tile::RemoveSymbol(  )
	{
		Symbol blank;
		m_stored = blank;
		m_full = false;
	}

//
// Member functions
//

	/**********************************************************************
	*	void Tile::DisplayTile(  )
	*
	*	   Purpose:	Displays a tile.  The tile may have a gold background
	*				and a symbol.
	*
	*		 Entry:	When a tile needs to be displayed.
	*
	*		  Exit: After the tile is displayed.
	*
	**********************************************************************/
	void Tile::DisplayTile(  )
	{
		HANDLE handle = GetStdHandle( STD_OUTPUT_HANDLE );

		if( m_gold )
			m_background = GoldBack;

		if( !m_full )
			RemoveSymbol(  );

		SetConsoleTextAttribute( handle, m_stored.GetColor(  ) | m_background );
		cout << m_stored.GetSymbol(  );
		SetConsoleTextAttribute( handle, 7 );
		
	}

	/**********************************************************************
	*	bool Tile::isGold(  )
	*
	*	   Purpose: Returns whether a tile is gold, or not.
	*
	*		 Entry:	When it needs to be known if a tile is gold.
	*
	*		  Exit:	After the value of m_gold is returned.
	*
	**********************************************************************/
	bool Tile::isGold(  )
	{
		return m_gold;
	}

	/**********************************************************************
	*	bool Tile::isFull(  )
	*
	*	   Purpose: Returns whether a tile is full, or not.
	*
	*		 Entry:	When it needs to be known if a tile is full.
	*
	*		  Exit:	After the value of m_full is returned.
	*
	**********************************************************************/
	bool Tile::isFull(  )
	{
		return m_full;
	}

	/**********************************************************************
	*	Symbol Tile::GetSymbol(  )
	*
	*	   Purpose:	Returns the symbol stored in a tile.
	*
	*		 Entry:	When the symbol stored in a tile needs to be accessed.
	*
	*		  Exit:	After the symbol is returned.
	*
	**********************************************************************/
	Symbol Tile::GetSymbol(  )
	{
		return m_stored;
	}