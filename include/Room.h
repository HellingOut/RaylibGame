#pragma once

#include "GameObject.h"
#include <vector>
#include <string>

class Room: GameObject
{
    std::vector<GameObject*> objects;
    std::string file_path;
    void AddObjectsFromFile();
    void InitObjects();
    
public:
    Room();
    Room(std::string file_path);

    void StartRoom();
    void AddObject(GameObject* object);
    
    void OnUpdate(float delta);
    void OnDraw();
    void OnDrawGUI();


    ~Room();
};