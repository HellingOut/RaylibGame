#pragma once

#include <raylib.h>
#include "Entity.h"

class Player: public Entity
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