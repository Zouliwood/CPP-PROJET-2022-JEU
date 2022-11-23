
#ifndef CPP_PROJET_2022_JEU_PLAYERDOMINOS_HPP
#define CPP_PROJET_2022_JEU_PLAYERDOMINOS_HPP

#include "Player.hpp"
#include "../tuile/TuileDominos.hpp"

class PlayerDominos final: public Player<TuileDominos> {

public:
    /* Constructeur & Destructeur */
    PlayerDominos();
    ~PlayerDominos() override;

};

#endif //CPP_PROJET_2022_JEU_PLAYERDOMINOS_HPP