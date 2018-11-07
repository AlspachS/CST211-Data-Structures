/**********************************************************************
* Author:						Steven Alspach
* Date Created:					5/29/2015
* Last Modification Date:		5/30/2015
* Lab Number:					L06 HashTable
* File Name:					Lab_6_HashTable.cpp
*
*	  Overview: This file is a test driver for the hash table data
*				structure.
*	
*		 Input:	There is no user input for this file.
*	
*		Output:	The output is various hard-coded values that represent
*				the possible uses and errors the hash table will see.
*		
**********************************************************************/
#include <iostream>
	using std::cout;
	using std::endl;

#include <string>
	using std::string;

#include "HashTable.h"
#include "Exception.h"

const int HASHTABLESIZE = 10;

struct Book
{
	string mTitle;
	string mAuthor;
	int mPages;
};

int AsciiHash( string key );
int XORHash( string key );
void Display( Book & value );

int main(  )
{
	HashTable< string, Book > table( HASHTABLESIZE );

	void ( *visit )( Book& );
	visit = &Display;

	int ( *hash1 )( string );
	hash1 = &AsciiHash;

	int ( *hash2 )( string );
	hash2 = &XORHash;

	try
	{
		table.Traverse( visit );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	table.SetHash( hash1 );

	Book temp10 = { "Hash Array Element 8", "", 1 };
	table.Insert( "0", temp10 );

	Book temp11 = { "Hash Array Element 9", "", 1 };
	table.Insert( "1", temp11 );

	Book temp12 = { "Hash Array Element 0", "", 1 };
	table.Insert( "2", temp12 );

	Book temp13 = { "Hash Array Element 1", "", 1 };
	table.Insert( "3", temp13 );

	Book temp14 = { "Hash Array Element 2", "", 1 };
	table.Insert( "4", temp14 );

	Book temp15 = { "Hash Array Element 3", "", 1 };
	table.Insert( "5", temp15 );

	Book temp16 = { "Hash Array Element 4", "", 1 };
	table.Insert( "6", temp16 );

	Book temp17 = { "Hash Array Element 5", "", 1 };
	table.Insert( "7", temp17 );

	Book temp18 = { "Hash Array Element 6", "", 1 };
	table.Insert( "8", temp18 );

	Book temp19 = { "Hash Array Element 7", "", 1 };
	table.Insert( "9", temp19 );

	Book temp1 = { "C++: An Active Learning Approach", "Randal Albert", 625 };
	table.Insert( "0763757233", temp1 );

	Book temp2 = { "Rodeo for Dummies", "Calvin Caldwell", 1 };
	table.Insert( "7063757233", temp2 );

	Book temp3 = { "And That n There", "Ralph Carestia", 1 };
	table.Insert( "7063757234", temp3 );

	cout << table[ "0763757233" ].mTitle << endl;	
	cout << table[ "7063757233" ].mTitle << endl;
	cout << table[ "7063757234" ].mTitle << endl;

	table.Traverse( visit );

	cout << endl;

	table.Traverse( visit );
	cout << endl;

	table.SetHash( hash2 );

	table.Traverse( visit );
	cout << endl;

	table.SetHash( hash1 );

	table.Traverse( visit );
	cout << endl;

	table.Delete( "7063757234" );
	table.Delete( "7063757233" );
	table.Delete( "0763757233" );

	Book temp5 = { "And That n There", "Ralph Carestia", 1 };
	table.Insert( "7063757234", temp3 );

	try
	{
		Book temp4 = { "And That n There", "Ralph Carestia", 1 };
		table.Insert( "9", temp4 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		table[ "10" ].mAuthor = "Todd Breedlove";
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		table.Delete( "10" );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	return 0;
}

/**********************************************************************
*	int AsciiHash( string key )
*
*	   Purpose: Determines the hash value for a particular data key.
*
*		 Entry:	The key, in this case, is a string of data.  The Ascii
*				values in this string are summed, then modulused by
*				the size of the array portion of the hash table.
*
*		  Exit:	The hash value, an array index value, is returned.
*
**********************************************************************/
int AsciiHash( string key )
{
	int hash( 0 );
	for( unsigned int i( 0 ); i < key.size(  ); ++i )
	{
		hash += key[ i ];
	}
	return hash % HASHTABLESIZE;
}

/**********************************************************************
*	int RotateHash( string key )
*
*	   Purpose: Determines the hash value for a particular data key.
*				I'm not sure what's going on here, I just needed a
*				second hash algorithm to test if the table gets
*				rehashed when the hash data member is changed.
*
*		 Entry:	The key, in this case, is a string of data.  The Ascii
*				values in this string are summed, then modulused by
*				the size of the array portion of the hash table.
*
*		  Exit:	The hash value, an array index value, is returned.
*
**********************************************************************/
int XORHash( string key )
{
    int hash( 0 );

    for( unsigned int i( 0 ); i < key.size(  ); ++i )
    {
        hash ^= key[i];
    }

    return hash % HASHTABLESIZE;
}

/**********************************************************************
*	void Display( Book & value )
*
*	   Purpose: Traverses the hash table and prints out the data 
*				stored in it.  This is just an example function to
*				test the function pointer in the hash table traversal.
*
*		 Entry:	This function will receive a reference to the data
*				so changes can be made to all values in the table.
*
*		  Exit:	All the data has had some action performed on it.
*
**********************************************************************/
void Display( Book & value )
{
	cout << "The book title is " << value.mTitle << endl;
	cout << "by " << value.mAuthor << endl;
}