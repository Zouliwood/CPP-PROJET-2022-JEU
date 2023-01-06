#ifndef CPP_PROJET_2022_JEU_PLATEAU_HPP
#define CPP_PROJET_2022_JEU_PLATEAU_HPP


#include <vector>
#include <iostream>
#include "../joueurs/Player.hpp"
#include "../tuile/Tuile.hpp"
#include "../vector/AxeVector.hpp"
#include "../tuile/TuileDominos.hpp"
#include "../../view/obj/tuile/TuileDominosObjView.hpp"

template <typename TF>
class Plateau {

protected:
    /* attributs */
    vector<Player<TF> *> listPlayer;
    AxeVector<AxeVector<TF>> listTuile;
    Player<TF> * courant; /* Pas besoin de free est deja supprimé c'est un pointeur */
    int current_player, nbr_tuile, nbr_player;

public:
    /* Constructeur & Destructeur */
    Plateau(int current_player, int nbr_tuile);
    Plateau(const Plateau &) = delete;
    virtual ~Plateau();

    /* to override function */
    virtual int calculPoint(const TF * value, int x, int y)=0;
    virtual bool placeFirstTuile() = 0;
    virtual bool checkVictory() = 0;
    virtual TF *getFirstTuilePose()=0;
    virtual bool compareTuile(const TF *courant, const TF *tuileUp, const TF *tuileDown, const TF *tuileRight, const TF *tuileLeft) = 0;

    /* define function */
    void init(int l, int L);
    bool placeTuile(TF * t, int x, int y);
    void nextPlayer();
    Player<TF> * getPlayerCourant();
    const TF * getTuileAt(int x, int y)const;
    vector<Player<TF> *> getListPlayer();
    AxeVector<AxeVector<TF>> getListTuile()const;
    int getCurrentPlayer();
    ostream & operator<<(ostream &os);
    bool canPlay();
    int nombreCarteRestant();
    void piocheCarte();
};


#include "../../../src/model/plateau/Plateau.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
