#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "doublelinkedlist.h"

template< typename T >
class ListQueue
{
	public:
		ListQueue(  );
		ListQueue( const ListQueue< T > & copy );
		ListQueue< T > & operator=( const ListQueue< T > & rhs );
		~ListQueue(  );

		void Enqueue( T data );
		T Dequeue(  );
		T & Front(  );
		int Size(  );
		bool isEmpty(  );

	private:
		DoubleLinkedList< T > mQueue;
		int mMax;		

};
#endif
	
	template< typename T >
	ListQueue< T >::ListQueue(  ) :
								mQueue(  ), mMax( 0 )
	{  }

	template< typename T >
	ListQueue< T >::ListQueue( const ListQueue< T > & copy ) :
								mQueue( copy.mQueue ), mMax( copy.mMax )
	{  }

	template< typename T >
	ListQueue< T > & ListQueue< T >::operator=( const ListQueue< T > & rhs )
	{
		if( this != &rhs )
		{
			mQueue = rhs.mQueue;
			mMax = rhs.mMax;
		}
		return *this;
	}

	template< typename T >
	ListQueue< T >::~ListQueue(  )
	{  }

	template< typename T >
	void ListQueue< T >::Enqueue( T data )
	{
		mQueue.Append( data );
		++mMax;
	}

	template< typename T >
	T ListQueue< T >::Dequeue(  )
	{
		if( isEmpty(  ) )
			throw Exception( "List is empty" );

		T returnData = mQueue.First(  );
		mQueue.Extract( returnData );
		--mMax;
		
		return returnData;
	}
d
	template< typename T >
	T & ListQueue< T >::Front(  )
	{
		if( isEmpty(  ) )
			throw Exception( "List is empty" );

		return mQueue.First(  );
	}

	template< typename T >
	int ListQueue< T >::Size(  )
	{
		return mMax;
	}


	template< typename T >
	bool ListQueue< T >::isEmpty(  )
	{
		bool empty( false );

		if( mQueue.getHead(  ) == nullptr )
			empty = true;

		return empty;
	}