/***********************************************************************
* 	 Class: ListNode
* Filename: ListNode.h
*
*		A node to store data in for a linked list.
*
* Constructors:
*			node(  )
*				Constructs an empty node.
*
*			node( T data )
*				Constructs a node with 'data' stored in it.
*
*	  Mutators:
*			SetData( T data )
*				Sets the data in a node to 'data'.
*
*			SetNext( node * next )
*				Sets the m_next pointer to 'next'.
*
*			SetPrev( node * prev )
*				Sets the m_prev pointer to 'prev'
*
*	   Methods:
*			T GetData(  ) const
*				Returns the value stored in the node.
*
*			node * GetNext(  ) const
*				Returns the next node.
*
*			node * GetPrev(  ) const
*				Returns the previous node.
*
***********************************************************************/
#ifndef	LISTNODE_H
#define LISTNODE_H

template< typename T > class DoubleLinkedList;

template< typename T >
class ListNode
{
	friend class DoubleLinkedList< T >;

	public:

	// Manager functions

		// No argument constructor
		ListNode(  );

		// One argument constructor
		ListNode( T data );

		// Copy constructor
		ListNode( const ListNode< T > & copy );

		// Assignment operator
		ListNode< T > & operator=( const ListNode< T > & rhs );

		// Destructor
		~ListNode(  );

	// Accessor methods

		// Data Accessor
		T GetData(  ) const;

		// Next pointer accessor
		ListNode< T > * GetNext(  ) const;

		// Previous pointer accessor
		ListNode< T > * GetPrev(  ) const;

	// Mutator methods

		// Data mutator
		void SetData( T data );

		// Next pointer mutator
		void SetNext( ListNode< T > * next );

		// Previous pointer mutator
		void SetPrev( ListNode< T > * prev );

	private:
		T m_data;			// Data stored in the node
		ListNode< T > * m_next;		// Pointer to the next node
		ListNode< T > * m_prev;		// Pointer to the previous node
};


//
// Manager functions
//

	/**********************************************************************
	*	ListNode::ListNode(  )
	*
	*	   Purpose: Creates an instance of the node class.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T >::ListNode(  ) : 
						m_data(  ), m_next( nullptr ), m_prev( nullptr )
	{  }

	/**********************************************************************
	*	ListNode::ListNode(  )
	*
	*	   Purpose: Creates an instance of the node class and stored 'data'
	*				in m_data.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T >::ListNode( T data ) : 
						m_data( data ), m_next( nullptr ), m_prev( nullptr )
	{  }

	/**********************************************************************
	*	ListNode::ListNode( const ListNode & copy )
	*
	*	   Purpose: Creates a node object that is a copy of an 
	*				existing node object.
	*
	*		 Entry:	'copy' is some existing node object.
	*
	*		  Exit:	'this' is now a replica of 'copy'.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T >::ListNode( const ListNode< T > & copy ) :
						m_data( copy.m_data ), m_next( copy.m_next ), m_prev( copy.m_prev )
	{  }

	/**********************************************************************
	*	ListNode & ListNode::operator=( const ListNode & rhs )
	*
	*	   Purpose:	Overwrites one node object with the data of another.
	*
	*		 Entry:	'this' has unimportant data that will be overwritten,
	*				and 'rhs' is the source of the data.
	*
	*		  Exit:	'this' will be the same as 'rhs'.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T > & ListNode< T >::operator=( const ListNode< T > & rhs )
	{
		if( this != &rhs )
		{
			m_data = rhs.m_data;
			m_next = rhs.m_next;
			m_prev = rhs.m_next;
		}
	}

	/**********************************************************************
	*	ListNode::~ListNode(  )
	*
	*	   Purpose: Destroys a node object.
	*
	*		 Entry:	'this' is some object.
	*
	*		  Exit: 'this' is no longer an object.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T >::~ListNode(  )
	{  }

//
// Accessor methods
//

	/**********************************************************************
	*	T ListNode< T >::GetData(  )
	*
	*	   Purpose: Access the data stored in a node.
	*
	*		 Entry:	'm_data' is some value.
	*
	*		  Exit:	The value in 'm_data' is returned.
	*
	**********************************************************************/
	template< typename T >
	T ListNode< T >::GetData(  ) const
	{
		return m_data;
	}

	/**********************************************************************
	*	ListNode< T > * ListNode< T >::GetNext(  )
	*
	*	   Purpose: Accesses the next node.
	*
	*		 Entry:	'm_next' is the pointer to the next node in the list.
	*
	*		  Exit:	'm_next' is returned.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T > * ListNode< T >::GetNext(  ) const
	{
		return m_next;
	}

	/**********************************************************************
	*	ListNode< T > * ListNode< T >::GetPrev(  )
	*
	*	   Purpose: Accesses the prev node.
	*
	*		 Entry:	'm_prev' is the pointer to the prev node in the list.
	*
	*		  Exit:	'm_prev' is returned.
	*
	**********************************************************************/
	template< typename T >
	ListNode< T > * ListNode< T >::GetPrev(  ) const
	{
		return m_prev;
	}

//
// Mutator methods
//

	/**********************************************************************
	*	void ListNode< T >::SetData( T data )
	*
	*	   Purpose: Stores 'data' in the node.
	*
	*		 Entry:	'data' is some value.
	*
	*		  Exit: 'm_data' is now 'data'.
	*
	**********************************************************************/
	template< typename T >
	void ListNode< T >::SetData( T data )
	{
		m_data = data;
	}

	/**********************************************************************
	*	void ListNode< T >::SetNext( ListNode< T > * next )
	*
	*	   Purpose: Changes the node the next pointer is pointing at.
	*
	*		 Entry:	'next' is a node pointer.
	*
	*		  Exit: 'm_next' is now 'next'.
	*
	**********************************************************************/
	template< typename T >
	void ListNode< T >::SetNext( ListNode< T > * next )
	{
		m_next = next;
	}

	/**********************************************************************
	*	void ListNode< T >::SetPrev( ListNode< T > * prev )
	*
	*	   Purpose: Changes the node the previous pointer is pointing at.
	*
	*		 Entry:	'prev' is a node pointer.
	*
	*		  Exit: 'm_prev' is now 'prev'.
	*
	**********************************************************************/
	template< typename T >
	void ListNode< T >::SetPrev( ListNode< T > * prev )
	{
		m_prev = prev;
	}

#endif