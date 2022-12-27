//
// Created by david on 23/12/22.
//

#ifndef CPP_PROJET_2022_JEU_SAC_HPP
#define CPP_PROJET_2022_JEU_SAC_HPP

#include <vector>
#include "../tuile/TuileCarcassonne.tpp"
#include "../tuile/fragment/FragmentQuadruple.tpp"

using namespace std;

class Sac {
    vector<TuileCarcassonne *> sac;
    Sac();
    TuileCarcassonne * getRandomTuile();
};


#endif //CPP_PROJET_2022_JEU_SAC_HPP