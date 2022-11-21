//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILE_HPP
#define CPP_PROJET_2022_JEU_TUILE_HPP

#include "../enum/directionTuile.hpp"
#include "fragment/FragmentTuile.hpp"

template <typename T>
class Tuile { //TODO: cacher les constructions juste pour leur fils

private:
    Tuile();
    Tuile(const Tuile &);
    virtual ~Tuile();

protected:

    virtual void rotate();//TODO: on verra = 0 necessaire
    virtual int getPoint();
public:

    //https://stackoverflow.com/a/9782100/16440965
    T & up;
    T & right;
    T & left;
    T & down;

};


#endif //CPP_PROJET_2022_JEU_TUILE_HPP
