#include "Exception.h"

//
// Friends
//

	/**********************************************************************
	*	ostream & operator<<( ostream & stream, const Exception & except )
	*
	*	   Purpose:	Used to display the message in the Exception object
	*				being thrown.
	*
	*		 Entry:	When the Exception object needs to display its message.
	*
	*		  Exit: After the message is displayed.
	*
	**********************************************************************/
	ostream & operator<<( ostream & stream, const Exception & except )
	{
		if( except.m_message != nullptr )
			stream << except.m_message;

		return stream;
	}


//
// Manager functions
//

	/**********************************************************************
	*	Exception::Exception(  )
	*
	*	   Purpose: Used to create an empty Exception object.
	*
	*		 Entry:	When a default Exception needs to be thrown.
	*
	*		  Exit:	After the Exception is created.
	*
	**********************************************************************/
	Exception::Exception(  ) : 
							m_message( nullptr )
	{  }


	/**********************************************************************
	*	Exception::Exception( char * message )
	*
	*	   Purpose: Used to return a message to the user, indicating why
	*				an exception was thrown.
	*
	*		 Entry:	When there was an error with another program.
	*
	*		  Exit:	After the Exception was created and thrown.
	*
	**********************************************************************/
	Exception::Exception( char * message ) : 
							m_message( nullptr )
	{ 
		m_message = new char[ strlen( message ) + 1 ];
		strcpy( m_message, message );
	}

	
	/**********************************************************************
	*	Exception::Exception( const Exception & copy )
	*
	*	   Purpose: Used to create an Exception object with an existing 
	*				Exception object.
	*
	*		 Entry:	When the new Exception object is created and the values
	*				from the existing Exception object is copied into it.
	*
	*		  Exit:	After the new object has the values of the existing 
	*				object.
	*
	**********************************************************************/
	Exception::Exception( const Exception & copy ) :
							m_message( nullptr )
	{ 
		*this = copy;
	}


	/**********************************************************************
	*	Exception & Exception::operator=( const Exception & rhs )
	*
	*	   Purpose: Used to assign one Exception object the value of 
	*				a second Exception object.
	*
	*		 Entry:	When the values of one Exception object need to be
	*				overwritten with the values of a second.
	*
	*		  Exit: After the calling Exception (lhs) has the values of
	*				the assigned Exception (rhs).
	*
	**********************************************************************/
	Exception & Exception::operator=( const Exception & rhs )
	{ 
		if( this != &rhs )
		{
			if( strlen( m_message ) != strlen( rhs.m_message ) )
			{
				delete [  ] m_message;
				m_message = new char[ strlen( rhs.m_message ) + 1 ];
			}
			strcpy( m_message, rhs.m_message );
		}
		return * this;
	}


	/**********************************************************************
	*	Exception::~Exception(  )
	*
	*	   Purpose:	Used to delete an Exception that is going out of scope.
	*
	*		 Entry:	When an Exception object has been caught and the
	*				the program is exiting the try/catch block.
	*
	*		  Exit:	After the Exception object is deleted.
	*
	**********************************************************************/
	Exception::~Exception(  )
	{ 
		delete [  ] m_message;	
		m_message = nullptr;
	}


	/**********************************************************************
	*	char * Exception::GetMessage(  ) const
	*
	*	   Purpose:	Used when the message in the Exception needs to be 
	*				known.
	*
	*		 Entry:	Can be used as an alternative way to display or store
	*				the message in the Exception object.
	*
	*		  Exit:	After the message is returned.
	*
	**********************************************************************/
	char * Exception::GetMessage(  ) const
	{ 
		return m_message;
	}


	/**********************************************************************
	*	void Exception::SetMessage( char * message )
	*
	*	   Purpose:	Used to change the message in the Exception object.
	*
	*		 Entry:	Called if the message in the Exception object needs
	*				to be changed.
	*
	*		  Exit:	After the message in the Exception object is changed.
	*
	**********************************************************************/
	void Exception::SetMessage( char * message )
	{ 
		delete [] m_message;
		m_message = new char[ strlen( message ) + 1 ];
		strcpy( m_message, message );
	}	