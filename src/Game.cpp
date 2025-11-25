#include "../include/Game.h"
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
using namespace std;

Game::Game() : snake(10, 10), board(20, 20) {
    score = 0;
    level = 1;
    speedMs = 200;
    running = true;
    srand((unsigned)time(0));
    spawnFood();
}

void Game::run() {
    thread inputThread(&Game::processInput, this);
    while (running) {
        update();
        this_thread::sleep_for(chrono::milliseconds(speedMs));
    }
    inputThread.join();
    cout << "Game Over! Final Score: " << score << endl;
}

void Game::processInput() {
    while (running) {
        if (_kbhit()) {
            int ch = _getch();
            if (ch == 224) { // Arrow key prefix
                ch = _getch();
                if (ch == 72) snake.changeDirection(Snake::UP);
                else if (ch == 80) snake.changeDirection(Snake::DOWN);
                else if (ch == 75) snake.changeDirection(Snake::LEFT);
                else if (ch == 77) snake.changeDirection(Snake::RIGHT);
            } else {
                if (ch == 'w') snake.changeDirection(Snake::UP);
                else if (ch == 's') snake.changeDirection(Snake::DOWN);
                else if (ch == 'a') snake.changeDirection(Snake::LEFT);
                else if (ch == 'd') snake.changeDirection(Snake::RIGHT);
                else if (ch == 'q') running = false;
            }
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    
    }
}

void Game::update() {
    snake.move();
    if (snake.checkCollision(board.getWidth(), board.getHeight())) {
        running = false;
        return;
    }
    pair<int, int> head = snake.getBody().front();
    if (head.first == food.first && head.second == food.second) {
        snake.grow();
        score += 10;
        if (score % 50 == 0) increaseLevel();
        spawnFood();
    }
    vector<pair<int, int>> snakeBody(snake.getBody().begin(), snake.getBody().end());
    board.draw(snakeBody, food, score, level);
}

void Game::spawnFood() {
    int x, y;
    do {
        x = rand() % (board.getWidth() - 2) + 1;
        y = rand() % (board.getHeight() - 2) + 1;
    } while (snake.isOnPosition(x, y));
    food = make_pair(x, y);
}

void Game::increaseLevel() {
    level++;
    if (speedMs > 50) speedMs -= 20;
}
