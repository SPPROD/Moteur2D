#include "stdafx.h"
#include "Game.h"

void Game::init(int width,int height){
	lastIdGiven = 0;
	allObjects = new Group();
	_graphics = new Graphics;
	_graphics -> init(this,width,height);
}

void Game::addObject(Objet* obj) {
	obj -> ajouter_groupe(allObjects);
	obj -> setId(lastIdGiven);
	lastIdGiven += 1;
}

bool Game::isAlive() {
	while (_graphics->getWindow().pollEvent(event)){
		if(event.type == sf::Event::Closed){
			return false;
		}
		else{
			//On ajoute l'évènement à la liste des évènements
			evenements.push_back(event);
		}
	}

	return true;
}

std::vector < sf::Event > Game::events() {
	std::vector < sf::Event > all_events = evenements;
	evenements.clear();
	return all_events;
}
void Game::update(){
	allObjects -> update();
}

void Game::render(){
	_graphics -> render(allObjects);
}

Game::~Game() {
	delete _graphics;
	delete allObjects;
}

void Game::setView(sf::View *vue) {
	_graphics -> getWindow().setView(*vue);
}

void Game::draw(sf::Drawable& obj) {
	_graphics -> addObjectToDraw(obj);
}