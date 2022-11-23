//
// Created by david on 18/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP
#define CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP


#include "Plateau.hpp"
#include "../tuile/fragment/FragmentTriple.hpp"
#include "../tuile/TuileDominos.hpp"

class PlateauDominos final: Plateau<int, FragmentTriple<int>>{//PLateauDominos<FragmentTriple<T>> plateau;

    //int calculPoint(const TuileDominos<FragmentTriple<int>> &t, int x, int y);
    ostream & operator<<(ostream& os);

public:
    PlateauDominos();
    //TODO: int calculPoint(const Tuile<FragmentTriple<int>> &t, int x, int y);
};


#endif //CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP
