#ifndef CPP_PROJET_2022_JEU_TUILE_HPP
#define CPP_PROJET_2022_JEU_TUILE_HPP

#include "../enum/directionTuile.hpp"
#include "fragment/FragmentTuile.hpp"

template <typename V>
class Tuile {

protected:
    /* attributs de la classe */
    FragmentTuile<V> & up;
    FragmentTuile<V> & right;
    FragmentTuile<V> & left;
    FragmentTuile<V> & down;

public:
    /* functions to override */
    virtual void rotate()=0;

    /* Constructeur & Destructeur */
    Tuile();
    virtual ~Tuile();
};


#endif //CPP_PROJET_2022_JEU_TUILE_HPP
