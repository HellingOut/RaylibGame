#include <raylib.h>
#include "Player.h"
#include "Room.h"

int main(void)
{

    float delta = 0.3;
    // Initialization
    const int screenWidth = 1600;
    const int screenHeight = 900;

    InitWindow(screenWidth, screenHeight, "Raylib");

    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(480, 272);
    SetTargetFPS(60);

    Camera2D camera = { 0 };
    
    Player player;

    camera.offset = Vector2{ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    Room main_room;

    main_room.AddEntity(&player);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsWindowResized())
            camera.offset = Vector2{ GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };

        main_room.OnUpdate(delta);

        camera.target = Vector2{ player.GetPosition().x, player.GetPosition().y };
        
        BeginDrawing();
        
        DrawFPS(GetScreenWidth()-GetScreenWidth()/14.54, GetScreenHeight()/100);
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);

        main_room.OnDraw();

        DrawText("Text Depends By Camera", 0, 0, 24, BLACK);
        EndMode2D();

        main_room.OnDrawGUI();

        EndDrawing();

        delta = GetFrameTime();
    }

    // De-Initialization
    CloseWindow();// Close window and OpenGL context

    return 0;
}