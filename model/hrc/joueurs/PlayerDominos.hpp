//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLAYERDOMINOS_HPP
#define CPP_PROJET_2022_JEU_PLAYERDOMINOS_HPP

#include "Player.hpp"
#include "../tuile/TuileDominos.hpp"


class PlayerDominos final: protected Player<TuileDominos>{

public:
    ~PlayerDominos();
};

#endif //CPP_PROJET_2022_JEU_PLAYERDOMINOS_HPP
