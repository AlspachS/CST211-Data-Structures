#include "MorseTree.h"


	/**********************************************************************
	*	MorseTree::MorseTree(  )
	*
	*	   Purpose:	Creates a tree with the data from the Morse.dat file.
	*
	*		 Entry: No tree exists.
	*
	*		  Exit: A MorseTree object has been created.
	*
	**********************************************************************/
	MorseTree::MorseTree(  ) : 
						mRoot( nullptr )
	{
		mRoot = new TreeNode< string >( "*" );

		string morse( "" );
		string letter( "" );
		ifstream fin;
		fin.open( "Morse.dat" );

		while( !fin.eof(  ) )
		{
			getline( fin, morse );
			letter = morse[ 0 ];

			Insert( letter, &morse[ 1 ] );
		}
		fin.close(  );
	}

	/**********************************************************************
	*	MorseTree::MorseTree( const MorseTree & copy )
	*
	*	   Purpose: Copies one MorseTree into a MorseTree being created.
	*
	*		 Entry:	One MorseTree exists, the other is being created.
	*
	*		  Exit: Two MorseTree now exist, one of which is a copy of the other.
	*
	**********************************************************************/
	MorseTree::MorseTree( const MorseTree & copy ) :
						mRoot( nullptr )
	{ 
		*this = copy;
	}

	/**********************************************************************
	*	MorseTree & MorseTree::operator=( const MorseTree & rhs )
	*
	*	   Purpose: Copies one existing MorseTree into another existing MorseTree.
	*
	*		 Entry: Two MorseTrees exist, one of which will become the same
	*				as the other.
	*
	*		  Exit: The two MorseTrees are now the same.
	*
	**********************************************************************/
	MorseTree & MorseTree::operator=( const MorseTree & rhs )
	{
		if( this != &rhs )
		{
			Copy( mRoot, rhs.mRoot );
		}
		return * this;
	}

	/**********************************************************************
	*	MorseTree::~MorseTree(  )
	*
	*	   Purpose:	Destroys a MorseTree object as it goes out of scope.
	*
	*		 Entry: When an object leaves scope.
	*
	*		  Exit: After the object is destroyed.
	*
	**********************************************************************/
	MorseTree::~MorseTree(  )
	{ 
		Purge(  );
	}

	/**********************************************************************
	*	void MorseTree::Insert( string data )
	*
	*	   Purpose: User-interface for the recursive insert function.
	*
	*		 Entry: The tree has read in some data, and that data is passed
	*				to the recursive insert function.
	*
	*		  Exit: The data has been inserted in the tree in the appropriate
	*				location.
	*
	**********************************************************************/
	void MorseTree::Insert( string data, string morse )
	{
		Insert( data, morse, mRoot );
	}

	/**********************************************************************
	*	void MorseTree::Insert( string data, TreeNode< string > *& root )
	*
	*	   Purpose: Recursive function that receives the data from the user
	*				interface insert function.  Searches for the correct
	*				location in the tree until an empty node has been found.
	*				Creates a node at this location with the data.  This 
	*				also leaves a trail of empty nodes in its wake.
	*
	*		 Entry: The data is the character the constructor has read in,
	*				and root is the current node the function is at.
	*
	*		  Exit:	The data is in the correct location and the call stack
	*				has unwound.  As the call stack unwinds, the parent
	*				pointer is set to the current node.
	*
	**********************************************************************/
	void MorseTree::Insert( string data, string morse, TreeNode< string > *& root )
	{
		if( root == nullptr )
			root = new TreeNode< string >(  );
		
		if( morse.size(  ) != 0 )
		{
			if( morse[ 0 ] == '.' )
			{	
				Insert( data, &morse[ 1 ], root->mLeftChild );
				root->mLeftChild->mParent = root;
			}	
			else
			{
				Insert( data, &morse[ 1 ], root->mRightChild );		
				root->mRightChild->mParent = root;
			}
		}
		else
		{
			root->mData = data;
			mAlphabet.push_back( root );
		}
	}

	/**********************************************************************
	*	void MorseTree::Purge(  )
	*
	*	   Purpose: User interface for the recursive purge function.
	*
	*		 Entry:	The tree may or may not have data in it.
	*
	*		  Exit:	The tree doesn't have any data in it.
	*
	**********************************************************************/
	void MorseTree::Purge(  )
	{
		Purge( mRoot );
	}

	/**********************************************************************
	*	void MorseTree::Purge( TreeNode< string > *& root )
	*
	*	   Purpose: Removes all data from the tree.
	*
	*		 Entry: The tree may or may not have data in it.
	*
	*		  Exit:	All data is removed from the tree and the root node
	*				is set to nullptr.
	*
	**********************************************************************/
	void MorseTree::Purge( TreeNode< string > *& root )
	{
		if( root != nullptr )
		{
			Purge( root->mLeftChild );
			Purge( root->mRightChild );

			delete root;
			root = nullptr;
		}
	}

	/**********************************************************************
	*	string MorseTree::Decode( string morse )
	*
	*	   Purpose: Decodes the morse string that is passed into the function
	*				and returns a character value that morse value represents.
	*
	*		 Entry: 'morse' is a string of dots and dashes that represent
	*				a morse code value.
	*
	*		  Exit:	The character represented by the string 'morse' is 
	*				found and returned.
	*
	**********************************************************************/
	string MorseTree::Decode( string morse )
	{
		return Decode( morse, mRoot );
	}

	/**********************************************************************
	*	string MorseTree::Decode( string morse, TreeNode< string > *& root )
	*
	*	   Purpose: Does the heavy-lifting of the decode function.  
	*				Recurses down the tree, using the morse string, to
	*				find the character the morse string represents.
	*
	*		 Entry: 'morse' is a string to indicate the direction to 
	*				travel in the tree (dot to go left, dash to go right).
	*				Root is the root of the tree being traversed.
	*
	*		  Exit:	The character value that 'morse' represents is found and
	*				returned.
	*				is set to nullptr.
	*
	**********************************************************************/
	string MorseTree::Decode( string morse, TreeNode< string > *& root )
	{
		string toReturn( "" );

		if( morse.size(  ) != 0 )
		{
			if( morse[ 0 ] == '.' )
				toReturn = Decode( &morse[ 1 ], root->mLeftChild );
			else
				toReturn = Decode( &morse[ 1 ], root->mRightChild );
		}
		else
			toReturn = root->mData;

		return toReturn;
	}

	/**********************************************************************
	*	string MorseTree::Encode( string text )
	*
	*	   Purpose: Receives the word to encode into morse code.  Makes all
	*				characters in the word uppercase, finds their location
	*				in the 'mAlphabet' vector to get the starting TreeNode
	*				then calls the recursive Encode function.  After the
	*				recursive insert exits, the received value is reversed
	*				and has a space appended to the end.  After the entire
	*				word is encoded, a morse code space is appended to the
	*				end of the word.  After all this, the morse string is
	*				returned.
	*
	*		 Entry: 'text' is a word to be encoded into morse code.
	*
	*		  Exit:	The morse code value for the word is returned.
	*
	**********************************************************************/
	string MorseTree::Encode( string text )
	{
		string toReturn( "" );
		string morse( "" );
		int index( 0 );

		for( unsigned int i( 0 ); i < text.size(  ); ++i )
		{
			text[ i ] = toupper( text[ i ] );
			index = ( text[ i ] - 65 );

			morse = Encode( mAlphabet[ index ] );
			reverse( morse.begin(  ), morse.end(  ) );
			toReturn += morse;
			toReturn += " ";
		}

		toReturn += Encode( mAlphabet[ 26 ] );
		toReturn += " ";

		return toReturn;
	}

	/**********************************************************************
	*	void MorseTree::Encode( TreeNode< string > *& start )
	*
	*	   Purpose: Gathers the dots and dashes to encode a character into
	*				morse code.  This happens by going to a node in the tree
	*				and following the 'mParent' pointers up the tree gathering
	*				dots and dashes until it gets to 'mRoot'.  Once it gets
	*				to 'mRoot', the string of dots and dashes are backward,
	*				This is compensated for in the public Encode function.
	*
	*		 Entry: 'start' is the node of the character to encode.
	*
	*		  Exit:	'toReturn' has gathered the backward string of dots
	*				and dashes.
	*
	**********************************************************************/
	string MorseTree::Encode( TreeNode< string > *& start )
	{
		string toReturn( "" );

		if( start != mRoot )
		{
			if( start->mParent->mLeftChild == start )
			{
				toReturn += ".";
				toReturn += Encode( start->mParent );
			}
			else
			{
				toReturn += "-";
				toReturn += Encode( start->mParent );
			}
		}
		return toReturn;
	}

	/**********************************************************************
	*	void MorseTree::Copy( TreeNode< string > *& copy, const TreeNode< string > * orig )
	*
	*	   Purpose: Creates a copy of a tree by recursively copying all the
	*				nodes in the tree.
	*
	*		 Entry:	The copy node is the node to copy the original node 
	*				into.
	*
	*		  Exit:	The node is copied.  When all instances of the function
	*				resolve, the tree should be copied.
	*
	**********************************************************************/
	void MorseTree::Copy( TreeNode< string > *& copy, const TreeNode< string > * orig )
	{
		if( orig != nullptr )
		{
			copy = new TreeNode< string >( orig->mData );
			Copy( copy->mLeftChild, orig->mLeftChild );
			Copy( copy->mRightChild, orig->mRightChild );
			mAlphabet.push_back( copy );

			if( copy->mLeftChild != nullptr )
				copy->mLeftChild->mParent = copy;
			if( copy->mRightChild != nullptr )
				copy->mRightChild->mParent = copy;
		}
		else
			copy = nullptr;
	}

