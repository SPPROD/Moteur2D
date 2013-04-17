#include "stdafx.h"
#include "Objet.h"

void Objet::ajouter_groupe(Group* groupe) {
	//On ajoute l'objet au groupe
	groupe -> ajouter(this);
	//On ajoute le groupe aux groupes de l'objet
	groupes.push_back(groupe);
}

void Objet::supprimer_groupe(Group* groupe) {
	groupe -> supprimer(this);
}

void Objet::supprimer(Group* exception) {
	//Pour supprimer un objet on l'enlève d'abord de tous ses groupes, sauf celui passé en paramètre
	for(unsigned int i = 0;i < groupes.size();i++) {
		if(groupes[i] != exception)
			this -> supprimer_groupe(groupes[i]);
	}

	//Puis on libère la mémoire
	delete this;
}

void Objet::afficher(sf::RenderWindow& app) {
	//On affiche l'objet
	app.draw(sprite);
}

void Objet::update() {
}

sf::IntRect Objet::boundingBox() {
	return sf::IntRect(sprite.getPosition().x,sprite.getPosition().y,sprite.getTextureRect().width,sprite.getTextureRect().height);
}