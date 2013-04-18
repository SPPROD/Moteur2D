#include "init.h"
#include "Platforms.h"
#include "Doodle.h"

class Jeu {
private:
	Game game;
	sf::Texture image_doodle,image_pieds,image_plateforme_basique,image_plateforme_bougeable;
	Body* doodle;
	int planche_la_plus_haute;
	sf::View vue;
	Group plateformes;
public:
	void init();
	int demarrer();
	void generer_planches(int);
};