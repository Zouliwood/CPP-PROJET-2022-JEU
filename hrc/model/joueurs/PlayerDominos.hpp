
#ifndef CPP_PROJET_2022_JEU_PLAYERDOMINOS_HPP
#define CPP_PROJET_2022_JEU_PLAYERDOMINOS_HPP

#include "Player.hpp"
#include "../tuile/TuileDominos.hpp"

class PlayerDominos final: public Player<TuileDominos> {

    /**
     * Class PlayerDominos. Aucune specificité liée à cette objet
     * il permet une meilleur compréhension du code
     */
public:
    /* Constructeur & Destructeur */
    PlayerDominos(string & pseudo);
    PlayerDominos(const PlayerDominos & plateauDominos) = delete ;
    ~PlayerDominos() override;

};

#endif