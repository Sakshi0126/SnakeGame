#pragma once
#include <deque>
#include <utility>
using namespace std;

class Snake {
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Snake(int startX, int startY);
    void move();
    void changeDirection(Direction dir);
    void grow();
    bool checkCollision(int width, int height) const;
    bool isOnPosition(int x, int y) const;
    const deque<pair<int, int>>& getBody() const;
    Direction getDirection() const;
private:
    deque<pair<int, int>> body;
    Direction direction;
    bool growNext;
};
