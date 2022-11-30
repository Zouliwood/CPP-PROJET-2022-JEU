
#ifndef CPP_PROJET_2022_JEU_CONTROLLER_HPP
#define CPP_PROJET_2022_JEU_CONTROLLER_HPP

#include "../model/plateau/Plateau.hpp"

template<typename T>
class Controller {

private:
    Plateau<T> plateauCourant;

public:
    void init();
    void deletePlateau();
    void suivantJoueur();
    void defausserTuile();
    bool placerTuileDomino(const Tuile<T> t, int x, int y);
    bool placerTuileCarcasonne(const Tuile<T> t, int x, int y);
    bool placerTuileTrax(const Tuile<T> t, int x, int y);
};


#endif //CPP_PROJET_2022_JEU_CONTROLLER_HPP
