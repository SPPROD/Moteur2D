#pragma once
#include "Include.h"
#include "Group.h"
class Game_Object{
public:
	Game_Object(Group *hGroup);
	virtual void Move() = 0;
	virtual void Action() = 0;

	void setId(int i);
	sf::Sprite &getSprite();
	int getId();
private:
	sf::Sprite Sprite;
	sf::Vector2i position;
	int id;

	Group *Home_group;
};