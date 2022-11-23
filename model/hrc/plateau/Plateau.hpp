#ifndef CPP_PROJET_2022_JEU_PLATEAU_HPP
#define CPP_PROJET_2022_JEU_PLATEAU_HPP


#include <vector>
#include <iostream>
#include "../joueurs/Player.hpp"
#include "../tuile/Tuile.hpp"

template <typename V>

class Plateau {

protected:
    /* attributs */
    vector<const Player<V> *> listPlayer;
    vector<vector<Tuile<FragmentTuile<V>> *>> listTuile;
    int current_player;

public:
    /* Constructeur & Destructeur */
    Plateau();
    virtual ~Plateau();

    /* to override function */
    virtual int calculPoint(const Tuile<FragmentTuile<V>> & value, int x, int y)=0;

    /* define function */
    void init(int l, int L);
    bool placeTuile(const Tuile<FragmentTuile<V>> & t, int x, int y);
    void nextPlayer();
    const Player<V> * getPlayerCourant() const;
    Tuile<FragmentTuile<V>> getTuileAt(int x, int y) const;

};
#include "../../src/plateau/Plateau.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
// virtual ostream & operator<<(ostream& os) const =0;//TODO: virtual??
