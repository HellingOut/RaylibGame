#include "Room.h"

Room::Room() :
	size{256, 265}
{};
Room::Room(std::string file_path):
	size{ 256, 265 } 
{};

void Room::InitObjects(){};

void Room::StartRoom(){};

void Room::AddEntity(Entity* entity)
{
	entities.push_back(entity);
};

void Room::OnUpdate(float delta)
{
	for (auto enitiy : entities) {
		enitiy->OnUpdate(delta);
	}
}

void Room::OnDraw()
{
	for (auto enitiy : entities) {
		enitiy->OnDraw();
	}
}

void Room::OnDrawGUI()
{
	for (auto enitiy : entities) {
		enitiy->OnDrawGUI();
	}
};

Room::~Room(){};
