//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLAYER_HPP
#define CPP_PROJET_2022_JEU_PLAYER_HPP

#include <string>

using namespace std;

class Player { //TODO: abstract class

private:
    Player();
    Player(const Player &);
    virtual ~Player();

protected:
    string pseudo;
    int points;
};


#endif //CPP_PROJET_2022_JEU_PLAYER_HPP
