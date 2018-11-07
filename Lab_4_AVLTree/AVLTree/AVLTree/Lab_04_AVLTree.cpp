/**********************************************************************
* Author:						Steven Alspach
* Date Created:					05-11-2015
* Last Modification Date:		05-13-2015
* Lab Number:					Lab 04 AVL Tree
* File Name:					Lab_04_AVLTree.cpp
*
*	  Overview: This is an implementation of a self-balancing binary
*				tree, or an AVL tree.
*	
*		 Input:	There is no input required from the user.
*	
*		Output: All output is generated through the testing of the 
*				AVL tree.
*		
**********************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>


#include "AVLTree.h"

void DisplayNode( int & data );


int main(  )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	void (*StuffToDo)(int&);
	StuffToDo = &DisplayNode;

	AVLTree< int > test;

	test.Insert( 8 );
	test.Insert( 9 );
	test.Insert( 10 );
	test.Insert( 2 );
	test.Insert( 1 );
	test.Insert( 5 );
	test.Insert( 3 );
	test.Insert( 6 );
	test.Insert( 4 );
	test.Insert( 7 );
	test.Insert( 11 );

	test.BreadthFirst( StuffToDo );
	cout << endl;
	
	test.Delete( 5 );

	test.BreadthFirst( StuffToDo );
	cout << endl;

	test.Delete( 8 );
	cout << endl;

	test.BreadthFirst( StuffToDo );
	cout << endl;
	// 9 10 2 1 3 6 4 7 11
	test.Insert( 50 );
	test.Insert( 25 );
	test.Insert( 75 );
	test.Insert( 12 );
	test.Insert( 8 );
	test.Insert( 5 );
	test.Insert( 100 );
	test.Insert( 80 );
	test.Insert( 60 );
	test.Insert( 15 );
	test.Insert( 20 );
	test.Insert( -1 );
	test.Insert( -3 );

	test.BreadthFirst( StuffToDo );
	cout << endl;

	test.Delete( 8 );
	test.Delete( 100 );
	test.Delete( 75 );
	test.Delete( 25);
	test.Delete( 50 );
	test.Delete( 15 );
	test.Delete( -1 );
	test.Delete( -3 );
	test.Delete( 80 );
	test.Delete( 60 );

	test.BreadthFirst( StuffToDo );
	cout << endl;

	try
	{
		test.Delete( 8 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	test.Purge(  );

	try
	{
		test.Delete( 15 );
	}
	catch( Exception & except )
	{
		cout << except << endl;
	}

	test.Insert( 8 );
	test.Insert( 9 );
	test.Insert( 10 );
	test.Insert( 2 );
	test.Insert( 1 );
	test.Insert( 5 );
	test.Insert( 3 );
	test.Insert( 6 );
	test.Insert( 4 );
	test.Insert( 7 );
	test.Insert( 11 );

	AVLTree< int > test2( test );
	AVLTree< int > test3;

	test3 = test;

	test.BreadthFirst( StuffToDo );
	cout << endl;
	test2.BreadthFirst( StuffToDo );
	cout << endl;
	test3.BreadthFirst( StuffToDo );
	cout << endl;

	return 0;
}

	void DisplayNode( int & data )
	{
		cout << data << ' ';
	}