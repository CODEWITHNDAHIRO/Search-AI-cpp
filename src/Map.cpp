#include "../include/Map.h"
#include <iostream>

Map::Map() {
    // 5x5 grid setup
    grid = {
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };
}

void Map::printMap() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            if (cell == 1) std::cout << "# "; // Wall
            else std::cout << ". ";          // Walkable path
        }
        std::cout << "\n";
    }
}