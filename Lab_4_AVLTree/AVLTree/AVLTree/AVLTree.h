 /***********************************************************************
* 	 Class: AVLTree
* Filename: AVLTree.h
*
*		An implementation of an AVL tree.  An AVL tree is a binary
*		search tree that balances itself as nodes are inserted.
*
* Constructors:
*		AVLTree(  )
*			No argument constructor that initializes an empty tree.
*
*	  Mutators:
*		void Insert( T data, bool & taller, TreeNode< T > *& root )
*			Receives data from the user-interface insert function and 
*			inserts that data in the AVL tree in the correct location.
*
*		void Delete( T data, bool & shorter, TreeNode< T > *& root )
*			Receives data from the user-interface delete function, 
*			finds the node that contains that data, if it exists,
*			and deletes it from the tree.
*
*		void LeftRotation( TreeNode< T > *& root, TreeNode< T > *& newroot )
*			Rotates an AVL tree when a new node is inserted in the 
*			root of the problem's, left child's, left subtree.  It
*			may be called a left rotation, but the tree is actually
*			rotated right.
*
*		void RightRotation( TreeNode< T > *& root, TreeNode< T > *& newroot )
*			Rotates an AVL tree when a new node is inserted in the
*			root of the problem's, right child's right subtree.  It
*			may be called a right rotation, but the tree is actually
*			rotated left.
*
*	   Methods:
*		void Insert( T data )
*			User interface to insert data in the AVL tree.  Calls the
*			recursive insert function.
*
*		void Delete( T data )
*			User interface to delete data from the AVL tree.  Calls the
*			recursive delete function.
*
*		void InsLeftBalance( bool & taller, TreeNode< T > *& root )
*			Checks the balance factors of the tree after an insert into
*			the AVL tree.  As the call stack unwinds from the recursive
*			insert, the balance factors are checked and the tree is 
*			rebalanced if needed.
*
*		void InsRightBalance( bool & taller, TreeNode< T > *& root )
*			Checks the balance factors of the tree after an insert into
*			the AVL tree.  As the call stack unwinds from the recursive
*			insert, the balance factors are checked and the tree is 
*			rebalanced if needed.
*
*		void DelLeftBalance( bool & shorter, TreeNode< T > *& root )
*			Checks the balance factors of the tree after a delete from
*			the AVL tree.  As the call stack unwinds from the recursive
*			insert, the balance factors are checked and the tree is 
*			rebalanced if needed.
*
*		void DelRightBalance( bool & shorter, TreeNode< T > *& root )
*			Checks the balance factors of the tree after a delete from
*			the AVL tree.  As the call stack unwinds from the recursive
*			insert, the balance factors are checked and the tree is 
*			rebalanced if needed.
*
***********************************************************************/
#ifndef AVLTREE_H
#define AVLTREE_H

#define LH 1
#define EH 0
#define RH -1

#include "BinarySearchTree.h"
#include "Exception.h"

template< typename T >
class AVLTree : public BSTree< T >
{
	public:

	// Manager functions

		// No argument constructor
		AVLTree(  );

		// Copy constructor
		AVLTree( const AVLTree & copy );

		// Assignment operator
		AVLTree & operator=( const AVLTree & rhs );

		// Destructor
		~AVLTree(  );

	// Accessor methods

		// Accessor to the insert function
		void Insert( T data );

		// Accessor to the delete function
		void Delete( T data );

	private:
		
	// Mutator methods

		// Recursively inserts data into the tree
		void Insert( T data, bool & taller, TreeNode< T > *& root );

		// Recursively deletes data from the tree
		void Delete( T data, bool & shorter, TreeNode< T > *& root );

		// Checks the balance of a tree after an insert
		void InsLeftBalance( bool & taller, TreeNode< T > *& root );

		// Checks the balance of a tree after an insert
		void InsRightBalance( bool & taller, TreeNode< T > *& root );

		// Checks the balance of a tree after a delete
		void DelLeftBalance( bool & shorter, TreeNode< T > *& root );

		// Checks the balance of a tree after a delete
		void DelRightBalance( bool & shorter, TreeNode< T > *& root );

		// Rebalances a tree when it gets left heavy
		void LeftRotation( TreeNode< T > *& root, TreeNode< T > *& newroot );

		// Rebalances a tree when it gets right heavy
		void RightRotation( TreeNode< T > *& root, TreeNode< T > *& newroot );

};
	
//
// Manager functions
//

	/**********************************************************************
	*	AVLTree< T >::AVLTree(  )
	*
	*	   Purpose: Constructs an empty AVL tree.
	*
	*		 Entry:	No tree exists yet.
	*
	*		  Exit:	An empty tree is created.
	*
	**********************************************************************/
	template< typename T >
	AVLTree< T >::AVLTree(  )
	{  }

	/**********************************************************************
	*	AVLTree< T >::AVLTree( const AVLTree & copy )
	*
	*	   Purpose: Copies one AVL tree into another that is just created.
	*
	*		 Entry:	The copy is a tree that already exists and may have 
	*				data in it.
	*
	*		  Exit: A new tree is created that is a copy of the original
	*				tree.
	*
	**********************************************************************/
	template< typename T >
	AVLTree< T >::AVLTree( const AVLTree & copy )
	{
		*this = copy;
	}

	/**********************************************************************
	*	AVLTree< T > & AVLTree< T >::operator=( const AVLTree< T > & rhs )
	*
	*	   Purpose:	Overwrites the data in one tree with the data in
	*				another.
	*
	*		 Entry: The rhs tree is one that will overwrite the calling
	*				object.
	*
	*		  Exit: The calling object is now a copy of of the rhs tree.
	*
	**********************************************************************/
	template< typename T >
	AVLTree< T > & AVLTree< T >::operator=( const AVLTree< T > & rhs )
	{
		if( this != &rhs )
		{
			BSTree< T >::Copy( mRoot, rhs.mRoot );
		}
		return *this;
	}

	/**********************************************************************
	*	AVLTree< T >::~AVLTree(  )
	*
	*	   Purpose: Destroys a tree object when it goes out of scope.
	*
	*		 Entry:	The calling object is some tree with some data.
	*
	*		  Exit:	The calling object is now destroyed and all data
	*				stored in it is deleted.
	*
	**********************************************************************/
	template< typename T >
	AVLTree< T >::~AVLTree(  )
	{
		BSTree< T >::Purge(  );	
	}

//
// Member functions
//

	/**********************************************************************
	*	void AVLTree< T >::Insert( T data )
	*
	*	   Purpose:	Allows the user to store data in the AVL tree.  This 
	*				function is a bridge for the user to the recursive
	*				insert function.
	*
	*		 Entry: The data is the value the user wants to store in the 
	*				AVL tree.
	*
	*		  Exit:	The data is stored in the tree, and the tree is
	*				rebalanced.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::Insert( T data )
	{
		bool taller( false );

		Insert( data, taller, mRoot );
	}

	/**********************************************************************
	*	void AVLTree< T >::Insert( T data, bool & taller, TreeNode< T > *& root )
	*
	*	   Purpose: Recursively searches through the AVL for the appropriate
	*				location in the tree to insert the data.  After the data
	*				is inserted and the call stack is unwinding, the 
	*				balance factor of the tree is checked, recalculated,
	*				and the tree is rebalanced if needed.
	*
	*		 Entry:	The user wants to store data in the tree.  Taller
	*				indicates whether there was a change in height of the
	*				tree after the data is inserted in its location.  
	*
	*		  Exit:	The data is inserted and the tree is balanced again.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::Insert( T data, bool & taller, TreeNode< T > *& root )
	{
		if( root == nullptr )
		{
			root = new TreeNode< T >( data );
			taller = true;
		}
		else
		{
			if( data < root->mData )
			{
				Insert( data, taller, root->mLeftChild );

				if( taller )
				{
					switch( root->mBalance )
					{
						case LH:
							InsLeftBalance( taller, root );
						break;

						case EH:
							root->mBalance = LH;
						break;

						case RH:
							root->mBalance = EH;
							taller = false;
						break;			
					}
				}
			}
			else
			{
				Insert( data, taller, root->mRightChild );
		
				if( taller )
				{
					switch( root->mBalance )
					{
						case LH:
							root->mBalance = EH;
							taller = false;
						break;

						case EH:
							root->mBalance = RH;
						break;

						case RH:
							InsRightBalance( taller, root );
						break;
					}
				}
			}
		}
	}

	/**********************************************************************
	*	void AVLTree< T >::InsLeftBalance( bool & taller, TreeNode< T > *& root )
	*
	*	   Purpose:	Checks the balance factors of a tree after an insert
	*				and rotates the tree if needed.
	*
	*		 Entry:	The tree was left heavy before an insert in the left
	*				child's subtree, meaning the tree needs to be balanced.  
	*				If it was the left subtree, a LL rotation is needed.  
	*				If the left subtree belonged to the right child, a 
	*				double rotation is needed, a RL rotation.  Taller is 
	*				true.
	*
	*		  Exit: The balance factors are recalculated and the appropriate
	*				rotations have been performed.  Taller is false.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::InsLeftBalance( bool & taller, TreeNode< T > *& root )
	{
		TreeNode< T > * right;
		TreeNode< T > * left;

		left = root->mLeftChild;
		switch( left->mBalance )
		{
			case LH:
				root->mBalance = EH;
				left->mBalance = EH;
				RightRotation( root, root );
				taller = false;
			break;

			case EH:
				cout << "This is my secret area, my own personal code oubliette, go away!";
			break;

			case RH:
				right = left->mRightChild;

				switch( right->mBalance )
				{
					case LH:
						root->mBalance = RH;
						left->mBalance = EH;
					break;

					case EH:
						root->mBalance = EH;
						left->mBalance = EH;
					break;

					case RH:
						root->mBalance = EH;
						left->mBalance = LH;
					break;
				}

				right->mBalance = EH;
				LeftRotation( left, root->mLeftChild );
				RightRotation( root, root );

				taller = false;
			break;
		}
	}

	/**********************************************************************
	*	void AVLTree< T >::InsRightBalance( bool & taller, TreeNode< T > *& root )
	*
	*	   Purpose:	Checks the balance factors of a tree after an insert
	*				and rotates the tree if needed.
	*
	*		 Entry:	The tree was right heavy before an insert in the right
	*				child's subtree, meaning the tree needs to be balanced.  
	*				If it was the right subtree, a RR rotation is needed.  
	*				If the right subtree belonged to the left child, a 
	*				double rotation is needed, a LR rotation.  Taller is 
	*				true
	*
	*		  Exit: The balance factors are recalculated and the appropriate
	*				rotations have been performed.  Taller is false.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::InsRightBalance( bool & taller, TreeNode< T > *& root )
	{
		TreeNode< T > * left;
		TreeNode< T > * right;

		right = root->mRightChild;
		switch( right->mBalance )
		{
			case RH:
				root->mBalance = EH;
				right->mBalance = EH;
				LeftRotation( root, root );
				taller = false;
			break;

			case EH:
				cout << "I told you to stay out of my secret areas!";
			break;

			case LH:
				left = right->mLeftChild;

				switch( left->mBalance )
				{
					case RH:
						root->mBalance = LH;
						right->mBalance = EH;
					break;

					case EH:
						root->mBalance = EH;
						right->mBalance = EH;
					break;

					case LH:
						root->mBalance = EH;
						right->mBalance = RH;
					break;
				}

				left->mBalance = EH;
				RightRotation( right, root->mRightChild );
				LeftRotation( root, root );

				taller = false;
			break;
		}
	}

	/**********************************************************************
	*	void AVLTree< T >::LeftRotation( TreeNode< T > *& root, TreeNode< T > *& newroot )
	*
	*	   Purpose: Rotates a tree after an insertion in a left heavy 
	*				subtree.  Visually, this rotation rotated right.
	*
	*		 Entry:	The root is the current root, and newroot will be the
	*				new root of the subtree.
	*
	*		  Exit:	Newroot is set to the node that is now the root of the
	*				subtree.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::LeftRotation( TreeNode< T > *& root, TreeNode< T > *& newroot )
	{
		TreeNode< T > * temp;

		temp = root->mRightChild;
		root->mRightChild = temp->mLeftChild;
		temp->mLeftChild = root;
		newroot = temp;
	}

	/**********************************************************************
	*	void AVLTree< T >::RightRotation( TreeNode< T > *& root, TreeNode< T > *& newroot )
	*
	*	   Purpose: Rotates a tree after an insertion in a right heavy 
	*				subtree.  Visually, this rotation rotated left.
	*
	*		 Entry:	The root is the current root, and newroot will be the
	*				new root of the subtree.
	*
	*		  Exit:	Newroot is set to the node that is now the root of the
	*				subtree.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::RightRotation( TreeNode< T > *& root, TreeNode< T > *& newroot )
	{
		TreeNode< T > * temp;

		temp = root->mLeftChild;
		root->mLeftChild = temp->mRightChild;
		temp->mRightChild = root;
		newroot = temp;
	}

	/**********************************************************************
	*	void AVLTree< T >::Delete( T data )
	*
	*	   Purpose:	Allows the user to remove data in the AVL tree.  This 
	*				function is a bridge for the user to the recursive
	*				delete function.
	*
	*		 Entry: The data is the value the user wants to remove from the 
	*				AVL tree.
	*
	*		  Exit:	The data is removed from the tree, and the tree is
	*				rebalanced.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::Delete( T data )
	{
		if( mRoot == nullptr )
			throw Exception( "Tree is empty" );

		bool shorter( false );

		Delete( data, shorter, mRoot );
	}

	/**********************************************************************
	*	void AVLTree< T >::Delete( T data, bool & shorter, TreeNode< T > *& root )
	*
	*	   Purpose: Recursively searches through the AVL for the data to
	*				delete.  After the data is deleted and the call stack 
	*				is unwinding, the balance factor of the tree is 
	*				checked, recalculated, and the tree is rebalanced
	*				if needed.
	*
	*		 Entry:	The user wants to delete data in the tree.  Shorter
	*				indicates whether there was a change in height of the
	*				tree after the data is removed from its location.  
	*
	*		  Exit:	The data is removed and the tree is balanced again.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::Delete( T data, bool & shorter, TreeNode< T > *& root )
	{
		TreeNode< T > * remove;
		TreeNode< T > * exchange;

		if( root == nullptr )
		{
			throw Exception( "Data not found" );
		}

		if( data < root->mData )
		{
			Delete( data, shorter, root->mLeftChild );

			if( shorter )
				DelRightBalance( shorter, root );
		}
		else if( data > root->mData )
		{
			Delete( data, shorter, root->mRightChild );

			if( shorter )
				DelLeftBalance( shorter, root );
		}
		else
		{
			remove = root;

			if( root->mRightChild == nullptr )
			{
				root = root->mLeftChild;
				shorter = true;
				delete remove;
				remove = nullptr;
			}
			else
			{
				if( root->mLeftChild == nullptr )
				{
					root = root->mRightChild;
					shorter = true;
					delete remove;
					remove = nullptr;
				}
				else
				{
					exchange = root->mLeftChild;
					while( exchange->mRightChild )
						exchange = exchange->mRightChild;

					root->mData = exchange->mData;
					Delete( exchange->mData, shorter, root->mLeftChild );

					if( shorter )
						DelRightBalance( shorter, root );
				}
			}
		}
	}

	/**********************************************************************
	*	void AVLTree< T >::DelRightBalance( bool & shorter, TreeNode< T > *& root )
	*
	*	   Purpose:	Checks the balance factors of a tree after a delete
	*				and rotates the tree if needed.
	*
	*		 Entry:	The tree was left heavy before a delete in the right
	*				child's subtree, meaning the tree needs to be balanced.
	*				If it was the right subtree, a RR rotation is needed.  
	*				If it was the left subtree of the child, a double 
	*				rotation is needed, a LR rotation.  Shorter is true.
	*
	*		  Exit: The balance factors are recalculated and the appropriate
	*				rotations have been performed.  Shorter is false.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::DelRightBalance( bool & shorter, TreeNode< T > *& root )
	{
		TreeNode< T > * right;
		TreeNode< T > * left;

		switch( root->mBalance )
		{
			case LH:
				root->mBalance = EH;
			break;

			case EH:
				root->mBalance = RH;
				shorter = false;
			break;

			case RH:
				right = root->mRightChild;

				if( right->mBalance == LH )
				{
					left = right->mLeftChild;

					switch( left->mBalance )
					{
						case LH:
							right->mBalance = RH;
							root->mBalance = EH;
						break;

						case EH:
							right->mBalance = EH;
							root->mBalance = EH;
						break;

						case RH:
							right->mBalance = LH;
							root->mBalance = EH;
						break;
					}

					left->mBalance = EH;

					RightRotation( right, root->mRightChild );
					LeftRotation( root, root );
				}
				else
				{
					switch( right->mBalance )
					{
						case LH:
						case RH:
							root->mBalance = EH;
							right->mBalance = EH;
						break;

						case EH:
							root->mBalance = RH;
							right->mBalance = LH;
							shorter = false;
						break;
					}
					LeftRotation( root, root );
				}
		}
	}

	/**********************************************************************
	*	void AVLTree< T >::DelLeftBalance( bool & shorter, TreeNode< T > *& root )
	*
	*	   Purpose:	Checks the balance factors of a tree after a delete
	*				and rotates the tree if needed.
	*
	*		 Entry:	The tree was right heavy before a delete in the left
	*				child's subtree, meaning the tree needs to be balanced.
	*				If it was the left subtree, a LL rotation is needed.  
	*				If it was the right subtree of the child, a double 
	*				rotation is needed, a RL rotation.  Shorter is true.
	*
	*		  Exit: The balance factors are recalculated and the appropriate
	*				rotations have been performed.  Shorter is false.
	*
	**********************************************************************/
	template< typename T >
	void AVLTree< T >::DelLeftBalance( bool & shorter, TreeNode< T > *& root )
	{
		TreeNode< T > * left;
		TreeNode< T > * right;

		switch( root->mBalance )
		{
			case RH:
				root->mBalance = EH;
			break;

			case EH:
				root->mBalance = LH;
				shorter = false;
			break;

			case LH:
				left = root->mLeftChild;

				if( left->mBalance == RH )
				{
					right = left->mRightChild;

					switch( right->mBalance )
					{
						case RH:
							left->mBalance = LH;
							root->mBalance = EH;
						break;

						case EH:
							left->mBalance = EH;
							root->mBalance = EH;
						break;

						case LH:
							left->mBalance = RH;
							root->mBalance = EH;
						break;
					}

					right->mBalance = EH;

					LeftRotation( left, root->mLeftChild );
					RightRotation( root, root );
				}
				else
				{
					switch( left->mBalance )
					{
						case RH:
						case LH:
							root->mBalance = EH;
							left->mBalance = EH;
						break;

						case EH:
							root->mBalance = LH;
							left->mBalance = RH;
							shorter = false;
						break;
					}
					RightRotation( root, root );
				}
		}
	}

#endif