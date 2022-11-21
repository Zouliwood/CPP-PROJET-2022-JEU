//
// Created by david on 18/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP
#define CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP


#include "Plateau.hpp"
#include "../tuile/fragment/FragmentTriple.hpp"

template<typename T>
class PlateauDominos final: Plateau<T>{//PLateauDominos<FragmentTriple<T>> plateau;

    int calculPoint(const Tuile<T> &t, int x, int y);
    ostream & operator<<(ostream& os);

public:
    PlateauDominos();

};


#endif //CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP
