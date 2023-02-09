#include <iostream>
#include <time.h>
#include "player.h"
#include "land.h"
using namespace std;

const int WORLD_SIZE = 20;
Land* world[WORLD_SIZE][WORLD_SIZE];

void buildWorld(){
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            world[i][j] = getRandomLand();
        }
    }
}

int main(){
    srand(time(0));
    buildWorld();
    Player player(WORLD_SIZE / 2, WORLD_SIZE / 2);
    
    cout << "You wake up in an unknown place." << endl;
    
    while(player.isAlive()){
        player.nextTurn();
        cout << player.toString() << endl;
        cout << "Player position x: " << player.getXPosition() << " y: " << player.getYPosition() << endl;
        
        if((player.getYPosition() - 1) == 0){//check if north is past boundary
            cout << "To the north you see " << world[player.getXPosition()][player.getYPosition() + WORLD_SIZE]->getDescription() << endl;
        }
        else{
            cout << "To the north you see " << world[player.getXPosition()][player.getYPosition() - 1]->getDescription() << endl;
        }
        
        if((player.getXPosition() - 1) == 0){//check if east is past boundary
            cout << "To the east you see " << world[player.getXPosition() + WORLD_SIZE][player.getYPosition()]->getDescription() << endl;
        }
        else{
            cout << "To the east you see " << world[player.getXPosition() - 1][player.getYPosition()]->getDescription() << endl;  
        }
        
        if(player.getXPosition() == WORLD_SIZE - 1){//check if west is past boundary
            cout << "To the west you see " << world[player.getXPosition() - WORLD_SIZE][player.getYPosition()]->getDescription() << endl;
        }
        else{
            cout << "To the west you see " << world[player.getXPosition() + 1][player.getYPosition()]->getDescription() << endl;
        }
        
        if(player.getYPosition() == WORLD_SIZE - 1){
            cout << "To the south you see " << world[player.getXPosition()][player.getYPosition() - WORLD_SIZE]->getDescription() << endl;
        }
        else{
            cout << "To the south you see " << world[player.getXPosition()][player.getYPosition() + 1]->getDescription() << endl;
        }
        
        cout << "Which direction do you want to move?\n1: North, 2: East, 3: West, 4: South" << endl;
        int userInput;
        cin >> userInput;
        
        switch(userInput){
            case 1: // North
                cout << "You move North." << endl;
                if(player.getYPosition() == 0){
                    player.setPosition(player.getXPosition(), player.getYPosition() + (WORLD_SIZE - 1));
                }
                else{
                    player.setPosition(player.getXPosition(), player.getYPosition() - 1);
                }
                break;
            case 2: // East
                cout << "You move East." << endl;
                if(player.getXPosition() == 0){
                    player.setPosition(player.getXPosition() + (WORLD_SIZE - 1), player.getYPosition());
                }
                else{
                    player.setPosition(player.getXPosition() - 1, player.getYPosition());
                }
                break;
            case 3: // West
                cout << "You move West." << endl;
                if(player.getXPosition() == (WORLD_SIZE - 1)){
                    player.setPosition(player.getXPosition() - (WORLD_SIZE - 1), player.getYPosition());
                }
                else{
                    player.setPosition(player.getXPosition() + 1, player.getYPosition());
                }
                break;
            case 4: // South
                cout << "You move South." << endl;
                if(player.getYPosition() == (WORLD_SIZE - 1)){
                    player.setPosition(player.getXPosition(), player.getYPosition() - (WORLD_SIZE - 1));
                }
                else{
                    player.setPosition(player.getXPosition(), player.getYPosition() + 1);
                }
                break;
            default: // Error
                break;
        }
        
        cout << "Player position x: " << player.getXPosition() << " y: " << player.getYPosition() << endl;
        cout << world[player.getXPosition()][player.getYPosition()]->visit(player) << endl;
        cout << endl;
        cout << endl;
    }
    cout << "You died" << endl;
    cout << "Score: " << player.getScore() << endl;
    
    return 0;
}
