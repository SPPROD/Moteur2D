#pragma once
#include "Include.h"
#include "Game_Object.h"
#include "Group.h"

class Object_Manager{
public:
	std::vector<Game_Object*> Main_Group;//In the Main_Group are ALL the game's objects.
	void init();
	void loop();
private:

};