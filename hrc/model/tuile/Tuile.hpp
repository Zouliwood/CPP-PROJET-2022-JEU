#ifndef CPP_PROJET_2022_JEU_TUILE_HPP
#define CPP_PROJET_2022_JEU_TUILE_HPP

#include "../enum/directionTuile.hpp"
#include "../enum/colorTrax.hpp"
#include "../enum/environment.hpp"
#include "fragment/FragmentTuile.hpp"
#include "fragment/FragmentQuadruple.hpp"
#include "fragment/FragmentTriple.hpp"
#include "fragment/FragmentSolo.hpp"
#include <iostream>

using namespace std;

template <typename TF>
class Tuile {

protected:
    /* attributs de la classe */
    TF & up;
    TF & right;
    TF & left;
    TF & down;
    //pas const car rotate

public:
    /* Constructeur & Destructeur */
    Tuile(TF & up, TF & down, TF & right, TF & left);
    virtual ~Tuile();

    const TF & getUp() const;
    const TF & getRight() const;
    const TF & getLeft() const;
    const TF & getDown() const;

    /* functions to override */
    virtual void rotate()=0;


};


#endif //CPP_PROJET_2022_JEU_TUILE_HPP
