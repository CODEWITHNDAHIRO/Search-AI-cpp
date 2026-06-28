#include "../include/Map.h"
#include <iostream>

int main() {
    Map environment;
    
    int startX = 0, startY = 0;
    int goalX = 4, goalY = 4;

    std::cout << "=== Finding Path via A* Algorithm ===\n";
    auto path = environment.findPath(startX, startY, goalX, goalY);

    if (!path.empty()) {
        std::cout << "\nOptimal Path Found! Final Map Representation:\n";
        std::cout << "(S = Start, G = Goal, * = Calculated Route, # = Obstacle)\n\n";
        
        environment.printMapWithPath(path);
    } else {
        std::cout << "No valid route exists between points.\n";
    }

    return 0;
}