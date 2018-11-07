/**********************************************************************
*	namespace ColorStuff
*
*	   Purpose:	Used to store the hex values of the available 
*				predefined colors.  A few functions have been added!
*				
*			
*	inline void SizeConsoleAbsolute( int x, int y )
*		Changes the size of the console window to be a square with 
*		sides of x and y.
*
*	inline void ChangeText( int foreground = LGray, int background = BlackBack )
*		Changes the colors of the console window to be the colors passed
*		in.  If no values are received, it sets the values to default
*		console values.
*
*	inline void ClearWindow( int background )
*		Overwrites everything in the console window with spaces that 
*		have a background color of 'background'.
*
*	inline void CursorToPosition( int x = 0, int y = 0 )
*		Sets the cursor postion to the x and y value given.  This is 
*		where any text that will be outputted will start displaying.
*
**********************************************************************/
#ifndef WINDOWSMANIP_H
#define WINDOWSMANIP_H

#include <Windows.h>
	
namespace WindowsManip
{
	const int Black = 0x00;
	const int Blue = 0x01;
	const int Green = 0x02;
	const int Aqua = 0x03;
	const int Brick = 0x04;
	const int Purple = 0x05;
	const int Gold = 0x06;
	const int LGray = 0x07;
	const int DGray = 0x08;
	const int LBlue = 0x09;
	const int LGreen = 0x0A;
	const int LAqua = 0x0B;
	const int LRed = 0x0C;
	const int LPurple = 0x0D;
	const int Yellow = 0x0E;
	const int White = 0x0F;

	const int BlackBack = 0x00;
	const int BlueBack = 0x10;
	const int GreenBack = 0x20;
	const int AquaBack = 0x30;
	const int BrickBack = 0x40;
	const int PurpleBack = 0x50;
	const int GoldBack = 0x60;
	const int LGrayBack = 0x70;
	const int DGrayBack = 0x80;
	const int LBlueBack = 0x90;
	const int LGreenBack = 0xA0;
	const int LAquaBack = 0xB0;
	const int LRedBack = 0xC0;
	const int LPurpleBack = 0xD0;
	const int YellowBack = 0xE0;
	const int WhiteBack = 0xF0;
	

	inline void SizeConsoleAbsolute( int x, int y )
	{
		HANDLE wHand = GetStdHandle( STD_OUTPUT_HANDLE );
		SMALL_RECT newSize = { 0, 0, x, y };
		COORD buffer = { x + 1, y + 1 };

		SetConsoleWindowInfo( wHand, TRUE, &newSize );
		SetConsoleScreenBufferSize( wHand, buffer );
	}

	inline void ChangeText( int foreground = LGray, int background = BlackBack )
	{
		HANDLE wHand = GetStdHandle( STD_OUTPUT_HANDLE );
		SetConsoleTextAttribute( wHand, foreground | background );	
	}

	inline void ClearWindow( int background )
	{
		HANDLE wHand = GetStdHandle( STD_OUTPUT_HANDLE );
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo( wHand, &csbi );

		COORD position = { 0, 0 };
		short x = csbi.dwSize.X;
		short y = csbi.dwSize.Y;
		SMALL_RECT writeArea = { 0, 0, x - 1, y - 1 };
		CHAR_INFO * consoleBuffer = new CHAR_INFO[ x * y ];

		for( int i( 0 ); i < x * y; ++i )
		{
			consoleBuffer[ i ].Char.AsciiChar = ' ';
			consoleBuffer[ i ].Attributes = background;
		}
		WriteConsoleOutputA( wHand, consoleBuffer, csbi.dwSize, position, &writeArea );

		delete [  ] consoleBuffer;
	}

	inline void CursorToPosition( int x = 0, int y = 0 )
	{
		HANDLE wHand = GetStdHandle( STD_OUTPUT_HANDLE );
		COORD position = { x, y };

		SetConsoleCursorPosition( wHand, position );
	}

}
#endif