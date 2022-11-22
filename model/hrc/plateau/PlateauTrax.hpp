//
// Created by david on 18/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP
#define CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP


#include "Plateau.hpp"
#include "../enum/colorTrax.hpp"
#include "../tuile/fragment/FragmentSolo.hpp"

template<typename T>
class PlateauTrax final: Plateau<colorTrax, FragmentSolo<colorTrax>> {

    int calculPoint(const Tuile<T> &t, int x, int y);
    ostream & operator<<(ostream& os);

};


#endif //CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP
