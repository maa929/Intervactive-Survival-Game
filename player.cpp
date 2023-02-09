#include "player.h"
#include <iostream>
using namespace std;

Player::Player(int initX, int initY){
    health = 7;
    hunger = 10;
    thirst = 5;
    x = initX;
    y = initY;
    score = 0;
}

int Player::getScore() const{
    return score;
}

bool Player::isAlive() const{
    if (health == 0){
        return false;
    }
    else{
        return health > 0;
    }
}

int Player::getThirst() const{
    return thirst;
}
int Player::getHunger() const{
    return hunger;
}
int Player::getHealth() const{
    return health;
}
void Player::setThirst(int val) {
    thirst = val;
}
void Player::setHunger(int val) {
    hunger = val;
}
void Player::setHealth(int val){
    health = val;
}

int Player::getXPosition() const {
    return x;
}
int Player::getYPosition() const {
    return y;
}
void Player::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

string Player::toString(){
    stringstream ss;
    ss << "Health: " << health << endl;
    ss << "Hunger: " << hunger << endl;
    ss << "Thirst: " << thirst << endl;
    return ss.str();
}

void Player::nextTurn(){
    hunger--;
    thirst--;
    
    if(hunger <= 0){
        hunger = 0;
        health--;
    }
    
    if(thirst <= 0){
        thirst = 0;
        health--;
    }
    
    if(health < 0){
        health = 0;
    }
    score++;
}
