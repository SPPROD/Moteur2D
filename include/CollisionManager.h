#pragma once
#include "include.h"

class CollisionManager {
public:
//Retourne true s'il y a collision entre deux IntRect
static bool collision(sf::IntRect,sf::IntRect);
//Retourne la liste des objets du groupe en collisions.
//Le premier paramètre est un objet
//Le deuxième un groupe
//Le troisième indique si l'on veut supprimer les élément du groupe en collision
static std::vector < Objet* > spritecollide(Objet&,Group&,bool);
/*
Teste la collision entre 2 groupes, retourne la liste des objets des groupes en collision
3eme argument indique si l'on veut supprimer les éléments en collision du premier groupe
4eme argument indique si l'on veut supprimer les éléments en collision du deuxieme groupe
*/
static std::vector < Objet* > groupcollide(Group&,Group&,bool,bool);
};