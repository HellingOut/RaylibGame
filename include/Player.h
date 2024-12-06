#pragma once

#include <raylib.h>
#include <GameObject.h>
class Player: public GameObject
{
    Vector2 velocity;
    Vector2 direction;
    float speed;
    public:
        Player();
        void OnUpdate(float delta);
        void OnDraw();
        void OnDrawGUI();
        
};