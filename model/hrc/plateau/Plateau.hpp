#ifndef CPP_PROJET_2022_JEU_PLATEAU_HPP
#define CPP_PROJET_2022_JEU_PLATEAU_HPP


#include <vector>
#include <iostream>
#include "../joueurs/Player.hpp"
#include "../tuile/Tuile.hpp"

template <typename TF>
class Plateau {

protected:
    /* attributs */
    vector<const Player<TF> *> listPlayer;
    vector<vector<TF *>> listTuile;
    int current_player;

public:
    /* Constructeur & Destructeur */
    Plateau();
    virtual ~Plateau();

    /* to override function */
    virtual int calculPoint(const TF * value, int x, int y)=0;
    virtual bool placeFirstTuile() = 0;
 //TODO: Check si carcassonne en a besoin sinon supprimer   virtual const Tuile<TF> & generateRandomTuile() const = 0;

    /* define function */
    void init(int l, int L);
    bool placeTuile(TF * t, int x, int y, bool(* fun)(const TF * courant, const TF *up, const TF * down, const TF * right, const TF * left));
    void nextPlayer();
    const Player<TF> * getPlayerCourant() const;
    const TF * getTuileAt(int x, int y)const;
    vector<const Player<TF> *> getListPlayer() const;
    vector<vector<TF *>> getListTuile() const;
    int getCurrentPlayer();

    ostream & operator<<(ostream &os);
 //   string print();


};
#include "../../src/plateau/Plateau.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
// virtual ostream & operator<<(ostream& os) const =0;//TODO: virtual??
