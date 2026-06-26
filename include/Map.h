#ifndef MAP_H
#define MAP_H

#include <vector>

// Struct representing a single point/cell on our grid
struct Node {
    int x, y;
    int g_cost, h_cost, f_cost;
    Node* parent; // Pointer to previous node to reconstruct the final path

    Node(int r, int c, Node* p = nullptr) 
        : x(r), y(c), g_cost(0), h_cost(0), f_cost(0), parent(p) {}
};

// Simple class to hold our grid representation
class Map {
public:
    // 0 = Empty space, 1 = Wall/Obstacle
    std::vector<std::vector<int>> grid;

    Map();
    void printMap() const;
};

#endif