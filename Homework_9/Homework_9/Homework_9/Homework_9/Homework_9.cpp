#include <iostream>
	using std::cout;
	using std::endl;

#include <string>
	using std::string;

#include "ForwardIterator.h"
#include "BackwardIterator.h"
#include "doublelinkedlist.h"

int main(  )
{
	DoubleLinkedList< int > list;

	ForwardIterator< int > foriter( list );
	BackwardIterator< int > backiter( list );

	for( int i( 0 ); i < 17; ++i )
	{
		list.Append( i * 3 );
	}

	for( foriter.Reset(  ); foriter.isDone(  ); foriter.MoveNext(  ) )
	{
		cout << foriter.GetCurrent(  ) << endl;
	}

	cout << endl;

	for( backiter.Reset(  ); backiter.isDone(  ); backiter.MoveNext(  ) )
	{
		cout << backiter.GetCurrent(  ) << endl;
	}

	return 0;
}