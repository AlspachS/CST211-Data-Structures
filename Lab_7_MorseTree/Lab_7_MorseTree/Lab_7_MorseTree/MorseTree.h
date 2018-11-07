/***********************************************************************
* 	 Class: MorseTree
* Filename: BinarySearchTree.h
*
*		This is a binary search tree data structure.
*
* Constructors:
*			MorseTree(  )
*				No argument constructor that initializes an empty tree.
*			
*	  Mutators:
*			void Insert( string data, TreeNode< string > *& root )
*				Recursively finds the correct location in the tree to 
*				insert the data passed in by the user.
*
*			void Purge( TreeNode< string > *& root )
*				Deletes all data from the tree.	
*
*	   Methods:
*			void Insert( string data )
*				Receives the data the user wants to insert to the tree
*				and then calls the recursive insert function to finish
*				the insertion.
*
*			void Purge(  )
*				Gets called by the user when they want to delete all
*				data in the tree.  This function calls the recursive
*				delete function.
*
*			void Copy( TreeNode< string > *& copy, const TreeNode< string > * orig )
*				Recursively copies all nodes in a tree until a copy of the
*				original tree exists.
*
*			string Decode( string morse )
*				Receives the string to decode and calls the recursive 
*				decode function.
*
*			string Encode( string text )
*				Receives the string to encode and calls the recursive
*				encode function.
*
*			string Decode( string morse, TreeNode< string > *& root )
*				Receives the string to decode and recurses down the 
*				tree to the appropriate node and returns the value
*				in that node.
*			
*			string Encode( TreeNode< string > *& start )
*				Receives the address of the value to encode and recurses
*				up the tree, gathering dots and dashes as it goes.
*
***********************************************************************/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include "Exception.h"

#include <fstream>
	using std::ifstream;

#include <algorithm>
	using std::reverse;

#include <string>
	using std::string;

#include <vector>
	using std::vector;

class MorseTree
{
	public:
	
	// Manager functions

		// No argument constructor
		MorseTree(  );

		// Copy constructor
		MorseTree( const MorseTree & copy );

		// Assignment operator
		MorseTree & operator=( const MorseTree & rhs );

		// Destructor
		~MorseTree(  );

	// Member interfaces

		// User-available insert function
		void Insert( string data, string morse );

		// User-available purge function
		void Purge(  );

		// User-available decode function
		string Decode( string morse );

		// User-available endcode function
		string Encode( string text );
	
	protected:
		
	// Member functions

		// Inserts the data sent from the public insert into the tree
		void Insert( string data, string morse, TreeNode< string > *& root );

		// Deletes all data from the tree
		void Purge( TreeNode< string > *& root );

		// Copies one tree into another tree
		void Copy( TreeNode< string > *& copy, const TreeNode< string > * orig );

		// Decodes a morse value passed into the tree
		string Decode( string morse, TreeNode< string > *& root );

		// Encodes a text value passed into the tree
		string Encode( TreeNode< string > *& start );
	
		TreeNode< string > * mRoot;							// TreeNode that is the root of the tree
		vector< TreeNode< string > * > mAlphabet;			// Alphabet

};
#endif