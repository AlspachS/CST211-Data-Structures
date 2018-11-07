/***********************************************************************
* Class: Random.h
*
* Constructors:	No argument constructor that provides a seed for later
*				calls to the Rand() function.
*
* Mutators: 	No Setters necessary for this class as it is 
*				implemented	here.
*
* Methods: 		GetRandom( int n ) const;
*					Calls the Rand() function to generate and return a 
*					random number.  Receives a number that it uses to
*					set the maximum	random number returned.  
*
***********************************************************************/
#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
	using std::srand;
	using std::rand;

#include <ctime>
	using std::time;

class Random
{
	public:  

	// Manager Functions

		// Constructor
		Random(  )
		{
			srand(static_cast<unsigned> (time(NULL)));
		}

	// Member Functions

		unsigned GetRandom(  ) const 
		{ 
			return rand(  ); 
		}
};
#endif