/***********************************************************************
* 	 Class: Dijkstra
* Filename:	Dijkstra.h
*
*		Contains the algorithm to find the shortest path between two
*		nodes in a graph.
*
* Constructors:
*			Dijkstra( Graph< V, E > & map )
*
*	  Mutators:
*			No mutators for this class
*
*	   Methods:
*			void ShortestPath( V from, V to, Graph< V, E > & map )
*				Interface for the user to call to find the shortest 
*				path in the graph
*
*			void BuildArrays( V from, Graph< V, E > & map )
*				Constructs the distance and predecessor information for
*				all vertices in the graph
*
*			void FindPath( V to, Graph< V, E > & map )
*				Stacks up the path information from the arrays to find
*				the shortest path
*
*			void CalculateTime( Graph< V, E > & map )
*				Calculates the time it takes to travel between two
*				vertices using the speed and weight of the arc
*
*			void DisplayPathAndTime(  )
*				Unstacks and displays the path as well as converts the 
*				time from decimal to hours:minutes:seconds format
*
***********************************************************************/
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Graph.h"

#include <vector>
	using std::vector;

#include <stack>
	using std::stack;

#include <list>
	using std::list;

#include <cmath>
	using std::modf;
	using std::ceil;

template< typename V, typename E >
class Dijkstra
{
	public:

	// Manager functions

		// One argument constructor
		Dijkstra( Graph< V, E > & map );

	// Member function

		// Interface to use the shortest path algorithm
		void ShortestPath( V from, V to, Graph< V, E > & map );

	private:

	// Internal structure

		// Stores the information in one place, so multiple arrays aren't needed
		struct NODE
		{
			V data;
			int distance;
			int speed;
			int predecessor;
		};

	// Helper functions

		// Build the arrays needed to determine the shortest path
		void BuildArrays( V from, Graph< V, E > & map );

		// Determine, from the arrays, the shortest path
		void FindPath( V to, Graph< V, E > & map );

		// Calculate the time it takes to get from
		// the starting point to the destination
		void CalculateTime( Graph< V, E > & map );

		// Displays the route, mileage, and time the shortest path takes
		void DisplayPathAndTime(  );

		vector< NODE > mVertices;		// An array of nodes 
		stack< V > mPath;				// Stack to find path 
		double mTime;					// Time it takes to travel
		int mMiles;						// Distance between the starting vertex and ending vertex

};

	/**********************************************************************
	*	Dijkstra< V, E >::Dijkstra( Graph< V, E > & map )
	*
	*	   Purpose: Constructs a Dijkstra object and sets all the arrays
	*				to an initial value of -1.
	*
	*		 Entry: The graph has some vertices.
	*
	*		  Exit: The distance and predecessor arrays are set to  an 
	*				invalid value.
	*
	**********************************************************************/
	template< typename V, typename E >
	Dijkstra< V, E >::Dijkstra( Graph< V, E > & map ) : mTime( 0 ), mMiles( 0 )
	{
		int numofVs = map.GetCount(  );
		mVertices.resize( numofVs );

		for( int i( 0 ); i < numofVs; ++i )
		{
			mVertices[ i ].distance = -1;
			mVertices[ i ].predecessor = -1;
			mVertices[ i ].speed = 0;			
		}
	}

	/**********************************************************************
	*	void Dijkstra< V, E >::ShortestPath( V from, V to, Graph< V, E > & map )
	*
	*	   Purpose: Called by the user to find the distance between two nodes
	*				in their graph.
	*
	*		 Entry: The user is passing in the beginning vertex and ending
	*				vertex, as well as the graph.
	*
	*		  Exit:	No changes to the data passed in have been made.  The
	*				shortest path has been determined and displayed.
	*
	**********************************************************************/
	template< typename V, typename E > 
	void Dijkstra< V, E >::ShortestPath( V from, V to, Graph< V, E > & map )
	{
		BuildArrays( from, map );
		FindPath( to, map );
		CalculateTime( map );
		DisplayPathAndTime(  );
	}

	/**********************************************************************
	*	void Dijkstra< V, E >::BuildArrays( V from, Graph< V, E > & map )
	*
	*	   Purpose:	Constructs the NODE array such that each element
	*				has the shortest path to the starting node.
	*
	*		 Entry: The data stored in the NODE array is still default.
	*
	*		  Exit: The NODE array has been filled with the correct
	*				information about the distance and predecessor of each
	*				vertex.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Dijkstra< V, E >::BuildArrays( V from, Graph< V, E > & map )
	{
		list< Arc< V, E > > adjacent;
		list< Arc< V, E > >::iterator AdjListIt;
		vector< NODE >::iterator VerVecIt;
		int curr = map.GetPos( from );
		int next = 0;
		V current = from;
		
		mVertices[ curr ].distance = 0;
		mVertices[ curr ].data = from;
		for( int i( 0 ); i < map.GetCount(  ); ++i )
		{
			current = mVertices[ curr ].data;
			adjacent = map.FindVertex( current )->GetAdjacent(  );

			for( AdjListIt = adjacent.begin(  ); AdjListIt != adjacent.end(  ); ++AdjListIt )
			{
				if( !AdjListIt->GetDest(  )->GetProcessed(  ) )
				{
					mVertices[ map.GetPos( AdjListIt->GetDest(  )->GetData(  ) ) ].data = AdjListIt->GetDest(  )->GetData(  );
					next = map.GetPos( AdjListIt->GetDest(  )->GetData(  ) );
					
					if( mVertices[ map.GetPos( AdjListIt->GetDest(  )->GetData(  ) ) ].distance == -1 ||
						mVertices[ curr ].distance + AdjListIt->GetWeight(  ) <
						mVertices[ map.GetPos( AdjListIt->GetDest(  )->GetData(  ) ) ].distance )
					{
						mVertices[ map.GetPos( AdjListIt->GetDest(  )->GetData(  ) ) ].distance = mVertices[ curr ].distance + AdjListIt->GetWeight(  );
						mVertices[ map.GetPos( AdjListIt->GetDest(  )->GetData(  ) ) ].predecessor = curr;

						if( AdjListIt->GetData(  ) == "I-5" )
							mVertices[ map.GetPos( AdjListIt->GetDest(  )->GetData(  ) ) ].speed = 65;
						else
							mVertices[ map.GetPos( AdjListIt->GetDest(  )->GetData(  ) ) ].speed = 55;
					}
				}
			}

			map.FindVertex( mVertices[ curr ].data )->SetProcessed( true );
			curr = next;

			for( VerVecIt = mVertices.begin(  ); VerVecIt != mVertices.end(  ); ++VerVecIt )
			{
				if( map.FindVertex( VerVecIt->data ) )
				{
					if( !map.FindVertex( VerVecIt->data )->GetProcessed(  ) &&
						VerVecIt->distance != -1 &&
						VerVecIt->distance < mVertices[ curr ].distance )
					{
						curr = map.GetPos( VerVecIt->data );
					}
				}
			}
		}

		map.ResetProcessed(  );
	}

	/**********************************************************************
	*	void Dijkstra< V, E >::FindPath( V to, Graph< V, E > & map
	*
	*	   Purpose: Starting at the destination, travels through the NODE 
	*				array, stacking up each element it passes until it
	*				reaches the starting vertex.
	*
	*		 Entry: The stack mPath is empty.
	*
	*		  Exit:	The stack has been filled with the shortest path between
	*				two graph vertices.  The distance between these two 
	*				vertices is stored in mMiles.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Dijkstra< V, E >::FindPath( V to, Graph< V, E > & map )
	{
		V destination = to;
		mMiles = mVertices[ map.GetPos( destination ) ].distance;
		int prev = 0;

		while( mVertices[ map.GetPos( destination ) ].predecessor != -1 )
		{
			mPath.push( destination );
			prev = mVertices[ map.GetPos( destination ) ].predecessor;
			destination = mVertices[ prev ].data;
		}
		mPath.push( destination );
	}

	/**********************************************************************
	*	void Dijkstra< V, E >::CalculateTime( Graph< V, E > & map )
	*
	*	   Purpose: Copies the mPath variable, unstacks the copy to get the
	*				speed stored at each element, then calculates the time
	*				to travel that arc.
	*
	*		 Entry: Copies the mPath stack, but doesn't change it.
	*
	*		  Exit:	mTIme is now a decimal value of the time it takes to
	*				travel between the two vertices.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Dijkstra< V, E >::CalculateTime( Graph< V, E > & map )
	{
		stack< V > rate = mPath;
		double mph = 0;
		int length = 0;
		int last = 0;

		rate.pop(  );
		while( !rate.empty(  ) )
		{
			last = length;
			length = mVertices[ map.GetPos( rate.top(  ) ) ].distance;
			mph = mVertices[ map.GetPos( rate.top(  ) ) ].speed;
			mTime += ( ( length - last ) / mph );
			rate.pop(  );
		}
	}

	/**********************************************************************
	*	void Dijkstra< V, E >::DisplayPathAndTime(  )
	*
	*	   Purpose:	Unstacks the path that was stacked up in FindPath 
	*				function and displays them, then converts the mTime
	*				data member from decimal to hour, minute, second format.
	*
	*		 Entry: mPath has the shortest path between two vertices.  mTime
	*				has a decimal values of the time it takes to travel
	*				between these two vertices.
	*
	*		  Exit:	mPath is now empty, with the values in it having been
	*				displayed.  mTime is converted to hours:minutes:seconds
	*				format.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Dijkstra< V, E >::DisplayPathAndTime(  )
	{
		double hour = 0;
		double minu = 0;
		double seco = 0;

		while( !mPath.empty(  ) )
		{
			cout << mPath.top(  ) << endl;
			mPath.pop(  );
		}

		minu = modf( mTime, &hour );
		minu *= 60;
		seco = modf( minu, &minu );
		seco *= 60;
		seco = ceil( seco );

		cout << "\nThis is a distance of " << mMiles << endl;
		cout << "And a time of " << hour << ":" << minu << ":" << seco << ".\n" << endl;
	}

#endif
























































































//
//
//#include "Graph.h"
//
//#include <vector>
//	using std::vector;
//
//template< typename V, typename E >
//class Dijkstra
//{
//	//friend void AddNode( string & data );
//
//	struct NODE
//	{
//		V data;
//		int distance;
//		V predecessor;
//	};
//
//	public:
//		Dijkstra( Graph< V, E > & map );
//		Dijkstra( const Dijkstra< V, E > & copy );
//		Dijkstra< V, E > & operator=( const Dijkstra< V, E > & rhs );
//		~Dijkstra(  );
//
//		NODE & operator[]( V index );
//		void static AddNode( V & data );
//
//	private:
//		static vector< NODE > StaNodes;
//		vector< NODE > mNodes;
//
//};
//
//	template< typename V, typename E >
//	Dijkstra< V, E >::Dijkstra( Graph< V, E > & map )
//	{
//		map.BreadthFirst( AddNode );
//	}
//
//	template< typename V, typename E >
//	Dijkstra< V, E >::~Dijkstra(  )
//	{  }
//
//	template< typename V, typename E >
//	typename Dijkstra< V, E >::NODE & Dijkstra< V, E >::operator[]( V index )
//	{
//		
//	}
//
//	template< typename V, typename E >
//	void Dijkstra< V, E >::AddNode( V & data )
//	{
//		NODE Add;
//
//		Add.data = data;
//		Add.distance = -1;
//
//		StaNodes.push_back( Add );
//		//mNodes.push_back( Add );
//	}
//	