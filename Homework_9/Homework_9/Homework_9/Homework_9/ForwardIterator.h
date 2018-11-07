#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H

#include "ListIterator.h"

template< typename T >
class ForwardIterator : public ListIterator< T >
{
	public:
		ForwardIterator( DoubleLinkedList< T > & list );
		ForwardIterator( const ForwardIterator< T > & copy );
		virtual ~ForwardIterator(  );

		virtual void MoveNext(  );
		virtual void Reset(  );
		virtual bool isDone(  );
		virtual T GetCurrent(  );

	private:
		

	protected:
		
};
	
	template< typename T >
	ForwardIterator< T >::ForwardIterator( DoubleLinkedList< T > & list ) :
											ListIterator( list )
	{
		Reset(  );
	}

	template< typename T >
	ForwardIterator< T >::~ForwardIterator(  )
	{  }

	template< typename T >
	void ForwardIterator< T >::MoveNext(  )
	{
		mCurrent = mCurrent->GetNext(  );
	}

	template< typename T >
	void ForwardIterator< T >::Reset(  )
	{
		mCurrent = mList.getHead(  );
	}

	template< typename T >
	bool ForwardIterator< T >::isDone(  )
	{
		return mCurrent != nullptr;
	}

	template< typename T >
	T ForwardIterator< T >::GetCurrent(  )
	{
		return mCurrent->GetData(  );
	}


	
#endif