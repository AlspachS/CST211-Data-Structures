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