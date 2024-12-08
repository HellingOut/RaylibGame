#pragma once

#include "Entity.h"
#include <raylib.h>

class Wall: Entity
{
    Vector2 size;
    public:
        Wall();
        void OnUpdate(float delta);
        void OnDraw();
        void OnDrawGUI();
};
