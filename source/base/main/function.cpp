//
// Created by hoath on 5/5/2024.
//

#include <iostream>
#include "function.h"

const Configuration config{ConfigGame()};
const Vector2 screen{float(config.width), float(config.height)};

float velocity{};


bool FallingDown(character character, float pos) {
    return character.position.y > pos;
}

bool CheckGround(character character) {
    return character.position.y >= screen.y - character.rectangle.height;
}

float jumpFunction(character character, float gravity, float jumpVel, float deltaTime) {
    if (CheckGround(character)) {
        velocity = 0;
    } else {
        velocity += gravity * deltaTime;
    }
    if (IsKeyDown(KEY_SPACE) && CheckGround(character)) {
        std::cout << "JUMP" << std::endl;
        velocity += jumpVel;
    }
    return velocity * deltaTime;
}