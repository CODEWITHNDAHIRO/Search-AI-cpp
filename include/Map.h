#ifndef MAP_H
#define MAP_H

#include <vector>
#include <utility>

struct Node {
    int x, y;
    int g_cost, h_cost, f_cost;
    Node* parent;

    Node(int r, int c, Node* p = nullptr) 
        : x(r), y(c), g_cost(0), h_cost(0), f_cost(0), parent(p) {}
};

struct CompareNodeF {
    bool operator()(const Node* a, const Node* b) const {
        return a->f_cost > b->f_cost; 
    }
};

class Map {
public:
    std::vector<std::vector<int>> grid;

    
    Map(int rows = 15, int cols = 15, double obstacle_ratio = 0.25);
    
    void printMap() const;
    std::vector<std::pair<int, int>> findPath(int startX, int startY, int goalX, int goalY);
    void printMapWithPath(const std::vector<std::pair<int, int>>& path) const;
};

#endif