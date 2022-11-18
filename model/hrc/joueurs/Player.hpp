//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLAYER_HPP
#define CPP_PROJET_2022_JEU_PLAYER_HPP

#include <string>
#include "../tuile/Tuile.hpp"

using namespace std;

template<typename T>
class Player { //TODO: abstract class

private:
    Player();
    Player(const Player &);
    virtual ~Player();

protected:
    const string pseudo;
    const int points;
    const Tuile<T> tuilecourante;
};


#endif //CPP_PROJET_2022_JEU_PLAYER_HPP
