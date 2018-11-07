#include "ArrayQueue.h"

#include <iostream>
	using std::cout;
	using std::endl;

int main(  )
{
	ArrayQueue< int > test1( 5 );
	ArrayQueue< int > test2( 10 );
	ArrayQueue< int > test3( test1 );

	test3 = test2;

	try
	{
		for( int i( 0 ); i < 6; ++i )
		{
			test1.Enqueue( i * 2 );
			cout << " " << test1.Size(  ) << endl;
		}
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}


	try
	{
		for( int i( 0 ); i < 6; ++i )
		{
			cout << test1.Dequeue(  ) << " ";
			cout << test1.Size(  ) << endl;
		}
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}


	try
	{
		test2.Enqueue( 42 );
		cout << test2.Front(  ) << endl;
		cout << test2.Dequeue(  ) << endl;
		cout << test2.Front(  ) << endl;
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		for( int i( 0 ); i < 20; ++i )
		{
			test1.Enqueue( i * 3 );

			//if( i % 1 == 0 )
			cout << test1.Dequeue(  ) << " ";
			
		}
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	return 0;
}