#include "stdafx.h"
#include "Graphics.h"

void Graphics::init(Game *G,int width,int height){
	_game = G;
	Window.create(sf::VideoMode(width,height),"Game Engine");
}

sf::RenderWindow &Graphics::getWindow(){
	return Window;
}

void Graphics::render(Group* groupe) {
	Window.clear(sf::Color(255,255,255,255));
	groupe -> afficher(Window);
	for(unsigned int i = 0;i < objects.size();i++) {
		Window.draw(*objects[i]);
	}
	objects.clear();
	Window.display();
	Window.setFramerateLimit(40);
}

void Graphics::addObjectToDraw(sf::Drawable& obj) {
	objects.push_back(&obj);
}