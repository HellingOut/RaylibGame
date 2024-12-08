#pragma once

#include "Entity.h"
#include <vector>
#include <string>

class Room: Entity
{
    std::string file_path;

    std::string identifier;
    Vector2 size;
    
    std::vector<std::string> layers;

    std::vector<Entity*> entities;

    void InitObjects();
    
public:
    Room();
    Room(std::string file_path);

    void StartRoom();
    void AddEntity(Entity* entity);
    
    void OnUpdate(float delta);
    void OnDraw();
    void OnDrawGUI();


    ~Room();
};