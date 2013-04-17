#pragma once
#include "include.h"

class CollisionManager {
public:
//Retourne true s'il y a collision entre deux IntRect
static bool collision(sf::IntRect,sf::IntRect);
//Retourne la liste des objets du groupe en collisions.
//Le premier param�tre est un objet
//Le deuxi�me un groupe
//Le troisi�me indique si l'on veut supprimer les �l�ment du groupe en collision
static std::vector < Objet* > spritecollide(Objet&,Group&,bool);
/*
Teste la collision entre 2 groupes, retourne la liste des objets des groupes en collision
3eme argument indique si l'on veut supprimer les �l�ments en collision du premier groupe
4eme argument indique si l'on veut supprimer les �l�ments en collision du deuxieme groupe
*/
static std::vector < Objet* > groupcollide(Group&,Group&,bool,bool);
};