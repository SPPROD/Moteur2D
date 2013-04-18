#include "stdafx.h"
#include "Platforms.h"

Platform::Platform(sf::Texture& image,sf::Vector2f position) {
	sprite.setTexture(image);
	sprite.setPosition(position);
}

MovablePlatform::MovablePlatform(sf::Texture& image,sf::Vector2f position,int speed_ball) : Platform(image,position) {
	speed = speed_ball;
}

void MovablePlatform::update() {
	//Move the platform
	sprite.move(speed,0);
	//Verification of collisions
	if(boundingBox().left < 0) {
		sprite.setPosition(0,boundingBox().top);
		speed *= -1;
	}
	else if(boundingBox().left + boundingBox().width > WIDTH_SCREEN) {
		sprite.setPosition(WIDTH_SCREEN - boundingBox().width,boundingBox().top);
		speed *= -1;
	}
}
