
#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "doublelinkedlist.h"
#include "Exception.h"

template< typename T >
class LinkedStack
{
	public:
		LinkedStack(  );
		LinkedStack( const LinkedStack< T > & copy );
		LinkedStack< T > & operator=( const LinkedStack< T > & rhs );
		~LinkedStack(  );

		void Push( T data );
		T Pop(  );
		T Peek(  );
		int Size(  );
		bool isEmpty(  );

	private:
		DoubleLinkedList< T > mStack;
		int mSize;
		
};
#endif

	template< typename T >
	LinkedStack< T >::LinkedStack(  ) :
									mStack(  ), mSize( 0 )
	{  }

	template< typename T >
	LinkedStack< T >::LinkedStack( const LinkedStack< T > & copy ) :
									mStack( copy.mStack ), mSize( copy.mSize )
	{  }

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

	template< typename T >
	LinkedStack< T >::~LinkedStack(  )
	{  }

	template< typename T >
	void LinkedStack< T >::Push( T data )
	{
		++mSize;
		mStack.Append( data );
	}

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

	template< typename T >
	T LinkedStack< T >::Peek(  )
	{
		if( isEmpty(  ) )
			throw Exception( "Stack is empty" );

		return mStack.Last(  );
	}

	template< typename T >
	int LinkedStack< T >::Size(  )
	{
		return mSize;
	}

	template< typename T >
	bool LinkedStack< T >::isEmpty(  )
	{
		bool empty( false );
		
		if( mSize == 0 )
			empty = true;

		return empty;
	}