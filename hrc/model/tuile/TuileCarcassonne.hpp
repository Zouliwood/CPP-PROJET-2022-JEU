#ifndef CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP

#include <iostream>
#include <vector>
#include "Tuile.hpp"
#include "../enum/environment.hpp"

template <typename TF>
class TuileCarcassonne final: public Tuile<TF>{

private:
    /* attributs de la classe */
    TF & centre;

public:
    /* Constructeur & Destructeur */
    TuileCarcassonne();
    ~TuileCarcassonne();

    /*function override*/
    void rotate();
};

#endif
