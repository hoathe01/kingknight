//
// Created by hoath on 5/5/2024.
//

#include "../character/character.h"
#include "../../config/GameConfiguration.h"

#ifndef KINGKNIGHT_FUNCTION_H
#define KINGKNIGHT_FUNCTION_H
bool FallingDown(character character, float pos);
bool CheckGround(character character);
float jumpFunction(character character, float gravity, float jumpVel, float deltaTime);
#endif //KINGKNIGHT_FUNCTION_H
