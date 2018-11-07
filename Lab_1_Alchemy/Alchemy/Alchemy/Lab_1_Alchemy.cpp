/**********************************************************************
* Author:						Steven Alspach
* Date Created:					04-07-2015
* Last Modification Date:		04-13-2015
* Lab Number:					Lab 1, Alchemy
* File Name:					Lab_1_Alchemy.cpp
*	
*	  Overview:	This is a text-based version of the Pop-Cap game 
*				"Alchemy".
*	
*		 Input:	A symbol is generated, the user decides to keep or 
*				discard this symbol.  If they keep it, they decide
*				where to place it on the board.  If they discard
*				a symbol four times in a row, the game ends.
*	
*		Output: The out put looks as follows:
*
*					 123456789
*					1█████████1
*					2█████████2
*					3█████████3
*					4████ ████4
*					5█████████5
*					6█████████6
*					7█████████7
*					8█████████8
*					 123456789
*
*					The current score is:  0
*					The cauldron is curretly at:  0
*
*					The symbol this round is:  $
*					Would you like to keep this piece?
*					(1/Keep) (2/Discard)
*		
**********************************************************************/
#include "Alchemy.h"

int main()
{
	
	Alchemy game;

	game.GameDriver(  );

	return 0;
}



//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//
//#include <time.h>
//
//#include <iomanip>
//	using std::setw;
//	using std::setfill;
//
//#include <iostream>
//	using std::cout;
//	using std::endl;
//
//#include <fstream>
//	using std::ofstream;
//	using std::ios;
//
//#include <vector>
//	using std::vector;
//
//#include "Random.h"
//#include "Array.h"
//
//
//template< typename T >
//void Swap( T & elemone, T & elemtwo );
//
//template< typename T >
//void Display( T display, int n );
//
//void TimingAndOutput( char sortName[], clock_t first, clock_t second );
//
//// Required Sorts
//
//template< typename T >
//void BruteBubbleSort( T unsorted, int n );
//
//template< typename T >
//void FlaggedBubbleSort( T unsorted, int n );
//
//template< typename T >
//void InsertionSort( T unsorted, int n );
//
//template< typename T >
//void SelectionSort( T unsorted, int n );
//
//template< typename T >
//void ShellSort( T unsorted, int n );
//
//template< typename T >
//void QuickSort( T unsorted, int n );
//
//template< typename T >
//void QuickSort( T & split_unsorted, int first, int last );
//
//template< typename T >
//void MergeSort( T unsorted, int n );
//
//template< typename T >
//void MergeSort( T & unsorted, int first, int last );
//
//template< typename T >
//void Merge( T & unsorted, int first, int middle, int last );
//
//template< typename T >
//void HeapSort( T & unsorted, int n );
//
//template< typename T >
//void MoveDown( T & unsorted, int first, int last );
//
//// Optional Sorts
//
////ShakerSort
////TreeSort
////BinaryInsertionSort
////RadixSort
//
////const int NUM_OF_ELEMENTS = 400;
//const char OUTPUT_FILE[  ] = "SortTimes.txt";
//
//
//int main( int argc, char* argv[  ] )
//{
//	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
//
//	int n( 0 );
//	int exit( 0 );
//	ofstream output;
//
//
//	if( argc > 1 )
//	{
//		n = atoi( argv[ 1 ] );
//
//		Random rand;
//
//		int * unsorted_native_seed = new int[ n ];
//		int * unsorted_native = new int[ n ];
//		Array< int > unsorted_written( n );
//		vector< int > unsorted_vector( n );
//
//		for( int i( 0 ), temp( 0 ); i < n; ++i )
//		{
//			temp = rand.GetRandom(  );
//			unsorted_native_seed[ i ] = temp;
//			unsorted_written[ i ] = temp;
//			unsorted_vector[ i ] = temp;
//		}
//
//		output.open( OUTPUT_FILE );
//		if( output.is_open(  ) )
//		{
//			output << "This is a report of times taken for different sorts on "
//				   << n << " element arrays.\n" << endl;
//
//			output << "The first time is for the native C++ array.\n";
//			output << "The second time is for the student-written array class.\n";
//			output << "The third time is for the STL Vector class.\n";
//			output << endl;
//
//			output.close(  );
//		}
//		else
//			cout << "Unable to open file.\n";
//
//		Display( unsorted_native_seed, n );
//
//		for( int i( 0 ); i < n; ++i )
//		{
//			unsorted_native[ i ] = unsorted_native_seed[ i ];
//		}
//		
//		Display( unsorted_native, n );
//
//		BruteBubbleSort( unsorted_native, n );
//		BruteBubbleSort( unsorted_written, n );
//		BruteBubbleSort( unsorted_vector, n );
//
//		Display( unsorted_native_seed, n );
//		Display( unsorted_native, n );
//
//		delete[  ] unsorted_native;
//		unsorted_native = new int [ n ];
//		for( int i( 0 ); i < n; ++i )
//		{
//			unsorted_native[ i ] = unsorted_native_seed[ i ];
//		}
//		
//		Display( unsorted_native_seed, n );
//		Display( unsorted_native, n );
//
//		FlaggedBubbleSort( unsorted_native, n );
//		FlaggedBubbleSort( unsorted_written, n );
//		FlaggedBubbleSort( unsorted_vector, n );
//
//		delete[  ] unsorted_native;
//		unsorted_native = new int [ n ];
//		for( int i( 0 ); i < n; ++i )
//		{
//			unsorted_native[ i ] = unsorted_native_seed[ i ];
//		}
//
//		InsertionSort( unsorted_native, n );
//		InsertionSort( unsorted_written, n );
//		InsertionSort( unsorted_vector, n );
//
//		delete[  ] unsorted_native;
//		unsorted_native = new int [ n ];
//		for( int i( 0 ); i < n; ++i )
//		{
//			unsorted_native[ i ] = unsorted_native_seed[ i ];
//		}
//
//		SelectionSort( unsorted_native, n );
//		SelectionSort( unsorted_written, n );
//		SelectionSort( unsorted_vector, n );
//
//		delete[  ] unsorted_native;
//		unsorted_native = new int [ n ];
//		for( int i( 0 ); i < n; ++i )
//		{
//			unsorted_native[ i ] = unsorted_native_seed[ i ];
//		}
//
//		ShellSort( unsorted_native, n );
//		ShellSort( unsorted_written, n );
//		ShellSort( unsorted_vector, n );
//
//		delete[  ] unsorted_native;
//		unsorted_native = new int [ n ];
//		for( int i( 0 ); i < n; ++i )
//		{
//			unsorted_native[ i ] = unsorted_native_seed[ i ];
//		}
//
//		QuickSort( unsorted_native, n );
//		QuickSort( unsorted_written, n );
//		QuickSort( unsorted_vector, n );
//
//		delete[  ] unsorted_native;
//		unsorted_native = new int [ n ];
//		for( int i( 0 ); i < n; ++i )
//		{
//			unsorted_native[ i ] = unsorted_native_seed[ i ];
//		}
//
//		HeapSort( unsorted_native, n );
//		HeapSort( unsorted_written, n );
//		HeapSort( unsorted_vector, n );
//
//		delete[  ] unsorted_native;
//		unsorted_native = new int [ n ];
//		for( int i( 0 ); i < n; ++i )
//		{
//			unsorted_native[ i ] = unsorted_native_seed[ i ];
//		}
//
//		MergeSort( unsorted_native, n );
//		MergeSort( unsorted_written, n );
//		MergeSort( unsorted_vector, n );
//
//		delete [] unsorted_native;
//	}
//	else
//	{
//		cout << "Usage:  Sorts [# of elements to sort]\n";
//		exit = 1;
//	}
//	return exit;
//}
//
///**********************************************************************
//*	void Swap( T & elemone, T & elemtwo )
//*
//*	   Purpose:	Exchanges the location of two elements in an array.
//*
//*		 Entry: The 'elemone' has some value 'x' and 'elemtwo' has some
//*				value 'y'.
//*
//*		  Exit:	The values of 'elemone' and 'elemtwo' are exchanged. 
//*				So 'elemone' now contains 'y' and 'elemtwo' now
//*				contains 'x'.
//*
//**********************************************************************/
//template< typename T >
//void Swap( T & elemone, T & elemtwo )
//{
//	T temp = elemone;
//	elemone = elemtwo;
//	elemtwo = temp;
//}
//
///**********************************************************************
//*	void Display( T display, int n )
//*
//*	   Purpose: Displays the elements of an array.  This was done for
//*				verification that the array was unsorted before the 
//*				sort, and was correctly sorted after the sort.
//*
//*		 Entry: 'display' will be some array.  The values and order are
//*				inconsequential.
//*
//*		  Exit:	The values of 'display' are unchanged, but displayed
//*				on the console window.
//*
//**********************************************************************/
//template< typename T >
//void Display( T display, int n )
//{
//	for( int i( 0 ); i < n; ++i )
//	{
//		cout << display[ i ] << "  ";
//		if( i % 10 == 9 )
//			cout << endl;
//	}
//	cout << "\n" << endl;
//}
//
///**********************************************************************
//*	void TimingAndOutput( char sortName[], clock_t first, clock_t second )
//*
//*	   Purpose:	Writes the elapsed time to an output file and to the
//*				console window after a sort has finished.  The elapsed
//				must be calculated first.
//*
//*		 Entry: 'start' and 'end' are the starting and finishing 
//*				times of a sort.
//*
//*		  Exit:	The elapsed time has been written to the file and to
//*				the console window.  No values, except the file, have
//*				changed.
//*
//**********************************************************************/
//void TimingAndOutput( char sortName[], clock_t start, clock_t end )
//{
//	ofstream output;
//
//	clock_t elapsed( end - start );
//
//	int hours( elapsed / 3600000 );
//	elapsed %= 3600000;
//	int minutes( elapsed / 60000 );
//	elapsed %= 60000;
//	int seconds( elapsed / 1000 );
//	elapsed %= 1000;
//
//	output.open( OUTPUT_FILE, ios::app );
//	if( output.is_open(  ) )
//	{ 
//		cout << sortName << " took " << setw( 3 ) << setfill( '0' ) << hours << ":" 
//			 << setw( 2 ) << minutes << ":" << setw( 2 ) << seconds << "." << setw( 3 ) 
//			 << elapsed << endl;
//
//		output << sortName << " took " << setw( 3 ) << setfill( '0' ) << hours << ":" 
//			 << setw( 2 ) << minutes << ":" << setw( 2 ) << seconds << "." << setw( 3 ) 
//			 << elapsed << endl;
//
//		output.close(  );
//	}
//	else
//		cout << "Unable to open file.\n";
//}
//
///**********************************************************************
//*	void BruteBubbleSort( T unsorted, int n )
//*
//*	   Purpose:	Sorts 'unsorted' by comparing each element to the one
//*				after it, if the first element is greater than the 
//*				second element, the two elements are swapped.  This
//*				continues until all elements are in their correct
//*				locations.
//*
//*		 Entry: 'unsorted' is an array of values in random order.
//*
//*		  Exit:	'unsorted' is now in correct ascending order.
//*
//**********************************************************************/
//template< typename T >
//void BruteBubbleSort( T unsorted, int n )
//{
//	clock_t start;
//	clock_t end;
//	start = clock(  );
//	
//	for( int i( 0 ), temp( 0 ); i < n; ++i )
//	{
//		for( int j( 0 ); j < n - 1; ++j )
//		{
//			if( unsorted[ j ] >= unsorted[ j + 1 ] )
//			{
//				//temp = unsorted[ j ];
//				//unsorted[ j ] = unsorted[ j + 1 ];
//				//unsorted[ j + 1 ] = temp;
//
//				Swap( unsorted[ j ], unsorted[ j + 1 ] );
//			}
//		}
//	}
//
//	end = clock(  );
//	
//	TimingAndOutput( "BruteBubbleSort", start, end );
//}
//
///**********************************************************************
//*	void FlaggedBubbleSort( T unsorted, int n )
//*
//*	   Purpose: Sorts 'unsorted' similarly to BruteBubbleSort, by
//*				comparing one element to the next element, and swapping
//*				them if the first element is greater than the second.
//*				However, a flagged is used to track whether a swap
//*				occurred.  If the flag isn't set, no swap occurred,
//*				and the sort ends.
//*
//*		 Entry:	'unsorted' is an array of values in random order.
//*
//*		  Exit:	The values of 'unsorted' are now in correct 
//*				ascending order.
//*
//**********************************************************************/
//template< typename T >
//void FlaggedBubbleSort( T unsorted, int n )
//{
//	clock_t start;
//	clock_t end;
//	start = clock(  );
//
//	bool sorted( false );
//	for( int i( 0 ); i < n - 1 && !sorted; ++i )
//	{
//		sorted = true;
//		//for( int j( n - i - 1 ); j > i; --j )
//		for( int j( 0 ); j < n - i - 1; ++j )
//		{
//			if( unsorted[ j ] >= unsorted[ j + 1 ] )
//			//if( unsorted[ j ] <= unsorted[ j - 1 ] )
//			{
//				//temp = unsorted[ j ];
//				//unsorted[ j ] = unsorted[ j - 1 ];
//				//unsorted[ j - 1 ] = temp;
//
//				Swap( unsorted[ j ], unsorted[ j + 1 ] );
//				//Swap( unsorted[ j ], unsorted[ j - 1 ] );
//
//				sorted = false;
//			}
//		}
//	}
//
//	end = clock(  );
//	
//	TimingAndOutput( "FlaggedBubbleSort", start, end );
//}
//
///**********************************************************************
//*	void InsertionSort( T unsorted, int n )
//*
//*	   Purpose: Sorts 'unsorted' by first storing a value in a temp
//*				variable to make a hole in the array, then compares
//*				that value to all preceding values, and those values
//*				are moved up until the correct location is found, then
//*				the value is stored in its correct location.
//*
//*		 Entry:	'unsorted' is an array of values in random order.
//*
//*		  Exit: The values in 'unsorted' are now in correct ascending
//*				order.
//*
//**********************************************************************/
//template< typename T >
//void InsertionSort( T unsorted, int n )
//{
//	clock_t start;
//	clock_t end;
//	start = clock(  );
//
//	for( int i( 1 ), j( 0 ), temp( 0 ); i < n; ++i )
//	{
//		temp = unsorted[ i ];
//
//		for( j = i; j > 0 && temp < unsorted[ j - 1 ]; --j )
//		{
//			unsorted[ j ] = unsorted[ j - 1 ];
//		}
//
//		unsorted[ j ] = temp;
//	}
//
//	end = clock(  );
//	
//	TimingAndOutput( "InsertionSort", start, end );
//}
//
///**********************************************************************
//*	void SelectionSort( T unsorted, int n )
//*
//*	   Purpose: Sorts 'unsorted' by storing the index value of the 
//*				smallest value in a variable, then continues to compare
//*				this smallest value to other values.  If a smaller
//*				value is found, its index value is stored in the
//*				variable representing the smallest element of the array.
//*				When no other smaller value is found, a swap occurs with
//*				the smallest element and the first element of the
//*				unsorted section of the array.
//*
//*		 Entry:	'unsorted' is an array of values in random order.
//*
//*		  Exit: The values in 'unsorted' are now in correct ascending
//*				order.
//*
//**********************************************************************/
//template< typename T >
//void SelectionSort( T unsorted, int n )
//{
//	clock_t start;
//	clock_t end;
//	start = clock(  );
//	
//	for( int i( 0 ), j( 0 ), least( 0 ), temp( 0 ); i < n - 1; ++i )
//	{
//		for( j = ( i + 1 ), least = i; j < n; ++j )
//		{
//			if( unsorted[ j ] <= unsorted[ least ] )
//			{
//				least = j;
//			}
//		}
//		temp = unsorted[ i ];
//		unsorted[ i ] = unsorted[ least ];
//		unsorted[ least ] = temp;
//	
//		//Swap( unsorted[ i ], unsorted[ least ];
//	}
//
//	end = clock(  );
//	
//	TimingAndOutput( "SelectionSort", start, end );
//}
//
///**********************************************************************
//*	void ShellSort( T unsorted, int n )
//*
//*	   Purpose: Sorts 'unsorted' by first setting up a gap.  This gap
//*				shrinks for each pass made.  The two elements at the 
//*				ends of the gap are compared, and swapped if needed.
//*				If a swap is make, the gap is backed up to the two
//*				previous values compared to check if those two values
//*				are in the correct order.  After a pass, the gap is
//*				shrunk and another pass is made.  The last increment
//*				is a gap of one.
//*
//*		 Entry:	'unsorted' is an array of values in random order.
//*
//*		  Exit: The values in 'unsorted' are now in correct ascending
//*				order.
//*
//**********************************************************************/
//template< typename T >
//void ShellSort( T unsorted, int n )
//{
//	clock_t start;
//	clock_t end;
//	start = clock(  );
//
//	int gap_count(0);
//	int group(0);
//	int gap( 0 );
//	int gap_widths[ 20 ];
//		
//	for( gap = 1, gap_count = 0; gap < n; ++gap_count )
//	{
//		gap_widths[ gap_count ] = gap;
//		gap = 3 * gap + 1;
//	}
//
//	for( gap_count--; gap_count >= 0; gap_count-- )
//	{
//		gap = gap_widths[ gap_count ];
//		for( group = gap; group < 2 * gap; group++ )
//		{
//			for( int j( group ), k( 0 ); j < n; )
//			{
//				int temp = unsorted[ j ];
//				k = j;
//				while( k - gap >= 0 && temp < unsorted[ k-gap ] )
//				{
//					unsorted[ k ] = unsorted[ k - gap ];
//					k -= gap;
//				}
//				unsorted[ k ] = temp;
//				j += gap;
//			}
//		}
//	}
//	end = clock(  );
//	
//	TimingAndOutput( "ShellSort", start, end );
//}
//
///**********************************************************************
//*	void QuickSort( T unsorted, int n )
//*
//*	   Purpose: Sorts 'unsorted' by first finding the largest value
//*				in the array and moving it to the end of the array.
//*				This prevents the largest value from becoming the pivot,
//*				the value against which all other values are compared
//*				against to "split" the array into larger values and 
//*				smaller values.  Second, it calls the meat of the 
//*				QuickSort function.
//*
//*		 Entry:	'unsorted' is an array of values in random order.
//*
//*		  Exit: The values in 'unsorted' are now in correct ascending
//*				order.
//*
//**********************************************************************/
//template< typename T >
//void QuickSort( T unsorted, int n )
//{
//	clock_t start;
//	clock_t end;
//	start = clock(  );
//
//	int max( 0 );
//
//	if( n >= 2 )
//	{
//		for( int i = 1; i < n; ++i )
//		{
//			if( unsorted[ max ] < unsorted[ i ] )
//				max = i;
//		}
//		Swap( unsorted[ n - 1 ], unsorted[ max ] );
//		QuickSort( unsorted, 0, n - 2 );
//	}
//	end = clock(  );
//	
//	TimingAndOutput( "QuickSort", start, end );
//}
//
///**********************************************************************
//*	void QuickSort( T & split_unsorted, int first, int last )
//*
//*	   Purpose: First, a pivot value is determined.  All elements of
//*				the array are compared.  If a value in the "left" side
//*				of the array is greater than the pivot, that value is 
//*				kept until a value less than the pivot is found in the
//*				"right" side of the array.  These values are then
//*				swapped.  Once all values are put on the correct side
//*				of the pivot, the pivot is put in the space between the
//*				two sections.  This process is repeated recursively
//*				until all elements are in the correct location.
//*
//*		 Entry:	'split_unsorted' is an array of values in random order.
//*
//*		  Exit: The values in 'split_unsorted' are now in correct 
//*				ascending order.
//*
//**********************************************************************/
//template< typename T >
//void QuickSort( T & split_unsorted, int first, int last )
//{
//	int lower = first + 1;
//	int upper = last;
//	Swap( split_unsorted[ first ], split_unsorted[ ( first + last )/ 2 ] );
//	int bound = split_unsorted[ first ];
//	while( lower <= upper )
//	{
//		while( bound > split_unsorted[ lower ] )
//			lower++;
//		while( bound < split_unsorted[ upper ] )
//			upper--;
//		if( lower < upper )
//			Swap( split_unsorted[ lower++ ], split_unsorted[ upper-- ] );
//		else 
//			lower++;
//	}
//	Swap( split_unsorted[ upper ], split_unsorted[ first ] );
//	if( first < upper - 1 )
//		QuickSort( split_unsorted, first, upper - 1 );
//	if( upper + 1 < last )
//		QuickSort( split_unsorted, upper + 1, last );
//}
//
///**********************************************************************
//*	void MergeSort( T unsorted, int n )
//*
//*	   Purpose: Initial MergeSort function.  File I/O and Sort timing
//*				happen here.
//*
//*		 Entry:	'unsorted' is an array of values in random order.
//*
//*		  Exit: The values in 'unsorted' are now in correct ascending
//*				order.
//*
//**********************************************************************/
//template< typename T >
//void MergeSort( T unsorted, int n )
//{
//	clock_t start;
//	clock_t end;
//	start = clock(  );
//
//	MergeSort( unsorted, 0, n - 1 );
//
//	end = clock(  );
//	
//	TimingAndOutput( "MergeSort", start, end );
//}
//
///**********************************************************************
//*	void MergeSort( T & split_unsorted, int first, int last )
//*
//*	   Purpose: Breaks 'unsorted', which has been renamed 
//*				'split_unsorted', into one or two element sub-arrays.
//*
//*		 Entry:	'split_unsorted' is an array of values in random order.
//*
//*		  Exit: The values in 'split_unsorted' are now in correct 
//*				ascending order.
//*
//**********************************************************************/
//template< typename T >
//void MergeSort( T & split_unsorted, int first, int last )
//{
//	int middle( 0 );
//
//	if( first < last )
//	{
//		middle = ( first + last )/ 2;
//
//		MergeSort( split_unsorted, first, middle );
//		MergeSort( split_unsorted, middle + 1, last );
//		Merge( split_unsorted, first, middle, last );
//	}
//}
//
///**********************************************************************
//*	void Merge( T & split_unsorted, int low, int mid, int high )
//*
//*	   Purpose: Takes the smaller sub-arrays that were divided out by
//*				the recursive MergeSort call, puts those smaller 
//*				sub-arrays in correct order in a temporary array, 
//*				then copies those elements back into 'split_unsorted'. 
//*
//*		 Entry:	'split-unsorted' is an array of values in random order.
//*				'low' is the first element of the left sub-array, 'mid'
//*				is end of the left sub-array, and 'high' is the end of
//*				right sub-array.
//*
//*		  Exit: The values in 'split-unsorted' are now in correct 
//*				ascending order. 'low' 'mid' and 'high' are unchanged.
//*
//**********************************************************************/
//template< typename T >
//void Merge( T & split_unsorted, int low, int mid, int high )
//{
//	int leftstart( low );
//	int leftend( mid );
//	int rightstart( mid + 1 );
//	int rightend( high );
//
//	int temp_pos( 0 );
//
//	int * temp = new int[ high + 1 - low ];
//
//
//	while( leftstart <= leftend && rightstart <= rightend )
//	{
//		if( split_unsorted[ leftstart ] <= split_unsorted[ rightstart ] )
//		{
//			temp[ temp_pos ] = split_unsorted[ leftstart ];
//			++leftstart;
//		}
//		else
//		{
//			temp[ temp_pos ] = split_unsorted[ rightstart ];
//			++rightstart;
//		}
//		++temp_pos;
//	}
//
//	while( leftstart <= leftend )
//	{
//		temp[ temp_pos ] = split_unsorted[ leftstart ];
//		++temp_pos;
//		++leftstart;
//	}
//	while( rightstart <= rightend )
//	{
//		temp[ temp_pos ] = split_unsorted[ rightstart ];
//		++temp_pos;
//		++rightstart;
//	}
//
//	for( int i( 0 ); i <= high - low; ++i )
//	{
//		split_unsorted[ i + low ] = temp[ i ];
//	}
//
//	delete [  ] temp;
//}
//
///**********************************************************************
//*	void HeapSort( T & unsorted, int n )
//*
//*	   Purpose: Sorts 'unsorted' by first forming a virtual heap, (A 
//*				binary tree where each root element is less than the 
//*				elements above it) then swaps the element at the top
//*				of the tree to the end of the array.  Finally, the 
//*				tree is re-heaped and the process is repeated.
//*
//*		 Entry:	'unsorted' is an array of values in random order.
//*
//*		  Exit: The values in 'unsorted' are now in correct ascending
//*				order.
//*
//**********************************************************************/
//template< typename T >
//void HeapSort( T & unsorted, int n )
//{
//	clock_t start;
//	clock_t end;
//	start = clock(  );
//
//	for( int i( (n / 2) - 1 ); i >= 0; --i )
//	{
//		MoveDown( unsorted, i, n - 1 );
//	}
//
//	for( int i( n - 1 ); i >= 1; --i )
//	{
//		Swap( unsorted[ 0 ], unsorted[ i ] );
//		MoveDown( unsorted, 0, i - 1 );
//	}
//	end = clock(  );
//	
//	TimingAndOutput( "HeapSort", start, end );
//}
//
///**********************************************************************
//*	void MoveDown( T & unsorted, int parent, int last )
//*
//*	   Purpose: Forms a virtual heap of 'unsorted' by first comparing
//*				the the two children of the parent.  If one child is 
//*				larger than the parent, that child is promoted to the
//*				parent.  If that child had children, they are reviewed
//*				and re-heaped as necessary.
//*
//*		 Entry:	'unsorted' is the unsorted array, 'parent' points to
//*				parent node to verify heap status, and 'last' is the
//*				last element of the unsorted section of the array.
//*
//*		  Exit: 'unsorted' is either heaped or re-heaped.
//*
//**********************************************************************/
//template< typename T >
//void MoveDown( T & unsorted, int parent, int last )
//{
//	int first_child = parent * 2 + 1;
//
//	while( first_child <= last )
//	{
//		if( first_child < last && unsorted[ first_child ] < unsorted[ first_child + 1 ] )
//			first_child++;  // becomes second_child
//
//		if( unsorted[ parent ] < unsorted[ first_child ] )				// first_child is second child if the increment was hit
//		{
//			Swap( unsorted[ parent ], unsorted[ first_child ] );		// still second child  
//			parent = first_child;
//			first_child = parent * 2 + 1;								// back to first child of next node 
//		} 
//		else
//			first_child = last + 1;
//	}
//}