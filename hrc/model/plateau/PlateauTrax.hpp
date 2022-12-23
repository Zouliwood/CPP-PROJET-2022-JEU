#ifndef CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP
#define CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP

#include "Plateau.hpp"
#include "../enum/colorTrax.hpp"
#include "../tuile/fragment/FragmentSolo.hpp"
#include "../tuile/TuileTrax.hpp"

class PlateauTrax final: public Plateau<TuileTrax> {

public:

    /* Constructeur & Destructeur */
    PlateauTrax();
    ~PlateauTrax();
    /* define function */
    bool placeFirstTuile();//--OK--
    /* override function */
    int calculPoint(const TuileTrax * t, int x, int y) override;
    bool compareTuile(const TuileTrax *courant, const TuileTrax *tuileUp, const TuileTrax *tuileDown, const TuileTrax *tuileRight, const TuileTrax *tuileLeft) override;
    // virtual const TuileTrax & generateRandomTuile() const override;
    bool checkVictory() override;

    bool placeTuile(TuileTrax * t, int x, int y);

    bool isForced(int x, int y);

    bool canReplay();

    bool isLoop(int x, int y, colorTrax color, int from, int startX, int startY, int cpt);

    bool isLine(int x, int y, colorTrax color, int from, int startX, int startY);
};

ostream & operator<<(ostream& os, PlateauTrax & plateauTrax);

#endif //CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP
