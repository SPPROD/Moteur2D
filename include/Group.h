#pragma once

#include "include.h"

class Objet;
class Group {
private:
	//Tableau contenant les membres du groupe
	std::vector < Objet* > membres;
public:
	//Fonction appelant la méthode update de tous les objets appartenant au gruope
	void update();
	//Fonction appelant la méthode afficher de tous les objets appartenant au groupe
	void afficher(sf::RenderWindow&);
	//Fonction ajoutant un objet au groupe
	void ajouter(Objet*);
	//Fonction supprimant un objet du groupe
	void supprimer(Objet*);
	//Fonction retournant la liste des membres du groupe
	std::vector < Objet* > objets();

	~Group();
};