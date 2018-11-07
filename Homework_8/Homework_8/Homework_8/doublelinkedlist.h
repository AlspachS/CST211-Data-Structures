/***********************************************************************
*    Class: DoubleLinkedList
* Filename: doublelinkedlist.h
*
*		A linked list implementation with next connections and previous
*		connections.
*
* Constructors:
*
*	  Mutators:
*
*	   Methods:
*
***********************************************************************/
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
	using std::cout;
	using std::endl;

#include "Exception.h"
#include "Node.h"

template< typename T >
class DoubleLinkedList
{
	public:

	// Manager functions

		// No argument constructor
		DoubleLinkedList(  );

		// Copy constructors
		DoubleLinkedList( const DoubleLinkedList & copy );

		// Assignment operator
		DoubleLinkedList & operator=( const DoubleLinkedList & rhs );

		// Destructor
		~DoubleLinkedList(  );

	// Accessor methods

		// Head pointer accessor
		node< T > * getHead(  );

		// Tail pointer accessor
		node< T > * getTail(  );

	// Mutator methods

		// Change the head pointer
		void SetHead( node< T > * head );

		// Change the tail pointer
		void SetTail( node< T > * tail );
		
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
		node< T > * m_head;			// Pointer to the start of the list
		node< T > * m_tail;			// Pointer to the end of the list

};
#endif

//
// Manager functions
//

	/**********************************************************************
	*	DoubleLinkedList< T >::DoubleLinkedList(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	DoubleLinkedList< T >::DoubleLinkedList(  ) : 
				m_head( nullptr ), m_tail( nullptr )
	{  }

	/**********************************************************************
	*	DoubleLinkedList< T >::DoubleLinkedList( const DoubleLinkedList & copy )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	DoubleLinkedList< T >::DoubleLinkedList( const DoubleLinkedList & copy ) :
				m_head( nullptr ), m_tail( nullptr )
	{ 
		*this = copy;
	}

	/**********************************************************************
	*	DoubleLinkedList< T > & DoubleLinkedList< T >::operator=( const DoubleLinkedList & rhs )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	DoubleLinkedList< T > & DoubleLinkedList< T >::operator=( const DoubleLinkedList & rhs )
	{ 
		node< T > * travel = nullptr;

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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T > * DoubleLinkedList< T >::getHead(  )
	{
		return m_head;
	}

	/**********************************************************************
	*	node< T > * DoubleLinkedList< T >::getTail(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T > * DoubleLinkedList< T >::getTail(  )
	{
		return m_tail;
	}

//
// Mutator methods
//

	/**********************************************************************
	*	void DoubleLinkedList< T >::SetHead( node * head )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::SetHead( node< T > * head )
	{
		m_head = head;
	}


	/**********************************************************************
	*	void DoubleLinkedList< T >::SetTail( node * tail )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::SetTail( node< T > * tail )
	{
		m_tail = tail;
	}

//
// Member functions
//

	/**********************************************************************
	*	void DoubleLinkedList< T >::PrintForwards(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::Prepend( T data )
	{
		node< T > * add = new node< T >(data);

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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::Append( T data )
	{
		node< T > * add = new node< T >(data);

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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::Purge(  )
	{
		node< T > * temp = nullptr;

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
	*	void DoubleLinkedList< T >::Extract( T data )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::Extract( T param )
	{
		if( isEmpty(  ) )
			throw "ERROR:  List is empty\n";

		node< T > * travel = m_head;
		node< T > * trail = nullptr;

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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::InsertAfter( T data, T param )
	{	
		if( isEmpty(  ) )
			throw "ERROR:  List is empty\n";

		node< T > * levart = m_tail;
		node< T > * liart = nullptr;

		while( levart != nullptr && levart->m_data != param )
		{
			liart = levart;
			levart = levart->m_prev;
		}

		if( levart == nullptr )
			throw "ERROR:  Parameter doesn't exist\n";

		node< T > * add = new node< T >( data );

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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void DoubleLinkedList< T >::InsertBefore( T data, T param )
	{
		if( isEmpty(  ) )
			throw "ERROR:  List is empty\n";

		node< T > * travel = m_head;
		node< T > * trail = nullptr;

		while( travel != nullptr && travel->m_data != param )
		{
			trail = travel;
			travel = travel->m_next;
		}
		
		if( travel == nullptr )
			throw "ERROR:  Parameter doesn't exist\n";

		node< T > * add = new node< T >( data );

		if( trail != nullptr )
			trail->m_next = add;
		else
			m_head = add;

		add->m_prev = trail;
		add->m_next = travel;
		travel->m_prev = add;
	}