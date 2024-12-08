#pragma once

#include <raylib.h>

class Entity{
    protected:
        Vector2 position;
        float rotation;
        virtual void OnUpdate(float delta) = 0;
        virtual void OnDraw() = 0;
        virtual void OnDrawGUI() = 0;
    public:
        Vector2 GetPosition();
        void SetPosition(Vector2 new_position);
        virtual ~Entity() {};
        friend class Room;
        friend class EntityFactory;
};