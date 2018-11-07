/***********************************************************************
* 	 Class: Alchemy
* Filename: Alchemy.h
*
*		Text-based Alchemy game.  Not the combining one.
*
* Constructors:
*			Alchemy(  )
*				Constructs a game for the player to play.
*
*	  Mutators:
*			void SetLevel( int level );
*				Changes the level of the game.
*
*			void SetScore( int score );
*				Changes the current game score.
*
*			void SetCauldron( int cauldron );
*				Changes the number of symbols in the cauldron.
*
*	   Methods:
*			int GetLevel(  );
*				Returns the level the player is on.
*
*			int GetScore(  );
*				Returns the current score.
*
*			int GetCauldron(  );
*				Returns the number of symbols in the cauldron.
*
*			void Display(  );
*				Displays the game.
*
*			void GameDriver(  );
*				Handles game logic.
*
*			int GenerateSymbolSituation(  );
*				Determines what type of symbol the player has this turn.
*
*			void UserInput( int & row, int & col );
*				Gets and validates a row and column value from the player.
*
*			bool Discard(  );
*				Sends a symbol to the cauldron.
*
*			void IncrementLevel(  );
*				Checks the board at the end of each turn to see if the
*				conditions for a new level has been met.
*
***********************************************************************/
#ifndef	ALCHEMY_H
#define ALCHEMY_H

#include "Board.h"
#include "Symbol.h"
#include "Random.h"

#include <iostream>
	using std::cout;
	using std::cin;
	using std::endl;


class Alchemy
{
	public:
		
		enum SymbolSituations {	Normal, Solvent, FreeSpace };
		
		Alchemy(  );
		Alchemy( const Alchemy & copy );
		Alchemy & operator=( const Alchemy & rhs );
		~Alchemy(  );

		int GetLevel(  );
		int GetScore(  );
		int GetCauldron(  );
		
		void SetLevel( int level );
		void SetScore( int score );
		void SetCauldron( int cauldron );


		void Display(  );
		void GameDriver(  );
		int GenerateSymbolSituation(  );
		void UserInput( int & row, int & col );
		bool Discard(  );
		void IncrementLevel(  );
		

	private:
		static Random m_rand;
		Board m_board;
		Symbol m_symbol;
		int m_level;
		int m_score;
		int m_cauldron;
		bool m_over;
};
#endif