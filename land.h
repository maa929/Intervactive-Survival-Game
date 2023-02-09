#ifndef LAND_H
#define LAND_H
#include <string>
#include "player.h"
using namespace std;
enum LandTypes {FOREST, LAKE, DESERT, VOLCANO, BEACH, HOSPITAL, CITY, TUNDRA, NUM_LANDS};

class Land {
    public:
        virtual string getDescription(){
            return "Description of land";
        }
        virtual string visit(Player& player){
            return "You visit a land";
        }
};

class Forest : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Lake : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Desert : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Volcano : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Beach : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Hospital : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class City : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Tundra : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

Land* getRandomLand();

#endif
