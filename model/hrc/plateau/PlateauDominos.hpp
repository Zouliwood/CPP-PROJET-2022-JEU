#ifndef CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP
#define CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP


#include "Plateau.hpp"
#include "../tuile/fragment/FragmentTriple.hpp"
#include "../tuile/TuileDominos.hpp"

class PlateauDominos final: public Plateau<TuileDominos>{

public:
    /* Constructeur & Destructeur */
    PlateauDominos();
    ~PlateauDominos();

    bool placeFirstTuile();

    /* define function */
    void toprint();
    /* override function */
    int calculPoint(const TuileDominos & t, int x, int y);

};

ostream &operator<<(ostream &os, PlateauDominos & plateauDominos);

#endif

