/***********************************************************************
* Class:		Array
* Filename:		Array.h
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
#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"

template< typename T >
class Array
{
	public:

	// Manager functions

		// No argument constructor
		Array(  );

		// Two argument constructor
		Array( int length, int start_index = 0 );

		// Copy constructor
		Array( const Array & copy );

		// Assignment operator
		Array & operator=( const Array & rhs );

		// Destructor
		~Array(  );
		
	// Operator overloads

		// Index operator
		T & operator[]( int index );

	// Accessor methods

		// Retrieves the starting index
		int GetStartIndex(  ) const;

		// Retrieves the length of the array
		int GetLength(  ) const;
	
	// Mutator methods

		// Sets starting element
		void SetStartIndex( int start_index );

		// Sets the length of the array
		void SetLength( int length );
	
	private:
		T * m_array;			// Array of data
		int m_length;			// Length of m_array
		int m_start_index;		// Starting point in m_array
};
#endif

//
// Manager functions
//

	/**********************************************************************
	*	Array< T >::Array(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array< T >::Array(  ) : 
						m_array( nullptr ), m_length( 0 ), m_start_index( 0 ) 
	{  }


	/**********************************************************************
	*	Array< T >::Array( int length, int start_index )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array< T >::Array( int length, int start_index ) : 
						m_array( nullptr ),	m_length( length ),
						m_start_index( start_index )
	{
		if( length < 0 )
			throw Exception( "ERROR:  Invalid array length");
		else if( length > 0 )
			m_array = new T [ m_length ]();
	}


	/**********************************************************************
	*	Array< T >::Array( const Array & copy )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array< T >::Array( const Array< T > & copy ) :
						m_array( nullptr ), m_length( copy.m_length ), 
						m_start_index( copy.m_start_index )
	{
		*this = copy;
	}


	/**********************************************************************
	*	Array< T > & Array< T >::operator=( const Array & source )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array< T > & Array< T >::operator=( const Array< T > & rhs )
	{
		if( this != &rhs )
		{
			delete [  ] m_array;
			m_array = nullptr;
			m_array = new T [ rhs.m_length ]();
			for( int i( 0 ); i < rhs.m_length; ++i )
				m_array[ i ] = rhs.m_array[ i ];

			m_length = rhs.m_length;
			m_start_index = rhs.m_start_index;
		}
		return *this;
	}


	/**********************************************************************
	*	Array< T >::~Array(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	Array< T >::~Array(  )
	{
		delete [  ] m_array;
		m_array = nullptr;
		m_length = 0;
		m_start_index = 0;
	}

//
// Operator overloads
//

	/**********************************************************************
	*	T & Array< T >::operator[]( int index )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	T & Array< T >::operator[]( int index )
	{
		if( index - m_start_index < 0 )
			throw Exception ( "ERROR:  Index value below lower bound" );
		else if( index - m_start_index > m_length - 1 )
			throw Exception ( "ERROR:  Index value above upper bound" );
	
		return m_array[ index - m_start_index ];
	}

//
// Accessor methods
//

	/**********************************************************************
	*	int Array< T >::GetStartIndex(  ) const
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	int Array< T >::GetStartIndex(  ) const
	{
		return m_start_index;
	}


	/**********************************************************************
	*	int Array< T >::GetLength(  ) const
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	int Array< T >::GetLength(  ) const
	{
		return m_length;
	}

//
// Mutator methods
//

	/**********************************************************************
	*	void Array< T >::SetStartIndex( int start_index )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void Array< T >::SetStartIndex( int start_index )
	{
		m_start_index = start_index;
	}


	/**********************************************************************
	*	void Array< T >::SetLength( int length )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void Array< T >::SetLength( int length )
	{
		int smaller = m_length < length ? m_length : length;
		
		Array< T > temp( length, m_start_index );
		
		for( int i( 0 ); i < smaller; ++i )
			temp.m_array[ i ] = m_array[ i ];

		*this = temp;
	}