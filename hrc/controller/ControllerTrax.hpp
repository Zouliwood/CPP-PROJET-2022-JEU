#ifndef CPP_PROJET_2022_JEU_CONTROLLERTRAX_HPP
#define CPP_PROJET_2022_JEU_CONTROLLERTRAX_HPP

#include "../model/tuile/TuileDominos.hpp"
#include "Controller.hpp"
#include "../model/plateau/PlateauDominos.hpp"
#include "../model/plateau/PlateauTrax.hpp"

class ControllerTrax final  : public Controller<TuileTrax>{

public:
    ControllerTrax();
    void defausserTuile()override;
    bool placerTuile(TuileTrax *t, int x, int y)override;
    TuileTrax * getTuileJoueurQuiJoue() override;
    void piocheCarte()override;
    void suivantJoueur() override;
    void abandonnerParty() override;
    PlateauTrax *getPlateau() override;
    void generateRandomTuilePlateau() override;
};

#endif