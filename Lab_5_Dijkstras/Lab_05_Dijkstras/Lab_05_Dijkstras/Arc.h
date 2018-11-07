/***********************************************************************
* 	 Class: Arc
* Filename: Arc.h
*
*		The link between two vertices in a Graph.
*
* Constructors:
*			Arc(  )
*				Constructs an empty arc
*
*	  Mutators:
*			void SetData( E data )
*				Sets the data of the arc
*
*			void SetDest( Vertex< V, E > * dest )
*				Sets the destination of the arc
*
*			void SetWeight( int weight )
*				Sets the weight of the arc
*
*	   Methods:
*			E GetData(  )
*				Returns the data stored in the arc
*
*			Vertex< V, E > * GetDest(  )
*				Returns the destination of the arc
*
*			int GetWeight(  )
*				Returns the weight of the arc
*
***********************************************************************/
#ifndef ARC_H
#define ARC_H

template< typename V, typename E > class Vertex;

template< typename V, typename E >
class Arc
{
	friend class Vertex< V, E >;

	public:

	// Manager functions

		// No argument constructor
		Arc(  );

		// Copy constructor
		Arc( const Arc< V, E > & copy );

		// Assignment operator
		Arc< V, E > & operator=( const Arc< V, E > & rhs );

		// Destructor
		~Arc(  );

	// Operator overloads

		// Comparison operator
		bool operator==( Arc< V, E > rhs );

	// Mutator functions

		// Change data
		void SetData( E data );

		// Change destination
		void SetDest( Vertex< V, E > * dest );

		// Change weight
		void SetWeight( int weight );

	// Accessor functions

		// Return data
		E GetData(  );

		// Return destination
		Vertex< V, E > * GetDest(  );

		// Return weight
		int GetWeight(  );

	private:
		E mData;								// The data of the arc
		Vertex< V, E > * mDestination;			// The destination vertex of the arc
		int mWeight;							// The weight, or length, of the arc

	protected:

};

//
// Manager functions
//

	/**********************************************************************
	*	Arc< V, E >::Arc(  )
	*
	*	   Purpose:	Constructs an empty arc.  The data members of this arc
	*				can be set using the mutator functions.
	*
	*		 Entry:	No arc exists.
	*
	*		  Exit: An empty arc can now be used.
	*
	**********************************************************************/
	template< typename V, typename E >
	Arc< V, E >::Arc(  ) :
						mData(  ), mDestination( nullptr ), mWeight( 0 )
	{  }

	/**********************************************************************
	*	Arc< V, E >::Arc( const Arc< V, E > & copy )
	*
	*	   Purpose: Creates an arc that is a copy of an existing arc.
	*
	*		 Entry:	The new arc is not yet created, and 'copy' is an arc.
	*
	*		  Exit:	The new arc is created, and it has the same data as
	*				'copy'.
	*
	**********************************************************************/
	template< typename V, typename E >
	Arc< V, E >::Arc( const Arc< V, E > & copy ) :
						mData( copy.mData ), mDestination( copy.mDestination ),
						mWeight( copy.mWeight )
	{  }

	/**********************************************************************
	*	Arc< V, E > & Arc< V, E >::operator=( const Arc< V, E > & rhs )
	*
	*	   Purpose:	Assigns an existing arc the values of a second existing
	*				arc.
	*
	*		 Entry:	Both arcs are objects, and may have data.
	*
	*		  Exit:	The calling arc is now a copy of the 'rhs' arc.
	*
	**********************************************************************/
	template< typename V, typename E >
	Arc< V, E > & Arc< V, E >::operator=( const Arc< V, E > & rhs )
	{
		if( this != &rhs )
		{
			mData = rhs.mData;
			mDestination = rhs.mDestination;
			mWeight = rhs.mWeight;
		}
		return *this;
	}

	/**********************************************************************
	*	Arc< V, E >::~Arc(  )
	*
	*	   Purpose:	Destroys an arc object, removing all data in it, and
	*				removing the arc object.
	*
	*		 Entry:	The calling arc is going out of scope, taking its data
	*				with it.
	*
	*		  Exit:	The calling arc is now gone.
	*
	**********************************************************************/
	template< typename V, typename E >
	Arc< V, E >::~Arc(  )
	{  }

//
// Operator overloads
//

	/**********************************************************************
	*	bool Arc< V, E >::operator==( Arc< V, E > rhs )
	*
	*	   Purpose: Compares two arcs for equality.
	*
	*		 Entry:	Both arcs have data.
	*
	*		  Exit: Returns true if two arcs are equal, to be considered 
	*				equal, the data and the destination of the arc must 
	*				be the same.
	*
	**********************************************************************/
	template< typename V, typename E >
	bool Arc< V, E >::operator==( Arc< V, E > rhs )
	{
		return( mData == rhs.mData && mDestination == rhs.mDestination );
	}

//
// Mutator functions
//

	/**********************************************************************
	*	void Arc< V, E >::SetData( E data )
	*
	*	   Purpose:	Sets the data in the arc.
	*
	*		 Entry:	The arc's data is irrelevant because it will be 
	*				overwritten.
	*
	*		  Exit:	The arc's data is now the value passed in.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Arc< V, E >::SetData( E data )
	{
		mData = data;
	}

	/**********************************************************************
	*	void Arc< V, E >::SetDest( Vertex< V, E > * dest )
	*
	*	   Purpose:	Sets the destination of the arc.
	*
	*		 Entry:	The arc's current destination is irrelevant because 
	*				it will be overwritten.
	*
	*		  Exit:	The arc's destination is now the value passed in.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Arc< V, E >::SetDest( Vertex< V, E > * dest )
	{
		mDestination = dest;
	}

	/**********************************************************************
	*	void Arc< V, E >::SetWeight( int weight )
	*
	*	   Purpose:	Sets the weight of the arc.
	*
	*		 Entry:	The arc's weight is irrelevant because it will be 
	*				overwritten.
	*
	*		  Exit:	The arc's weight is now the value passed in.
	*
	**********************************************************************/
	template< typename V, typename E >
	void Arc< V, E >::SetWeight( int weight )
	{
		mWeight = weight;
	}

//
// Accessor functions
//

	/**********************************************************************
	*	E Arc< V, E >::GetData(  )
	*
	*	   Purpose: Returns the data stored in an arc.
	*
	*		 Entry: The arc may have some data.
	*
	*		  Exit:	The arc's data is returned.
	*
	**********************************************************************/
	template< typename V, typename E >
	E Arc< V, E >::GetData(  )
	{
		return mData;
	}

	/**********************************************************************
	*	E Arc< V, E >::GetDest(  )
	*
	*	   Purpose: Returns the destination of an arc.
	*
	*		 Entry: The arc may have some destination.
	*
	*		  Exit:	The arc's destination is returned.
	*
	**********************************************************************/
	template< typename V, typename E >
	Vertex< V, E > * Arc< V, E >::GetDest(  )
	{
		return mDestination;
	}

	/**********************************************************************
	*	E Arc< V, E >::GetWeight(  )
	*
	*	   Purpose: Returns the weight stored in an arc.
	*
	*		 Entry: The arc may have some weight.
	*
	*		  Exit:	The arc's weight is returned.
	*
	**********************************************************************/
	template< typename V, typename E >
	int Arc< V, E >::GetWeight(  )
	{
		return mWeight;
	}

#endif