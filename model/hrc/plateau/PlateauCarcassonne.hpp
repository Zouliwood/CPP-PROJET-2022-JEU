#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP

#include "Plateau.hpp"
#include "../tuile/TuileCarcassonne.hpp"

template<typename F>
class PlateauCarcassonne final: Plateau<TuileCarcassonne<F>> {


    ostream & operator<<(ostream& os);

public:
    /* Constructeur & Destructeur */
    PlateauCarcassonne();
    ~PlateauCarcassonne();
    /* define function */
    virtual bool placeFirstTuile() = 0;

    /* override function */
    int calculPoint(const F & t, int x, int y);

};
#include "../../src/plateau/PlateauCarcassonne.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
