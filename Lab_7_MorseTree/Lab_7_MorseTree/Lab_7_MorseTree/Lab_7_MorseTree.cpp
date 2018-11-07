/**********************************************************************
* Author:						Steven Alspach
* Date Created:					06/01/2015
* Last Modification Date:		06/03/2015
* Lab Number:					Lab 07 MorseTree
* File Name:					Lab_7_MorseTree.cpp
*
*	  Overview:	This program reads a file and then encodes or decodes
*				the message found in that file.
*	
*		 Input:	The input is from the file, no user input really needed.
*	
*		Output:	The output of the program is a character message decoded
*				from a string of dots and dashes, as well as a string
*				of dots and dashes the represent a character message.
*				For example:
*
*					THANK YOU FOR A FUN TERM
*					- .... .- -. -.- ---- -.-- --- ..- ---- ..-. 
*					--- .-. ---- .- ---- ..-. ..- -. ---- - . .-. --
*					
*				The two message do not have to be the same, the two
*				files can have different messages.
*		
**********************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
	using std::cout;
	using std::endl;

#include <fstream>
	using std::ifstream;

#include "MorseTree.h"



// Decodes a morse message
void MorseString( MorseTree & decoder );

// Encodes a text message
void TextString( MorseTree & encoder );

int main(  )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	MorseTree ditdah;

	MorseString( ditdah );
	TextString( ditdah );

	return 0;
}

/**********************************************************************
*	void MorseString( MorseTree & decoder )
*
*	   Purpose: Reads a morse message from a file, sends it into the 
*				MorseTree class to decode, and prints out the result.
*
*		 Entry: 'decoder' is a built MorseTree object that has the 
*				characters of the alphabet stored in the nodes.
*
*		  Exit: 'decoder' hasn't changed, but the message read from 
*				the file has been decoded and printed.
*
**********************************************************************/
void MorseString( MorseTree & decoder )
{
	string morse = "";
	string message = "";
	
	ifstream fin;
	fin.open( "Morse Message.txt" );
	while( !fin.eof(  ) )
	{
		getline( fin, morse, ' ' );
		
		message += decoder.Decode( morse );
	}
	fin.close(  );

	cout << message << endl;
}

/**********************************************************************
*	void TextString( MorseTree & encoder )
*
*	   Purpose: Reads a text message from a file and sends it to the 
*				MorseTree class to encode into a morse code message.
*	
*		 Entry: 'encoder' is a built MorseTree object that has the 
*				characters of the alphabet stored in the nodes.
*
*		  Exit: 'encoder' hasn't changed, but the message read from 
*				the file has been encoded and printed.
*
**********************************************************************/
void TextString( MorseTree & encoder )
{
	string morse = "";
	string message = "";

	ifstream fin;
	fin.open( "Text Message.txt" );
	while( !fin.eof(  ) )
	{
		getline( fin, message, ' ' );

		morse += encoder.Encode( message );
	}
	fin.close(  );

	cout << morse << endl;
}