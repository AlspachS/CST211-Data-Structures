/***********************************************************************
* 	 Class: HashNode
* Filename:	HashNode.h
*
*		A class to store a lookup key and a data value in a hash table.
*
* Constructors:
*			HashNode( K key, V value )
*				Constructs a HashNode to store the key and value in.
*
*	  Mutators:
*			No mutators available for this class.
*
*	   Methods:
*			No methods available for this class.
*
***********************************************************************/
#ifndef HASHNODE_H
#define HASHNODE_H

template< typename K, typename V >
class HashTable;

template< typename K, typename V >
class HashNode
{
	friend class HashTable< K, V >;

	public:

	// Manager functions

		// No argument constructor
		HashNode( K key, V value );

		// Copy constructor
		HashNode( const HashNode< K, V > & copy );

		// Assignment operator
		HashNode< K, V > & operator=( const HashNode< K, V > & rhs );

		// Destructor
		~HashNode(  );

	private:

		K mKey;			// Key used to determine storage location
		V mValue;		// Value to store in the table

	protected:

};

//
// Manager functions
//

	/**********************************************************************
	*	HashNode< K, V >::HashNode( K key, V value )
	*
	*	   Purpose:	Constructs a HashNode with a lookup key and data
	*				associated with that key.
	*
	*		 Entry:	No HashNode exists.
	*
	*		  Exit: A HashNode can now be stored in the hash table.
	*
	**********************************************************************/
	template< typename K, typename V >
	HashNode< K, V >::HashNode( K key, V value ) :
								mKey( key ), mValue( value )
	{  }

	/**********************************************************************
	*	HashNode< K, V >::HashNode( const HashNode< K, V > & copy )
	*
	*	   Purpose: Creates an HashNode that is a copy of an existing 
	*				HashNode.  Since the two nodes are the same, only one
	*				can be inserted in the hash table.
	*
	*		 Entry:	The new HashNode is not yet created, and 'copy' is 
	*				an HashNode.
	*
	*		  Exit:	The new HashNode is created, and it has the same 
	*				data as 'copy'.
	*
	**********************************************************************/
	template< typename K, typename V >
	HashNode< K, V >::HashNode( const HashNode< K, V > & copy ) :
								mKey( copy.mKey ), mValue( copy.mValue )
	{  }

	/**********************************************************************
	*	HashNode< K, V > & HashNode< K, V >::operator=( const HashNode< K, V > & rhs )
	*
	*	   Purpose:	Assigns an existing HashNode the values of a second
	*				existing HashNode.  Since the two nodes are the same,
	*				only one can be inserted in the hash table
	*
	*		 Entry:	Both HashNodes are objects, and may have data.
	*
	*		  Exit:	The calling HashNode is now a copy of the 'rhs' 
	*				HashNode.
	*
	**********************************************************************/
	template< typename K, typename V >
	HashNode< K, V > & HashNode< K, V >::operator=( const HashNode< K, V > & rhs )
	{
		if( this != &rhs )
		{
			mKey = rhs.mKey;
			mValue = rhs.mValue;
		}
		return *this;
	}

	/**********************************************************************
	*	HashNode< K, V >::~HashNode(  )
	*
	*	   Purpose:	Destroys a HashNode object, removing all data in it, 
	*				and	removing the HashNode object.
	*
	*		 Entry:	The calling HashNode is going out of scope, taking 
	*				its data with it.
	*
	*		  Exit:	The calling HashNode is now gone.
	*
	**********************************************************************/
	template< typename K, typename V >
	HashNode< K, V >::~HashNode(  )
	{  }

#endif