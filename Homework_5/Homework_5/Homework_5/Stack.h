/***********************************************************************
* 	 Class: Stack
* Filename: Stack.h
*
*		Creates an array of a size specified by the user and treats that
*		array as a stack, where items can only be added and removed from
*		the top.  Follows a first in, first out paradigm.
*
* Constructors:
*			Stack( int size );
*				Creates a stack with 'size' number of elements.
*
*	  Mutators:
*			void Push( T data )
*				Stores 'data' as the next item on the stack.  Once an
*				item has been pushed on the stack, no other items
*				can be accessed until that item has been removed.
*
*			T Pop(  )
*				Returns and removes the first item of the stack.  
*				The next item is moved up so it can be used accessed.
*
*	   Methods:
*			T Peek(  )
*				Returns the first item on the stack, but doesn't remove
*				it from the stack.
*
*			int Size(  )
*				Returns the number of items currently on the stack.
*
*			bool isEmpty(  )
*				Returns true if the stack has no items in the stack.
*
*			bool isFull(  )
*				Returns true if the stack is full.
*
***********************************************************************/
#ifndef STACK_H
#define STACK_H

#include "Array.h"
#include "Exception.h"

template< typename T >
class Stack
{
	public:

	// Manager functions

		// One argument constructor
		Stack( int size );

		// Copy Constructor
		Stack( const Stack< T > & copy );

		// Assignment operator
		Stack< T > & operator=( const Stack< T > & rhs );

		// Destructor
		~Stack(  );

	// Mutator functions

		// Puts something on the stack
		void Push( T data );

		// Removes something from the stack
		T Pop(  );

	// Accessor functions

		// Shows the top item of the stack
		T Peek(  );

		// Returns the number of items in the stack
		int Size(  );

	// Member functions

		// Returns true if the stack is empty
		bool isEmpty(  );

		// Returns true if the stack is full
		bool isFull(  );

	private:
		Array< T > mStack;		// Array treated as a stack
		int mTop;				// Current top of stack
		int mSize;				// Size of the stack
};
#endif

//
// Manager functions
//
	
	/**********************************************************************
	*	Stack< T >::Stack( int size )
	*
	*	   Purpose: Creates an array of 'size' elements.
	*
	*		 Entry:	None of the class variables exist yet, and 'size' is
	*				some value specified by the user.
	*
	*		  Exit: All class variables have been created and initialized.
	*				Also, mStack has been set to 'size' number of elements.
	*
	**********************************************************************/
	template< typename T >
	Stack< T >::Stack( int size ) :
					mStack(  ), mTop( -1 ), mSize( size )
	{
		mStack.SetLength( mSize );
	}

	/**********************************************************************
	*	Stack< T >::Stack( const Stack & copy )
	*
	*	   Purpose: Creates a Stack object with the values of the Stack
	*				object 'copy'.
	*
	*		 Entry:	None of the class variables exist yet, 'copy' is some
	*				Stack object that already exists.
	*
	*		  Exit: All class variables have been created and initialized
	*				to the same values stored in 'copy'.
	*
	**********************************************************************/
	template< typename T >
	Stack< T >::Stack( const Stack< T > & copy ) :
						mStack( copy.mStack ), mTop( copy.mTop ), mSize( copy.mSize ) 
	{  }

	/**********************************************************************
	*	Stack< T > & Stack::operator=( const Stack & rhs )
	*
	*	   Purpose: Assigns one Stack object to the values of a second
	*				Stack object.
	*
	*		 Entry:	The calling Stack object has some values, these values 
	*				are unimportant since they are about to be overwritten
	*				with the values from 'rhs'.
	*
	*		  Exit: The calling Stack's values have been overwritten to 
	*				match the values of 'rhs'.
	*
	**********************************************************************/
	template< typename T >
	Stack< T > & Stack< T >::operator=( const Stack< T > & rhs )
	{
		if( this != &rhs )
		{
			mStack = rhs.mStack;
			mTop = rhs.mTop;
			mSize = rhs.mSize;
		}
		return * this;
	}

	/**********************************************************************
	*	Stack< T >::~Stack(  )
	*
	*	   Purpose:	Deletes a Stack object.
	*
	*		 Entry:	The calling Stack object has some values that are
	*				unimportant since they are about to be deleted.
	*
	*		  Exit:	The Stack object has been deleted.  All class variables
	*				are deleted.
	*
	**********************************************************************/
	template< typename T >
	Stack< T >::~Stack(  )
	{  }

//
//	Member functions
//

	/**********************************************************************
	*	void Stack< T >::Push( T data )
	*
	*	   Purpose: Puts a data item on the Stack.  If the Stack is full,
	*				an exception is thrown.
	*
	*		 Entry:	The Stack may or may not have other data on it, and 
	*				'data' is some new value to be stored in the Stack.
	*				'mTop', which is the Stack "pointer" is incremented
	*				and 'data' is stored in the new index.
	*
	*		  Exit: 'data' has been stored in the next element of the 
	*				Stack.
	*
	**********************************************************************/
	template< typename T >
	void Stack< T >::Push( T data )
	{
		if( isFull(  ) )
			throw Exception( "Stack is full" );

		++mTop;
		mStack[ mTop ] = data;
	}

	/**********************************************************************
	*	T Stack< T >::Pop(  )
	*
	*	   Purpose: Removes and returns the item currently on top of the 
	*				Stack.  If there are no items on the Stack, then an
	*				Exception is thrown.
	*
	*		 Entry:	If the Stack has items in it, 'mTop' is decremented 
	*				and the item at 'mTop + 1' is returned.
	*
	*		  Exit: An item has been returned and "removed" from the Stack
	*				by decrementing the Stack pointer.
	*
	**********************************************************************/
	template< typename T >
	T Stack< T >::Pop(  )
	{
		if( isEmpty(  ) )
			throw Exception( "Stack is empty" );

		--mTop;
		return mStack[ mTop + 1 ];
	}

	/**********************************************************************
	*	T Stack< T >::Peek(  )
	*
	*	   Purpose: Returns the item on the top of the Stack without
	*				"removing" it from the Stack.  If the Stack is empty
	*				an exception is thrown.
	*
	*		 Entry:	'mTop' is pointing to some item on the Stack.  This
	*				value is returned without decrementing the Stack
	*				pointer.
	*
	*		  Exit: The item on the top of the Stack is returned.
	*
	**********************************************************************/	
	template< typename T >
	T Stack< T >::Peek(  )
	{
		if( isEmpty(  ) )
			throw Exception( "Stack is empty" );

		return mStack[ mTop ];
	}

	/**********************************************************************
	*	int Stack< T >::Size(  )
	*
	*	   Purpose:	Returns the number of items currently on the Stack.
	*
	*		 Entry: 'mTop' can be any value from -1 to 'mSize'.	
	*
	*		  Exit: 'mTop + 1' is returned.  
	*
	**********************************************************************/	
	template< typename T >
	int Stack< T >::Size(  )
	{
		return mTop + 1;		
	}

	/**********************************************************************
	*	bool Stack< T >::isEmpty(  )
	*
	*	   Purpose: Returns true is there are no items on the Stack.
	*
	*		 Entry:	The Stack may or may not contain any items.
	*
	*		  Exit:	No change has been made to the Stack or the data on the
	*				Stack.
	*
	**********************************************************************/
	template< typename T >
	bool Stack< T >::isEmpty(  )
	{
		bool empty = false;

		if( mTop == -1 )
			empty = true;

		return empty;
	}

	/**********************************************************************
	*	bool Stack< T >::isFull(  )
	*
	*	   Purpose:	Returns true if all elements of the Stack are full.
	*
	*		 Entry:	The Stack may or may not contain items.
	*
	*		  Exit:	No changes to the Stack or the data on the Stack have
	*				been made.
	*
	**********************************************************************/	
	template< typename T >
	bool Stack< T >::isFull(  )
	{
		bool full = false;

		if( mTop >= mSize - 1 )
			full = true;

		return full;
	}