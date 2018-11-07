/***********************************************************************
*    Class: Row
* Filename: Row.h
*
*		Used in conjunction with the Array2D class to achieve expected
*		syntax (behavior).
*
* Constructors:
*			Row( Array2D< T > &array, int row );
*				Creates a Row object with a reference to an Array2D 
*				object.  'row' is the row of the Array2D the user 
*				wishes to access.
*
*	  Mutators:
*			No mutators available for this class.
*
*	   Methods:
*			const T & operator[]( int col ) const;
*				Used to access a specific element of the Row object.
*				This is a const version to use with constant objects.
*				
*			T & operator[]( int col );
*				Used to access a specific element of the Row object.
*
***********************************************************************/
#ifndef ROW_H
#define ROW_H

template< typename T > class Array2D;

template< typename T >
class Row
{

	public:

	// Manager functions

		// Two argument constructor
		Row( Array2D< T > &array, int row );

		// Copy constructor
		Row( const Array2D< T > &array, int row );

	// Operator overloads

		// Subscript operator, const version
		const T & operator[]( int col ) const;

		// Subscript operator
		T & operator[]( int col );

	private:
		Array2D< T > & m_array2D;		// A reference to an Array2D object
		int m_row;						// The row the user wants to access
};
#endif

//
// Manager functions
//
	
	/**********************************************************************
	*	Row< T >::Row( const Array2D< T > &array, int row )
	*
	*	   Purpose: Creates a Row object that is a reference to an Array2D
	*				object.  This is done in order to have a second
	*				subscript operator so the syntax Array2D[ row ][ col ]
	*				can be used.  The const_cast is so this can be used on
	*				constant Array2D objects as well.
	*
	*		 Entry:	Called when the subscript operators of the Array2D
	*				class are used.
	*
	*		  Exit:	After the Row object is constructed and initialized.
	*				(init list must be used because of the reference 
	*				variable)
	*
	**********************************************************************/
	template< typename T >
	Row< T >::Row( Array2D< T > &array, int row ) : 
					m_array2D( array ), m_row( row )
	{  }

	/**********************************************************************
	*	Row< T >::Row( const Array2D< T > &array, int row )
	*
	*	   Purpose: Used to copy one Row object into another.
	*
	*		 Entry:	Called when a Row object is initialized with another
	*				Row object.
	*
	*		  Exit:	After the second Row object has the values of the first
	*				Row object.
	*
	**********************************************************************/
	template< typename T>
	Row< T >::Row( const Array2D< T > &array, int row ) :
					m_array2D( const_cast< Array2D< T > & >( array ) ), m_row( row )
	{  }

//
// Operator overloads
//

	/**********************************************************************
	*	const T & Row< T >::operator[]( int col )
	*
	*	   Purpose: Used to access a specific element of the Array2D 
	*				object that constructed this Row object.
	*				This is a const version to be used with constant
	*				objects.
	*
	*		 Entry:	Called when the user uses the Array2D[ row ][ col ] 
	*				syntax.
	*
	*		  Exit:	After the element of the Array2D the user is seeking 
	*				is returned.
	*
	**********************************************************************/
	template< typename T >
	const T & Row< T >::operator[]( int col ) const
	{
		return m_array2D.Select( m_row, col );
	}

	/**********************************************************************
	*	T & Row< T >::operator[]( int col )
	*
	*	   Purpose: Used to access a specific element of the Array2D 
	*				object that constructed this Row object.
	*
	*		 Entry:	Called when the user uses the Array2D[ row ][ col ] 
	*				syntax.
	*
	*		  Exit:	After the element of the Array2D the user is seeking 
	*				is returned.
	*
	**********************************************************************/
	template< typename T >
	T & Row< T >::operator[]( int col )
	{
		return m_array2D.Select( m_row, col );
	}