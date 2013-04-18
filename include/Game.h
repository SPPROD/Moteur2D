#pragma once
#include "Include.h"
#include "Graphics.h"
#include "GameContainer.h"


class Game{
public:
	void init(GameContainer *GC);
	bool check_events(sf::Event::EventType EV);
	void update();
	void render();
	bool closeRequested();
private:
	Graphics *_graphics;
	sf::Event event;
	GameContainer * _GC;
};