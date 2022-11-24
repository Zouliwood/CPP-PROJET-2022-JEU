#ifndef CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP
#define CPP_PROJET_2022_JEU_TUILEDOMINOS_HPP


#include "Tuile.hpp"
#include "../enum/directionTuile.hpp"
#include "fragment/FragmentTriple.hpp"
#include <ostream>
#define LEN_TUILE 3

using namespace std;

class TuileDominos final: public Tuile<FragmentTriple<int>> {//ici

public:
    /* Constructeur & Destructeur*/
    TuileDominos(FragmentTriple<int> & up, FragmentTriple<int> & right, FragmentTriple<int> & down, FragmentTriple<int> & left);
    ~TuileDominos() override;

    ostream & operator<<(ostream &os);

    /*function override*/
    void rotate() override;
    //void swapTab(FragmentTriple<int> &, FragmentTriple<int> &);
};


#endif
