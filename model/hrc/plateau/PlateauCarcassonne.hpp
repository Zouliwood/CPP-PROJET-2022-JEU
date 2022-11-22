//
// Created by david on 18/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP

#include "Plateau.hpp"
#include "../tuile/TuileCarcassonne.hpp"

template<typename TF>
class PlateauCarcassonne final: Plateau<TF, TF> {

    //  int calculPoint(const Tuile<TF> &t, int x, int y);
    ostream & operator<<(ostream& os);

};


#endif //CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
