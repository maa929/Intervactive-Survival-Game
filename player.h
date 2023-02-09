#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <sstream>
using namespace std;

class Player {
    public:
        Player(int initX, int initY);
        int getScore() const;
        bool isAlive() const;
        int getThirst() const;
        int getHunger() const;
        int getHealth() const;
        void setThirst(int val);
        void setHunger(int val);
        void setHealth(int val);
        int getXPosition() const;
        int getYPosition() const;
        void setPosition(int newX, int newY);
        string toString();
        void nextTurn();
    private:
        int thirst;
        int hunger;
        int health;
        int x, y;
        int score;
};
#endif
