#include "../include/Map.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue> 


Map::Map() {
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
            if (cell == 1) std::cout << "# ";
            else std::cout << ". ";
        }
        std::cout << "\n";
    }
}


int getHeuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

bool isValid(int x, int y, const std::vector<std::vector<int>>& grid) {
    return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0);
}

std::vector<std::pair<int, int>> Map::findPath(int startX, int startY, int goalX, int goalY) {
    
    std::priority_queue<Node*, std::vector<Node*>, CompareNodeF> open_list;
    
    std::vector<std::vector<bool>> closed_list(grid.size(), std::vector<bool>(grid[0].size(), false));

    Node* start_node = new Node(startX, startY);
    start_node->h_cost = getHeuristic(startX, startY, goalX, goalY);
    start_node->f_cost = start_node->h_cost;
    
    open_list.push(start_node);

    std::vector<Node*> allocated_nodes;
    allocated_nodes.push_back(start_node);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!open_list.empty()) {
        Node* current = open_list.top();
        open_list.pop(); 

        if (closed_list[current->x][current->y]) continue;
        closed_list[current->x][current->y] = true;

        if (current->x == goalX && current->y == goalY) {
            std::vector<std::pair<int, int>> path;
            Node* curr = current;
            while (curr != nullptr) {
                path.push_back({curr->x, curr->y});
                curr = curr->parent;
            }
            std::reverse(path.begin(), path.end());

            for (Node* n : allocated_nodes) delete n;
            return path;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            if (isValid(newX, newY, grid) && !closed_list[newX][newY]) {
                int new_g = current->g_cost + 1;

                Node* neighbor = new Node(newX, newY, current);
                neighbor->g_cost = new_g;
                neighbor->h_cost = getHeuristic(newX, newY, goalX, goalY);
                neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;
                
                open_list.push(neighbor); 
                allocated_nodes.push_back(neighbor);
            }
        }
    }

    for (Node* n : allocated_nodes) delete n;
    return {};
}


void Map::printMapWithPath(const std::vector<std::pair<int, int>>& path) const {
    std::vector<std::vector<char>> display_grid(grid.size(), std::vector<char>(grid[0].size()));

    for (size_t r = 0; r < grid.size(); ++r) {
        for (size_t c = 0; c < grid[0].size(); ++c) {
            display_grid[r][c] = (grid[r][c] == 1) ? '#' : '.';
        }
    }

    for (const auto& waypoint : path) {
        display_grid[waypoint.first][waypoint.second] = '*';
    }

    if (!path.empty()) {
        display_grid[path.front().first][path.front().second] = 'S';
        display_grid[path.back().first][path.back().second] = 'G';
    }

    for (const auto& row : display_grid) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}