#include "stdafx.h"
#include "Group.h"

void Group::update() {
	for(unsigned int i = 0;i < membres.size();i++) {
		membres[i] -> update();
	}
}

void Group::afficher(sf::RenderWindow& application) {
	for(unsigned int i = 0;i < membres.size();i++) {
		membres[i] -> afficher(application);
	}
}

void Group::ajouter(Objet* obj) {
	membres.push_back(obj);
}

std::vector < Objet* > Group::objets() {
	return membres;
}

void Group::supprimer(Objet* adresse) {
	for(unsigned int i = 0;i < membres.size();i++) {
		if(membres[i] == adresse)
			membres.erase(membres.begin() + i);
	}
}

Objet* Group::getById(int id) {
	for(unsigned int i = 0;i < membres.size();i++) {
		if(membres[i] -> getId() == id)
			return membres[i];
	}
}

Group::~Group() {
	for(unsigned int i = 0;i < membres.size();i++) {
		membres[i] -> supprimer(this);
	}
}