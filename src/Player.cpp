#include "Player.h"

Player::Player():
    direction{ 0, 0 }, velocity{ 0, 0 }
{
    position = Vector2{0, 0};
    speed = 200;
};

void Player::OnUpdate(float delta)
{
    direction.x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    direction.y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    
    velocity.x = direction.x * speed * delta;
    velocity.y = direction.y * speed * delta;

    position.x += velocity.x;
    position.y += velocity.y;
}

void Player::OnDraw()
{
    DrawRectangleV({position.x - 32, position.y - 32}, {64, 64}, LIGHTGRAY);
}

void Player::OnDrawGUI()
{

}