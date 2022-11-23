//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP

#include <vector>
#include "Player.hpp"
#include "../plateau/Pion.hpp"

template<typename TF>
class PlayerCarcassonne final: public Player<TF>{

private:
    /* attributs */
    vector<Pion> listePionsJoueur;

public:
    /* Constructeur & Destructeur */
    PlayerCarcassonne();
    ~PlayerCarcassonne();

    /* other function */
    vector<Pion> getListPions();
};

#include "../../src/joueurs/PlayerCarcassonne.tpp"
#endif
