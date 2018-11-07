#ifndef INORDERITERATOR_H
#define INORDERITERATOR_H

#include "TreeIterator.h"

template< typename T >
class InOrderIterator : public TreeIterator< T >
{
	public:
		InOrderIterator( BSTree< T > & tree );
		InOrderIterator( const InOrderIterator & copy );
		virtual ~InOrderIterator(  );

		virtual void MoveNext(  );
		virtual void Reset(  );
		virtual bool isDone(  );
		virtual T GetCurrent(  );

	private:
		void Reset( TreeNode< T > * root );

	protected:

};

	template< typename T >
	InOrderIterator< T >::InOrderIterator( BSTree< T > & tree ) :
											TreeIterator( tree )
	{
		Reset(  );
	}

	template< typename T >
	InOrderIterator< T >::~InOrderIterator(  )
	{  }

	template< typename T >
	void InOrderIterator< T >::MoveNext(  )
	{
		mHorizTree.Dequeue(  );
	}

	template< typename T >
	void InOrderIterator< T >::Reset(  )
	{
		if( !mHorizTree.isEmpty(  ) )
			mHorizTree.Dequeue(  );

		Reset( mTree.GetRoot(  ) );
	}

	template< typename T >
	bool InOrderIterator< T >::isDone(  )
	{
		return mHorizTree.isEmpty(  );
	}

	template< typename T >
	T InOrderIterator< T >::GetCurrent(  )
	{
		return mHorizTree.Front(  );
	}

	template< typename T >
	void InOrderIterator< T >::Reset( TreeNode< T > * root )
	{
		if( root != nullptr )
		{
			Reset( root->GetLeftChild(  ) );
			mHorizTree.Enqueue( root->GetData(  ) );
			Reset( root->GetRightChild(  ) );
		}
	}

#endif