#pragma once

#include "GameObject.h"
#include <raylib.h>

class Wall: GameObject
{
    Vector2 size;
    public:
        Wall();
        void OnUpdate(float delta);
        void OnDraw();
        void OnDrawGUI();
};
