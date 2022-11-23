#ifndef CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP

#include <iostream>
#include <vector>
#include "Tuile.hpp"
#include "../enum/environment.hpp"

template <typename V>
class TuileCarcassonne final: public Tuile<V>{

private:
    /* attributs de la classe */
    FragmentTuile<V> & centre;

public:
    /* Constructeur & Destructeur */
    TuileCarcassonne();
    virtual ~TuileCarcassonne();

    /*function override*/
    void rotate();
};

#endif
