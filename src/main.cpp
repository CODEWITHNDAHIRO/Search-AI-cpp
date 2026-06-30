#include "../include/Map.h"
#include <iostream>

int main() {
    // Initializing a 15x15 map with 25% obstacle coverage
    int rows = 15;
    int cols = 15;
    Map environment(rows, cols, 0.25);
    
    int startX = 0, startY = 0;
    int goalX = rows - 1, goalY = cols - 1;

    std::cout << "=== Scale Testing A* Algorithm (" << rows << "x" << cols << ") ===\n";
    auto path = environment.findPath(startX, startY, goalX, goalY);

    if (!path.empty()) {
        std::cout << "\nOptimal Path Found! Final Procedural Map Layout:\n";
        std::cout << "(S = Start, G = Goal, * = Path, # = Obstacle)\n\n";
        environment.printMapWithPath(path);
    } else {
        std::cout << "\nNo valid path found through the procedural maze layout. Run again to generate a new map!\n";
    }

    return 0;
}