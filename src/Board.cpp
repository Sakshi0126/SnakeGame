#include "../include/Board.h"
#include <iostream>
using namespace std;

Board::Board(int width, int height) : width(width), height(height) {}

void Board::draw(const vector<pair<int, int>>& snakeBody, pair<int, int> food, int score, int level) const {
    system("cls");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) cout << "#";
            else if (food.first == x && food.second == y) cout << "*";
            else {
                bool isSnake = false;
                for (int i = 0; i < snakeBody.size(); i++) {
                    if (snakeBody[i].first == x && snakeBody[i].second == y) {
                        cout << "O";
                        isSnake = true;
                        break;
                    }
                }
                if (!isSnake) cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "Score: " << score << "  Level: " << level << "\n";
}

int Board::getWidth() const { return width; }
int Board::getHeight() const { return height; }
