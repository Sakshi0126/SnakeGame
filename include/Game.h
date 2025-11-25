#pragma once
#include "Snake.h"
#include "Board.h"
#include <utility>
using namespace std;

class Game {
public:
    Game();
    void run();
private:
    void processInput();
    void update();
    void spawnFood();
    void increaseLevel();
    bool running;
    Snake snake;
    Board board;
    pair<int, int> food;
    int score;
    int level;
    int speedMs;
};
