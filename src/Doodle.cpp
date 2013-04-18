#include "stdafx.h"
#include "Doodle.h"

Foot::Foot(sf::Texture& image,sf::Vector2f position) {
	sprite.setTexture(image);
	sprite.setPosition(position);
}

Body::Body(sf::Texture& image_corps,sf::Texture& foot,sf::Vector2f position,Game& game,sf::View* game_view) {
	sprite.setTexture(image_corps);
	sprite.setPosition(position);
	hauteur_initiale = position.y;
	doodle_foot = new Foot(foot,sf::Vector2f(boundingBox().left,boundingBox().top + boundingBox().height));
	game.addObject(doodle_foot);
	view = game_view;
	highestPoint = position.y;
	jump();
	changeView();
}

void Body::jump() {
	gravity = INITIAL_GRAVITY;
}

void Body::changeView() {
	int point = boundingBox().top + boundingBox().height/2 + doodle_foot -> boundingBox().height/2;
	if(point < highestPoint)
		highestPoint = point;
	view -> setCenter(WIDTH_SCREEN/2,highestPoint);
}

void Body::move(sf::Vector2f vector) {
	sprite.move(vector);
	doodle_foot -> move(vector);
}

void Body::move_x(int direction) {
	if(direction == LEFT)
		move(sf::Vector2f(DOODLE_SPEED * -1,0));
	else
		move(sf::Vector2f(DOODLE_SPEED,0));
}

void Body::update() {
	move(sf::Vector2f(0,gravity));
	gravity += 1;
	changeView();
}

Foot* Body::get_foot() {
	return doodle_foot;
}

void Foot::move(sf::Vector2f vector) {
	sprite.move(vector);
}

void Body::setPositionX(int position) {
	sprite.setPosition(position,sprite.getPosition().y);
	doodle_foot -> setPositionX(position);
}

void Foot::setPositionX(int position) {
	sprite.setPosition(position,sprite.getPosition().y);
}

int Body::getScore() {
	return hauteur_initiale - highestPoint;
}