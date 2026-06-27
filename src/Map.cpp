#ifndef MAP_H
#define MAP_H

#include <vector>

struct Node {
    int x, y;
    int g_cost, h_cost, f_cost;
    Node* parent;

    Node(int r, int c, Node* p = nullptr) 
        : x(r), y(c), g_cost(0), h_cost(0), f_cost(0), parent(p) {}
};

class Map {
public:
    std::vector<std::vector<int>> grid;

    Map();
    void printMap() const;
    
    // --- Day 9 Addition: A* Pathfinding Method ---
    std::vector<std::pair<int, int>> findPath(int startX, int startY, int goalX, int goalY);
};

#endif