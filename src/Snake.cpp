
#include "../include/Snake.h"

Snake::Snake(int startX, int startY) {
    direction = RIGHT;
    growNext = false;
    body.push_back(std::make_pair(startX, startY));
}

void Snake::move() {
    int headX = body.front().first;
    int headY = body.front().second;
    if (direction == UP) headY--;
    else if (direction == DOWN) headY++;
    else if (direction == LEFT) headX--;
    else if (direction == RIGHT) headX++;
    body.push_front(std::make_pair(headX, headY));
    if (!growNext) body.pop_back();
    else growNext = false;
}

void Snake::changeDirection(Direction dir) {
    // Don't allow reversing
    if ((direction == UP && dir != DOWN) ||
        (direction == DOWN && dir != UP) ||
        (direction == LEFT && dir != RIGHT) ||
        (direction == RIGHT && dir != LEFT)) {
        direction = dir;
    }
}

void Snake::grow() {
    growNext = true;
}

bool Snake::checkCollision(int width, int height) const {
    int headX = body.front().first;
    int headY = body.front().second;
    if (headX < 0 || headX >= width || headY < 0 || headY >= height)
        return true;
    for (int i = 1; i < body.size(); ++i) {
        if (body[i].first == headX && body[i].second == headY)
            return true;
    }
    return false;
}

bool Snake::isOnPosition(int x, int y) const {
    for (int i = 0; i < body.size(); ++i) {
        if (body[i].first == x && body[i].second == y)
            return true;
    }
    return false;
}

const std::deque<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

Snake::Direction Snake::getDirection() const {
    return direction;
}
