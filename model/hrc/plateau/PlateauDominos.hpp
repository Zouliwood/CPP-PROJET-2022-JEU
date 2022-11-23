#ifndef CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP
#define CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP


#include "Plateau.hpp"
#include "../tuile/fragment/FragmentTriple.hpp"
#include "../tuile/TuileDominos.hpp"

class PlateauDominos final: public Plateau<int>{

    ostream & operator<<(ostream& os);

public:
    /* Constructeur & Destructeur */
    PlateauDominos();
    ~PlateauDominos();

    /* define function */

    /* override function */
    int calculPoint(const Tuile<FragmentTuile<int>> & t, int x, int y);

};


#endif
