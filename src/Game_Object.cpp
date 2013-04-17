#include "Game_Object.h"

Game_Object::Game_Object(Group *hGroup){
	Home_group = hGroup;
	id = -1;
}
sf::Sprite &Game_Object::getSprite(){
	return Sprite;
}
int Game_Object::getId(){
	return id;
}
void Game_Object::setId(int i){
	id = i;
}