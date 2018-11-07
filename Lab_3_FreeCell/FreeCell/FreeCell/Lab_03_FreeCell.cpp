/**********************************************************************
* Author:						Steven Alspach
* Date Created:					04-27-2015
* Last Modification Date:		05-07-2015
* Lab Number:					Lab 3, FreeCell
* File Name:					FreeCell
*
*	  Overview:	This is a FreeCell game, it's fun to play.
*	
*		 Input: The user gives input formatted as "p1 f1", which moves
*				a card from playcell one to freecell one.  They 
*				continues this until all cards are in the homecell area.
*				When this happens, they win the game.
*	
*		Output: The format is as follows:
*	
*					"Explanation of move entry"
*
*					"Entry of moves"
*					"If playcell to playcell, asks for number of cards"
*
*					1 2 3 4         1 2 3 4
*					█ █ █ █         █ █ █ █
*
*						1 2 3 4 5 6 7 8
*			    		█ █ █ █ █ █ █ █
*
*				The player's goal is to get all cards from the lower 
*				area into the stack at the top-right of the board.
*		
**********************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "FreeCellGame.h"

int main(  )
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	
	FreeCellGame test;
	
	test.GameDriver(  );

	return 0;
}