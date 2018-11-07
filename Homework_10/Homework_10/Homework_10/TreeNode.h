/***********************************************************************
* 	 Class: TreeNode
* Filename: TreeNode.h
*
*		A TreeNode to store Data in for a binary tree.
*
* Constructors:
*			TreeNode(  )
*				Constructs an empty TreeNode.
*
*			TreeNode( T Data )
*				Constructs a TreeNode with 'Data' stored in it.
*
*	  Mutators:
*			SetData( T Data )
*				Sets the Data in a TreeNode to 'Data'.
*
*			SetLeftChild( TreeNode * LeftChild )
*				Sets the mLeftChild pointer to 'LeftChild'.
*
*			SetRightChild( TreeNode * RightChild )
*				Sets the mRightChild pointer to 'RightChild'
*
*	   Methods:
*			T GetData(  ) const
*				Returns the value stored in the TreeNode.
*
*			TreeNode * GetLeftChild(  ) const
*				Returns the LeftChild TreeNode.
*
*			TreeNode * GetRightChild(  ) const
*				Returns the RightChild TreeNode.
*
***********************************************************************/
#ifndef	TreeNode_H
#define TreeNode_H

template< typename T > 
class BSTree;

template< typename T >
class TreeNode
{

	friend class BSTree< T >;

	public:

	// Manager functions

		// No argument constructor
		TreeNode(  );

		// One argument constructor
		TreeNode( T Data );

		// Copy constructor
		TreeNode( const TreeNode< T > & copy );

		// Assignment operator
		TreeNode< T > & operator=( const TreeNode< T > & rhs );

		// Destructor
		~TreeNode(  );

	// Accessor methods

		// Data Accessor
		T GetData(  ) const;

		// LeftChild pointer accessor
		TreeNode< T > * GetLeftChild(  ) const;

		// Previous pointer accessor
		TreeNode< T > * GetRightChild(  ) const;

	// Mutator methods

		// Data mutator
		void SetData( T Data );

		// LeftChild pointer mutator
		void SetLeftChild( TreeNode< T > * LeftChild );

		// Previous pointer mutator
		void SetRightChild( TreeNode< T > * RightChild );

	private:
		T mData;						// Data stored in the TreeNode
		TreeNode< T > * mLeftChild;			// Pointer to the LeftChild TreeNode
		TreeNode< T > * mRightChild;		// Pointer to the previous TreeNode
};


//
// Manager functions
//

	/**********************************************************************
	*	TreeNode::TreeNode(  )
	*
	*	   Purpose: Creates an instance of the TreeNode class.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	template< typename T >
	TreeNode< T >::TreeNode(  ) : 
						mData(  ), mLeftChild( nullptr ), mRightChild( nullptr )
	{  }

	/**********************************************************************
	*	TreeNode::TreeNode( T Data )
	*
	*	   Purpose: Creates an instance of the TreeNode class and stores 'Data'
	*				in mData.
	*
	*		 Entry:	Data members don't exist yet, neither does the object.
	*
	*		  Exit: Data members are initialized and the object is created.
	*
	**********************************************************************/
	template< typename T >
	TreeNode< T >::TreeNode( T Data ) : 
						mData( Data ), mLeftChild( nullptr ), mRightChild( nullptr )
	{  }

	/**********************************************************************
	*	TreeNode::TreeNode( const TreeNode & copy )
	*
	*	   Purpose: Creates a TreeNode object that is a copy of an 
	*				existing TreeNode object.
	*
	*		 Entry:	'copy' is some existing TreeNode object.
	*
	*		  Exit:	'this' is now a replica of 'copy'.
	*
	**********************************************************************/
	template< typename T >
	TreeNode< T >::TreeNode( const TreeNode< T > & copy ) :
						mData( copy.mData ), mLeftChild( copy.mLeftChild ), mRightChild( copy.mRightChild )
	{  }

	/**********************************************************************
	*	TreeNode & TreeNode::operator=( const TreeNode & rhs )
	*
	*	   Purpose:	Overwrites one TreeNode object with the Data of another.
	*
	*		 Entry:	'this' has unimportant Data that will be overwritten,
	*				and 'rhs' is the source of the Data.
	*
	*		  Exit:	'this' will be the same as 'rhs'.
	*
	**********************************************************************/
	template< typename T >
	TreeNode< T > & TreeNode< T >::operator=( const TreeNode< T > & rhs )
	{
		if( this != &rhs )
		{
			mData = rhs.mData;
			mLeftChild = rhs.mLeftChild;
			mRightChild = rhs.mRightChild;
		}
		return * this;
	}

	/**********************************************************************
	*	TreeNode::~TreeNode(  )
	*
	*	   Purpose: Destroys a TreeNode object.
	*
	*		 Entry:	'this' is some object.
	*
	*		  Exit: 'this' is no longer an object.
	*
	**********************************************************************/
	template< typename T >
	TreeNode< T >::~TreeNode(  )
	{  }

//
// Accessor methods
//

	/**********************************************************************
	*	T TreeNode< T >::GetData(  )
	*
	*	   Purpose: Access the Data stored in a TreeNode.
	*
	*		 Entry:	'mData' is some value.
	*
	*		  Exit:	The value in 'mData' is returned.
	*
	**********************************************************************/
	template< typename T >
	T TreeNode< T >::GetData(  ) const
	{
		return mData;
	}

	/**********************************************************************
	*	TreeNode< T > TreeNode< T >::GetLeftChild(  )
	*
	*	   Purpose: Accesses the LeftChild TreeNode.
	*
	*		 Entry:	'mLeftChild' is the pointer to the LeftChild TreeNode in the list.
	*
	*		  Exit:	'mLeftChild' is returned.
	*
	**********************************************************************/
	template< typename T >
	TreeNode< T > * TreeNode< T >::GetLeftChild(  ) const
	{
		return mLeftChild;
	}

	/**********************************************************************
	*	TreeNode< T > TreeNode< T >::GetRightChild(  )
	*
	*	   Purpose: Accesses the RightChild TreeNode.
	*
	*		 Entry:	'mRightChild' is the pointer to the RightChild TreeNode in the list.
	*
	*		  Exit:	'mRightChild' is returned.
	*
	**********************************************************************/
	template< typename T >
	TreeNode< T > * TreeNode< T >::GetRightChild(  ) const
	{
		return mRightChild;
	}

//
// Mutator methods
//

	/**********************************************************************
	*	void TreeNode< T >::SetData( T Data )
	*
	*	   Purpose: Stores 'Data' in the TreeNode.
	*
	*		 Entry:	'Data' is some value.
	*
	*		  Exit: 'mData' is now 'Data'.
	*
	**********************************************************************/
	template< typename T >
	void TreeNode< T >::SetData( T Data )
	{
		mData = Data;
	}

	/**********************************************************************
	*	void TreeNode< T >::SetLeftChild( TreeNode< T > LeftChild )
	*
	*	   Purpose: Changes the TreeNode the LeftChild pointer is pointing at.
	*
	*		 Entry:	'LeftChild' is a TreeNode pointer.
	*
	*		  Exit: 'mLeftChild' is now 'LeftChild'.
	*
	**********************************************************************/
	template< typename T >
	void TreeNode< T >::SetLeftChild( TreeNode< T > * LeftChild )
	{
		mLeftChild = LeftChild;
	}

	/**********************************************************************
	*	void TreeNode< T >::SetRightChild( TreeNode RightChild )
	*
	*	   Purpose: Changes the TreeNode the previous pointer is pointing at.
	*
	*		 Entry:	'RightChild' is a TreeNode pointer.
	*
	*		  Exit: 'mRightChild' is now 'RightChild'.
	*
	**********************************************************************/
	template< typename T >
	void TreeNode< T >::SetRightChild( TreeNode< T > * RightChild )
	{
		mRightChild = RightChild;
	}

#endif