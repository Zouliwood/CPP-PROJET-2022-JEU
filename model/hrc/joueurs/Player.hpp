#ifndef CPP_PROJET_2022_JEU_PLAYER_HPP
#define CPP_PROJET_2022_JEU_PLAYER_HPP

#include <string>
#include <iostream>
#include "../tuile/Tuile.hpp"

using namespace std;

template<typename TF>
class Player {

protected:
    /* Constructeur & Destructeur */
    Player();
    virtual ~Player();

    /* attributs */
    const string pseudo;
    mutable int points;
    //mutable Tuile<FragmentTuile<V>> tuilecourante ;

public:
    int getPoints();
    TF getTuile() const;

};
#include "../../src/joueurs/Player.tpp"

#endif //CPP_PROJET_2022_JEU_PLAYER_HPP
