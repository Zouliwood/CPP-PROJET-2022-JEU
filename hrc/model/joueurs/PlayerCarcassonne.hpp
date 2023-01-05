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
     // int nombre_de_partisans;


public:
    /* Constructeur & Destructeur */
    vector<Pion *> listPion;

    PlayerCarcassonne();
    ~PlayerCarcassonne();

    /* other function */
   // vector<Pion> getListPions();

};

#endif
