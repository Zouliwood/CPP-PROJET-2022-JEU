//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PION_HPP
#define CPP_PROJET_2022_JEU_PION_HPP

#include "../enum/roleCarcassonne.hpp"
#include "../joueurs/PlayerCarcassonne.hpp"


class Pion final {

private:
    roleCarcassonne role;
    PlayerCarcassonne<TuileCarcassonne> * playerCarcassonne;
    int x, y, pos;
    Pion(int x, int y, int pos_frag, roleCarcassonne role, PlayerCarcassonne<TuileCarcassonne> * joueur);
    ~Pion();

public:

    int getX() const;
    int getY() const;
    int getPos() const;

};


#endif //CPP_PROJET_2022_JEU_PION_HPP
