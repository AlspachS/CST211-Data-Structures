#ifndef PREORDERITERATOR_H
#define PREORDERITERATOR_H

#include "TreeIterator.h"

template< typename T >
class PreOrderIterator : public TreeIterator< T >
{
	public:
		PreOrderIterator( BSTree< T > & tree );
		PreOrderIterator( const PreOrderIterator & copy );
		virtual ~PreOrderIterator(  );

		virtual void MoveNext(  );
		virtual void Reset(  );
		virtual bool isDone(  );
		virtual T GetCurrent(  );

	private:
		void Reset( TreeNode< T > * root );

	protected:

};

	template< typename T >
	PreOrderIterator< T >::PreOrderIterator( BSTree< T > & tree ) :
													TreeIterator( tree )
	{
		Reset(  );
	}

	template< typename T >
	PreOrderIterator< T >::~PreOrderIterator(  )
	{  }

	template< typename T >
	void PreOrderIterator< T >::MoveNext(  )
	{
		mHorizTree.Dequeue(  );
	}

	template< typename T >
	void PreOrderIterator< T >::Reset(  )
	{
		if( !mHorizTree.isEmpty(  ) )
			mHorizTree.Dequeue(  );

		Reset( mTree.GetRoot(  ) );
	}

	template< typename T >
	bool PreOrderIterator< T >::isDone(  )
	{
		return mHorizTree.isEmpty(  );
	}

	template< typename T >
	T PreOrderIterator< T >::GetCurrent(  )
	{
		return mHorizTree.Front(  );
	}

	template< typename T >
	void PreOrderIterator< T >::Reset( TreeNode< T > * root )
	{
		if( root != nullptr )
		{
			mHorizTree.Enqueue( root->GetData(  ) );
			Reset( root->GetLeftChild(  ) );
			Reset( root->GetRightChild(  ) );
		}
	}

#endif