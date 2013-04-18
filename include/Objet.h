#ifndef OBJET
#define OBJET

#include "include.h"

class Group;

class Objet {
protected:
	//La liste des groupes auquel l'objet appartient
	std::vector < Group* > groupes;
	//Le sprite de l'objet. Un objet de jeu a forcément un sprite.
	sf::Sprite sprite;
	int id;
public:
	//Ajouter un groupe à l'objet
	void ajouter_groupe(Group*);
	//Supprimer un groupe à l'objet
	void supprimer_groupe(Group*);
	//Supprimer l'objet 
	void supprimer(Group* exception = 0);
	//La fonction raffraichissant un objet, par défaut vide
	virtual void update();
	//FOnction retournant l'id de l'objet
	int getId() const;
	//Fonction mettant l'id à l'objet
	void setId(int);
	//La fonction affichant le sprite de l'objet
	void afficher(sf::RenderWindow&);
	//Retourne la boite englobante de l'objet
	sf::IntRect boundingBox();
};

#endif