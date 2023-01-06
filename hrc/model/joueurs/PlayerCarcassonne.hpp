#ifndef CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP

#include <vector>
#include "Player.hpp"
#include "../tuile/TuileCarcassonne.hpp"
#include "../plateau/Pion.hpp"

class PlayerCarcassonne final: public Player<TuileCarcassonne>{

private:
    /* attributs */
//    vector<Pion> listePionsJoueur;
    int r,g,b;

public:
    /* Constructeur & Destructeur */
    vector<Pion *> listPion;

    PlayerCarcassonne(string & pseudo);
    PlayerCarcassonne(const PlayerCarcassonne & player) = delete ;
    ~PlayerCarcassonne();

    /* other function */
    int getR() const;
    int getG() const;
    int getB() const;
    vector<Pion *> getListPion() const;
    Pion * getPionLibre();

};
#endif
