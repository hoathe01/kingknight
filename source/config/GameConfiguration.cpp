//
// Created by hoath on 5/3/2024.
//
#include "GameConfiguration.h"
#include <fstream>
#include <iostream>
#include "../json.hpp"

using json = nlohmann::json;

json ConfigData() {
    std::ifstream config("../source/config/config.json");
    const json ConfigData = json::parse(config);
    return ConfigData;
}

Configuration ConfigGame() {
    const json config = ConfigData();
    std::string name = config["screen"]["name"];
    Configuration configuration {
            {name},
            {config["screen"]["width"]},
            {config["screen"]["height"]},
            {config["screen"]["fps"]}
    };
    std::cout << configuration.name << std::endl;
    return configuration;
}






