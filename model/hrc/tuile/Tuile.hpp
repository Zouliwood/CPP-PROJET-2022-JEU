//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILE_HPP
#define CPP_PROJET_2022_JEU_TUILE_HPP

#include "../enum/directionTuile.hpp"
#include "fragment/FragmentTuile.hpp"

template <typename TF>
class Tuile { //TODO: cacher les constructions juste pour leur fils

private:
    Tuile();
    Tuile(const Tuile &);
protected:

    virtual void rotate();//TODO: on verra = 0 necessaire
    virtual int getPoint();
public:
    virtual ~Tuile();

    //https://stackoverflow.com/a/9782100/16440965
    TF & up;
    TF & right;
    TF & left;
    TF & down;

};

template<typename TF>
Tuile<TF>::~Tuile() {

}

template<typename TF>
void Tuile<TF>::rotate() {

}

template<typename TF>
int Tuile<TF>::getPoint() {
    return 0;
}


#endif //CPP_PROJET_2022_JEU_TUILE_HPP
