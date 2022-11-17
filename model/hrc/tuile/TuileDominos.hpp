//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP
#define CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP


#include "Tuile.hpp"
#include "../enum/directionTuile.hpp"
#include "fragment/FragmentTriple.hpp"
#define LEN_TUILE 3

template<typename T>
class TuileDominos final: protected Tuile<FragmentTriple<T>> {//ici

private:
    void swapTab(FragmentTriple<int> &, FragmentTriple<int> &);

public:
    ~TuileDominos();
    void rotate();

};


#endif //CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP
