#ifndef ABSTRACTITERATOR_H
#define ABSTRACTITERATOR_H

template< typename T >
class AbstractIterator
{
	public:
		virtual void MoveNext(  ) = 0;
		virtual void Reset(  ) = 0;
		virtual bool isDone(  ) = 0;
		virtual T GetCurrent(  ) = 0;

	private:

	protected:

};
#endif