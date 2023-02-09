#include "land.h"

Land* getRandomLand(){
    LandTypes selection = (LandTypes)(rand() % NUM_LANDS);
    
    switch(selection){
        case FOREST:
            return new Forest;
            break;
        case LAKE:
            return new Lake;
            break;
        case DESERT:
            return new Desert;
            break;
        case VOLCANO:
            return new Volcano;
            break;
        case BEACH:
            return new Beach;
            break;
        case HOSPITAL:
            return new Hospital;
            break;
        case CITY:
            return new City;
            break;
        case TUNDRA:
            return new Tundra;
            break;
        default:
            return nullptr;
            break;
    }
}

string Forest::getDescription(){
    return "a densely wooded forest.";
}
string Forest::visit(Player& player){
    int chance = rand() % 4 + 1;
    
    if(chance == 1){
        player.setHunger(player.getHunger() + 1);
        return "You venture in and forage for nuts & berries, restoring your hunger.";
    }
    else if (chance == 2){
        player.setHealth(player.getHealth() - 2);
        return "You got attacked by a bear but managed to run away although you sustained injuries.";
    }
    else{
       return "You found nothing in the forest."; 
    }
}

string Lake::getDescription(){
    return "a sparkling clear lake.";
}
string Lake::visit(Player& player){
    int chance = rand() % 4 + 1;
    
    if(chance == 1){
        return "The lake was too dirty to drink from.";
    }
    else{
        player.setThirst(player.getThirst() + 1);
        return "You drink from the lake, re-hydrating yourself.";
    }
}

string Desert::getDescription(){
    return "a barren, dry desert.";
}
string Desert::visit(Player& player){
    int chance = rand() % 10 + 1;
    
    if(chance == 1){
        player.setThirst(player.getThirst() + 1);
        return "You miraculously found an oasis in the desert!";
    }
    else if(chance == 2 || chance == 3){
        player.setHealth(player.getHealth() - 1);
        player.setThirst(player.getThirst() - 1);
        return "You got bit by a rattlesnake. The venom gave you cottonmouth.";
    }
    else{
        return "What did you expect to find here?";
    }
}

string Volcano::getDescription(){
    return "a rocky, unstable volcano.";
}
string Volcano::visit(Player& player){
    int chance = rand() % 5 + 1;
    
    if(chance == 1){
        player.setHealth(player.getHealth() - 1);
        return "The volcano erupted. You escape the blast radius with some burns from the hot debris.";
    }
    else{
        return "The volcano did not erupt and you hiked across safely.";
    }
}

string Beach::getDescription(){
    return "a sunny beach with a cool breeze.";
}
string Beach::visit(Player& player){
    int chance = rand() % 5 + 1;
    
    if(chance == 1){
        player.setHunger(player.getHunger() + 1);
        return "You encountered a fisherman who gave you fish to eat";
    }
    else if(chance == 2){
        player.setHealth(player.getHealth() - 1);
        return "In a quick swim in th sea, you get stung by a jellyfish.";
    }
    else{
        return "You chill on the beach for a bit.";
    }
}

string Hospital::getDescription(){
    return "a large hospital!";
}
string Hospital::visit(Player& player){
    int chance = rand() % 5 + 1;
    
    if(chance == 1){
        return "The hospital was full of patients and were unable to aid you.";
    }
    else{
        int aid = rand() % 3 + 1;
        player.setHealth(player.getHealth() + aid);
        player.setThirst(player.getThirst() + aid);
        player.setHunger(player.getHunger() + aid);
        return "The hospital aided you with medicine, food, and water.";
    }
}

string City::getDescription(){
    return "a city full of skyscrapers.";
}
string City::visit(Player& player){
    int chance = rand() % 10 + 1;
    
    if(chance == 1){
        player.setHunger(player.getHunger() + 1);
        player.setThirst(player.getThirst() + 1);
        return "Someone invites you to eat at a restaurant because they consider you a hobo.";
    }
    if(chance == 2){
        player.setHealth(player.getHealth() - 1);
        return "A group of malicious men attacked you in an alley way.";
    }
    else{
        return "You continue walking through the city to your next location.";
    }
}

string Tundra::getDescription(){
    return "a cold tundra full of snow.";
}
string Tundra::visit(Player& player){
    int chance = rand() % 10 + 1;
    
    if(chance == 1 || chance == 4){
        player.setHunger(player.getHunger() + 1);
        return "You found a bush with honeyberries!";
    }
    else if(chance == 2){
        player.setThirst(player.getThirst() + 1);
        return "You found a cold freshwater pond!";
    }
    else if(chance == 3){
        player.setHealth(player.getHealth() - 2);
        return "You suffered frostbite on your soles walking on the snow for too long.";
    }
}
