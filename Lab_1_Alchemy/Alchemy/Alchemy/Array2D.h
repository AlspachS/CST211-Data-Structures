/***********************************************************************
* 	 Class: Array2D
* Filename: Array2D.h
*
*		An implementation of a two-dimensional array.
*
* Constructors:
*			Array2D(  );
*				Creates default Array2D object. 'm_array', 'm_row', and
*				'm_col' are set to default values.
*				
*			Array2D( int row, int col = 0 );
*				Creates an Array2D with 'row' rows, and 'col' columns.
*
*	  Mutators:
*			void setRow( int row );
*				Changes the number of rows in the array.
*				DATA CAN BE LOST!
*	
*			void setColumn( int col );
*				Changes the number of columns in the array.
*				DATA CAN BE LOST!
*
*	   Methods:
*			int getRow(  ) const;
*				Returns the number of rows in the Array2D object.
*
*			int getColumn(  ) const:
*				Returns the number of columns in the Array2D object.
*
*			T & Select( int row, int col );
*				Uses fancy math to access a specific cell in the 
*				Array2D object.
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
	*	   Purpose: Creates a default Array2D object, with a default size
	*				of zero elements.
	*
	*		 Entry: This constructor can be called at any time.
	*
	*		  Exit:	After the Array2D object is created and set with 
	*				default values.
	*
	**********************************************************************/
	template< typename T >
	Array2D< T >::Array2D(  ) : 
							m_array(  ), m_row( 0 ), m_col( 0 )
	{  }


	/**********************************************************************
	*	Array2D< T >::Array2D( int row, int col )
	*
	*	   Purpose: Creates an Array2D object with 'row' number of rows and
	*				'col' number of columns.  'col' has a default value of 
	*				zero.  
	*
	*		 Entry: Called when an Array2D object is called with a row 
	*				value (and a col value) are specified.
	*
	*		  Exit:	After the Array2D object is created and all data 
	*				members are set to the specified values
	*
	**********************************************************************/
	template< typename T >
	Array2D< T >::Array2D( int row, int col ) :
							m_array( row * col ), m_row( row ), m_col( col )
 	{  }


	/**********************************************************************
	*	Array2D< T >::Array2D( const Array2D & copy )
	*
	*	   Purpose: Copies one Array2D object into another upon the first
	*				Array2D object's creation.  Also used for passing or
	*				receiving an Array2D object by value.
	*
	*		 Entry: When a copy of an existing Array2D object is created.
	*
	*		  Exit:	After the copy has been created.
	*
	**********************************************************************/
	template< typename T >
	Array2D< T >::Array2D( const Array2D & copy ) : 
							m_array( copy.m_array ), m_row( copy.m_row ), m_col( copy.m_col )
	{  }


	/**********************************************************************
	*	Array2D< T > & Array2D< T >::operator=( const Array2D & rhs )
	*
	*	   Purpose: Used to assign one Array2D object to another Array2D 
	*				object.
	*
	*		 Entry: Used when the assignment operator is called.
	*
	*		  Exit: After the left-hand Array2D object is overwritten with
	*				the right-hand Array2D object.
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
	*	   Purpose: Deletes an Array2D object when one goes out of scope.
	*
	*		 Entry:	Called when an Array2D object goes out of scope or is
	*				deleted.
	*
	*		  Exit:	After the Array2D object is deleted.
	*
	**********************************************************************/
	template< typename T >
	Array2D< T >::~Array2D(  )
	{  }


	/**********************************************************************
	*	const Row< T > Array2D< T >::operator[]( int index ) const
	*
	*	   Purpose:	Used to access an element of the Array2D object with
	*				Array2D[ row ][ col ] syntax.  Returns a Row object
	*				which is the 'm_array' in one-dimensional form.  The
	*				index becomes the Row objects 'm_row' which is used to
	*				access a specific row of the Array2D in the Row object's
	*				overloaded operator[].
	*				This is a const version of the operator[] for use with
	*				constant objects.
	*
	*		 Entry:	Used when access a row of the Array2D object.
	*
	*		  Exit:	After the Row object is created and returned.
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
	*	   Purpose:	Used to access an element of the Array2D object with
	*				Array2D[ row ][ col ] syntax.  Returns a Row object
	*				which is the 'm_array' in one-dimensional form.  The
	*				index becomes the Row objects 'm_row' which is used to
	*				access a specific row of the Array2D in the Row object's
	*				overloaded operator[].
	*
	*		 Entry:	Used when access a row of the Array2D object.
	*
	*		  Exit:	After the Row object is created and returned.
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
	*	   Purpose: Returns the number of rows in the Array2D object.
	*
	*		 Entry:	Called when the number of rows in the Array2D object
	*				needs to be known.
	*
	*		  Exit: After the number of rows in the array is returned.
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
	*	   Purpose: Returns the number of columns in the Array2D object.
	*
	*		 Entry:	Called when the number of columns in the Array2D object
	*				needs to be known.
	*
	*		  Exit: After the number of columns in the array is returned.
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
	*	   Purpose: Changes the number rows in the Array2D object.  This 
	*				can be to a value that is larger or smaller than the 
	*				current number of rows.  If the value is smaller than
	*				the current number of rows, loss of data can occur.
	*
	*		 Entry:	Called when the user wants to resize the Array2D
	*				object.
	*
	*		  Exit:	After the Array2D object is resized.
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
	*	   Purpose: Changes the number columns in the Array2D object.  
	*				This can be to a value that is larger or smaller than 
	*				the current number of rows.  If the value is smaller 
	*				than the current number of columns, loss of data can 
	*				occur.
	*
	*		 Entry:	Called when the user wants to resize the Array2D
	*				object.
	*
	*		  Exit:	After the Array2D object is resized.
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
	*	   Purpose: Used to access a specific element in the Array2D object
	*
	*		 Entry: Called when an element needs to be accessed.
	*
	*		  Exit:	After a reference to the array element is returned.
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