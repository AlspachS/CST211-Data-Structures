/***********************************************************************
* 	 Class: Graph
* Filename:	Graph.h
*
*		A graph, or map, data structure implemented as a multi-list.
*
* Constructors:
*			Graph(  )
*				Creates an empty graph object.
*				
*	  Mutators:
*			void InsertVertex( V data )
*				Inserts a vertex into the graph
*
*			void DeleteVertex( V data )
*				Removes a vertex from the graph
*
*			void InsertArc( V start, V end, E edge, int weight = 0 )
*				Inserts an arc into the graph
*
*			void DeleteArc( V start, V end, E edge )
*				Removes an arc from the graph
*
*			void ResetProcessed(  );
*				Resets the processed state of all vertices in the graph
*
*	   Methods:
*			void DepthFirst( void ( *visit )( V& ) )
*				Traverses the graph and performs *visit on the vertices
*
*			void BreadthFirst( void ( *visit )( V& ) )
*				Traverses the graph and performs *visit on the vertices
*
*			int GetCount(  )
*				Returns the number of vertices in the graph
*
*			int GetPos( V data )
*				Returns a pseudo-index number for a vertex
*
*			bool isEmpty(  )
*				Returns true if the graph is empty
*
*			Vertex< V, E > * FindVertex( V data )
*				Finds a particular vertex in the graph and returns a 
*				pointer to that vertex, or nullptr if the vertex wasn't 
*				found
*
*
***********************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Exception.h"

#include <list>
	using std::list;
	using std::iterator;

#include <stack>
	using std::stack;

#include <queue>
	using std::queue;

template< typename V, typename E >
class Graph
{
	public:

	// Manager functions

		// No argument constructor
		Graph(  );

		// Copy constructor
		Graph( const Graph< V, E > & copy );

		// Assignment operator
		Graph< V, E > & operator=( const Graph< V, E > & rhs );

		// Destructor
		~Graph(  );

	// Mutator functions

		// Insert a new vertex
		void InsertVertex( V data );

		// Remove an existing vertex
		void DeleteVertex( V data );

		// Insert a new arc
		void InsertArc( V start, V end, E edge, int weight = 0 );

		// Remove an existing arc
		void DeleteArc( V start, V end, E edge );

		// Resets all processed vertices to unprocessed
		void ResetProcessed(  );

	// Accessor functions

		// Traverse the graph in a depth-first order
		void DepthFirst( void ( *visit )( V& ) );

		// Traverse the graph in a breadth-first order
		void BreadthFirst( void ( *visit )( V& ) );

		// Returns the number of nodes in the graph
		int GetCount(  );

		// Returns the position of the vertex in the list
		int GetPos( V data );

	// Member functions

		// Returns true if the graph is empty
		bool isEmpty(  );

		// Returns a pointer to a vertex
		Vertex< V, E > * FindVertex( V data );

	private:
		list< Vertex< V, E > > mVertexList;		// List of vertices in the graph
		int mCount;								// Number of vertices in the graph

	protected:
};

//
// Manager functions
//

	/**********************************************************************
	*	Graph< V, E >::Graph(  )
	*
	*	   Purpose:	Constructs an empty Graph.  The data members of this Graph
	*				can be set using the mutator functions.
	*
	*		 Entry:	No Graph exists.
	*
	*		  Exit: An empty Graph can now be used.
	*
	**********************************************************************/
	template< typename V, typename E >
	Graph< V, E >::Graph(  ) : 
							mVertexList(  ), mCount( 0 )
	{  }

	/**********************************************************************
	*	Graph< V, E >::Graph( const Graph< V, E > & copy )
	*
	*	   Purpose: Creates an Graph that is a copy of an existing Graph.
	*
	*		 Entry:	The new Graph is not yet created, and 'copy' is an Graph.
	*
	*		  Exit:	The new Graph is created, and it has the same data as
	*				'copy'.
	*
	**********************************************************************/
	template< typename V, typename E >
	Graph< V, E >::Graph( const Graph< V, E > & copy ) :
							mVertexList( copy.mVertexList ), mCount( copy.mCount )
	{ 
		*this = copy;
	}

	/**********************************************************************
	*	Graph< V, E > & Graph< V, E >::operator=( const Graph< V, E > & rhs )
	*
	*	   Purpose:	Assigns an existing Graph the values of a second existing
	*				Graph.  The destination pointers of all arcs must be 
	*				updated to point to the new graph's vertices.
	*
	*		 Entry:	Both arcs are objects, and may have data.
	*
	*		  Exit:	The calling Graph is now a copy of the 'rhs' Graph.
	*
	**********************************************************************/
	template< typename V, typename E >
	Graph< V, E > & Graph< V, E >::operator=( const Graph< V, E > & rhs )
	{
		if( this != &rhs )
		{
			V tempvertdata;

			mVertexList = rhs.mVertexList;
			mCount = rhs.mCount;

			for( list< Vertex< V, E > >::iterator ListIt = mVertexList.begin(  ); ListIt != mVertexList.end(  ); ++ListIt )
			{
				for( list< Arc< V, E > >::iterator ArcListIt = ListIt->mArcs.begin(  ); ArcListIt != ListIt->mArcs.end(  ); ++ArcListIt )
				{
					tempvertdata = ArcListIt->GetDest(  )->GetData(  );
					ArcListIt->SetDest( FindVertex( tempvertdata ) );				
				}
			}
		}
		return *this;
	}

	/**********************************************************************
	*	Graph< V, E >::~Graph(  )
	*
	*	   Purpose:	Destroys an Graph object, removing all data in it, and
	*				removing the Graph object.
	*
	*		 Entry:	The calling Graph is going out of scope, taking its data
	*				with it.
	*
	*		  Exit:	The calling Graph is now gone.
	*
	**********************************************************************/
	template< typename V, typename E >
	Graph< V, E >::~Graph(  )
	{  }

//
// Member functions
//

	/**********************************************************************
	*	void Graph< V, E >::InsertVertex( V data )
	*
	*	   Purpose:	Inserts a vertex in the graph.
	*
	*		 Entry:	Data is the value the user wants to store in a new 
	*				vertex.
	*
	*		  Exit:	A new vertex has been created and appended to the 
	*				vertex list.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Graph< V, E >::InsertVertex( V data )
	{
		Vertex< V, E > * found = FindVertex( data );

		if( !found )
		{
			Vertex< V, E > added;
			added.SetData( data );
			mVertexList.push_back( added );  
			++mCount;
		}
	}

	/**********************************************************************
	*	void Graph< V, E >::DeleteVertex( V data )
	*
	*	   Purpose:	Removes a vertex from the graph.
	*
	*		 Entry:	Data is the vertex that the user wants to remove.
	*
	*		  Exit:	The vertex has been removed, and all arcs ending at
	*				the removed vertex have also been removed.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Graph< V, E >::DeleteVertex( V data )
	{
		Vertex< V, E > * remove = FindVertex( data );
		if( !remove )
			throw Exception( "Can't delete vertex, vertex not found" );


		remove->RemoveInRoads(  );
		mVertexList.remove( *remove );
		--mCount;
	}

	/**********************************************************************
	*	void Graph< V, E >::InsertArc( V start, V end, E edge, int weight = 0 )
	*
	*	   Purpose:	Insert an arc between two vertices.
	*
	*		 Entry:	Start is the vertex the arc starts at, and end is the
	*				vertex the arc will go to.
	*
	*		  Exit: An arc has been inserted that points to the destination
	*				vertex from the source vertex, as well as one inserted
	*				from the destination to the source vertex.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Graph< V, E >::InsertArc( V start, V end, E edge, int weight = 0 )
	{
		Vertex< V, E > * tempstart = FindVertex( start );
		if( !tempstart )
			throw Exception( "Starting vertex not found" );

		Vertex< V, E > * tempend = FindVertex( end );
		if( !tempend )
			throw Exception( "Destination vertex not found" );

		Arc< V, E > path;
		path.SetData( edge );
		path.SetWeight( weight );

		if( tempstart != tempend )
		{
			path.SetDest( tempend );
			tempstart->AddArc( path );

			path.SetDest( tempstart );
			tempend->AddArc( path );
		}
		else
		{
			path.SetDest( tempstart );
			tempstart->AddArc( path );
		}
	}

	/**********************************************************************
	*	void Graph< V, E >::DeleteArc( V start, V end, E edge )
	*
	*	   Purpose: Removes an arc between two vertices.
	*
	*		 Entry:	Start is the vertex from which the vertex originates, 
	*				and end is the destination vertex.
	*
	*		  Exit:	The arc has been removed from both the start vertex,
	*				and from the destination vertex.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Graph< V, E >::DeleteArc( V start, V end, E edge )
	{
		Vertex< V, E > * tempstart = FindVertex( start );
		if( !tempstart )
			throw Exception( "Starting vertex not found" );

		Vertex< V, E > * tempend = FindVertex( end );
		if( !tempend )
			throw Exception( "Destination vertex not found" );

		Arc< V, E > path;
		path.SetData( edge );

		if( tempstart != tempend )
		{
			path.SetDest( tempend );
			tempstart->DeleteArc( path );

			path.SetDest( tempstart );
			tempend->DeleteArc( path );
		}
		else
		{
			path.SetDest( tempstart );
			tempstart->DeleteArc( path );
		}
	}

	/**********************************************************************
	*	void Graph< V, E >::ResetProcessed(  )
	*
	*	   Purpose:	Resets all the vertices in a graph to an unprocessed
	*				state.
	*
	*		 Entry:	The value of the mProcessed flag is boolean, and will
	*				be overwritten.
	*
	*		  Exit:	All processed flags in the graph have been set to false.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Graph< V, E >::ResetProcessed(  )
	{
		for( list< Vertex< V, E > >::iterator ListIt = mVertexList.begin(  ); ListIt != mVertexList.end(  ); ++ListIt )
		{
			ListIt->SetProcessed( false );
		}
	}

	/**********************************************************************
	*	bool Graph< V, E >::isEmpty(  )
	*
	*	   Purpose: Tells whether the graph is empty, or not.
	*
	*		 Entry:	The graph either has vertices, or it doesn't.
	*
	*		  Exit:	Returns true if the graph is empty.
	*
	**********************************************************************/
	template< typename V, typename E >
	bool Graph< V, E >::isEmpty(  )
	{
		return( mVertexList.size(  ) == 0 );
	}

	/**********************************************************************
	*	Vertex< V, E > * Graph< V, E >::FindVertex( V data )
	*
	*	   Purpose: Looks through the vertex list for specific data and 
	*				returns a pointer to that vertex if the data is found.
	*				If the data is not found, returns nullptr.
	*
	*		 Entry:	The value of data is the vertex being searched for.
	*
	*		  Exit:	The vertex has either been found, or not, regardless,
	*				a pointer is returned.
	*
	**********************************************************************/
	template< typename V, typename E >
	Vertex< V, E > * Graph< V, E >::FindVertex( V data )
	{
		Vertex< V, E > * found = nullptr;
		for( list< Vertex< V, E > >::iterator ListIt = mVertexList.begin(  ); ListIt != mVertexList.end(  ) && !found; ++ListIt )
		{
			if( ListIt->GetData(  ) == data )
				found = &(*ListIt);
		}
		return found;
	}

	/**********************************************************************
	*	void Graph< V, E >::DepthFirst( void ( *visit )( V& ) )
	*
	*	   Purpose: Traverses and processes the graph in depth first
	*				manner.
	*
	*		 Entry: The graph has to have vertices in it.  Visit is a 
	*				pointer to a function.
	*
	*		  Exit: The graph has been processes, and whatever visit
	*				does to the vertices has been done to all the vertices.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Graph< V, E >::DepthFirst( void ( *visit )( V& ) )
	{
		if( mVertexList.empty(  ) )
			throw Exception( "Graph is empty" );

		stack< Vertex< V, E > * > dep;
		Vertex< V, E > * current;

		dep.push( &mVertexList.front(  ) );
		while( !dep.empty(  ) )
		{
			current = dep.top(  );
			dep.pop(  );
			visit( current->GetData(  ) );
			current->SetProcessed( true );

			for( list< Arc< V, E > >::iterator ListIt = current->mArcs.begin(  ); ListIt != current->mArcs.end(  ); ++ListIt )
			{
				if( !ListIt->GetDest(  )->GetProcessed(  ) )
				{
					dep.push( ListIt->GetDest(  ) );
					ListIt->GetDest(  )->SetProcessed( true );
				}
			}
		}
		ResetProcessed(  );
	}

	/**********************************************************************
	*	void Graph< V, E >::BreadthFirst( void ( *visit )( V& ) )
	*
	*	   Purpose: Traverses and processes the graph in breadth first
	*				manner.
	*
	*		 Entry: The graph has to have vertices in it.  Visit is a 
	*				pointer to a function.
	*
	*		  Exit: The graph has been processes, and whatever visit
	*				does to the vertices has been done to all the vertices.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Graph< V, E >::BreadthFirst( void ( *visit )( V& ) )
	{
		if( mVertexList.empty(  ) )
			throw Exception( "Graph is empty" );

		queue< Vertex< V, E > * > bread;
		Vertex< V, E > * current;

		bread.push( &mVertexList.front(  ) );
		while( !bread.empty(  ) )
		{
			current = bread.front(  );
			bread.pop(  );
			visit( current->GetData(  ) );
			current->SetProcessed( true );

			for( list< Arc< V, E > >::iterator ListIt = current->mArcs.begin(  ); ListIt != current->mArcs.end(  ); ++ListIt )
			{
				if( !ListIt->GetDest(  )->GetProcessed(  ) )
				{
					bread.push( ListIt->GetDest(  ) );
					ListIt->GetDest(  )->SetProcessed( true );
				}
			}
		}
		ResetProcessed(  );
	}

	/**********************************************************************
	*	int Graph< V, E >::GetCount(  )
	*
	*	   Purpose: Returns the number of vertices in the graph.
	*
	*		 Entry:	mCount is the number of vertices in the graph.
	*
	*		  Exit:	mCount has been returned.
	*
	**********************************************************************/
	template< typename V, typename E >
	int Graph< V, E >::GetCount(  )
	{
		return mCount;
	}

	/**********************************************************************
	*	int Graph< V, E >::GetPos( V data )
	*
	*	   Purpose: Find the position of a particular value in the vertex
	*				list and returns this value.  This is kind of an index
	*				value for that vertex.
	*
	*		 Entry:	The value to find is held in data.
	*
	*		  Exit:	The data is found and the integer of where it is in the
	*				list is returned.
	*
	**********************************************************************/
	template< typename V, typename E >
	int Graph< V, E >::GetPos( V data )
	{
		bool found = false;
		int pos = 0;

		for( list< Vertex< V, E > >::iterator ListIt = mVertexList.begin(  ); ListIt != mVertexList.end(  ) && !found; ++ListIt, ++pos )
		{
			if( ListIt->GetData(  ) == data )
				found = true;
		}

		return pos - 1;
	}

#endif