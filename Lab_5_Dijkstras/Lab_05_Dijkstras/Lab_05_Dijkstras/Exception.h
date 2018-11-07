/***********************************************************************
*    Class: Exception
* Filename: Exception.h
*
*		Used to throw exceptions to the user to warn of possible errors
*		in their use of classes.
*
* Constructors:
*			Exception(  );
*				Used when an empty exception is thrown.  This is not
*				very useful.
*
*			Exception( char * message );
*				Used when an exception is given a message to return to 
*				the user.
*
*	  Mutators:
*			void SetMessage( char * message );
*				Could be used to change the message in the Exception
*				object being thrown.
*
*	   Methods:
*			char * GetMessage(  ) const;
*				Returns the message stored in the Exception object.
*
***********************************************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
	using std::ostream;

class Exception
{
	// Friends
	friend ostream & operator<<( ostream & stream, const Exception & except );

	public:

	// Manager functions

		// No argument constructor
		Exception(  );

		// One argument constructor
		Exception( char * message );

		// Copy constructor
		Exception( const Exception & copy );

		// Assignment operator
		Exception & operator=( const Exception & rhs );

		// Destructor
		~Exception(  );

	// Accessor methods
		
		// Retrieves the message of the class
		char * GetMessage(  ) const;

	// Mutator methods
		
		// Sets message of the class
		void SetMessage( char * message );
		
	private:
		char * m_message;		// Message to display for exception

};
#endif