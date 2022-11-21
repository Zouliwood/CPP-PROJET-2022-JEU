//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAU_HPP
#define CPP_PROJET_2022_JEU_PLATEAU_HPP


#include <vector>
#include <iostream>
#include "../joueurs/Player.hpp"
#include "../tuile/Tuile.hpp"

template <typename T>
//TODO:https://stackoverflow.com/a/30687399/16440965
class Plateau {

protected:
    vector<const Player<T>&> listPlayer;
    vector<vector<const T &>> listTuile;
    int current_player = 0;

public:
    //virtual int calculPoint(const Tuile<FragmentTuile<T>> & t, int x, int y)=0;
    void nextPlayer();
    const Player<T> * getPlayerCourant() const;
    ostream & operator<<(ostream& os) const; // =0;//TODO: virtual??
    const T getTuileAt(int x, int y) const;
    bool placeTuile(const T t, int x, int y);
    void init(int l, int L);

};

#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
