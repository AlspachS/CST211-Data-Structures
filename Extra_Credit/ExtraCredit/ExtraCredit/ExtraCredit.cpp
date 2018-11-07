#include "PreOrderIterator.h"
#include "PostOrderIterator.h"
#include "InOrderIterator.h"
#include "BreadthFirstIterator.h"
#include "BinarySearchTree.h"

int main(  )
{
	BSTree< int > test;

	PostOrderIterator< int > PostIter( test );
	InOrderIterator< int > InIter( test );
	PreOrderIterator< int > PreIter( test );
	BreadthFirstIterator< int > Bread( test );

	test.Insert( 5 );
	test.Insert( 8 );
	test.Insert( 9 );
	test.Insert( 10 );
	test.Insert( 2 );
	test.Insert( 1 );
	test.Insert( 3 );
	test.Insert( 6 );
	test.Insert( 4 );
	test.Insert( 7 );
	test.Insert( 11 );
	
	for( PostIter.Reset(  ); !PostIter.isDone(  ); PostIter.MoveNext(  ) )
		cout << PostIter.GetCurrent(  ) << ' ';

	cout << endl;

	for( InIter.Reset(  ); !InIter.isDone(  ); InIter.MoveNext(  ) )
		cout << InIter.GetCurrent(  ) << ' ';

	cout << endl;

	for( PreIter.Reset(  ); !PreIter.isDone(  ); PreIter.MoveNext(  ) )
		cout << PreIter.GetCurrent(  ) << ' ';

	cout << endl;

	for( InIter.Reset(  ); !InIter.isDone(  ); InIter.MoveNext(  ) )
		cout << InIter.GetCurrent(  ) << ' ';

	cout << endl;

	for( InIter.Reset(  ); !InIter.isDone(  ); InIter.MoveNext(  ) )
		cout << InIter.GetCurrent(  ) << ' ';

	cout << endl;

	for( PreIter.Reset(  ); !PreIter.isDone(  ); PreIter.MoveNext(  ) )
		cout << PreIter.GetCurrent(  ) << ' ';

	cout << endl;

	for( Bread.Reset(  ); !Bread.isDone(  ); Bread.MoveNext(  ) )
		cout << Bread.GetCurrent(  ) << ' ';

	cout << endl;

	return 0;
}