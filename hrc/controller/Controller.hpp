#ifndef CPP_PROJET_2022_JEU_CONTROLLER_HPP
#define CPP_PROJET_2022_JEU_CONTROLLER_HPP

#include "../model/plateau/Plateau.hpp"

template<typename T>
class Controller {

protected:
    Plateau<T> * plateauCourant;

public:
    Controller() = default;
    ~Controller(){ delete plateauCourant;}
    virtual bool placerTuile(T * t, int x, int y) = 0;
    virtual void defausserTuile() = 0;
    virtual T * getTuileJoueurQuiJoue() = 0;
    virtual void piocheCarte() = 0;
    virtual void suivantJoueur() = 0;
    virtual void abandonnerParty() = 0;
    virtual Plateau<T> *getPlateau() = 0;
   virtual void generateRandomTuilePlateau() = 0;
};

#endif