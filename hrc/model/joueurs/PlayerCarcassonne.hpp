#ifndef CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLAYERCARCASSONNE_HPP

#include <vector>
#include "Player.hpp"
#include "../tuile/TuileCarcassonne.hpp"
#include "../plateau/Pion.hpp"

class PlayerCarcassonne final: public Player<TuileCarcassonne>{

    /**
     * Class PlayerCarcassonne represente un joueur carcassonne.
     * Une couleur identifié par 3 int r,g,b
     * et une liste de pointeur d'objet Pion qui represente les partisants
     */

private:
    const int r,g,b;
    vector<Pion *> listPion;

public:
    /* Constructeur & Destructeur */
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
