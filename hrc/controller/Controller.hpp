#ifndef CPP_PROJET_2022_JEU_CONTROLLER_HPP
#define CPP_PROJET_2022_JEU_CONTROLLER_HPP

#include "../model/plateau/Plateau.hpp"

template<typename T>
class Controller {

private:
    Plateau<T> plateauCourant;

public:
    Controller() = default;
    void init(int nombre_joueur, int nombre_tuile);
    void deletePlateau();
    void defausserTuile();
    bool placerTuile(Tuile<T> t, int x, int y);

    void piocheCarte();
    void suivantJoueur();
    void abandonnerParty();
};

#include "../../src/controller/Controller.tpp"
#endif