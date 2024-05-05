//
// Created by hoath on 5/4/2024.
//

#include <iostream>
#include "character.h"

character CreateCharacter(Texture2D texture, float scale, Vector2 screen, int maxFrame) {
    character character{};
    character.scaleTex = scale;
    texture.height *= character.scaleTex;
    texture.width *= character.scaleTex;
    character.texture = texture;
    character.rectangle = {0, 0,
                           float(texture.width / maxFrame),
                           float(texture.height)};
    character.position = {200, (screen.y - texture.height)};
    character.updateTime = 1.0 / 12.0;
    character.maxFrame = 10;
    return character;
}

character AnimationUpdate(character character, float deltaTime) {
    character.tick += deltaTime;
    if (character.tick >= character.updateTime) {
        character.tick = 0;
        character.rectangle.x = ++character.frame * character.rectangle.width;
        if (character.frame >= character.maxFrame) {
            character.frame = 0;
        }
    }
    return character;
}

character ChangeAnimation(character character, Texture2D texture, int maxFrame) {
    character.texture = texture;
    character.maxFrame = maxFrame;
    character.texture.width *= character.scaleTex;
    character.texture.height *= character.scaleTex;
    return character;
}