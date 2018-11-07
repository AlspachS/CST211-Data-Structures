/***********************************************************************
* Class: Class Name
*
*		Description...
*
* Constructors:
*
*	  Mutators:
*
*	   Methods:
*
***********************************************************************/
#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "Row.h"

#include "Exception.h"

template< typename T >
class Array2D
{
	public:

	// Manager functions

		// No argument constructor
		Array2D(  );

		// Two argument constructor
		Array2D( int row, int col = 0 );

		// Copy constructor
		Array2D( const Array2D< T > & copy );

		// Copy constructor
		Array2D< T > & operator=( const Array2D< T > & rhs );

		// Destructor
		~Array2D(  );

	// Operator overloads

		// Subscript operator, const version
		const Row< T > operator[]( int index ) const;

		// Subscript operator
		Row< T > operator[]( int index );

	// Accessor methods

		// m_row accessor
		int getRow(  ) const;

		// m_col accessor
		int getColumn(  ) const;

	// Mutator methods

		// m_row mutator
		void setRow( int row );

		// m_col mutator
		void setColumn( int col );

	// Member functions

		// References a cell of the array
		T & Select( int row, int col );

		const T & Select( int row, int col ) const;


	private:
		T ** m_array;			// Pointer treated as a 2D array
		int m_row;				// Number of rows in the array
		int m_col;				// Number of columns in the array

};
#endif

	/**********************************************************************
	*	Array2D< T >::Array2D(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array2D< T >::Array2D(  ) : 
							m_array( nullptr ), m_row( 0 ), m_col( 0 )
	{  }


	/**********************************************************************
	*	Array2D< T >::Array2D( int row, int col )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array2D< T >::Array2D( int row, int col ) :
							m_array( nullptr ), m_row( row ), m_col( col )
 	{ 
		if( m_row < 0 )
			throw Exception( "ERROR:  Invalid row length" );
		if( m_col < 0 )
			throw Exception( "ERROR:  Invalid column length" );

		m_array = new T * [ m_row ];
		for( int i( 0 ); i < m_row; ++i )
			m_array[ i ] = new T[ m_col ];
	}


	/**********************************************************************
	*	Array2D< T >::Array2D( const Array2D & copy )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array2D< T >::Array2D( const Array2D & copy ) : 
							m_array( nullptr ), m_row( copy.m_row ), m_col( copy.m_col )
	{  
		m_array = new T * [ m_row ];
		for( int i( 0 ); i < m_row; ++i )
			m_array[ i ] = new T[ m_col ];

		*this = copy;
	}


	/**********************************************************************
	*	Array2D< T > & Array2D< T >::operator=( const Array2D & rhs )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array2D< T > & Array2D< T >::operator=( const Array2D & rhs )
	{ 
		if( this != &rhs )
		{
			if( m_row != rhs.m_row && m_col != rhs.m_col )
			{
				for( int i( 0 ); i < m_row; ++i )
				{
					delete [  ] m_array[ i ];
					m_array[ i ] = nullptr;
				}
				delete [  ] m_array;
				m_array = nullptr;

				m_array = new T * [ rhs.m_row ];
				for( int i( 0 ); i < rhs.m_row; ++i )
					m_array[ i ] = new T[ rhs.m_col ];
			}
		
			for( int i( 0 ); i < rhs.m_row; ++i )
			{
				for( int j( 0 ); j < rhs.m_col; ++j )
				{
					m_array[ i ][ j ] = rhs.m_array[ i ][ j ];
				}
			}
			m_col = rhs.m_col;
			m_row = rhs.m_row;
		}
		return *this;
	}


	/**********************************************************************
	*	Array2D< T >::~Array2D(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array2D< T >::~Array2D(  )
	{ 
		for( int i ( 0 ); i < m_row; ++i )
		{
			delete [  ] m_array[ i ];
			m_array[ i ] = nullptr;
		}
		delete [  ] m_array;
		m_array = nullptr;

		m_row = 0;
		m_col = 0;
	}


	/**********************************************************************
	*	const Row< T > Array2D< T >::operator[]( int index ) const
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	const Row< T > Array2D< T >::operator[]( int index ) const
	{
		if( index < 0 )
			throw Exception ( "ERROR:  Index value below lower bound" );
		else if( index > m_row - 1 )
			throw Exception ( "ERROR:  Index value above upper bound" );
		
		return Row< T > ( *this, index );
	}


	/**********************************************************************
	*	Row< T > Array2D< T >::operator[]( int index )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Row< T > Array2D< T >::operator[]( int index )
	{
		if( index < 0 )
			throw Exception ( "ERROR:  Index value below lower bound" );
		else if( index > m_row - 1 )
			throw Exception ( "ERROR:  Index value above upper bound" );

		return Row< T > ( *this, index );
	}


	/**********************************************************************
	*	int Array2D< T >::getRow(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	int Array2D< T >::getRow(  ) const
	{ 
		return m_row;
	}


	/**********************************************************************
	*	int Array2D< T >::getColumn(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	int Array2D< T >::getColumn(  ) const
	{ 
		return m_col;
	}


	/**********************************************************************
	*	void Array2D< T >::setRow( int row )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void Array2D< T >::setRow( int row )
	{ 
		if( row < 0 )
			throw Exception( "ERROR:  Invalid row length" );

		int smaller = m_row < row ? m_row : row;
		T ** temp = nullptr;

		temp = new T * [ row ];
		for( int i( 0 ); i < row; ++i )
			temp[ i ] = new T [ m_col ];

		for( int i( 0 ); i < smaller; ++i )
		{
			for( int j( 0 ); j < m_col; ++j )
			{
				temp[ i ][ j ] = m_array[ i ][ j ];
			}
		}

		for( int i( 0 ); i < m_row; ++i )
		{
			delete [  ] m_array[ i ];
			m_array[ i ] = nullptr;
		}
		delete [  ] m_array;
		m_array = nullptr;

		m_array = temp;
		m_row = row;
	}


	/**********************************************************************
	*	void Array2D< T >::setColumn( int col )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void Array2D< T >::setColumn( int col )
	{ 
		if( col < 0 )
			throw Exception( "ERROR:  Invalid column length" );

		int smaller = m_col < col ? m_col : col;
		T ** temp = nullptr;

		temp = new T * [ m_row ];
		for( int i( 0 ); i < m_row; ++i )
			temp[ i ] = new T [ col ];

		for( int i( 0 ); i < m_row; ++i )
		{
			for( int j( 0 ); j < smaller; ++j )
			{
				temp[ i ][ j ] = m_array[ i ][ j ];
			}
		}

		for( int i( 0 ); i < m_row; ++i )
		{
			delete [  ] m_array[ i ];
			m_array[ i ] = nullptr;
		}
		delete [  ] m_array;
		m_array = nullptr;

		m_array = temp;		
		m_col = col;
	}


	/**********************************************************************
	*	T & Array2D< T >::Select( int row, int col )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	T & Array2D< T >::Select( int row, int col )
	{ 
		if( row < 0 )
			throw Exception( "ERROR:  Row value below lower bound" );
		else if( col < 0 )
			throw Exception( "ERROR:  Column value below lower bound" );
		else if( row > m_row - 1 )
			throw Exception( "ERROR:  Row value above upper bound" );
		else if( col > m_col - 1 )
			throw Exception( "ERROR:  Column value above upper bound" );

		return m_array[ row ][ col ];
	}


	/**********************************************************************
	*	T & Array2D< T >::Select( int row, int col )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	const T & Array2D< T >::Select( int row, int col )  const
	{ 
		if( row < 0 )
			throw Exception( "ERROR:  Row value below lower bound" );
		else if( col < 0 )
			throw Exception( "ERROR:  Column value below lower bound" );
		else if( row > m_row - 1 )
			throw Exception( "ERROR:  Row value above upper bound" );
		else if( col > m_col - 1 )
			throw Exception( "ERROR:  Column value above upper bound" );

		return m_array[ row ][ col ];
	}