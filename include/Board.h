#pragma once
#include <vector>
#include <utility>
using namespace std;

class Board {
public:
    Board(int width, int height);
    void draw(const vector<pair<int, int>>& snakeBody, pair<int, int> food, int score, int level) const;
    int getWidth() const;
    int getHeight() const;
private:
    int width;
    int height;
};
