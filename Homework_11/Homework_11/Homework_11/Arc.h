/***********************************************************************
* 	 Class: Class Name
* Filename:
*
*		Description...
*
* Constructors:
*
*	  Mutators:
*
*	   Methods:
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
		E mData;
		Vertex< V, E > * mDestination;
		int mWeight;

	protected:

};

//
// Manager functions
//

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename V, typename E >
	Arc< V, E >::Arc(  ) :
						mData(  ), mDestination( nullptr ), mWeight( 0 )
	{  }

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename V, typename E >
	Arc< V, E >::Arc( const Arc< V, E > & copy ) :
						mData( copy.mData ), mDestination( copy.mDestination ),
						mWeight( copy.mWeight )
	{  }

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename V, typename E >
	Arc< V, E >::~Arc(  )
	{  }

//
// Operator overloads
//

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename V, typename E >
	void Arc< V, E >::SetData( E data )
	{
		mData = data;
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename V, typename E >
	void Arc< V, E >::SetDest( Vertex< V, E > * dest )
	{
		mDestination = dest;
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename V, typename E >
	E Arc< V, E >::GetData(  )
	{
		return mData;
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename V, typename E >
	Vertex< V, E > * Arc< V, E >::GetDest(  )
	{
		return mDestination;
	}

	/**********************************************************************
	*	
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	template< typename V, typename E >
	int Arc< V, E >::GetWeight(  )
	{
		return mWeight;
	}

#endif