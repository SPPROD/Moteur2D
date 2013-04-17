#include "Graphics.h"

void Graphics::init(Game *G){
	_game = G;
	Window.create(sf::VideoMode(640,480),"Game Engine");
}

sf::RenderWindow &Graphics::getWindow(){
	return Window;
}