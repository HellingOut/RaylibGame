#include "raylib.h"
#include "Player.h"


int main(void)
{
    
    float delta = 0.3;
    // Initialization
    const int screenWidth = 480;
    const int screenHeight = 272;

    InitWindow(screenWidth, screenHeight, "Raylib");
    Player player = Player();
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(480, 272);
    
    Camera2D camera = { 0 };
    camera.offset = Vector2{ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsWindowResized())
            camera.offset = Vector2 { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
        
        player.OnUpdate(delta);
        camera.target = Vector2 { player.GetPosition().x, player.GetPosition().y};
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);

                player.OnDraw();
                DrawText("Text Depends By Camera", 0, 0, 24, BLACK);

            EndMode2D();

            player.OnDrawGUI();
        
        EndDrawing();
        
        delta = GetFrameTime();
    }

    // De-Initialization
    CloseWindow();// Close window and OpenGL context    
    return 0;
}