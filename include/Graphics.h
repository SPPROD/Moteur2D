#pragma once
#include "Include.h"
#include "Game.h"

class Graphics{
public:
	void init(Game *G);
	sf::RenderWindow &getWindow();
	
	//Graphicals functions
private:
	sf::RenderWindow Window;
	Game * _game;
};