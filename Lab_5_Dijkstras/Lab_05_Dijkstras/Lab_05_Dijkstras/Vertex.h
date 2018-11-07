/***********************************************************************
* 	 Class: Vertex
* Filename:	Vertex.h
*
*		The vertex object that makes up a graph.
*
* Constructors:
*			Vertex(  )
*				Creates an empty vertex.
*
*	  Mutators:
*			void SetData( V data )
*				Sets the data in the arc.
*
*			void SetProcessed( bool change )
*				Sets the processed flag in the vertex
*
*			void AddArc( Arc< V, E > road )
*				Adds an arc to the vertex
*
*			void DeleteArc( Arc< V, E > road )
*				Removes an arc to the vertex
*
*			void RemoveInRoads(  )
*				Removes all the arcs of a vertex
*
*	   Methods:
*			V GetData(  )
*				Returns the data in the vertex
*
*			list< Arc< V, E > > GetAdjacent(  )
*				Returns a copy of the arc list of the vertex
*
*			bool GetProcessed(  )
*				Returns whether the vertex has been processed
*
***********************************************************************/
#ifndef	VERTEX_H
#define VERTEX_H

#include "Arc.h"

#include <list>
	using std::list;

template< typename V, typename E > class Graph;

template< typename V, typename E >
class Vertex
{
	friend class Graph< V, E >;

	public:

	// Manager functions

		// No argument constructor
		Vertex(  );

		// Copy constructor
		Vertex( const Vertex< V, E > & copy );

		// Assignment operator
		Vertex< V, E > & operator=( const Vertex< V, E > & rhs );

		// Destructor
		~Vertex(  );

	// Operator overloads

		// Equality operator
		bool operator==( Vertex< V, E > rhs );

	// Mutator functions

		// Sets the data in the vertex
		void SetData( V data );

		// Change the processed state
		void SetProcessed( bool change );

		// Adds an arc
		void AddArc( Arc< V, E > road );

		// Removes an arc
		void DeleteArc( Arc< V, E > road );

		// Removes all arcs pointing to a vertex
		void RemoveInRoads(  );

	// Accessor functions

		// Data accessor
		V GetData(  );

		// Returns a copy of the list of arcs
		list< Arc< V, E > > GetAdjacent(  );

		// Returns the state of the vertex
		bool GetProcessed(  );

	private:
		list< Arc< V, E > > mArcs;		// The arcs leading out of the vertex
		V mData;						// The data of the vertex
		int mRoads;						// The number of arcs the vertex has
		bool mProcessed;				// Whether the arc has been processed

	protected:
};

	/**********************************************************************
	*	Vertex< V, E >::Vertex(  )
	*
	*	   Purpose:	Constructs an empty vertex.  The data members of this 
	*				vertex can be set using the mutator functions.
	*
	*		 Entry:	No vertex exists.
	*
	*		  Exit: An empty vertex can now be used.
	*
	**********************************************************************/
	template< typename V, typename E >
	Vertex< V, E >::Vertex(  ) :
							mArcs(  ), mData(  ), mRoads( 0 ),
							mProcessed( false )
	{  }

	/**********************************************************************
	*	Vertex< V, E >::Vertex( const Vertex< V, E > & copy )
	*
	*	   Purpose: Creates an Vertex that is a copy of an existing Vertex.
	*
	*		 Entry:	The new Vertex is not yet created, and 'copy' is an Vertex.
	*
	*		  Exit:	The new Vertex is created, and it has the same data as
	*				'copy'.
	*
	**********************************************************************/
	template< typename V, typename E >
	Vertex< V, E >::Vertex( const Vertex< V, E > & copy ) :
							mArcs( copy.mArcs ), mData( copy.mData ),
							mRoads( copy.mRoads ), mProcessed( copy.mProcessed )
	{  }

	/**********************************************************************
	*	vertex< V, E > & vertex< V, E >::operator=( const vertex< V, E > & rhs )
	*
	*	   Purpose:	Assigns an existing vertex the values of a second existing
	*				vertex.
	*
	*		 Entry:	Both vertices are objects, and may have data.
	*
	*		  Exit:	The calling vertex is now a copy of the 'rhs' vertex.
	*
	**********************************************************************/
	template< typename V, typename E >
	Vertex< V, E > & Vertex< V, E >::operator=( const Vertex< V, E > & rhs )
	{
		if( this != &rhs )
		{
			mArcs = rhs.mArcs;
			mData = rhs.mData;
			mRoads =  rhs.mRoads;
			mProcessed = rhs.mProcessed;
		}
		return * this;
	}

	/**********************************************************************
	*	Vertex< V, E >::~Vertex(  )
	*
	*	   Purpose:	Destroys an Vertex object, removing all data in it, and
	*				removing the Vertex object.
	*
	*		 Entry:	The calling Vertex is going out of scope, taking its data
	*				with it.
	*
	*		  Exit:	The calling Vertex is now gone.
	*
	**********************************************************************/
	template< typename V, typename E >
	Vertex< V, E >::~Vertex(  )
	{  }

//
// Operator overloads
//

	/**********************************************************************
	*	bool Vertex< V, E >::operator==( Vertex< V, E > rhs )
	*
	*	   Purpose: Compares two vertices for equality.
	*
	*		 Entry:	Both vertices have data.
	*
	*		  Exit: Returns true if two vertices are equal, to be considered 
	*				equal, the data of the Vertices must be the same.
	*
	**********************************************************************/
	template< typename V, typename E >
	bool Vertex< V, E >::operator==( Vertex< V, E > rhs )
	{
		return ( mData == rhs.mData );
	}

//
// Mutator functions
//

	/**********************************************************************
	*	void Vertex< V, E >::SetData( V data )
	*
	*	   Purpose:	Sets the data in the Vertex.
	*
	*		 Entry:	The Vertex's data is irrelevant because it will be 
	*				overwritten.
	*
	*		  Exit:	The Vertex's data is now the value passed in.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Vertex< V, E >::SetData( V data )
	{
		mData = data;
	}

	/**********************************************************************
	*	void Vertex< V, E >::SetProcessed( bool changed )
	*
	*	   Purpose: Sets the processed flag in a vertex.
	*
	*		 Entry:	The flag is either boolean value.
	*
	*		  Exit:	The flag is now the boolean value of the value passed
	*				in.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Vertex< V, E >::SetProcessed( bool changed )
	{
		mProcessed = changed;
	}
	
	/**********************************************************************
	*	void Vertex< V, E >::AddArc( Arc< V, E > road )
	*
	*	   Purpose: Adds an arc to a vertex.
	*
	*		 Entry:	The new arc is being passed it.
	*
	*		  Exit:	The new arc has been pushed onto the back of the 
	*				vertex's arc list and the number of arcs the vertex
	*				has has been updated.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Vertex< V, E >::AddArc( Arc< V, E > road )
	{
		mArcs.push_back( road );
		mRoads = mArcs.size(  );
	}

	/**********************************************************************
	*	void Vertex< V, E >::DeleteArc( Arc< V, E > road )
	*
	*	   Purpose:	Removes an arc from a vertex.
	*
	*		 Entry:	The a copy of the arc to remove is passed in.
	*
	*		  Exit:	The arc has been removed from the vertex's arc list.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Vertex< V, E >::DeleteArc( Arc< V, E > road )
	{
		mArcs.remove( road );
		mRoads = mArcs.size(  );
	}

	/**********************************************************************
	*	void Vertex< V, E >::RemoveInRoads(  )
	*
	*	   Purpose: Removes all arcs pointing to a vertex.
	*
	*		 Entry:	The calling vertex has arcs pointing to it from other 
	*				vertices.
	*
	*		  Exit:	All the arcs to the calling vertex from other vertices
	*				have been removed.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Vertex< V, E >::RemoveInRoads(  )
	{
		Vertex< V, E > * tempV = nullptr;
		
		Arc< V, E > tempA;
		tempA.SetDest( this );
		
		for( list< Arc< V, E > >::iterator AListIt = mArcs.begin(  ); AListIt != mArcs.end(  ) && mArcs.size(  ) != 0; AListIt++ )
		{
			if( AListIt->GetDest(  ) != this )
			{
				tempA.SetData( AListIt->GetData(  ) );
				tempV = AListIt->GetDest(  );
				tempV->DeleteArc( tempA );
			}
		}
	}

//
// Accessor functions
//

	/**********************************************************************
	*	V Vertex< V, E >::GetData(  )
	*
	*	   Purpose: Returns the data stored in a Vertex.
	*
	*		 Entry: The Vertex may have some data.
	*
	*		  Exit:	The Vertex's data is returned.
	*
	**********************************************************************/
	template< typename V, typename E >
	V Vertex< V, E >::GetData(  )
	{
		return mData;
	}

	/**********************************************************************
	*	list< Arc< V, E > > Vertex< V, E >::GetAdjacent(  )
	*
	*	   Purpose: Returns a copy of the vertices arc list.
	*
	*		 Entry:	The vertex has some arcs leading to other vertices.
	*
	*		  Exit:	The list of arcs leading to other vertices has been
	*				returned.
	*
	**********************************************************************/
	template< typename V, typename E >
	list< Arc< V, E > > Vertex< V, E >::GetAdjacent(  )
	{
		return mArcs;
	}

	/**********************************************************************
	*	bool Vertex< V, E >::GetProcessed(  )
	*
	*	   Purpose: Returns whether the node has been processed yet.
	*
	*		 Entry:	The vertex has some boolean state of being processed,
	*				or not.
	*
	*		  Exit:	The state of the vertex has been processed.
	*
	**********************************************************************/
	template< typename V, typename E >
	bool Vertex< V, E >::GetProcessed(  )
	{
		return mProcessed;
	}

#endif