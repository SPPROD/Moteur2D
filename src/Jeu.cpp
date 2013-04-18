#include "stdafx.h"
#include "Jeu.h"
#include <cmath>
#include <sstream>

void Jeu::init() {
	game.init(WIDTH_SCREEN,HEIGHT_SCREEN);
	//Chargement des images
	image_doodle.loadFromFile("doodle.png");
	image_pieds.loadFromFile("pieds.png");
	image_plateforme_basique.loadFromFile("plateforme_basique.png");
	image_plateforme_bougeable.loadFromFile("plateforme_bougeable.png");

	//Création de la vue
	vue = sf::View(sf::Vector2f(400,300),sf::Vector2f(WIDTH_SCREEN,HEIGHT_SCREEN));

	//Création du doodle
	doodle = new Body(image_doodle,image_pieds,sf::Vector2f(WIDTH_SCREEN/2,HEIGHT_SCREEN/2),game,&vue);
	game.addObject(doodle);

	//ajout de 30 plateformes
	planche_la_plus_haute = HEIGHT_SCREEN;
	generer_planches(30);
}

int Jeu::demarrer() {
	init();
	while(game.isAlive()) {
		//Deplacement du joueur
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			doodle -> move_x(LEFT);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			doodle -> move_x(RIGHT);

		//Mise à jour du jeu
		game.update();

		//On gère les collisions du doodle
		if(doodle -> gravity > 0) {
			std::vector < Objet* > collisions = CollisionManager::spritecollide(*(doodle -> get_foot()),plateformes,false);
			if(collisions.size() > 0) {
				doodle -> jump();
			}
		}

		//Si le doodle est tout à gauche ou tout à droite, on change sa position
		if(doodle -> boundingBox().left < 0)
			doodle -> setPositionX(WIDTH_SCREEN - doodle -> boundingBox().width);
		else if(doodle -> boundingBox().left + doodle -> boundingBox().width > WIDTH_SCREEN)
			doodle -> setPositionX(0);

		//On regarde s'il faut générer des planches, si oui on en génère 30
		if(abs(planche_la_plus_haute - doodle -> boundingBox().top) < WIDTH_SCREEN * 3/2) {
			generer_planches(30);
		}

		//On supprime les plateformes trop basses
		std::vector < Objet* > objs = plateformes.objets();
		for(unsigned int i = 0;i < objs.size();i++) {
			if(objs[i] -> boundingBox().top > vue.getCenter().y + vue.getSize().y/2) {
				objs[i] -> supprimer();
			}
		}

		//Si le joueur perd, on quitte
		if(doodle -> boundingBox().top > vue.getCenter().y + vue.getSize().y/2)
			return 0;

		//On met la vue
		game.setView(&vue);
		//On affiche le jeu
		game.render();
		//On affiche le score
		
		
	}

	return 0;

}

//Génère aléatoirement le nombre de planches demandé
void Jeu::generer_planches(int nombre) {
	int derniere_ordonnee = planche_la_plus_haute;
	for(int i = 0;i < nombre;i++) {
		int planche_type = rand() % 2,position_x_max = WIDTH_SCREEN - image_plateforme_basique.getSize().x,abscisse = rand() % position_x_max,ordonnee = derniere_ordonnee - (rand() % 100 + 30);
		if(planche_type == 0) {
			MovablePlatform* plat = new MovablePlatform(image_plateforme_bougeable,sf::Vector2f(abscisse,ordonnee),4);
			game.addObject(plat);
			plat -> ajouter_groupe(&plateformes);
		}
		else {
			Platform *plat = new Platform(image_plateforme_basique,sf::Vector2f(abscisse,ordonnee));
			game.addObject(plat);
			plat -> ajouter_groupe(&plateformes);
		}

		
		derniere_ordonnee = ordonnee;
	}

	planche_la_plus_haute = derniere_ordonnee;
}