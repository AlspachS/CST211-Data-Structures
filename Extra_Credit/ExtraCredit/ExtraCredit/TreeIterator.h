#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "AbstractIterator.h"
#include "BinarySearchTree.h"
#include "ListQueue.h"

template< typename T >
class TreeIterator : public AbstractIterator< T >
{
	public:
		TreeIterator( BSTree< T > & tree  );
		TreeIterator( const TreeIterator< T > & copy );
		virtual ~TreeIterator(  );

	private:

	protected:
		BSTree< T > & mTree;
		TreeNode< T > * mCurrent;
		ListQueue< T > mHorizTree;
};

	template< typename T >
	TreeIterator< T >::TreeIterator( BSTree< T > & tree ) :
									mTree( tree ), mCurrent( nullptr ), mHorizTree(  )
	{  }

	template< typename T >
	TreeIterator< T >::TreeIterator( const TreeIterator< T > & copy ) :
									mTree( copy.mTree ), mCurrent( copy.mCurrent ), mHorizTree( copy.HorizTree )
	{  }

	template< typename T >
	TreeIterator< T >::~TreeIterator(  )
	{  }

#endif