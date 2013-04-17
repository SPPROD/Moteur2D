#include "Group.h"

Group::Group(){
	freeId = 0;
}

void Group::add(Game_Object* GO){
	Objects.push_back(GO);
	IDS.insert(std::pair<int,Game_Object *>(GO->getId(), GO));
}
void Group::addandcreate(char type){
	
}

void Group::kill(int id){
	this->AdressFromId(id);//Call kill unless the object is of type Game_Object (this class is virtual pure)
}

Game_Object *Group::AdressFromId(int id){
	return IDS.find(id)->second;
}