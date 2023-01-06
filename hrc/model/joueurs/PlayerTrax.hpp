#ifndef CPP_PROJET_2022_JEU_PLAYERTRAX_HPP
#define CPP_PROJET_2022_JEU_PLAYERTRAX_HPP


#include "Player.hpp"
#include "../tuile/TuileTrax.hpp"

class PlayerTrax final: public Player<TuileTrax>{

    /**
     * Class PlayerTrax represente un joueur du jeu Trax.
     * colorTrax est une enumeration qui  represente la couleur
     */
private:
    /* attributs */
    colorTrax couleur;

public:
    /* Constructeur & Destructeur */
    PlayerTrax(string & pseudo);
    PlayerTrax(const PlayerTrax &) = delete;
    ~PlayerTrax() override;

    /* function */
    colorTrax getColor();
};


#endif //CPP_PROJET_2022_JEU_PLAYERTRAX_HPP
