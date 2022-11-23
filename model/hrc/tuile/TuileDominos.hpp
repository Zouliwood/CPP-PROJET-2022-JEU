#ifndef CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP
#define CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP


#include "Tuile.hpp"
#include "../enum/directionTuile.hpp"
#include "fragment/FragmentTriple.hpp"
#include <ostream>
#define LEN_TUILE 3

using namespace std;

class TuileDominos final: public Tuile<int> {//ici

public:
    /* Constructeur & Destructeur*/
    TuileDominos();
    ~TuileDominos();

    /*function override*/
    void rotate() override;
    //void swapTab(FragmentTriple<int> &, FragmentTriple<int> &);
};


#endif
