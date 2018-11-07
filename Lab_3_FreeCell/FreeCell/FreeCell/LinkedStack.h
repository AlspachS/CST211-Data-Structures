/***********************************************************************
* 	 Class: LinkedStack
* Filename: LinkedStack.h
*
*		A stack implementation using a linked list as the core data
*		structure.
*
* Constructors:
*			LinkedStack(  )
*				Creates an instance of a linkedstack object.  There are
*				no nodes or data in this object.
*
*	  Mutators:
*			void Push( T data )
*				Puts 'data' on the top of the stack.
*
*			T Pop(  )
*				Removes and returns the object on the top of the stack.
*
*	   Methods:
*			T Peek(  )
*				Returns the object on the top of the stack without 
*				removing it.
*
*			int Size(  )
*				Returns the number of element on the stack.
*
*			bool isEmpty(  )
*				Checks to see if the list is empty.
*
***********************************************************************/
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "doublelinkedlist.h"
#include "Exception.h"

template< typename T >
class LinkedStack
{
	public:

	// Manager functions

		// No argument constructor
		LinkedStack(  );

		// Copy constructor
		LinkedStack( const LinkedStack< T > & copy );

		// Assignment operator
		LinkedStack< T > & operator=( const LinkedStack< T > & rhs );

		// Destructor
		~LinkedStack(  );

	// Mutator methods

		// Puts a value on the stack
		void Push( T data );

		// Removes a value from the stack
		T Pop(  );

	// Accessor methods

		// Returns the top value from the stack
		T Peek(  );

		// Returns the number of elements on the stack
		int Size(  );

	// Member functions

		// Checks if the list is empty
		bool isEmpty(  );

	private:
		DoubleLinkedList< T > mStack;		// Linkedlist to use as a stack
		int mSize;							// The number of elements on the stack
		
};

//
// Manager functions
//

	/**********************************************************************
	*	LinkedStack::LinkedStack(  )
	*
	*	   Purpose: Creates an instance of the LinkedStack class.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	template< typename T >
	LinkedStack< T >::LinkedStack(  ) :
									mStack(  ), mSize( 0 )
	{  }

	/**********************************************************************
	*	LinkedStack::LinkedStack( const LinkedStack & copy )
	*
	*	   Purpose: Creates a LinkedStack object that is a copy of an 
	*				existing LinkedStack object.
	*
	*		 Entry:	'copy' is some existing LinkedStack object.
	*
	*		  Exit:	'this' is now a replica of 'copy'.
	*
	**********************************************************************/

	template< typename T >
	LinkedStack< T >::LinkedStack( const LinkedStack< T > & copy ) :
									mStack( copy.mStack ), mSize( copy.mSize )
	{  }

	/**********************************************************************
	*	LinkedStack & LinkedStack::operator=( const LinkedStack & rhs )
	*
	*	   Purpose:	Overwrites one LinkedStack object with the data of another.
	*
	*		 Entry:	'this' has unimportant data that will be overwritten,
	*				and 'rhs' is the source of the data.
	*
	*		  Exit:	'this' will be the same as 'rhs'.
	*
	**********************************************************************/
	template< typename T >
	LinkedStack< T > & LinkedStack< T >::operator=( const LinkedStack< T > & rhs )
	{
		if( this != &rhs )
		{
			mStack = rhs.mStack;
			mSize = rhs.mSize;
		}
		return *this;
	}

	/**********************************************************************
	*	LinkedStack::~LinkedStack(  )
	*
	*	   Purpose: Destroys a LinkedStack object.
	*
	*		 Entry:	'this' is some object.
	*
	*		  Exit: 'this' is no longer an object.
	*
	**********************************************************************/
	template< typename T >
	LinkedStack< T >::~LinkedStack(  )
	{  }

//
// Member functions
//

	/**********************************************************************
	*	void LinkedStack< T >::Push( T data )
	*
	*	   Purpose: Puts a data item on the LinkedStack.
	*
	*		 Entry:	The LinkedStack may or may not have other data on it, and 
	*				'data' is some new value to be stored in the LinkedStack.
	*				
	*		  Exit: 'data' has been stored in a new node of the	LinkedStack.
	*
	**********************************************************************/
	template< typename T >
	void LinkedStack< T >::Push( T data )
	{
		++mSize;
		mStack.Append( data );
	}

	/**********************************************************************
	*	T LinkedStack< T >::Pop(  )
	*
	*	   Purpose: Removes and returns the item currently on top of the 
	*				LinkedStack.  If there are no items on the LinkedStack,
	*				then an	Exception is thrown.
	*
	*		 Entry:	If the LinkedStack has items in it, 'mSize' is decremented 
	*				and the item on top is returned.
	*
	*		  Exit: An item has been returned and removed from the LinkedStack
	*				object.
	*
	**********************************************************************/
	template< typename T >
	T LinkedStack< T >::Pop(  )
	{
		if( isEmpty(  ) )
			throw Exception( "Stack is empty" );

		T temp = mStack.Last(  );

		--mSize;
		mStack.Extract( temp );

		return temp;
	}

	/**********************************************************************
	*	T LinkedStack< T >::Peek(  )
	*
	*	   Purpose: Returns the item on the top of the LinkedStack without
	*				"removing" it from the LinkedStack.  If the LinkedStack is empty
	*				an exception is thrown.
	*
	8		 Entry:	The top value is returned without removing the data.
	*
	*		  Exit: The item on the top of the LinkedStack is returned.
	*
	**********************************************************************/	
	template< typename T >
	T LinkedStack< T >::Peek(  )
	{
		if( isEmpty(  ) )
			throw Exception( "Stack is empty" );

		return mStack.Last(  );
	}

	/**********************************************************************
	*	int LinkedStack< T >::Size(  )
	*
	*	   Purpose:	Returns the number of items currently on the LinkedStack.
	*
	*		 Entry: 'mSize' is the number of elements on the LinkedStack.	
	*
	*		  Exit: 'mSize' is returned.  
	*
	**********************************************************************/
	template< typename T >
	int LinkedStack< T >::Size(  )
	{
		return mSize;
	}

	/**********************************************************************
	*	bool LinkedStack< T >::isEmpty(  )
	*
	*	   Purpose: Returns true is there are no items on the LinkedStack.
	*
	*		 Entry:	The LinkedStack may or may not contain any items.
	*
	*		  Exit:	No change has been made to the LinkedStack or the data on the
	*				LinkedStack.
	*
	**********************************************************************/
	template< typename T >
	bool LinkedStack< T >::isEmpty(  )
	{
		bool empty( false );
		
		if( mSize == 0 )
			empty = true;

		return empty;
	}

#endif