#pragma once
#include "Include.h"

#include "Game.h"

class GameContainer{
public:
	void start();
	void pause();
	void gameloop();
	~GameContainer();
private:
	Game *_game;
};