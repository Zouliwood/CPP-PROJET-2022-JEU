//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAU_HPP
#define CPP_PROJET_2022_JEU_PLATEAU_HPP


#include <vector>
#include "joueurs/Player.hpp"
#include "tuile/Tuile.hpp"

template <typename T>
//TODO:https://stackoverflow.com/a/30687399/16440965
class Plateau {


private:
    vector<vector<Player &>> listPlayer;
    vector<vector<Tuile<T> &>> listTuile;


};


#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
