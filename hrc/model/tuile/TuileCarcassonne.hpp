#ifndef CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP

#include <iostream>
#include <vector>
#include "Tuile.hpp"
#include "../enum/environment.hpp"
#include "fragment/FragmentQuadruple.hpp"

class TuileCarcassonne final: public Tuile<FragmentTriple<environment>>{

private:
    /* attributs de la classe */
    FragmentQuadruple<environment> & centre;

public:
    int x_pos_view, y_pos_view, rotation;
    /* Constructeur & Destructeur */
    TuileCarcassonne(int, int, FragmentTriple<environment> & up, FragmentTriple<environment> & right, FragmentTriple<environment> & down, FragmentTriple<environment> & left, FragmentQuadruple<environment> & center);
    ~TuileCarcassonne();

    const FragmentQuadruple<environment> & getCentre() const;

    /*function override*/
    void rotate();
};

#endif
