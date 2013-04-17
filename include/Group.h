#pragma once
#include "Include.h"
#include "Game_Object.h"

class Group{
public:
	Group();
	void add(Game_Object* GO);
	void addandcreate(char type);
	void kill(int id);
	void action();

	

	std::map<int,Game_Object *> IDS;
private:
	int freeId;
	Game_Object *AdressFromId(int id);
	std::vector<Game_Object*> Objects;
};
//Group permet d'indexer differentes adresses de Game_Object et d'effectuer des modifications sur 
//l'objet qu'elles pointent.
//Les IDs sont stockées 