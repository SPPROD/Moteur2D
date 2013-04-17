#include "GameContainer.h"

void GameContainer::start(){
	_game = new Game;
	_game->init(this);

	this->gameloop();
}
void GameContainer::gameloop(){
	while(!_game->closeRequested()){
		_game->update();//Updates game logic
		_game->render();//Renders the game on the window
	}
}

GameContainer::~GameContainer(){
	delete _game;
}