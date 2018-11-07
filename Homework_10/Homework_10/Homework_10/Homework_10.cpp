

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "BinarySearchTree.h"
#include "Exception.h"

#include <iostream>
	using std::cout;
	using std::endl;

template <typename T>
void DisplayNode( T & TreeNode );

int main(  )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	BSTree< int > test;

	cout << test.Height(  ) << endl;
	test.Insert( 20 );
	cout << test.Height(  ) << endl;
	test.Insert( 12 );
	cout << test.Height(  ) << endl;
	test.Insert( 25 );
	cout << test.Height(  ) << endl;
	test.Insert( 11 );
	cout << test.Height(  ) << endl;
	test.Insert( 18 );
	cout << test.Height(  ) << endl;
	test.Insert( 22 );
	cout << test.Height(  ) << endl;
		
	void (*StuffToDo)(int&);
	StuffToDo = &DisplayNode;

	test.InOrder( StuffToDo );
	cout << endl;

	test.PreOrder( StuffToDo );
	cout << endl;

	test.PostOrder( StuffToDo );
	cout << endl;

	test.BreadthFirst( StuffToDo );
	cout << endl;

	cout << test.Height(  ) << endl;

	test.Delete( 25 );
	cout << test.Height(  ) << endl;
	test.Delete( 11 );
	cout << test.Height(  ) << endl;
	
	cout << test.Height(  ) << endl;

	

	cout << test.Height(  ) << endl;

	try
	{
		test.Delete( 12 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test.Delete( 5 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	try
	{
		test.Delete( 11 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	test.Purge(  );

	cout << test.Height(  ) << endl;
	test.Insert( 20 );
	cout << test.Height(  ) << endl;
	test.Insert( 12 );
	cout << test.Height(  ) << endl;
	test.Insert( 25 );
	cout << test.Height(  ) << endl;
	test.Insert( 11 );
	cout << test.Height(  ) << endl;
	test.Insert( 18 );
	cout << test.Height(  ) << endl;
	test.Insert( 22 );
	cout << test.Height(  ) << endl;
	

	BSTree< int > test2( test );

	BSTree< int > test3;

	test3 = test;

	test2.InOrder( StuffToDo );
	cout << endl;

	test3.InOrder( StuffToDo );
	cout << endl;



	test2.Purge(  );
	test3.Purge(  );

	return 0;
}
	
	template <typename T>
	void DisplayNode( T & TreeNode )
	{
		cout << TreeNode->getData() << ' ';
	}