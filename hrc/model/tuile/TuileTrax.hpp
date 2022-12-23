#ifndef CPP_PROJET_2022_JEU_TUILETRAX_HPP
#define CPP_PROJET_2022_JEU_TUILETRAX_HPP

#include "../enum/colorTrax.hpp"
#include "Tuile.hpp"
#include "fragment/FragmentSolo.hpp"
#include <vector>

class TuileTrax final: public Tuile<FragmentSolo<colorTrax>>{

public:
    /* Constructeur & Destructeur*/
    TuileTrax(FragmentSolo<colorTrax> & up,FragmentSolo<colorTrax> & right,FragmentSolo<colorTrax> & down ,FragmentSolo<colorTrax> & left);
    ~TuileTrax() override;

    void flipTuile();

    /*function override*/
    void rotate() override;
    //TODO: ajouter atrb ensemble comme graph

};

ostream & operator<<(ostream &os, const TuileTrax & ttrax);

#endif
