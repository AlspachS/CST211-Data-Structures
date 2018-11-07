/***********************************************************************
* 	 Class: BSTree
* Filename: BinarySearchTree.h
*
*		This is a binary search tree data structure.
*
* Constructors:
*			BSTree(  )
*				No argument constructor that initializes an empty tree.
*			
*	  Mutators:
*			void Insert( T data, TreeNode< T > *& root )
*				Recursively finds the correct location in the tree to 
*				insert the data passed in by the user.
*
*			void DeleteNode( TreeNode< T > *& root )
*				Deletes the node containing the data the user wants to
*				remove from the tree.
*
*			void Purge( TreeNode< T > *& root )
*				Deletes all data from the tree.	
*
*	   Methods:
*			void Insert( T data )
*				Receives the data the user wants to insert to the tree
*				and then calls the recursive insert function to finish
*				the insertion.
*
*			void Delete( T param )
*				Receives the data the user wants to delete, finds the 
*				node that contains the data, and passes that node to
*				the DeleteNode function to finish the deletion.
*
*			void Purge(  )
*				Gets called by the user when they want to delete all
*				data in the tree.  This function calls the recursive
*				delete function.
*
*			int Height(  )
*				Gets called by the user when they want to find the 
*				height of the tree.
*
*			int Height( TreeNode< T > *& root )
*				Recursively calculates the height of the tallest 
*				branch of tree.
*
*			void Copy( TreeNode< T > *& copy, const TreeNode< T > * orig )
*				Recursively copies all nodes in a tree until a copy of the
*				original tree exists.
*
*			void InOrder( void ( *StuffToDo )( T& ) )
*				Calls the recursive traversal function.
*
*			void InOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
*				Recurses into the tree and displays the data in each node
*				in the tree.
*
*			void PreOrder( void ( *StuffToDo )( T& ) )
*				Calls the recursive traversal function.
*
*			void PreOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
*				Recurses into the tree and displays the data in each node
*				in the tree.
*
*			void PostOrder( void ( *StuffToDo )( T& ) )
*				Calls the recursive traversal function.
*
*			void PostOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
*				Recurses into the tree and displays the data in each node
*				in the tree.
*
*			void BreadthFirst( void ( *StuffToDo )( T& ) )
*				Calls the recursive traversal function.
*
*			void BreadthFirst( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
*				Recurses into the tree and displays the data in each node
*				in the tree.
*
***********************************************************************/
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include "Exception.h"
#include "ListQueue.h"

template< typename T >
class BSTree
{
	public:
	
	// Manager functions

		// No argument constructor
		BSTree(  );

		// Copy constructor
		BSTree( const BSTree< T > & copy );

		// Assignment operator
		BSTree< T > & operator=( const BSTree< T > & rhs );

		// Destructor
		~BSTree(  );

	// Member interfaces

		// User-available insert function
		void Insert( T data );

		// User-available delete function
		void Delete( T param );

		// User-available purge function
		void Purge(  );

		// User-available height function
		int Height(  );
	
		// User-available inorder traversal
		void InOrder( void ( *StuffToDo )( T& ) );

		// User-available preorder traversal
		void PreOrder( void ( *StuffToDo )( T& ) );

		// User-available postorder traversal
		void PostOrder( void ( *StuffToDo )( T& ) );

		// User-available breadthfirst traversal
		void BreadthFirst( void ( *StuffToDo )( T& ) );
	
	protected:
		
	// Member functions

		// Inserts the data sent from the public insert into the tree
		void Insert( T data, TreeNode< T > *& root );

		// Deletes the node containing the data, sent from the public delete, from the tree
		void DeleteNode( TreeNode< T > *& root );

		// Deletes all data from the tree
		void Purge( TreeNode< T > *& root );

		// Determines the height of the tree
		int Height( TreeNode< T > *& root );

		// Copies one tree into another tree
		void Copy( TreeNode< T > *& copy, const TreeNode< T > * orig );

		// Traverses the tree in order of the data
		void InOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode );

		// Traverses the tree in order of 
		void PreOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode );

		// Traverses the tree in order of
		void PostOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode );

		// Traverses the tree according to levels
		void BreadthFirst( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode );
	
		TreeNode< T > * mRoot;			// TreeNode that is the root of the tree

};

	/**********************************************************************
	*	BSTree< T >::BSTree(  )
	*
	*	   Purpose:	Creates an empty tree, and prepares it to insert data.
	*
	*		 Entry: No tree exists.
	*
	*		  Exit: A tree object has been created.
	*
	**********************************************************************/
	template< typename T >
	BSTree< T >::BSTree(  ) : 
						mRoot( nullptr )
	{  }

	/**********************************************************************
	*	BSTree< T >::BSTree( const BSTree< T > & copy )
	*
	*	   Purpose: Copies one tree into a tree being created.
	*
	*		 Entry:	One tree exists, the other is being created.
	*
	*		  Exit: Two tree now exist, one of which is a copy of the other.
	*
	**********************************************************************/
	template< typename T >
	BSTree< T >::BSTree( const BSTree< T > & copy ) :
						mRoot( nullptr )
	{ 
		*this = copy;
	}

	/**********************************************************************
	*	BSTree< T > & BSTree< T >::operator=( const BSTree< T > & rhs )
	*
	*	   Purpose: Copies one existing tree into another existing tree.
	*
	*		 Entry: Two trees exist, one of which will become the same
	*				as the other.
	*
	*		  Exit: The two trees are now the same.
	*
	**********************************************************************/
	template< typename T >
	BSTree< T > & BSTree< T >::operator=( const BSTree< T > & rhs )
	{
		if( this != &rhs )
		{
			Copy( mRoot, rhs.mRoot );
		}
		return * this;
	}

	/**********************************************************************
	*	BSTree< T >::~BSTree(  )
	*
	*	   Purpose:	Destroys a tree object as it goes out of scope.
	*
	*		 Entry: When an object leaves scope.
	*
	*		  Exit: After the object is destroyed.
	*
	**********************************************************************/
	template< typename T >
	BSTree< T >::~BSTree(  )
	{ 
		Purge(  );
	}

	/**********************************************************************
	*	void BSTree< T >::Insert( T data )
	*
	*	   Purpose: User-interface for the recursive insert function.
	*
	*		 Entry: The user has sent in some data, and that data is passed
	*				to the recursive insert function.
	*
	*		  Exit: The data has been inserted in the tree in the appropriate
	*				location.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::Insert( T data )
	{
		Insert( data, mRoot );
	}

	/**********************************************************************
	*	void BSTree< T >::Insert( T data, TreeNode< T > *& root )
	*
	*	   Purpose: Recursive function that receives the data from the user
	*				interface insert function.  Searches for the correct
	*				location in the tree until an empty node has been found.
	*				Creates a node at this location with the data.
	*
	*		 Entry: The data is anything the user has passed in, and root
	*				is the current node the function is at.
	*
	*		  Exit:	The data is in the correct location and the call stack
	*				has unwound.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::Insert( T data, TreeNode< T > *& root )
	{
		if( root == nullptr )
		{
			root = new TreeNode< T >( data );
		}
		else
		{
			if( data < root->mData )
				Insert( data, root->mLeftChild );
			else
				Insert( data, root->mRightChild );		
		}
	}

	/**********************************************************************
	*	void BSTree< T >::Delete( T param )
	*
	*	   Purpose: Interface for the user to send in data that they want
	*				removed from the tree.  Throws an exception if the 
	*				user tries to delete data from an empty tree.  Also
	*				throws an exception if the data does not exist in the
	*				tree.
	*
	*		 Entry:	The user wants to remove a piece of data from the tree.
	*
	*		  Exit: After the data has been found and removed.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::Delete( T param )
	{
		if( mRoot == nullptr )
			throw Exception( "Tree is empty" );
		else
		{
			TreeNode< T > * current = mRoot;
			TreeNode< T > * previous = mRoot;
			bool found( false );

			while( current != nullptr && !found )
			{
				if( current->mData == param )
					found = true;
				else
				{
					previous = current;
					if( current->mData > param )
						current = current->mLeftChild;
					else
						current = current->mRightChild;
				}
			}
			if( current == nullptr )
				throw Exception( "Data not found" );
			else if( found )
			{
				if( mRoot == current )
					DeleteNode( mRoot );
				else if( previous->mData > param )
					DeleteNode( previous->mLeftChild );
				else
					DeleteNode( previous->mRightChild );
			}
		}
	}

	/**********************************************************************
	*	void BSTree< T >::DeleteNode( TreeNode< T > *& root )
	*
	*	   Purpose: Removes the node from the tree that is passed by the 
	*				delete function.  Then reconnects all the nodes to 
	*				maintain the cohesion of the tree.
	*
	*		 Entry:	The root is the node to be deleted.
	*
	*		  Exit: The root is deleted and the connects are set.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::DeleteNode( TreeNode< T > *& root )
	{
		TreeNode< T > * previous = nullptr;
		TreeNode< T > * current = root;

		if( root == nullptr )
			throw Exception( "Tree is empty" );
		else if( current->mLeftChild == nullptr && current->mRightChild == nullptr )
		{
			root = nullptr;
		}
		else if( current->mLeftChild == nullptr && current->mRightChild != nullptr )
		{
			root = root->mRightChild;
		}
		else if( current->mLeftChild != nullptr && current->mRightChild == nullptr )
		{
			root = root->mLeftChild;
		}
		else
		{
			current = root->mLeftChild;
			while( current->mRightChild != nullptr )
			{
				previous = current;
				current = current->mRightChild;
			}
			root->mData = current->mData;
			if( previous == nullptr )
				root->mLeftChild = current->mLeftChild;
			else
				previous->mRightChild = current->mLeftChild;
		}
		delete current;
		current = nullptr;
	}

	/**********************************************************************
	*	void BSTree< T >::Purge(  )
	*
	*	   Purpose: User interface for the recursive purge function.
	*
	*		 Entry:	The tree may or may not have data in it.
	*
	*		  Exit:	The tree doesn't have any data in it.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::Purge(  )
	{
		Purge( mRoot );
	}

	/**********************************************************************
	*	void BSTree< T >::Purge( TreeNode< T > *& root )
	*
	*	   Purpose: Removes all data from the tree.
	*
	*		 Entry: The tree may or may not have data in it.
	*
	*		  Exit:	All data is removed from the tree and the root node
	*				is set to nullptr.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::Purge( TreeNode< T > *& root )
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
	*	int BSTree< T >::Height(  )
	*
	*	   Purpose: User interface to the height function, which determines
	*				how many layers are in the tree.
	*
	*		 Entry: The tree may or may not have anything in it.
	*
	*		  Exit: The height of the tree is returned.
	*
	**********************************************************************/
	template< typename T >
	int BSTree< T >::Height(  )
	{
		return Height( mRoot );
	}

	/**********************************************************************
	*	int BSTree< T >::Height( TreeNode< T > *& root )
	*
	*	   Purpose: Recursively calculates the height of the tree.
	*
	*		 Entry: The tree may or may not have data in it.  If it doesn't
	*				the function returns a zero value.
	*
	*		  Exit:	The height of the tree is determined and returned.
	*
	**********************************************************************/
	template< typename T >
	int BSTree< T >::Height( TreeNode< T > *& root )
	{
		int left( 0 );
		int right( 0 );
		int max( 0 );

		if( root != nullptr )
		{
			left = Height( root->mLeftChild );
			right = Height( root->mRightChild );
			max = left < right ? right : left;
			++max;
		}

		return max;
	}

	/**********************************************************************
	*	void BSTree< T >::InOrder( void ( *StuffToDo )( T& ) )
	*
	*	   Purpose: User interface to the traversal function.  
	*
	*		 Entry: The user wants to interact with the data in the tree,
	*				so StuffToDo is a function pointer to the function
	*				the user wants to do on all the data in the tree.
	*
	*		  Exit: The tree has been traversed and the data interacted
	*				with.
	*
	**********************************************************************/	
	template< typename T >
	void BSTree< T >::InOrder( void ( *StuffToDo )( T& ) )
	{
		InOrder( StuffToDo, mRoot );
	}

	/**********************************************************************
	*	void BSTree< T >::InOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
	*
	*	   Purpose: Traverses through the tree and performs the function 
	*				pointed to by StuffToDo on all data in the tree.
	*
	*		 Entry:	StuffToDo is a function pointer and OnThisNode is the
	*				node that contains the data that the user wants to
	*				perform an action on.
	*
	*		  Exit: The data in OnThisNode has been acted on by StuffToDo.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::InOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
	{
		if( OnThisNode != nullptr )
		{
			InOrder( StuffToDo, OnThisNode->mLeftChild );
			StuffToDo( OnThisNode->mData );
			InOrder( StuffToDo, OnThisNode->mRightChild );
		}
	}

	/**********************************************************************
	*	void BSTree< T >::PreOrder( void ( *StuffToDo )( T& ) )
	*
	*	   Purpose: User interface to the traversal function.  
	*
	*		 Entry: The user wants to interact with the data in the tree,
	*				so StuffToDo is a function pointer to the function
	*				the user wants to do on all the data in the tree.
	*
	*		  Exit: The tree has been traversed and the data interacted
	*				with.
	*
	**********************************************************************/	
	template< typename T >
	void BSTree< T >::PreOrder( void ( *StuffToDo )( T& ) )
	{
		PreOrder( StuffToDo, mRoot );
	}

	/**********************************************************************
	*	void BSTree< T >::PreOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
	*
	*	   Purpose: Traverses through the tree and performs the function 
	*				pointed to by StuffToDo on all data in the tree.
	*
	*		 Entry:	StuffToDo is a function pointer and OnThisNode is the
	*				node that contains the data that the user wants to
	*				perform an action on.
	*
	*		  Exit: The data in OnThisNode has been acted on by StuffToDo.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::PreOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
	{
		if( OnThisNode != nullptr )
		{
			StuffToDo( OnThisNode->mData );
			PreOrder( StuffToDo, OnThisNode->mLeftChild );
			PreOrder( StuffToDo, OnThisNode->mRightChild );
		}	
	}

	/**********************************************************************
	*	void BSTree< T >::PostOrder( void ( *StuffToDo )( T& ) )
	*
	*	   Purpose: User interface to the traversal function.  
	*
	*		 Entry: The user wants to interact with the data in the tree,
	*				so StuffToDo is a function pointer to the function
	*				the user wants to do on all the data in the tree.
	*
	*		  Exit: The tree has been traversed and the data interacted
	*				with.
	*
	**********************************************************************/	
	template< typename T >
	void BSTree< T >::PostOrder( void ( *StuffToDo )( T& ) )
	{
		PostOrder( StuffToDo, mRoot );
	}

	/**********************************************************************
	*	void BSTree< T >::PostOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
	*
	*	   Purpose: Traverses through the tree and performs the function 
	*				pointed to by StuffToDo on all data in the tree.
	*
	*		 Entry:	StuffToDo is a function pointer and OnThisNode is the
	*				node that contains the data that the user wants to
	*				perform an action on.
	*
	*		  Exit: The data in OnThisNode has been acted on by StuffToDo.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::PostOrder( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
	{
		if( OnThisNode != nullptr )
		{
			PostOrder( StuffToDo, OnThisNode->mLeftChild );
			PostOrder( StuffToDo, OnThisNode->mRightChild );
			StuffToDo( OnThisNode->mData );
		}	
	}

	/**********************************************************************
	*	void BSTree< T >::BreadthFirst( void ( *StuffToDo )( T& ) )
	*
	*	   Purpose: User interface to the traversal function.  
	*
	*		 Entry: The user wants to interact with the data in the tree,
	*				so StuffToDo is a function pointer to the function
	*				the user wants to do on all the data in the tree.
	*
	*		  Exit: The tree has been traversed and the data interacted
	*				with.
	*
	**********************************************************************/	
	template< typename T >
	void BSTree< T >::BreadthFirst( void ( *StuffToDo )( T& ) )
	{
		BreadthFirst( StuffToDo, mRoot );	
	}

	/**********************************************************************
	*	void BSTree< T >::BreadthFirst( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
	*
	*	   Purpose: Traverses through the tree and performs the function 
	*				pointed to by StuffToDo on all data in the tree.
	*
	*		 Entry:	StuffToDo is a function pointer and OnThisNode is the
	*				node that contains the data that the user wants to
	*				perform an action on.
	*
	*		  Exit: The data in OnThisNode has been acted on by StuffToDo.
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::BreadthFirst( void ( *StuffToDo )( T& ), TreeNode< T > * OnThisNode )
	{
		ListQueue< TreeNode< T > * > breadth;
		TreeNode< T > * current;

		breadth.Enqueue( mRoot );
		while( !breadth.isEmpty(  ) )
		{
			current = breadth.Dequeue(  );
			StuffToDo( current->mData );

			if( current->mLeftChild != nullptr )
				breadth.Enqueue( current->mLeftChild );

			if( current->mRightChild != nullptr )
				breadth.Enqueue( current->mRightChild );
		}
	}

	/**********************************************************************
	*	void BSTree< T >::Copy( TreeNode< T > *& copy, const TreeNode< T > * orig )
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
	template< typename T >
	void BSTree< T >::Copy( TreeNode< T > *& copy, const TreeNode< T > * orig )
	{
		if( orig != nullptr )
		{
			copy = new TreeNode< T >( orig->mData );
			Copy( copy->mLeftChild, orig->mLeftChild );
			Copy( copy->mRightChild, orig->mRightChild );
		}
		else
			copy = nullptr;
	}

#endif