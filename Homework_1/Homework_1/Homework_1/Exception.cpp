#include "Exception.h"

//
// Friends
//

	/**********************************************************************
	*	(  )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	Exception::Exception(  ) : 
							m_message( nullptr )
	{  }


	/**********************************************************************
	*	Exception::Exception( char * message )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
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
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	char * Exception::GetMessage(  ) const
	{ 
		return m_message;
	}


	/**********************************************************************
	*	void Exception::SetMessage( char * message )
	*
	*	   Purpose:
	*
	*		 Entry:
	*
	*		  Exit:
	*
	**********************************************************************/
	void Exception::SetMessage( char * message )
	{ 
		delete [] m_message;
		m_message = new char[ strlen( message ) + 1 ];
		strcpy( m_message, message );
	}	