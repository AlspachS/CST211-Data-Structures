//#include "Stack.h"
//
//#include <iostream>
//	using std::cout;
//	using std::endl;
//
//int main(  )
//{
//	Stack< int > test( 5 );
//
//	Stack< int > test1( test );
//	Stack< int > test2( 19 );
//
//	test1 = test2;
//
//	try
//	{
//		test.Peek(  );
//	}
//	catch( Exception & except )
//	{
//		cout << except;
//	}
//	for( int i( 0 ); i < 5; ++i )
//	{
//		test.Push( i );
//		cout << test.Size(  ) << endl;
//	}
//
//	cout << test.Peek(  ) << endl;
//
//	for( int i( 0 ); i < 5; ++i )
//	{
//		cout << test.Pop(  ) << " ";
//		cout << test.Size(  ) << endl;
//	}	
//	cout << endl;
//
//	try
//	{
//		for( int i( 0 ); i < 6; ++i )
//		{
//			test.Push( i );
//		}
//	}
//	catch( Exception & except )
//	{
//		cout << except;
//	}
//
//	try
//	{
//		for( int i( 0 ); i < 6; ++i )
//		{
//			cout << test.Pop(  ) << " ";
//		}
//		cout << endl;
//	}
//	catch( Exception & except )
//	{
//		cout << except;
//	}
//	return 0;
//}

#include <iostream>
	using std::cout;
	using std::endl;

#include <string>
	using std::string;

int main(  )
{
	string a = "Hello";
	string b = "World";

	cout << "a " << a << endl;
	cout << "b " << b << endl;

	cout << "____________________" << endl;

	a = a ^ b;
	cout << a << endl;
	b = b ^ a;
	cout << b << endl;
	a = a ^ b;
	cout << a << endl;

	cout << "____________________" << endl;

	cout << "a " << a << endl;
	cout << "b " << b << endl;


	return 0;
}