#pragma once

#include <raylib.h>
#include "Entity.h"

class Player: public Entity
{
    Vector2 velocity;
    Vector2 direction;
    float speed;
    Player();
    public:
        void OnUpdate(float delta) override;
        void OnDraw() override;
        void OnDrawGUI() override;
        
};