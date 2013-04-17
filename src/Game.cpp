#include "Game.h"


void Game::init(GameContainer *GC){
	_graphics = new Graphics;
	_graphics->init(this);
}

bool Game::closeRequested(){
	while (_graphics->getWindow().pollEvent(event)){
		if(event.type == sf::Event::Closed){
			return true;
		}
		else{
			//Other tests about direct events for example..
		}
	}
	return false;
}

void Game::update(){

}

void Game::render(){
	_graphics->getWindow().display();
}