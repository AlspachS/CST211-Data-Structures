
#include "Array.h"
#include "Exception.h"

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

template< typename T >
class ArrayQueue
{
	public:
		ArrayQueue( int max );
		ArrayQueue( const ArrayQueue< T > & copy );
		ArrayQueue< T > & operator=( const ArrayQueue< T > & rhs );
		~ArrayQueue(  );

		void Enqueue( T data );
		T Dequeue(  );
		T & Front(  );
		int Size(  );
		bool isEmpty(  );
		bool isFull(  );

	private:
		Array< T > mQueue;
		int mSize;
		int mFront;
		int mRear;
		int mMax;

};
#endif
	
	template< typename T >
	ArrayQueue< T >::ArrayQueue( int max ) :
								mQueue( Array< T >( max ) ), mSize( 0 ), mFront( 0 ),
								mRear( 0 ), mMax( max )
	{  }

	template< typename T >
	ArrayQueue< T >::ArrayQueue( const ArrayQueue & copy ) :
								mQueue( Array< T >( copy.mMax ) ), mSize( copy.mSize ),
								mFront( copy.mFront ), mRear( copy.mRear ), mMax( copy.mMax )
	{  }

	template< typename T >
	ArrayQueue< T > & ArrayQueue< T >::operator=( const ArrayQueue & rhs )
	{
		if( this != &rhs )
		{
			mQueue = rhs.mQueue;
			mSize = rhs.mSize;
			mFront = rhs.mFront;
			mRear = rhs.mRear;
			mMax = rhs.mMax;
		}
		return *this;
	}

	template< typename T >
	ArrayQueue< T >::~ArrayQueue(  )
	{  }

	
	template< typename T >
	void ArrayQueue< T >::Enqueue( T data )
	{
		if( isFull(  ) )
			throw Exception( "Queue is full" );
				
		mQueue[ mRear ] = data;

		if( mRear == mMax - 1 )
			mRear = 0;
		else
			++mRear;

		++mSize;
	}


	template< typename T >
	T ArrayQueue< T >::Dequeue(  )
	{
		if( isEmpty(  ) )
			throw Exception( "Queue is empty" );
		
		T returnData = mQueue[ mFront ];

		if( mFront == mMax - 1 )
			mFront = 0;
		else
			++mFront;	
		
		--mSize;
		return returnData;

	}


	template< typename T >
	T & ArrayQueue< T >::Front(  )
	{
		if( isEmpty(  ) )
			throw Exception( "Queue is empty" );

		return mQueue[ mFront ];
	}

	template< typename T >
	int ArrayQueue< T >::Size(  )
	{
		return mSize;
	}

	template< typename T >
	bool ArrayQueue< T >::isEmpty(  )
	{
		bool empty( false );

		if( mSize == 0 )
			empty = true;

		return empty;
	}

	template< typename T >
	bool ArrayQueue< T >::isFull(  )
	{
		bool full( false );

		if( mSize == mMax )
			full = true;

		return full;
	}