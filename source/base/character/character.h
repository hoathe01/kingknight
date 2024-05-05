//
// Created by hoath on 5/4/2024.
//
#include "raylib.h"

#ifndef KINGKNIGHT_CHARACTER_H
#define KINGKNIGHT_CHARACTER_H


struct character {
    Texture2D texture;
    Rectangle rectangle;
    Vector2 position;
    float updateTime;
    float tick;
    int frame;
    int maxFrame;
    float scaleTex;
};

character AnimationUpdate(character character, float deltaTime);

character CreateCharacter(Texture2D texture, float scale, Vector2 screen, int maxFrame);

character ChangeAnimation(character character, Texture2D texture, int maxFrame);
#endif //KINGKNIGHT_CHARACTER_H
