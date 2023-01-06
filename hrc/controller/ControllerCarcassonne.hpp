#ifndef CPP_PROJET_2022_JEU_CONTROLLERCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_CONTROLLERCARCASSONNE_HPP


#include "../model/tuile/TuileCarcassonne.hpp"
#include "Controller.hpp"
#include "../model/plateau/PlateauCarcassonne.hpp"

class ControllerCarcassonne final  : public Controller<TuileCarcassonne>{

public:
    ControllerCarcassonne(int i);
    void defausserTuile()override;
    bool placerTuile(TuileCarcassonne *t, int x, int y)override;
    TuileCarcassonne * getTuileJoueurQuiJoue() override;
    void piocheCarte()override;
    void suivantJoueur() override;
    void abandonnerParty() override;
    PlateauCarcassonne *getPlateau() override;
    void generateRandomTuilePlateau() override;
    PlayerCarcassonne * getJoueurQuiJoue();
};


#endif
