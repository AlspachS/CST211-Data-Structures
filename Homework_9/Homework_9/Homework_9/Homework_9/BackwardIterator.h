#ifndef BACKWARDITERATOR_H
#define BACKWARDITERATOR_H

#include "ListIterator.h"

template< typename T >
class BackwardIterator : public ListIterator< T >
{
	public:
		BackwardIterator( DoubleLinkedList< T > & list );
		BackwardIterator( const BackwardIterator< T > & copy );
		virtual ~BackwardIterator(  );

		virtual void MoveNext(  );
		virtual void Reset(  );
		virtual bool isDone(  );
		virtual T GetCurrent(  );

	private:

	protected:

};

	template< typename T >
	BackwardIterator< T >::BackwardIterator( DoubleLinkedList< T > & list ) :
											ListIterator( list )
	{
		Reset(  );
	}

	template< typename T >
	BackwardIterator< T >::BackwardIterator( const BackwardIterator & copy ) :
											ListIterator( copy.mList )
	{  }

	template< typename T >
	BackwardIterator< T >::~BackwardIterator(  )
	{  }

	template< typename T >
	void BackwardIterator< T >::MoveNext(  )
	{
		mCurrent = mCurrent->GetPrev(  );
	}

	template< typename T >
	void BackwardIterator< T >::Reset(  )
	{
		mCurrent = mList.getTail(  );
	}

	template< typename T >
	bool BackwardIterator< T >::isDone(  )
	{
		return mCurrent != nullptr;
	}

	template< typename T >
	T BackwardIterator< T >::GetCurrent(  )
	{
		return mCurrent->GetData(  );
	}

#endif