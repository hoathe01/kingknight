//
// Created by hoath on 5/3/2024.
//

#ifndef KINGKNIGHT_GAMECONFIGURATION_H
#define KINGKNIGHT_GAMECONFIGURATION_H


#include <string>

struct Configuration{
    std::string name;
    int width;
    int height;
    int fps;
};

Configuration ConfigGame();


#endif //KINGKNIGHT_GAMECONFIGURATION_H
