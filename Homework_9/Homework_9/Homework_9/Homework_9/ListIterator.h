#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "AbstractIterator.h"

#include "doublelinkedlist.h"

template< typename T >
class ListIterator : public AbstractIterator< T >
{
	public:
		ListIterator( DoubleLinkedList< T > & list );
		ListIterator( const ListIterator< T > & copy );
		virtual ~ListIterator(  );

	private:

	protected:
		DoubleLinkedList< T > & mList;
		node< T > * mCurrent;
};
	
	template< typename T >
	ListIterator< T >::ListIterator( DoubleLinkedList< T > & list ) :
									mList( list ), mCurrent( nullptr )
	{  }

	template< typename T >
	ListIterator< T >::ListIterator( const ListIterator & copy ) :
									mList( copy.mList ), mCurrent( copy.mCurrent )
	{  }

	template< typename T >
	ListIterator< T >::~ListIterator(  )
	{  }


#endif