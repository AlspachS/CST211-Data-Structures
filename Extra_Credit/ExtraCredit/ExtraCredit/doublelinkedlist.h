/***********************************************************************
*    Class: DoubleLinkedList
* Filename: doublelinkedlist.h
*
*		A linked list implementation with next connections and previous
*		connections.
*
* Constructors:
*		DoubleLinkedList(  )
*			Creates an instance of a DoubleLinkedList.
*
*	  Mutators:
*		void SetHead( node< T > * head )
*			Changes the head node of the linked list.  BAD IDEA!
*
*		void SetTail( node< T > * head )
*			Changes the tail node of the linked list.  ALSO A BAD IDEA!
*
*	   Methods:
*		node< T > * getHead(  )
*			Returns the head node of the linked list.
*
*		node< T > * getTail(  )
*			Returns the tail node of the linked list.
*
*		void PrinkForewards(  )
*			Displays the contents of the list from beginning to end.
*
*		void PrintBackwards(  )
*			Displays the contents of the list from end to beginning.
*
*		bool isEmpty(  ) const
*			Returns true if the list is empty.
*
*		const T & first(  ) const
*			Returns a reference to the data in the head node.
*
*		const T & last(  ) const
*			Returns a reference to the data in the tail node.
*
*		void Prepend( T data )
*			Creates a new node with 'data' in it, and stores that node
*			at the beginning of the list.
*
*		void Append( T data )
*			Creates a new node with 'data' in it, and stores that node
*			at the end of the list.
*
*		void Purge(  )
*			Deletes all nodes in a list.
*
*		void Extract( T data )
*			Deletes the node from the list that has 'data' in it.
*
*		void InsertAfter( T data, T param )
*			Stores 'data' in a node and places that node after the node
*			that has 'param' stored in it.
*
*		void InsertBefore( T data, T param )
*			Stores 'data' in a node and places that node before the node
*			that has 'param' stored in it.
*
***********************************************************************/
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
	using std::cout;
	using std::endl;

#include "Exception.h"
#include "ListNode.h"

template< typename T >
class DoubleLinkedList
{
	public:

	// Manager functions

		// No argument constructor
		DoubleLinkedList(  );

		// Copy constructors
		DoubleLinkedList( const DoubleLinkedList< T > & copy );

		// Assignment operator
		DoubleLinkedList< T > & operator=( const DoubleLinkedList< T > & rhs );

		// Destructor
		~DoubleLinkedList(  );

	// Accessor methods

		// Head pointer accessor
		ListNode< T > * getHead(  );

		// Tail pointer accessor
		ListNode< T > * getTail(  );

	// Mutator methods

		// Change the head pointer
		void SetHead( ListNode< T > * head );

		// Change the tail pointer
		void SetTail( ListNode< T > * tail );
		
	// Member functions

		// Display the list front-to-back
		void PrintForwards(  );

		// Display the list back-to-front
		void PrintBackwards(  );

		// Checks if the list is empty
		bool isEmpty(  ) const;

		// Returns the data in the first node (head)
		T & First(  ) const;

		// Returns the data in the last node (tail)
		const T & Last(  ) const;

		// Inserts a node at the beginning of the list
		void Prepend( T data );

		// Inserts a node at the end of the list
		void Append( T data );

		// Removes all the data in the list
		void Purge(  );

		// Removes one node in thet list
		void Extract( T data );

		// Inserts a node after certain data
		void InsertAfter( T data, T param );

		// Inserts a node before certain data
		void InsertBefore( T data, T param );

	private:
		ListNode< T > * m_head;			// Pointer to the start of the list
		ListNode< T > * m_tail;			// Pointer to the end of the list

};


//
// Manager functions
//

	/**********************************************************************
	*	DoubleLinkedList< T >::DoubleLinkedList(  )
	*
	*	   Purpose: Creates a linked list object.
	*
	*		 Entry:	The list will be empty, no nodes.
	*
	*		  Exit:	Nodes will be added as needed.
	*
	**********************************************************************/
	template< typename T >
	DoubleLinkedList< T >::DoubleLinkedList(  ) : 
				m_head( nullptr ), m_tail( nullptr )
	{  }

	/**********************************************************************
	*	DoubleLinkedList< T >::DoubleLinkedList( const DoubleLinkedList & copy )
	*
	*	   Purpose:	Creates a copy of an existing list.
	*
	*		 Entry: 'copy' will be some existing list.
	*
	*		  Exit: 'this' will be a copy of 'copy'.
	*
	**********************************************************************/
	template< typename T >
	DoubleLinkedList< T >::DoubleLinkedList( const DoubleLinkedList< T > & copy ) :
				m_head( nullptr ), m_tail( nullptr )
	{ 
		*this = copy;
	}

	/**********************************************************************
	*	DoubleLinkedList< T > & DoubleLinkedList< T >::operator=( const DoubleLinkedList & rhs )
	*
	*	   Purpose:	Assigns the values of one list into another list.
	*
	*		 Entry: 'this' will be some list object, as will 'rhs'.
	*
	*		  Exit:	'this' will have the same values as 'rhs'.
	*
	**********************************************************************/
	template< typename T >
	DoubleLinkedList< T > & DoubleLinkedList< T >::operator=( const DoubleLinkedList< T > & rhs )
	{ 
		ListNode< T > * travel = nullptr;

		if( this != &rhs )
		{
			if( !rhs.isEmpty(  ) )
			{
				if (m_head != nullptr)
				{
					Purge(  );
				}
				
				travel = rhs.m_head;
				while( travel->m_next != nullptr )
				{
					Append( travel->m_data );
					travel = travel->m_next;
				}
			}
		}
		return *this;
	}

	/**********************************************************************
	*	DoubleLinkedList< T >::~DoubleLinkedList(  )
	*
	*	   Purpose: Destroys a list object.
	*
	*		 Entry:	'this' will be some list.
	*
	*		  Exit:	'this' will be gone.
	*
	**********************************************************************/
	template< typename T >
	DoubleLinkedList< T >::~DoubleLinkedList(  )
	{
		Purge(  );
	}

//
// Accessor methods
//

	/**********************************************************************
	*	node< T > * DoubleLinkedList< T >::getHead(  )
	*
	*	   Purpose: Returns a pointer to the head node of a list.
	*
	*		 Entry:	m_head is either nullptr or a node pointer.
	*
	*		  Exit:	m_head is returned.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T > * DoubleLinkedList< T >::getHead(  )
	{
		return m_head;
	}

	/**********************************************************************
	*	node< T > * DoubleLinkedList< T >::getTail(  )
	*
	*	   Purpose: Returns a pointer to the tail node of a list.
	*
	*		 Entry:	m_tail is either nullptr or a node pointer.
	*
	*		  Exit:	m_tail is returned.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T > * DoubleLinkedList< T >::getTail(  )
	{
		return m_tail;
	}

//
// Mutator methods
//

	/**********************************************************************
	*	void DoubleLinkedList< T >::SetHead( node * head )
	*
	*	   Purpose: Changes the head pointer of a list to point to a 
	*				different node.  THIS IS A BAD IDEA!
	*
	*		 Entry: DON'T!  DON'T ENTER THIS FUNCTION!
	*
	*		  Exit: If you're exiting this function, you need to reconsider
	*				your life choices.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::SetHead( ListNode< T > * head )
	{
		m_head = head;
	}


	/**********************************************************************
	*	void DoubleLinkedList< T >::SetTail( node * tail )
	*
	*	   Purpose: Changes the tail pointer of a list to point to a 
	*				different node.  THIS IS ALSO A BAD IDEA!
	*
	*		 Entry:	ENTERING THIS FUNCTION IS ONLY SLIGHTLY BETTER THAN
	*				ENTERING THE SETHEAD FUNCTION.
	*
	*		  Exit: If you exiting this function, you should still 
	*				reconsider your life choices, but only slightly less
	*				than if you're exiting the SetHead function.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::SetTail( ListNode< T > * tail )
	{
		m_tail = tail;
	}

//
// Member functions
//

	/**********************************************************************
	*	void DoubleLinkedList< T >::PrintForwards(  )
	*
	*	   Purpose: Displays all entries in the list from front to back.
	*				This function is only here for testing.
	*
	*		 Entry:	The list does or doesn't have values it it, it 
	*				doesn't matter.  If there are no values, nothing
	*				happens.
	*
	*		  Exit:	The list is all displayed.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::PrintForwards(  )
	{
		node< T > * travel = m_head;

		while( travel != nullptr )
		{
			cout << travel->m_data << endl;
			travel = travel->m_next;
		}
	}

	/**********************************************************************
	*	void DoubleLinkedList< T >::PrintBackwards(  )
	*
	*	   Purpose: Displays all entries in the list from back to front.
	*				This function is only here for testing.
	*
	*		 Entry:	The list does or doesn't have values it it, it 
	*				doesn't matter.  If there are no values, nothing
	*				happens.
	*
	*		  Exit:	The list is all displayed.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::PrintBackwards(  )
	{
		node< T > * levart = m_tail;

		while( levart != nullptr )
		{
			cout << levart->m_data << endl;
			levart = levart->m_prev;
		}
	}


	/**********************************************************************
	*	bool DoubleLinkedList< T >::isEmpty(  )
	*
	*	   Purpose: Checks to see if the list is empty.
	*
	*		 Entry:	The list may or may not have values in it.  If it 
	*				doesn't, the return value will be true.
	*
	*		  Exit: The bool value is returned.
	*
	**********************************************************************/
	template< typename T >
	bool DoubleLinkedList< T >::isEmpty(  ) const
	{
		return !m_head;
	}

	/**********************************************************************
	*	T & DoubleLinkedList< T >::First(  ) const
	*
	*	   Purpose: Returns the data stored in the m_head pointer.
	*
	*		 Entry:	If the list is empty, and exception is thrown, otherwise
	*				the data is returned.
	*
	*		  Exit:	After the data is returned.
	*
	**********************************************************************/
	template< typename T >
	T & DoubleLinkedList< T >::First(  ) const
	{
		if( isEmpty() )
			throw "ERROR:  List is empty\n";
		return m_head->m_data;
	}

	/**********************************************************************
	*	T & DoubleLinkedList< T >::Last(  ) const
	*
	*	   Purpose: Returns the data stored in the m_tail pointer.
	*
	*		 Entry:	If the list is empty, and exception is thrown, otherwise
	*				the data is returned.
	*
	*		  Exit:	After the data is returned.
	*
	**********************************************************************/
	template< typename T >
	const T & DoubleLinkedList< T >::Last(  ) const
	{
		if( isEmpty(  ) )
			throw "ERROR:  List is empty\n";
		return m_tail->m_data;
	}

	/**********************************************************************
	*	void DoubleLinkedList< T >::Prepend( T data )
	*
	*	   Purpose: Stores 'data' at the front of the list.
	*
	*		 Entry:	'data' is some value.
	*
	*		  Exit: A new node has been created, inserted in the list, and
	*				m_head has been updated.  m_tail too, if it needed to
	*				be.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::Prepend( T data )
	{
		ListNode< T > * add = new ListNode< T >(data);

		if( !isEmpty(  ) )
		{
			m_head->m_prev = add;
			add->m_next = m_head;
		}
		
		if( isEmpty(  ) )
			m_tail = add;
		m_head = add;
	}

	/**********************************************************************
	*	void DoubleLinkedList< T >::Append( T data )
	*
	*	   Purpose: Stores 'data' at the end of the list.
	*
	*		 Entry:	'data' is some value.
	*
	*		  Exit: A new node has been created, inserted in the list, and
	*				m_tail has been updated.  m_head too, if it needed to
	*				be.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::Append( T data )
	{
		ListNode< T > * add = new ListNode< T >(data);

		if( !isEmpty(  ) )
		{
			m_tail->m_next = add;
			add->m_prev = m_tail;
		}

		if( isEmpty(  ) )
			m_head = add;
		m_tail = add;

	}

	/**********************************************************************
	*	void DoubleLinkedList< T >::Purge(  )
	*
	*	   Purpose: Removes all nodes from a list.
	*
	*		 Entry:	The list has an undetermined amount of data stored in
	*				it.
	*
	*		  Exit:	The list is now empty.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::Purge(  )
	{
		ListNode< T > * temp = nullptr;

		while( m_head != nullptr )
		{
			temp = m_head;
			m_head = m_head->m_next;
			delete temp;
		}
		m_head = nullptr;
		m_tail = nullptr;
	}

	/**********************************************************************
	*	void DoubleLinkedList< T >::Extract( T param )
	*
	*	   Purpose:	Removes a specific node from the list.
	*
	*		 Entry:	'param' is the value stored in the node that is to be
	*				removed.
	*
	*		  Exit:	If the value isn't found, or the list is empty, an 
	*				exception is thrown.  Otherwise 'param' is removed
	*				from the list. 
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::Extract( T param )
	{
		if( isEmpty(  ) )
			throw "ERROR:  List is empty\n";

		ListNode< T > * travel = m_head;
		ListNode< T > * trail = nullptr;

		while( travel != nullptr && travel->m_data != param )
		{
			trail = travel;
			travel = travel->m_next;
		}

		if( travel == nullptr )
			throw "ERROR:  Parameter doesn't exist\n";

		if( trail == nullptr )				
		{
			m_head = travel->m_next;
			if( m_head == nullptr )
				m_tail = nullptr;
		}
		else if( travel->m_next == nullptr )
		{
			m_tail = travel->m_prev;
			m_tail->m_next = nullptr;
		}
		else
		{
			trail->m_next = travel->m_next;
			trail = travel->m_next;
			trail->m_prev = travel->m_prev;
		}
		delete travel;

		travel = nullptr;
		trail = nullptr;
	}

	/**********************************************************************
	*	void DoubleLinkedList< T >::InsertAfter( T data, T param )
	*
	*	   Purpose: Inserts 'data' after the node that contains 'param'.
	*
	*		 Entry: 'data' and 'param' are some values to compare.  If
	*				they are complex data types, the comparison operators
	*				for that type need to be overloaded.
	*
	*		  Exit: A new node has been created with 'data' stored in it, 
	*				and inserted after the node that contains 'param'.
	*				Will throw exceptions if the list is empty or the 
	*				'param' value is not found.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::InsertAfter( T data, T param )
	{	
		if( isEmpty(  ) )
			throw "ERROR:  List is empty\n";

		ListNode< T > * levart = m_tail;
		ListNode< T > * liart = nullptr;

		while( levart != nullptr && levart->m_data != param )
		{
			liart = levart;
			levart = levart->m_prev;
		}

		if( levart == nullptr )
			throw "ERROR:  Parameter doesn't exist\n";

		ListNode< T > * add = new ListNode< T >( data );

		if( liart != nullptr )
			liart->m_prev = add;
		else
			m_tail = add;

		add->m_next = liart;
		add->m_prev = levarat;
		levart->m_next = add;
	}

	/**********************************************************************
	*	void DoubleLinkedList< T >::InsertBefore( T data, T param )
	*
	*	   Purpose: Inserts 'data' before the node that contains 'param'.
	*
	*		 Entry: 'data' and 'param' are some values to compare.  If
	*				they are complex data types, the comparison operators
	*				for that type need to be overloaded.
	*
	*		  Exit: A new node has been created with 'data' stored in it, 
	*				and inserted before the node that contains 'param'.
	*				Will throw exceptions if the list is empty or the 
	*				'param' value is not found.
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::InsertBefore( T data, T param )
	{
		if( isEmpty(  ) )
			throw "ERROR:  List is empty\n";

		ListNode< T > * travel = m_head;
		ListNode< T > * trail = nullptr;

		while( travel != nullptr && travel->m_data != param )
		{
			trail = travel;
			travel = travel->m_next;
		}
		
		if( travel == nullptr )
			throw "ERROR:  Parameter doesn't exist\n";

		ListNode< T > * add = new ListNode< T >( data );

		if( trail != nullptr )
			trail->m_next = add;
		else
			m_head = add;

		add->m_prev = trail;
		add->m_next = travel;
		travel->m_prev = add;
	}

#endif