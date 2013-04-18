#include "init.h"

//Basic Platform
class Platform : public Objet {
public:
	//The image of the platform and her position
	Platform(sf::Texture&,sf::Vector2f);
};

class MovablePlatform : public Platform {
private:
	int speed;
public:
	//The image of the platform and her position
	MovablePlatform(sf::Texture&,sf::Vector2f,int);
	//Move the platform
	void update();
};