//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILE_HPP
#define CPP_PROJET_2022_JEU_TUILE_HPP

#include "../enum/directionTuile.hpp"

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

    T up;
    T right;
    T left;
    T down;

    //  virtual bool isValide(T, enum directionTuile) ;
    virtual bool operator==(const T) = 0;
    virtual bool operator!=(const T) = 0;

};


#endif //CPP_PROJET_2022_JEU_TUILE_HPP
