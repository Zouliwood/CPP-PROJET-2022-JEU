#ifndef CPP_PROJET_2022_JEU_SAC_HPP
#define CPP_PROJET_2022_JEU_SAC_HPP

#include "tuile/TuileCarcassonne.hpp"
#include <vector>

using namespace std;

class Sac {

public:
    vector<TuileCarcassonne *> sac;
    Sac();
    TuileCarcassonne * getRandomTuile();

};


#endif
