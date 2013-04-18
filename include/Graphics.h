#pragma once
#include "Include.h"
#include "Game.h"
#include "Group.h"
class Graphics{
public:
	void init(Game *G);
	sf::RenderWindow &getWindow();
	
	//Graphicals functions
	void draw(sf::Sprite &Sprite);
	void draw(sf::Sprite &Sprite, sf::RenderWindow &Target);
	void draw(sf::Sprite &Sprite, sf::RenderTexture &Target);

	void draw(Group*);
private:
	sf::RenderWindow Window;
	Game * _game;
};