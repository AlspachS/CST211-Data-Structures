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

#include "Array.h"
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

	private:
		Array< T > m_array;		// Array object treated as a 2D array
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
							m_array(  ), m_row( 0 ), m_col( 0 )
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
							m_array( row * col ), m_row( row ), m_col( col )
 	{  }


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
							m_array( copy.m_array ), m_row( copy.m_row ), m_col( copy.m_col )
	{  }


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
			m_array = rhs.m_array;
			m_row = rhs.m_row;
			m_col = rhs.m_col;
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
	{  }


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

		m_array.SetLength( m_col * row );
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

		Array< T > temp( m_row * col );
		int smaller = m_col < col ? m_col : col;

		for( int i( 0 ); i < m_row; ++i )
		{
			for( int j( 0 ); j < smaller; ++j )
			{
				temp[ col * i + j ] = m_array[ m_col * i + j ];
			}
		}

		m_array.SetLength( m_row * col );

		for( int i( 0 ); i < m_row * col; ++i )
		{
			 m_array[ i ] = temp[ i ];
		}
		
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
		else if( col > m_col -1 )
			throw Exception( "ERROR:  Column value above upper bound" );

		return m_array[ row * m_col + col ];
	}