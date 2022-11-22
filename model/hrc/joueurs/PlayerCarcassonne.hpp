//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP

#include "Player.hpp"

//FRAGMENT TF
//TUILE T
template<typename TF>
class PlayerCarcassonne final: protected Player<TF>{

public:
    ~PlayerCarcassonne();

};

#include "../../src/joueurs/PlayerCarcassonne.tpp"


#endif //CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP
