/***********************************************************************
* Class: Class Name
*
*		Description...
*
* Constructors:
*
*	  Mutators:
*
*	   Methods:
*
***********************************************************************/
#ifndef	NODE_H
#define NODE_H

template< typename T > class DoubleLinkedList;

template< typename T >
class node
{
	friend class DoubleLinkedList< T >;

	public:

	// Manager functions

		// No argument constructor
		node(  );

		// One argument constructor
		node( T data );

		// Copy constructor
		node( const node & copy );

		// Assignment operator
		node & operator=( const node & rhs );

		// Destructor
		~node(  );

	// Accessor methods

		// Data Accessor
		T GetData(  ) const;

		// Next pointer accessor
		node * GetNext(  ) const;

		// Previous pointer accessor
		node * GetPrev(  ) const;

	// Mutator methods

		// Data mutator
		void SetData( T data );

		// Next pointer mutator
		void SetNext( node * next );

		// Previous pointer mutator
		void SetPrev( node * prev );

	private:
		T m_data;			// Data stored in the node
		node * m_next;		// Pointer to the next node
		node * m_prev;		// Pointer to the previous node
};

//
// Manager functions
//

	/**********************************************************************
	*	node< T >::node(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T >::node(  ) : 
						m_data(  ), m_next( nullptr ), m_prev( nullptr )
	{  }

	/**********************************************************************
	*	node< T >::node( T data )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T >::node( T data ) : 
						m_data( data ), m_next( nullptr ), m_prev( nullptr )
	{  }

	/**********************************************************************
	*	node< T >::node( const node & copy )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T >::node( const node & copy ) :
						m_data( copy.m_data ), m_next( copy.m_next ), m_prev( copy.m_prev )
	{  }

	/**********************************************************************
	*	node< T > & node< T >::operator=( const node & rhs )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T > & node< T >::operator=( const node & rhs )
	{
		if( this != &rhs )
		{
			m_data = rhs.m_data;
			m_next = rhs.m_next;
			m_prev = rhs.m_next;
		}
	}

	/**********************************************************************
	*	node< T >::~node(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T >::~node(  )
	{  }

//
// Accessor methods
//

	/**********************************************************************
	*	T node< T >::GetData(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	T node< T >::GetData(  ) const
	{
		return m_data;
	}

	/**********************************************************************
	*	node< T > node< T >::GetNext(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T > * node< T >::GetNext(  ) const
	{
		return m_next;
	}

	/**********************************************************************
	*	node< T > node< T >::GetPrev(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	node< T > * node< T >::GetPrev(  ) const
	{
		return m_prev;
	}

//
// Mutator methods
//

	/**********************************************************************
	*	void node< T >::SetData( T data )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void node< T >::SetData( T data )
	{
		m_data = data;
	}

	/**********************************************************************
	*	void node< T >::SetNext( node next )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void node< T >::SetNext( node * next )
	{
		m_next = next;
	}

	/**********************************************************************
	*	void node< T >::SetPrev( node prev )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void node< T >::SetPrev( node * prev )
	{
		m_prev = prev;
	}
	
#endif