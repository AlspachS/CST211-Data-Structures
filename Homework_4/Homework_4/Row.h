
#ifndef ROW_H
#define ROW_H

template< typename T > class Array2D;

template< typename T >
class Row
{
	// friend Array2D< T >;

	public:
		Row( Array2D< T > &array, int row );
		const T & operator[]( int col ) const;
		T & operator[]( int col );

	private:
		Array2D< T > & m_array2D;
		int m_row;
};
#endif

	template< typename T >
	Row< T >::Row( Array2D< T > &array, int row ) : 
					m_array2D( array ), m_row( row )
	{  }

	template< typename T >
	const T & Row< T >::operator[]( int col ) const
	{
		return m_array2D.Select( m_row, col );
	}

		template< typename T >
	T & Row< T >::operator[]( int col )
	{
		return m_array2D.Select( m_row, col );
	}