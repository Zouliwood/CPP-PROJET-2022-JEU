#ifndef CPP_PROJET_2022_JEU_CONTROLLERDOMINOS_HPP
#define CPP_PROJET_2022_JEU_CONTROLLERDOMINOS_HPP


#include "../model/tuile/TuileDominos.hpp"
#include "Controller.hpp"
#include "../model/plateau/PlateauDominos.hpp"

class ControllerDominos final  : public Controller<TuileDominos>{

public:
    ControllerDominos(int i, int i1);

    void init(int nombre_joueur, int nombre_tuile) override;
    void defausserTuile()override;
    bool placerTuile(TuileDominos *t, int x, int y)override;
    TuileDominos * getTuileJoueurQuiJoue() override;
    void piocheCarte()override;
    void suivantJoueur() override;
    void abandonnerParty() override;
    PlateauDominos *getPlateau() override;
    void generateRandomTuilePlateau() override;
};

#endif
