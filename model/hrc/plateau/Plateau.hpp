//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAU_HPP
#define CPP_PROJET_2022_JEU_PLATEAU_HPP


#include <vector>
#include <iostream>
#include "../joueurs/Player.hpp"
#include "../tuile/Tuile.hpp"
//VALUE = value ou enum
template <typename V, typename TF>
//TODO:https://stackoverflow.com/a/30687399/16440965
class Plateau {

private:
    vector<const Player<TF> *> listPlayer;
    vector<vector<const Tuile<FragmentTuile<V>> &>> listTuile;
    int current_player = 0;

protected:
    virtual int calculPoint(const Tuile<FragmentTuile<V>> & value, int x, int y)=0;

public:
    void init(int l, int L);
    bool placeTuile(const Tuile<FragmentTuile<V>> & v , int x, int y);

    void nextPlayer();
    const Player<TF> * getPlayerCourant() const;

    // virtual ostream & operator<<(ostream& os) const =0;//TODO: virtual??
    const Tuile<FragmentTuile<V>> getTuileAt(int x, int y) const;

};
#include "../../src/plateau/Plateau.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
