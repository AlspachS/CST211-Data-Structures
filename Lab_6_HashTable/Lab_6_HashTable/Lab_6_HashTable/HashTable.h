/***********************************************************************
* 	 Class: HashTable
* Filename:	HashTable.h
*
*		An implementation of a hash table.
*
* Constructors:
*			HashTable( int size )
*				Creates a HashTable object and sets the number of 
*				buckets to size.
*
*	  Mutators:
*			void Insert( K key, V value )
*				Creates a HashNode and inserts places it in the correct
*				bucket.
*
*			void SetHash( int ( *hash )( K key ) )
*				Sets the hash algorithm to a user-defined algorithm and
*				rehashes the table to fit this new algorithm.
*
*			void Delete( K key )
*				Removes a HashNode from the hash table.
*
*	   Methods:
*			void Traverse( void ( *visit )( V & value ) );
*
***********************************************************************/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
	using std::list;
	using std::iterator;

#include <vector>
	using std::vector;
	using std::iterator;

#include "Exception.h"
#include "HashNode.h"

template< typename K, typename V >
class HashTable
{
	public:

	// Manager functions

		// One argument constructor
		HashTable( int size );

		// Copy constructor
		HashTable( const HashTable< K, V > & copy );

		// Assignment operator
		HashTable< K, V > & operator=( const HashTable< K, V > & rhs );

		// Destructor
		~HashTable(  );

	// Operator overloads

		// Subscript operator
		V & operator[]( K key );

	// Mutator functions

		// Insert an entry in the table
		void Insert( K key, V value );

		// Set hash function
		void SetHash( int ( *hash )( K key ) );

		// Remove an entry from the table
		void Delete( K key );

	// Accessor functions

		// Traverses the table
		void Traverse( void ( *visit )( V & value ) );

	private:

		vector< list< HashNode< K, V > > > mTable;		// Array of linked lists to store values
		int ( *mHash )( K );							// Pointer to the hash function

	protected:

};

//
// Manager functions
//

	/**********************************************************************
	*	HashTable< K, V >::HashTable( int size )
	*
	*	   Purpose:	Constructs an empty HashTable.  The size of the hash
	*				table array is set to size.
	*
	*		 Entry:	No HashTable exists.
	*
	*		  Exit: An empty HashTable can now be used.
	*
	**********************************************************************/
	template< typename K, typename V >
	HashTable< K, V >::HashTable( int size )
	{
		mTable.resize( size );
	}

	/**********************************************************************
	*	HashTable< K, V >::HashTable( const HashTable< K, V > & copy )
	*
	*	   Purpose: Creates an HashTable that is a copy of an existing 
	*				HashTable.
	*
	*		 Entry:	The new HashTable is not yet created, and 'copy' is 
	*				an HashTable.
	*
	*		  Exit:	The new HashTable is created, and it has the same 
	*				data as 'copy'.
	*
	**********************************************************************/
	template< typename K , typename V >
	HashTable< K, V >::HashTable( const HashTable< K, V > & copy ) : 
									mTable( copy.mTable ), mHash( copy.mHash )
	{  }

	/**********************************************************************
	*	HashTable< K, V > & HashTable< K, V >::operator=( const HashTable< K, V > & rhs )
	*
	*	   Purpose:	Assigns an existing HashTable the values of a second
	*				existing HashTable.
	*
	*		 Entry:	Both HashTables are objects, and may have data.
	*
	*		  Exit:	The calling HashTable is now a copy of the 'rhs' 
	*				HashTable.
	*
	**********************************************************************/
	template< typename K, typename V >
	HashTable< K, V > & HashTable< K, V >::operator=( const HashTable< K, V > & rhs )
	{
		if( this != &rhs )
		{
			mTable = rhs.mTable;
			mHash = rhs.mHash;
		}
		return *this;
	}

	/**********************************************************************
	*	HashTable< K, V >::~HashTable(  )
	*
	*	   Purpose:	Destroys a HashTable object, removing all data in it, 
	*				and	removing the HashTable object.
	*
	*		 Entry:	The calling HashTable is going out of scope, taking 
	*				its data with it.
	*
	*		  Exit:	The calling HashTable is now gone.
	*
	**********************************************************************/
	template< typename K, typename V >
	HashTable< K, V >::~HashTable(  )
	{  }

//
// Operator overloads
//

	/**********************************************************************
	*	V & HashTable< K, V >::operator[]( K key )
	*
	*	   Purpose: Allows the user to access the data in the hash table
	*				with the key that is paired with the data value.
	*
	*		 Entry:	Key is the lookup key of the value the user wants to
	*				access.
	*
	*		  Exit:	A reference to the data has been returned.
	*
	**********************************************************************/
	template< typename K, typename V >
	V & HashTable< K, V >::operator[]( K key )
	{
		int index( mHash( key ) );
		bool found( false );
		list< HashNode< K, V > >::iterator mListIt;

		for( mListIt = mTable[ index ].begin(  ); mListIt != mTable[ index ].end(  ) && !found; ++mListIt )
		{
			if( mListIt->mKey == key )
				found = true;
		}

		if( !found )
			throw Exception( "Cannot access, data doesn't exist" );

		return ( --mListIt )->mValue;
	}

//
// Mutator functions
//

	/**********************************************************************
	*	void HashTable< K, V >::Insert( K key, V value )
	*
	*	   Purpose: Inserts a value into the hash table according the the
	*				hash function.
	*
	*		 Entry:	Value is the data the user wants to store in the 
	*				hash table, and key is the lookup key for that data
	*				value.
	*
	*		  Exit:	Key and Value have been used to construct a HashNode,
	*				key has been run through the hash function to find the
	*				index of the array the value should be placed in, and 
	*				the HashNode containing key and value has been
	*				inserted in the hash table.
	*
	**********************************************************************/
	template< typename K, typename V >
	void HashTable< K, V >::Insert( K key, V value )
	{
		HashNode< K, V > next( key, value );
		int index( mHash( key ) );
		bool found( false );
		list< HashNode< K, V > >::iterator mListIt;

		for( mListIt = mTable[ index ].begin(  ); mListIt != mTable[ index ].end(  ) && !found; ++mListIt )
		{
			if( mListIt->mKey == key )
				found = true;
		}

		if( found )
			throw Exception( "Cannot insert, duplicate value" );

		mTable[ index ].push_back( next );
	}

	/**********************************************************************
	*	void HashTable< K, V >::SetHash( int ( *hash )( K key ) )
	*
	*	   Purpose:	Sets the hash function to a new function.  When this 
	*				happens, the table is rehashed and all values are 
	*				placed into new locations according to the new hash
	*				function.
	*
	*		 Entry:	*hash is a pointer to the new hash function.
	*
	*		  Exit:	mHash has been set to *hash, and the table has been
	*				rehashed according to the new hash function.
	*
	**********************************************************************/
	template< typename K, typename V >
	void HashTable< K, V >::SetHash( int ( *hash )( K key ) )
	{
		vector< list< HashNode< K, V > > >::iterator mVecIt;
		list< HashNode< K, V > >::iterator mListIt;
		vector< list< HashNode< K, V > > > inter;
		int index( 0 );

		mHash = hash;
		inter.resize( mTable.size(  ) );

		for( mVecIt = mTable.begin(  ); mVecIt != mTable.end(  ); ++mVecIt )
		{
			for( mListIt = mVecIt->begin(  ); mListIt != mVecIt->end(  ); ++mListIt )
			{
				index = mHash( mListIt->mKey );
				HashNode< K, V > mediate( mListIt->mKey, mListIt->mValue );
				inter[ index ].push_back( mediate );
			}
		}
		mTable = inter;
	}

	/**********************************************************************
	*	void HashTable< K, V >::Delete( K key )
	*
	*	   Purpose: Removes a value from the hash table.
	*
	*		 Entry:	Key is the lookup key associated with the value to 
	*				remove from the table.
	*
	*		  Exit:	The data and its key have been removed from the hash
	*				table.
	*
	**********************************************************************/
	template< typename K, typename V >
	void HashTable< K, V >::Delete( K key )
	{
		int index( mHash( key ) );
		bool found( false );
		list< HashNode< K, V > >::iterator mListIt;

		for( mListIt = mTable[ index ].begin(  ); mListIt != mTable[ index ].end(  ) && !found; ++mListIt )
		{
			if( mListIt->mKey == key )
				found = true;
		}
		if( !found )
			throw Exception( "Cannot delete, data doesn't exist" );

		mTable[ index ].erase( --mListIt );
	}

//
// Accessor functions
//

	/**********************************************************************
	*	void HashTable< K, V >::Traverse( void ( *visit )( V & value ) )
	*
	*	   Purpose: Allows the user to travers the hash table and perform
	*				some action on all values stored in the
	*
	*		 Entry: The table has some values, and the visit function will
	*				be called for all elements.
	*
	*		  Exit:	Whatever action visit performs has been done.
	*
	**********************************************************************/
	template< typename K, typename V >
	void HashTable< K, V >::Traverse( void ( *visit )( V & value ) )
	{
		vector< list< HashNode< K, V > > >::iterator mVecIt;
		list< HashNode< K, V > >::iterator mListIt;
		int thing( 0 );

		for( mVecIt = mTable.begin(  ); mVecIt != mTable.end(  ); ++mVecIt )
		{
			for( mListIt = mVecIt->begin(  ); mListIt != mVecIt->end(  ); ++mListIt )
			{
				visit( mListIt->mValue );
				thing += mVecIt->size(  );
			}
		}

		if( !thing )
			throw Exception( "Hash Table is empty" );
	}

#endif