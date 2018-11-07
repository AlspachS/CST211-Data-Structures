/**********************************************************************
* Author:						Steven Alspach
* Date Created:					5/22/2015
* Last Modification Date:		5/29/2015
* Lab Number:					LO5 Dijkstra's
* File Name:					Lab_5_Dijkstras.cpp
*
*	  Overview:	Contains an implementation of Dijkstra's shortest path
*				algorithm, which finds the shortest distance between
*				two vertices in a graph data structure.
*	
*		 Input:	The list of available vertices is displayed, from which
*				the user can pick a starting vertex and an ending
*				vertex.  The program then calculates the path, mileage,
*				and travel time it would take to travel between those 
*				two vertices (which represent cities in this program).
*	
*		Output:	The out put is formatted as follows:
*
*					Vertex
*					Vertex
*					Vertex
*					Vertex
*					Vertex
*					Vertex
*					Vertex
*					Vertex
*					Vertex
*
*					Enter a starting vertex:  
*					Enter an ending vertex:  
*
*					Starting vertex
*					vertex
*					vertex
*					vertex
*					Ending vertex
*
*					This is a distance of "miles"
*					And a time of HR:MIN:SEC.
*
*					Calculate another path? (1):Yes, (2):No
*		
**********************************************************************/
#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;

#include "Graph.h"

#include <fstream>
	using std::ifstream;

#include <string>
	using std::string;

#include <vector>
	using std::vector;

#include "Dijkstra.h"

void Display( string & data );

template< typename V, typename E >
void ReadFile( Graph< V, E > & map  );

template< typename V, typename E >
void UserInput( string & from, string & to, Graph< V, E > & map );

template< typename V, typename E >
void DijkstrasPath( string from, string to, Graph< V, E > & map );

int main(  )
{
	Graph< string, string > map;
	string from;
	string to;
	char choice;
	int menu = 0;
	bool quit = false;
	
	void (*visit)(string&);
	visit = &Display;

	ReadFile( map );

	while( !quit )
	{
		map.BreadthFirst( visit );
		cout << endl;
		UserInput( from, to, map );
		cout << endl;
		DijkstrasPath( from, to, map );

		while( menu != 1 && menu != 2 )
		{
			cout << "Calculate another path? (1):Yes, (2):No\n";
			cin.get( choice );
			cin.sync(  );
			menu = atoi( &choice );
		
			if( menu == 1 )
				system( "CLS" );
			else if( menu == 2 )
				quit = true;
			else
				cout << "Invalid" << endl;
		}
		menu = 0;
	}

	return 0;
}
 
/**********************************************************************
*	void Display( string & data )
*
*	   Purpose: Displays the data in a vertex, passed to the
*				BreadthFirst traversal as a function pointer.
*
*		 Entry:	The data in the vertex is passed in as data.
*
*		  Exit:	The data is displayed.
*
**********************************************************************/
void Display( string & data )
{
	cout << data << endl;
}

/**********************************************************************
*	void ReadFile( Graph< V, E > & map )
*
*	   Purpose: Reads the MapInfo.txt provided with the lab and stores
*				the values in the Graph.
*
*		 Entry:	The graph passed is an empty graph.
*
*		  Exit:	The graph has been filled with the values from the 
*				text file.
*
**********************************************************************/
template< typename V, typename E >
void ReadFile( Graph< V, E > & map )
{
	string nodeone;
	string nodetwo;
	string arc;
	string sweight;
	int weight = 0;

	ifstream fin;
	fin.open( "MapInfo.txt" );
	
	while( !fin.eof(  ) )
	{
		getline( fin, nodeone, ',' );
		getline( fin, nodetwo, ',' );
		getline( fin, arc, ',' );
		getline( fin, sweight );
		weight = stoi( sweight );

		map.InsertVertex( nodeone );
		map.InsertVertex( nodetwo );
		map.InsertArc( nodeone, nodetwo, arc, weight );
	}
	fin.close();
}

/**********************************************************************
*	void UserInput( string & from, string & to, Graph< V, E > & map )
*
*	   Purpose: Gets vertex data from the user for a starting vertex and
*				and ending vertex.
*
*		 Entry:	The data in from and to will be overwritten.
*
*		  Exit:	The data in from and to now represent the vertices the
*				user wants to determine the path between.
*
**********************************************************************/
template< typename V, typename E >
void UserInput( string & from, string & to, Graph< V, E > & map ) 
{
	do
	{
		cout << "Enter the starting node:  ";
		getline( cin, from );
		if( !map.FindVertex( from ) )
			cout << "Invalid starting location.\n";
	}while( !map.FindVertex( from ) );

	do
	{
		cout << "Enter the ending node:  ";
		getline( cin, to );
		if( !map.FindVertex( to ) )
			cout << "Invalid ending location.\n";
	}while( !map.FindVertex( to ) );
 }

/**********************************************************************
*	void DijkstrasPath( string from, string to, Graph< V, E > & map )
*
*	   Purpose: Uses the Dijkstra class to run the shortest path 
*				algorithm on the graph.
*
*		 Entry:	The user has given the starting and ending vertices
*				in a previous function, these values are valid values.
*
*		  Exit:	The shortest path has been found and displayed.
*
**********************************************************************/
template< typename V, typename E >
void DijkstrasPath( string from, string to, Graph< V, E > & map )
{
	Dijkstra< string, string > DijAlg( map );
	DijAlg.ShortestPath( from, to, map );
}