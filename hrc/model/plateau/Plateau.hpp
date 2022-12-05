#ifndef CPP_PROJET_2022_JEU_PLATEAU_HPP
#define CPP_PROJET_2022_JEU_PLATEAU_HPP


#include <vector>
#include <iostream>
#include "../joueurs/Player.hpp"
#include "../tuile/Tuile.hpp"
#include "../vector/AxeVector.hpp"

template <typename TF>
class Plateau {

protected:
    /* attributs */
    vector<const Player<TF> *> listPlayer;
    //vector<vector<TF *>> listTuile;
    AxeVector<AxeVector<TF>> listTuile;

    int current_player;

public:
    /* Constructeur & Destructeur */
    Plateau();
    virtual ~Plateau();

    /* to override function */
    virtual int calculPoint(const TF * value, int x, int y)=0;
    virtual bool placeFirstTuile() = 0;

    virtual bool compareTuile(const TF *courant, const TF *tuileUp, const TF *tuileDown, const TF *tuileRight, const TF *tuileLeft) = 0;
 //TODO: Check si carcassonne en a besoin sinon supprimer   virtual const Tuile<TF> & generateRandomTuile() const = 0;

    /* define function */
    void init(int l, int L);
    bool placeTuile(TF * t, int x, int y);
    void nextPlayer();
    const Player<TF> * getPlayerCourant() const;
    const TF * getTuileAt(int x, int y)const;
    vector<const Player<TF> *> getListPlayer() const;
    //vector<vector<TF *>> getListTuile() const;
    AxeVector<AxeVector<TF>> getListTuile()const;
    int getCurrentPlayer();

    virtual bool isFirstTuile(const TF * tuileUp, const TF * tuileDown, const TF * tuileRight, const TF * tuileLeft)=0;

    ostream & operator<<(ostream &os);
 //   string print();


};

#include "../../../src/model/plateau/Plateau.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
// virtual ostream & operator<<(ostream& os) const =0;//TODO: virtual??
