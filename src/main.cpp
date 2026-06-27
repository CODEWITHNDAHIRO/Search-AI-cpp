#include "../include/Map.h"
#include <iostream>

int main() {
    Map environment;
    std::cout << "=== Grid Environment ===\n";
    environment.printMap();

    int startX = 0, startY = 0;
    int goalX = 4, goalY = 4;

    std::cout << "\nFinding path from (" << startX << "," << startY << ") to (" << goalX << "," << goalY << ")...\n";
    auto path = environment.findPath(startX, startY, goalX, goalY);

    if (!path.empty()) {
        std::cout << "Path successfully found!\nWaypoints: ";
        for (const auto& coordinate : path) {
            std::cout << "(" << coordinate.first << "," << coordinate.second << ") ";
        }
        std::cout << "\n";
    } else {
        std::cout << "No path could be found.\n";
    }

    return 0;
}