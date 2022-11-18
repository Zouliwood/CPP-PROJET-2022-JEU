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

private:
    vector<const Player<Tuile<FragmentTuile<T>>> *> listPlayer;
    vector<vector<const Tuile<FragmentTuile<T>> &>> listTuile;
    int current_player = 0;

protected:
    virtual int calculPoint(const Tuile<FragmentTuile<T>> & t, int x, int y)=0;

public:
    bool placeTuile(const Tuile<FragmentTuile<T>> t, int x, int y);
    void nextPlayer();
    const Player<Tuile<FragmentTuile<T>>> * getPlayerCourant() const;
    virtual ostream & operator<<(ostream& os) const =0;//TODO: virtual??
    const Tuile<FragmentTuile<T>> getTuileAt(int x, int y) const;

};

#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
