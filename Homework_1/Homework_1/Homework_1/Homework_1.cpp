#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>

#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;

#include <string>
	using std::string;

#include "Array.h"
#include "Exception.h"

int main(  )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	int * temp = nullptr;									// Making sure the memory leak checker is working
	delete temp;
	

	cout << "Making an array with no arg constructor\n";
		Array< int > array_test1;							// checking no arg constructor
		cout << "Displaying the values of 'array_test1' array\n";
		cout << array_test1.GetLength(  ) << endl;			// checking the GetLength accessor
		cout << array_test1.GetStartIndex(  ) << endl;		// checking the GetStartIndex accessor
	
	
	cout << "Making an array with two arg constructor, using default value\n";
		Array< int > array_test2( 10 );						// checking two arg constructor with default value
		cout << "Displaying the values of 'array_test2' array\n";
		cout << array_test2.GetLength(  ) << endl;			// checking the GetLength accessor
		cout << array_test2.GetStartIndex(  ) << endl;		// checking the GetStartIndex accessor

	cout << "Storing a single value in the fourth element of 'array_test2'\n";
		array_test2[ 3 ] = 15;								// putting data in one of the arrays
		cout << array_test2[ 3 ] << endl;


	cout << "Making an array with two arg constructor, specifying both values\n";
		Array< int > array_test3( 5, 2 );					// checking two arg constructor without default value
		cout << "Displaying the values of 'array_test3' array\n";
		cout << array_test3.GetLength(  ) << endl;
		cout << array_test3.GetStartIndex(  ) << endl;

	cout << "Checking the assignment operator by copying 'array_test2' into 'array_test1'\n";
		cout << "'array_test1' information is:\n";
		cout << array_test1.GetLength(  ) << " is 'array_test1' length\n";
		cout << array_test1.GetStartIndex(  ) << " is 'array_test1' starting index\n";
		for( int i( 0 ); i < array_test1.GetLength(  ); ++i )
		{
			cout << array_test1[ i ] << " ";
			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;

		cout << "'array_test2' information is:\n";
		cout << array_test2.GetLength(  ) << " is 'array_test2' length\n";
		cout << array_test2.GetStartIndex(  ) << " is 'array_test2' starting index\n";
		for( int i( 0 ); i < array_test2.GetLength(  ); ++i )
		{
			cout << array_test2[ i ] << " ";
			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;

		array_test1 = array_test2;							// checking assignment operator

		cout << "'array_test1' information is now:\n";
		cout << array_test1.GetLength(  ) << " is 'array_test1' length\n";
		cout << array_test1.GetStartIndex(  ) << " is 'array_test1' starting index\n";
		for( int i( 0 ); i < array_test2.GetLength(  ); ++i )
		{
			cout << array_test1[ i ] << " ";
			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;

		cout << "'array_test2' information is now:\n";
		cout << array_test2.GetLength(  ) << " is 'array_test2' length\n";
		cout << array_test2.GetStartIndex(  ) << " is 'array_test2' starting index\n";
		for( int i( 0 ); i < array_test2.GetLength(  ); ++i )
		{
			cout << array_test2[ i ] << " ";
			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;
	
	cout << "Making an array using the copy constructor\n";
		cout << "'array_test1' information is:\n";
		cout << array_test1.GetLength(  ) << " is 'array_test1' length\n";
		cout << array_test1.GetStartIndex(  ) << " is 'array_test1' starting index\n";
		for( int i( 0 ); i < array_test1.GetLength(  ); ++i )
		{
			cout << array_test1[ i ] << " ";
			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;

		Array< int > array_test4 = array_test1;				// checking copy constructor

		cout << "'array_test1' information is now:\n";
		cout << array_test1.GetLength(  ) << " is 'array_test1' length\n";
		cout << array_test1.GetStartIndex(  ) << " is 'array_test1' starting index\n";
		for( int i( 0 ); i < array_test2.GetLength(  ); ++i )
		{
			cout << array_test1[ i ] << " ";
			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;

		cout << "'array_test4' information is now:\n";
		cout << array_test4.GetLength(  ) << " is 'array_test4' length\n";
		cout << array_test4.GetStartIndex(  ) << " is 'array_test4' starting index\n";
		for( int i( 0 ); i < array_test4.GetLength(  ); ++i )
		{
			cout << array_test4[ i ] << " ";
			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;
	
	cout << "Testing 'array_test1' for out of lower bounds.\n";
		try
		{
			array_test1[ -1 ] = 5;
		}
		catch( Exception & except )
		{
			cout << except << endl;
		}

	cout << "Testing 'array_test1' for out of upper bounds.\n";
		try
		{
			array_test1[ 10 ] = 20;
		}
		catch( Exception & except )
		{
			cout << except << endl;
		}

	cout << "Testing 'array_test1' for invalid length in two arg constructor.\n";
		try
		{
			Array< int > array_test5( -1 );
		}
		catch( Exception & except )
		{
			cout << except << endl;
		}

	cout << "Testing 'array_test1' for invalid length in SetLength(  ).\n";
		try
		{
			array_test1.SetLength( -1 );
		}
		catch( Exception & except )
		{
			cout << except << endl;
		}
	
	cout << "Making an array of Array objects.\n";
		Array< int > ra[ 15 ];

	cout <<  "Explicitly calling the destructor.\n";
		array_test4.~Array();
	
	cout << "Filling 'array_test1'\n";
		for( int i( 0 ); i < array_test1.GetLength(  ); ++i )
		{
			array_test1[ i ] = i;
			cout << array_test1[ i ] << " ";

			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;

	cout << "Changing the length of 'array_test1'\n";
		array_test1.SetLength( 5 );

	cout << "Checking the data left in 'array_test1'\n";
		for( int i( 0 ); i < array_test1.GetLength(  ); ++i )
		{
			cout << array_test1[ i ] << " ";

			if( i % 5 == 4 )
				cout << endl;
		}
		cout << endl;

	cout << "Changing the 'start_index' on 'array_test1'\n";
		array_test1.SetStartIndex( 3 );

	cout << "then changing the length of the array so 'start_index' is out of bounds\n";
		array_test1.SetLength( 1 );
		
	cout << "last, trying to access the start of the array at 'start_index'.\n";
		try
		{
			cout << array_test1[ 3 ] << endl;
		}
		catch( Exception except )
		{
			cout << except << endl;
		}

	cout << "Making an array of strings with a different start index\n";
		Array< string > Strings( 10, 5 );

	cout << "Setting a value to an index of the new string array\n";
		Strings[ 7 ] = "Hello Strings, meet Array.\n";
		cout << Strings[ 7 ];

	cout << "Changing the starting index\n";
		Strings.SetStartIndex( 0 );

	cout << "Displaying the string in its 'new' location\n";
		cout << Strings[ 2 ];

	cout << "Changing the length of string array\n";
	cout << "This new length will remove the data in the array\n";
		Strings.SetLength( 1 );

	cout << "Trying to access the data in the array, that is now gone\n";
		try
		{
			cout << Strings[ 2 ];
		}
		catch( Exception & except )
		{
			cout << except << endl;
		}

	return 0;
}