
#include <iostream>
#include "base.h"
#include "raylib.h"
#include "function.h"

const Configuration config{ConfigGame()};
const Vector2 screen{float(config.width), float(config.height)};
character player;

int Start() {
    InitWindow(config.width, config.height, config.name.c_str());
    player = CreateCharacter(
            {LoadTexture(R"(..\source\texture\character\_Idle.png)")},
            3,
            {screen},
            10);
    return 0;
}


int Update() {
    float lastPos{};
    bool isFallDown{false};
    SetTargetFPS(config.fps);
    while (!WindowShouldClose()) {
        const float deltaTime{GetFrameTime()};
        BeginDrawing();
        ClearBackground(WHITE);

        player.position.y += jumpFunction(player, 1000, -600, deltaTime);
        if (!CheckGround(player)) {
            player = ChangeAnimation(player, LoadTexture(R"(..\source\texture\character\_Jump.png)"), 3);
            if (FallingDown(player, lastPos)) {
                player = ChangeAnimation(
                        player,
                        LoadTexture(R"(..\source\texture\character\_JumpFallInbetween.png)"),
                        1);
            }
        } else {
            player = ChangeAnimation(player, LoadTexture(R"(..\source\texture\character\_Idle.png)"), 10);
        }
        lastPos = player.position.y;

        player = AnimationUpdate(player, deltaTime);
        DrawTextureRec(player.texture, player.rectangle, player.position, WHITE);
        
        EndDrawing();
    }
    UnloadTexture(player.texture);
    CloseWindow();
    return 0;
}