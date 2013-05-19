#ifndef TESTGAME_H
#define TESTGAME_H

#include "Game.h"

/*! \brief Brief description.
 *         Simple test game to show functionality of class Game and its inheridance
 */

class TestGame : Game
{
	TestGame();		//!< default constructor

	virtual void start();
};

#endif