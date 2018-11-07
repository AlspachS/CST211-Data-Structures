#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "Exception.h"
#include "Array2D.h"
#include <string>
	using std::string;
#include <iostream>
	using std::cout;
	using std::endl;



int main(  )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	char b = '\u2630';
	cout << b << endl;

	cout << "Creating, filling, and displaying a five by five array\n";
	Array2D< int > test( 5, 5 );
	

	for( int i( 0 ); i < test.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test.getColumn(  ); ++j )
		{
			// test[ i ][ j ] = "This is a string ";
			test[ i ][ j ] = 2 * i + j;
		}
	}

	for( int i( 0 ); i < test.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test.getColumn(  ); ++j )
		{
			cout << test[ i ][ j ] << " ";
			if( j % 5 == 4 )
				cout << endl;
		}
	}


	cout << "===========================================================================\n";
	cout << "Changing the number of columns in the array to four, from five\n";

	test.setColumn( 4 );
	for( int i( 0 ); i < test.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test.getColumn(  ); ++j )
		{
			cout << test[ i ][ j ] << " ";
			if( j % 4 == 3 )
				cout << endl;
		}
	}


	cout << "===========================================================================\n";
	cout << "Changing the number of columns in the array to six, from four\n";

	test.setColumn( 6 );
	for( int i( 0 ); i < test.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test.getColumn(  ); ++j )
		{
			cout << test[ i ][ j ] << " ";
			if( j % 6 == 5 )
				cout << endl;
		}
	}


	cout << "===========================================================================\n";
	cout << "Changing the number of rows in the array to four, from five\n";

	test.setRow( 4 );
	for( int i( 0 ); i < test.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test.getColumn(  ); ++j )
		{
			cout << test[ i ][ j ] << " ";
			if( j % 6 == 5 )
				cout << endl;
		}
	}
	
	cout << "===========================================================================\n";
	cout << "Changing the number of rows in the array to six, from four\n";

	test.setRow( 6 );
	for( int i( 0 ); i < test.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test.getColumn(  ); ++j )
		{
			cout << test[ i ][ j ] << " ";
			if( j % 6 == 5 )
				cout << endl;
		}
	}

	cout << "===========================================================================\n";
	cout << "Testing the exception throws\n";
	
	try
	{
		test[ 6 ] [ 4 ];
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test[ -1 ] [ 4 ];
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test[ 4 ] [ 6 ];
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test[ 4 ] [ -1 ];
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test.setColumn( -1 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test.setRow( -1 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test.Select( -1, 0 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test.Select( 0, -1 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test.Select( 7, 0 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test.Select( 0, 7 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	cout << "===========================================================================\n";
	cout << "Testing copy constructor and assignment operator\n";

	Array2D< int > test2( test );
	Array2D< int > test3;
	test3 = test2;

	for( int k( 0 ); k < 3; ++k )
	{
		for( int i( 0 ); i < test.getRow(  ); ++i )
		{
			for( int j( 0 ); j < test.getColumn(  ); ++j )
			{
				cout << test[ i ][ j ] << " ";
				if( j % 6 == 5 )
					cout << endl;
			}
		}
		cout << endl;
	}

	cout << "===========================================================================\n";
	cout << "Testing destructor\n";

	test3.~Array2D(  );
	

	cout << "===========================================================================\n";
	cout << "Testing const things\n";

	cout << "===========================================================================\n";
	cout << "Initializing a constant array\n";

	const Array2D< int > constTest( test );

	cout << "===========================================================================\n";
	cout << "Displaying the const array with the two const subscprit operators\n";

	for( int i( 0 ); i < constTest.getRow(  ); ++i )
	{
		for( int j( 0 ); j < constTest.getColumn(  ); ++j )
		{
			cout << test[ i ][ j ] << " ";
			if( j % 6 == 5 )
				cout << endl;
		}
	}
	cout << endl;

	cout << "===========================================================================\n";
	cout << "Trying to change the size of the const array\n";
	// constTest.setColumn( 12 );
	// constTest.setRow( 12 );

	cout << "===========================================================================\n";
	cout << "Setting a non-const array to the const array with copy constructor\n";

	Array2D< int > test4 = constTest;

	for( int i( 0 ); i < test4.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test4.getColumn(  ); ++j )
		{
			cout << test4[ i ] [ j ] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "===========================================================================\n";
	cout << "Setting a non-const array to the const array with assignment operator\n";

	Array2D< int > test5;
	test5 = constTest;

	for( int i( 0 ); i < test5.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test5.getColumn(  ); ++j )
		{
			cout << test5[ i ] [ j ] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "===========================================================================\n";
	cout << "Displaying the const array with the Select() function\n";

	for( int i( 0 ); i < test5.getRow(  ); ++i )
	{
		for( int j( 0 ); j < test5.getColumn(  ); ++j )
		{
			cout << constTest.Select( i, j ) << " ";
		}
		cout << endl;
	}

	cout << "===========================================================================\n";
	cout << "Calling the destructor from the const array\n";

	constTest.~Array2D(  );

	cout << "===========================================================================\n";
	cout << "Trying to change the value in the const array\n";

	//for( int i( 0 ); i < constTest.getRow(  ); ++i )
	//{
	//	for( int j( 0 ); j < constTest.getColumn(  ); ++j )
	//	{
	//		constTest[ i ] [ j ] = 2 * i + j;
	//	}
	//}

	return 0;
}
