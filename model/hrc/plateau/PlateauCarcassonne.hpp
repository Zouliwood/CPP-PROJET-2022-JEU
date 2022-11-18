//
// Created by david on 18/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP

#include "Plateau.hpp"

template<typename T>
class PlateauCarcassonne final: Plateau<T> {

    int calculPoint(const Tuile<T> &t, int x, int y);
    ostream & operator<<(ostream& os);

};


#endif //CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
