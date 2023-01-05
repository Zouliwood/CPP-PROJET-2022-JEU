#ifndef CPP_PROJET_2022_JEU_PLAYERTRAX_HPP
#define CPP_PROJET_2022_JEU_PLAYERTRAX_HPP


#include "Player.hpp"
#include "../tuile/TuileTrax.hpp"

class PlayerTrax final: public Player<TuileTrax>{

private:
    /* attributs */
    colorTrax & couleur;

public:
    /* Constructeur & Destructeur */
    PlayerTrax();
    ~PlayerTrax() override;

    /* function */
    colorTrax getColor();
};


#endif //CPP_PROJET_2022_JEU_PLAYERTRAX_HPP
