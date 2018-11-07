#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H

#include "TreeIterator.h"

template< typename T >
class BreadthFirstIterator : public TreeIterator< T >
{
	public:
		BreadthFirstIterator( BSTree< T > & tree );
		BreadthFirstIterator( const BreadthFirstIterator< T > & copy );
		virtual ~BreadthFirstIterator(  );

		virtual void MoveNext(  );
		virtual void Reset(  );
		virtual bool isDone(  );
		virtual T GetCurrent(  );

	private:
		void Reset( TreeNode< T > * root );

	protected:

};

	template< typename T >
	BreadthFirstIterator< T >::BreadthFirstIterator( BSTree< T > & tree ) :
													TreeIterator( tree )
	{
		if( tree.GetRoot(  ) != nullptr )
			Reset(  );
	}

	template< typename T >
	BreadthFirstIterator< T >::~BreadthFirstIterator(  )
	{  }

	template< typename T >
	void BreadthFirstIterator< T >::MoveNext(  )
	{
		if( !mHorizTree.isEmpty(  ) )
			mHorizTree.Dequeue(  );
	}

	template< typename T >
	void BreadthFirstIterator< T >::Reset(  )
	{
		if( !mHorizTree.isEmpty(  ) )
			mHorizTree.Dequeue(  );

		Reset( mTree.GetRoot(  ) );
	}

	template< typename T >
	bool BreadthFirstIterator< T >::isDone(  )
	{
		return mHorizTree.isEmpty(  );
	}

	template< typename T >
	T BreadthFirstIterator< T >::GetCurrent(  )
	{
		return mHorizTree.Front(  );
	}

	template< typename T >
	void BreadthFirstIterator< T >::Reset( TreeNode< T > * root )
	{
		ListQueue< TreeNode< T > * > temp;

		temp.Enqueue( mTree.GetRoot(  ) );
		while( !temp.isEmpty(  ) )
		{
			mCurrent = temp.Dequeue(  );
			mHorizTree.Enqueue( mCurrent->GetData(  ) );

			if( mCurrent->GetLeftChild(  ) != nullptr )
				temp.Enqueue( mCurrent->GetLeftChild(  ) );

			if( mCurrent->GetRightChild(  ) != nullptr )
				temp.Enqueue( mCurrent->GetRightChild(  ) );
		}
	}

#endif