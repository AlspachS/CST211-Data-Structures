#include "LinkedStack.h"

#include <iostream>
	using std::cout;
	using std::endl;

int main(  )
{
	LinkedStack< int > test;

	LinkedStack< int > test1( test );
	LinkedStack< int > test2;

	test1 = test2;

	try
	{
		test.Peek(  );
	}
	catch( Exception & except )
	{
		cout << except;
	}
	for( int i( 0 ); i < 5; ++i )
	{
		test.Push( i );
		cout << test.Size(  ) << endl;
	}

	cout << test.Peek(  ) << endl;

	for( int i( 0 ); i < 5; ++i )
	{
		cout << test.Pop(  ) << " ";
		cout << test.Size(  ) << endl;
	}	
	cout << endl;

	try
	{
		for( int i( 0 ); i < 6; ++i )
		{
			test.Push( i );
		}
	}
	catch( Exception & except )
	{
		cout << except;
	}

	try
	{
		for( int i( 0 ); i < 7; ++i )
		{
			cout << test.Pop(  ) << " ";
		}
		cout << endl;
	}
	catch( Exception & except )
	{
		cout << except;
	}
	return 0;
}