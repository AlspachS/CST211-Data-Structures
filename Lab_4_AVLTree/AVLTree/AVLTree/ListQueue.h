/***********************************************************************
* 	 Class: ListQueue
* Filename: ListQueue.h
*
*		A queue implemented with a linked list.
*
* Constructors:
*		ListQueue(  )
*			Creates an empty queue object.
*
*	  Mutators:
*		void Enqueue( T data )
*			Stores data in the back of the queue.
*
*		T Dequeue(  )
*			Removes the data in the front of the queue.
*
*		T & Front(  )
*			Returns a reference to the data in the front of the queue
*			so it can be edited.
*
*	   Methods:
*		int Size(  )
*			Returns the number of objects in the queue.
*
*		bool isEmpty(  )
*			Returns true if the queue is empty.
*
*
***********************************************************************/
#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "doublelinkedlist.h"

template< typename T >
class ListQueue
{
	public:

	// Manager functions

		// No argument constructor
		ListQueue(  );

		// Copy constructor
		ListQueue( const ListQueue< T > & copy );

		// Assignment operator
		ListQueue< T > & operator=( const ListQueue< T > & rhs );

		// Destructor
		~ListQueue(  );

	// Mutators

		// Stores data in the queue
		void Enqueue( T data );

		// Removes data from the queue
		T Dequeue(  );

		// Allows the data in the front of the queue to be changed
		T & Front(  );

	// Accessors

		// Returns the number of elements in the queue
		int Size(  );

	// Member functions

		// Returns true if the queue is empty
		bool isEmpty(  );

	private:
		DoubleLinkedList< T > mQueue;			// Linked list to act as a queue
		int mMax;								// Number of elements in the queue

};

//
// Manager functions
//
	
	/**********************************************************************
	*	ListQueue< T >::ListQueue(  )
	*
	*	   Purpose: Creates a ListQueue object.
	*
	*		 Entry: The object is not yet in existence.
	*
	*		  Exit: The object now exists and can store data.
	*
	**********************************************************************/
	template< typename T >
	ListQueue< T >::ListQueue(  ) :
								mQueue(  ), mMax( 0 )
	{  }

	/**********************************************************************
	*	ListQueue< T >::ListQueue( const ListQueue< T > & copy )
	*
	*	   Purpose: Copies an existing ListQueue object into a newly
	*				created one.
	*
	*		 Entry: The ListQueue copy is an already existing ListQueue.
	*				Its values will be copied into the newly created 
	*				ListQueue object.
	*
	*		  Exit:	The newly created ListQueue is a duplicated of copy.
	*
	**********************************************************************/
	template< typename T >
	ListQueue< T >::ListQueue( const ListQueue< T > & copy ) :
								mQueue( copy.mQueue ), mMax( copy.mMax )
	{  }

	/**********************************************************************
	*	ListQueue< T > & ListQueue< T >::operator=( const ListQueue< T > & rhs )
	*
	*	   Purpose: Copies the values of one ListQueue object into another
	*				ListQueue object.
	*
	*		 Entry:	The first ListQueue object's values don't matter since
	*				they are about to be overwritten.  The second is some
	*				ListQueue object that may or may not have values in 
	*				it.
	*
	*		  Exit: Both ListQueue objects are the same.
	*
	**********************************************************************/
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

	/**********************************************************************
	*	ListQueue< T >::~ListQueue(  )
	*
	*	   Purpose: Destroys a ListQueue object.
	*
	*		 Entry:	The ListQueue object has some values, or not, in it,
	*				and is going out of scope.
	*
	*		  Exit: The ListQueue object is destroyed along with all data
	*				in it.
	*
	**********************************************************************/
	template< typename T >
	ListQueue< T >::~ListQueue(  )
	{  }

//
// Mutator functions
//

	/**********************************************************************
	*	void ListQueue< T >::Enqueue( T data )
	*
	*	   Purpose: Stores data sent from the user in the ListQueue object.
	*
	*		 Entry:	The data is some value the user wishes to store in the
	*				ListQueue.
	*
	*		  Exit: The data is successfully stored in the ListQueue.
	*
	**********************************************************************/
	template< typename T >
	void ListQueue< T >::Enqueue( T data )
	{
		mQueue.Append( data );
		++mMax;
	}

	/**********************************************************************
	*	T ListQueue< T >::Dequeue(  )
	*
	*	   Purpose:	Removes the front object from the Queue and returns
	*				it.  If there is nothing in the list, it throws an
	*				error.
	*
	*		 Entry:	The Queue has some value in the front.
	*
	*		  Exit: The Queue now has the next object as the front.
	*
	**********************************************************************/
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

	/**********************************************************************
	*	T & ListQueue< T >::Front(  )
	*
	*	   Purpose: Returns a reference to the object in the front of the
	*				Queue so the user can edit that piece of data.
	*
	*		 Entry:	The front Queue object is some data value.
	*
	*		  Exit:	The front Queue object has been returned to the user
	*				for editing.
	*
	**********************************************************************/
	template< typename T >
	T & ListQueue< T >::Front(  )
	{
		if( isEmpty(  ) )
			throw Exception( "List is empty" );

		return mQueue.First(  );
	}

//
// Accessor functions
//

	/**********************************************************************
	*	int ListQueue< T >::Size(  )
	*
	*	   Purpose:	Returns the number of objects in the Queue.
	*
	*		 Entry:	There are some number of elements in the Queue, 
	*				recorded by mMax.
	*
	*		  Exit:	The value in mMax is returned.
	*
	**********************************************************************/
	template< typename T >
	int ListQueue< T >::Size(  )
	{
		return mMax;
	}

//
// Member functions
//

	/**********************************************************************
	*	bool ListQueue< T >::isEmpty(  )
	*
	*	   Purpose:	Returns true if the Queue is empty.  
	*
	*		 Entry:	The Queue is either empty, or has data in it.
	*
	*		  Exit:	Whether the Queue is empty, or has data is returned.
	*
	**********************************************************************/
	template< typename T >
	bool ListQueue< T >::isEmpty(  )
	{
		return( mQueue.getHead(  ) == nullptr );
	}

#endif