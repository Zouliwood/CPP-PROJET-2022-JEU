#ifndef CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP
#define CPP_PROJET_2022_JEU_PLATEAUTRAX_HPP

#include "Plateau.hpp"
#include "../enum/colorTrax.hpp"
#include "../tuile/fragment/FragmentSolo.hpp"
#include "../tuile/TuileTrax.hpp"
#include "../joueurs/PlayerTrax.hpp"

class PlateauTrax final: public Plateau<TuileTrax> {

    vector<const TuileTrax *> deja_vu;
public:

    /* Constructeur & Destructeur */
    PlateauTrax();
    PlateauTrax(const PlateauTrax &)=delete;
    ~PlateauTrax();
    /* define function */
    bool placeFirstTuile();//--OK--
    /* override function */
    int calculPoint(const TuileTrax * t, int x, int y) override;
    bool compareTuile(const TuileTrax *courant, const TuileTrax *tuileUp, const TuileTrax *tuileDown, const TuileTrax *tuileRight, const TuileTrax *tuileLeft) override;
    // virtual const TuileTrax & generateRandomTuile() const override;
    bool checkVictory() override;

    virtual bool placeTuile(TuileTrax * t, int x, int y);
    TuileTrax* getFirstTuilePose() override;
    bool isLoop(int x, int y, colorTrax color, int from, int startX, int startY, int cpt);
    bool existForcedAction(int x, int y);
    bool coupIsOk(int x, int y);
    bool isLine(int x, int y, colorTrax color, int startX, int startY, int from, int cpt=0);
};

#endif