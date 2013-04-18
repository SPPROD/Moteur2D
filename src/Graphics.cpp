#include "Graphics.h"

void Graphics::init(Game *G){
	_game = G;
	Window.create(sf::VideoMode(640,480),"Game Engine");
}

sf::RenderWindow &Graphics::getWindow(){
	return Window;
}

void Graphics::draw(sf::Sprite &Sprite){
	Window.draw(Sprite);
}
void Graphics::draw(sf::Sprite &Sprite, sf::RenderWindow &Target){
	Target.draw(Sprite);
}

void Graphics::draw(sf::Sprite &Sprite, sf::RenderTexture &Target){
	Target.draw(Sprite);
}