/***********************************************************************
* 	 Class: BSTree
* Filename: BinarySearchTree.h
*
*		This is a binary search tree data structure.
*
* Constructors:
*
*	  Mutators:
*
*	   Methods:
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
	
	// Manager Functions

		BSTree(  );
		BSTree( const BSTree< T > & copy );
		BSTree< T > & operator=( const BSTree< T > & rhs );
		~BSTree(  );

		void Insert( T data );
		void Delete( T param );
		void Purge(  );
		int Height(  );
	
		void InOrder( void (*StuffToDo)(T&) );
		void PreOrder( void (*StuffToDo)(T&) );
		void PostOrder( void (*StuffToDo)(T&) );
		void BreadthFirst( void (*StuffToDo)(T&) );
	
	private:
		
		void Insert( T data, TreeNode< T > *& root );
		void DeleteNode( TreeNode< T > *& root );
		void Purge( TreeNode< T > *& root );
		int Height( TreeNode< T > *& root );
		void Copy( TreeNode< T > *& copy, const TreeNode< T > * orig );

		void InOrder( void (*StuffToDo)(T&), TreeNode< T > * OnThisNode );
		void PreOrder( void (*StuffToDo)(T&), TreeNode< T > * OnThisNode );
		void PostOrder( void (*StuffToDo)(T&), TreeNode< T > * OnThisNode );
		void BreadthFirst( void (*StuffToDo)(T&), TreeNode< T > * OnThisNode );
	
		TreeNode< T > * mRoot;

};

	/**********************************************************************
	*	BSTree< T >::BSTree(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	BSTree< T >::BSTree(  ) : 
						mRoot( nullptr )
	{  }

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	BSTree< T >::BSTree( const BSTree< T > & copy ) :
						mRoot( nullptr )
	{ 
		*this = copy;
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	BSTree< T >::~BSTree(  )
	{ 
		Purge(  );
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::Insert( T data )
	{
		Insert( data, mRoot );
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::Purge(  )
	{
		Purge( mRoot );
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	int BSTree< T >::Height(  )
	{
		return Height( mRoot );
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/	
	template< typename T >
	void BSTree< T >::InOrder( void (*StuffToDo)(T&) )
	{
		InOrder( StuffToDo, mRoot );
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename T >
	void BSTree< T >::InOrder( void (*StuffToDo)(T&), TreeNode< T > * OnThisNode )
	{
		if( OnThisNode != nullptr )
		{
			InOrder( StuffToDo, OnThisNode->mLeftChild );
			StuffToDo( OnThisNode->mData );
			InOrder( StuffToDo, OnThisNode->mRightChild );
		}
	}


	template< typename T >
	void BSTree< T >::PreOrder( void (*StuffToDo)(T&) )
	{
		PreOrder( StuffToDo, mRoot );
	}


	template< typename T >
	void BSTree< T >::PreOrder( void (*StuffToDo)(T&), TreeNode< T > * OnThisNode )
	{
		if( OnThisNode != nullptr )
		{
			StuffToDo( OnThisNode->mData );
			PreOrder( StuffToDo, OnThisNode->mLeftChild );
			PreOrder( StuffToDo, OnThisNode->mRightChild );
		}	
	}


	template< typename T >
	void BSTree< T >::PostOrder( void (*StuffToDo)(T&) )
	{
		PostOrder( StuffToDo, mRoot );
	}


	template< typename T >
	void BSTree< T >::PostOrder( void (*StuffToDo)(T&), TreeNode< T > * OnThisNode )
	{
		if( OnThisNode != nullptr )
		{
			PostOrder( StuffToDo, OnThisNode->mLeftChild );
			PostOrder( StuffToDo, OnThisNode->mRightChild );
			StuffToDo( OnThisNode->mData );
		}	
	}


	template< typename T >
	void BSTree< T >::BreadthFirst( void (*StuffToDo)(T&) )
	{
		BreadthFirst( StuffToDo, mRoot );	
	}


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