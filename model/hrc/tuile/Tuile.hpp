//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILE_HPP
#define CPP_PROJET_2022_JEU_TUILE_HPP

template <typename T>

class Tuile { //TODO: cacher les constructions juste pour leur fils

private:
    Tuile();
    Tuile(const Tuile &);
    virtual ~Tuile();

protected:
    T up;
    T down;
    T right;
    T left;

};


#endif //CPP_PROJET_2022_JEU_TUILE_HPP
