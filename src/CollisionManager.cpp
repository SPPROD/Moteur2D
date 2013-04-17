#include "stdafx.h"
#include "CollisionManager.h"

bool CollisionManager::collision(sf::IntRect premier,sf::IntRect deuxieme) {
	return premier.left < deuxieme.left + deuxieme.width && premier.left + premier.width > deuxieme.left && premier.top < deuxieme.top + deuxieme.height && premier.top + premier.height > deuxieme.top;
}

std::vector < Objet* > CollisionManager::spritecollide(Objet& obj,Group& groupe,bool supprimer) {
	std::vector < Objet* > sprites_collisions;
	std::vector < Objet* > objets_groupe = groupe.objets();
	//Pour tous les objets du groupe on regarde s'ils sont en collision avec un objet
	for(unsigned int i = 0;i < objets_groupe.size();i++) {
		if(collision(objets_groupe[i] -> boundingBox(),obj.boundingBox())) {
			//s'ils sont en collision, on ajoute l'objet du groupe au tableau
			sprites_collisions.push_back(objets_groupe[i]);
			if(supprimer)
				//Si on doit supp
				objets_groupe[i] -> supprimer();
		}
	}

	return sprites_collisions;
}

std::vector < Objet* > CollisionManager::groupcollide(Group& groupe2,Group& groupe,bool tuer2,bool tuer1) {
	std::vector < Objet* > sprites_collisions,objets_groupe1 = groupe.objets(),objets_groupe2 = groupe2.objets();
	for(unsigned int i = 0;i < objets_groupe1.size();i++) {
		for(unsigned int j = 0;j < objets_groupe2.size();j++) {
			if(collision(objets_groupe1[i] -> boundingBox(),objets_groupe2[j] -> boundingBox())) {
				sprites_collisions.push_back(objets_groupe1[i]);
				sprites_collisions.push_back(objets_groupe2[j]);
				if(tuer1)
					objets_groupe1[i] -> supprimer();
				if(tuer2)
					objets_groupe2[j] -> supprimer();
			}
		}
	}

	return sprites_collisions;
}