#ifndef POSTORDERITERATOR_H
#define POSTORDERITERATOR_H

#include "TreeIterator.h"

template< typename T >
class PostOrderIterator : public TreeIterator< T >
{
	public:
		PostOrderIterator( BSTree< T > & tree );
		PostOrderIterator( const PostOrderIterator & copy );
		virtual ~PostOrderIterator(  );

		virtual void MoveNext(  );
		virtual void Reset(  );
		virtual bool isDone(  );
		virtual T GetCurrent(  );

	private:
		void Reset( TreeNode< T > * root );

	protected:

};

	template< typename T >
	PostOrderIterator< T >::PostOrderIterator( BSTree< T > & tree ) :
													TreeIterator( tree )
	{
		Reset(  );
	}

	template< typename T >
	PostOrderIterator< T >::~PostOrderIterator(  )
	{  }

	template< typename T >
	void PostOrderIterator< T >::MoveNext(  )
	{
		mHorizTree.Dequeue(  );
	}

	template< typename T >
	void PostOrderIterator< T >::Reset(  )
	{
		if( !mHorizTree.isEmpty(  ) )
			mHorizTree.Dequeue(  );

		Reset( mTree.GetRoot(  ) );
	}

	template< typename T >
	bool PostOrderIterator< T >::isDone(  )
	{
		return mHorizTree.isEmpty(  );
	}

	template< typename T >
	T PostOrderIterator< T >::GetCurrent(  )
	{
		return mHorizTree.Front(  );
	}

	template< typename T >
	void PostOrderIterator< T >::Reset( TreeNode< T > * root )
	{
		if( root != nullptr )
		{
			Reset( root->GetLeftChild(  ) );
			Reset( root->GetRightChild(  ) );
			mHorizTree.Enqueue( root->GetData(  ) );
		}
	}

#endif