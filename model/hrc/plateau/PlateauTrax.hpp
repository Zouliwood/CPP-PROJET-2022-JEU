#ifndef CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP
#define CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP

#include "Plateau.hpp"
#include "../enum/colorTrax.hpp"
#include "../tuile/fragment/FragmentSolo.hpp"
#include "../tuile/TuileTrax.hpp"

class PlateauTrax final: Plateau<TuileTrax> {

    ostream & operator<<(ostream& os);

public:
    /* Constructeur & Destructeur */
    PlateauTrax();
    ~PlateauTrax();
    /* define function */
    virtual bool placeFirstTuile() = 0;

    /* override function */
    int calculPoint(const TuileTrax & t, int x, int y);

};



#endif //CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP
