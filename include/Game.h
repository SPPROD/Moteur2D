#pragma once
#include "include.h"
#include "Graphics.h"

class Graphics;
class Game{
public:
	void init(int,int);
	void update();
	void render();
	void draw(sf::Drawable&);
	void setView(sf::View*);
	bool isAlive();
	std::vector < sf::Event > events();
	void addObject(Objet*);
	sf::Event event;
	~Game();
private:
	Graphics *_graphics;
	Group* allObjects;
	bool is_alive;
	std::vector < sf::Event > evenements;
	int lastIdGiven;
};