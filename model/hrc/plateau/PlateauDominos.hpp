#ifndef CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP
#define CPP_PROJET_2022_JEU_PLATEAUDOMINOS_HPP


#include "Plateau.hpp"
#include "../tuile/fragment/FragmentTriple.hpp"
#include "../tuile/TuileDominos.hpp"

class PlateauDominos final: public Plateau<TuileDominos>{

public:
    /* Constructeur & Destructeur */
    PlateauDominos();
    ~PlateauDominos();

    bool placeFirstTuile();
    TuileDominos * generateRandomTuile() const;
    static bool compareTuile(TuileDominos * courant, TuileDominos * tuileUp, TuileDominos * tuileDown, TuileDominos * tuileRight, TuileDominos * tuileLeft);

    /* define function */
    void toprint();
    /* override function */
    //TODO: https://stackoverflow.com/questions/6969020/overriding-virtual-function-return-type-differs-and-is-not-covariant
    int calculPoint(const TuileDominos * t, int x, int y) override;
};

ostream &operator<<(ostream &os, PlateauDominos & plateauDominos);

#endif
