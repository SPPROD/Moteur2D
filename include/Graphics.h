#pragma once
#include "Include.h"
#include "Game.h"

class Game;
class Graphics{
public:
	void init(Game *G,int,int);
	sf::RenderWindow &getWindow();
	void render(Group*);
	void addObjectToDraw(sf::Drawable&);
	
	//Graphicals functions
private:
	sf::RenderWindow Window;
	std::vector < sf::Drawable* > objects;
	Game * _game;
};