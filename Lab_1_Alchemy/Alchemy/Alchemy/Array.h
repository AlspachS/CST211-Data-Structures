/***********************************************************************
* Class:		Array
* Filename:		Array.h
*
*		A templated implementation of an array to store data
*
* Constructors:
*			Array(  );
*				Creates a default array.  Sets the array pointer to 
*				nullptr, m_start_index to zero, and m_length to zero.
*
*			Array( int length, int start_index = 0 )
*				Creates a specified array of length.  start_index is an
*				offset which indicates the number of the first element
*				in the array.
*
*	  Mutators:
*			void SetStartIndex( int start_index )
*				Changes the starting index of the array.
*
*			void SetLength( int length )
*				Changes the length of the array.
*				DATA CAN BE LOST!
*
*	   Methods:
*			int GetStartIndex(  ) const;
*				Returns the starting index of the array.
*
*			int GetLength(  ) const;
*				Returns the length of the array
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
	*	   Purpose: Creates an empty array that the user can then change
	*				the length of as needed.
	*
	*		 Entry: This constructor can be used at any time.
	*
	*		  Exit:	The new array is "created" and all the member values
	*				set to default values.
	*
	**********************************************************************/
	template< typename T >
	Array< T >::Array(  ) : 
						m_array( nullptr ), m_length( 0 ), m_start_index( 0 ) 
	{  }


	/**********************************************************************
	*	Array< T >::Array( int length, int start_index )
	*
	*	   Purpose: Creates an array of the specified length.  This array
	*				can be changed as needed by the user.
	*
	*		 Entry:	This constructor can only be called if the minimum of
	*				length is specified.
	*
	*		  Exit: The new array is created and given a length of 
	*				'length'.  'start_index' is optional and would change
	*				the number used to access the first element of the
	*				array.
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
			m_array = new T [ m_length ];
	}


	/**********************************************************************
	*	Array< T >::Array( const Array & copy )
	*
	*	   Purpose:	Creates a copy of an array to be passed or received, 
	*				by value, or used in initialization of another array.
	*
	*		 Entry:	This constructor is entered when an array is passed or
	*				received by value, or when a newly generated array is 
	*				initialized to another array's data. 
	*
	*		  Exit: After the new array is created and the other array's 
	*				values are stored in it.
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
	*	   Purpose:	Used to assign one array the values of a second array.
	*
	*		 Entry:	Called with the assignment operator to overwrite one
	*				array with a second.
	*
	*		  Exit:	After the calling array (lhs) is overwritten with the
	*				data from the second array (rhs).
	*
	**********************************************************************/
	template< typename T >
	Array< T > & Array< T >::operator=( const Array< T > & rhs )
	{
		if( this != &rhs )
		{
			delete [  ] m_array;
			m_array = nullptr;
			m_array = new T [ rhs.m_length ];
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
	*	   Purpose:	Deallocates the memory that was allocated in the
	*				creation of the array.
	*
	*		 Entry:	Called when an array object goes out of scope.
	*
	*		  Exit:	The memory is deallocated and the data members are 
	*				reset to default values.
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
	*	   Purpose:	Used to access an element of the array with expected
	*				syntax.  The user is more protected against going out
	*				of bounds of the array.
	*
	*		 Entry: Called when the user wants to access an array element 
	*				with [ index ] syntax.
	*
	*		  Exit:	When the data at the desired element is returned.  This
	*				can be to read the data or write new data to the array
	*				element.
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
	*	   Purpose:	Returns the starting index of the array.  This is the 
	*				number used to access the first element of the array.
	*
	*		 Entry:	Called when the first array index is needed to be 
	*				known, such as for loops.
	*
	*		  Exit:	After the starting index is returned.
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
	*	   Purpose:	Returns the number of elements in the array.  
	*
	*		 Entry:	Called when the size of the array is needed, such as
	*				for loops.
	*
	*		  Exit: After the length of the array is returned.
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
	*	   Purpose:	Changes the number used to access the first element of 
	*				the array.
	*
	*		 Entry:	'm_start_index' is a certain value, zero or greater.
	*
	*		  Exit:	'm_start_index' has been changed to the new 
	*				'start_index' value.
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
	*	   Purpose:	Used to reset the size of the array to a different
	*				size.  If the user is shrinking the array, any data in
	*				the elements being removed will be lost.
	*
	*		 Entry:	Called when the user wants to grow or shrink the array.
	*
	*		  Exit:	After the desired elements have been added or removed.
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