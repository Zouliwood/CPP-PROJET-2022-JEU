//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP
#define CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP


#include "Tuile.hpp"
#include "../enum/directionTuile.hpp"

#define LEN_TUILE 3

class TuileDominos final: protected Tuile<int[3]> {

private:
    void swapTab(int tab[], int tab2[]);

public:
    ~TuileDominos();

    void rotate();
    bool operator==(const int[3]);
    bool operator!=(const int[3]);

};


#endif //CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP
