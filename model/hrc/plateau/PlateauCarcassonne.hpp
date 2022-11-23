#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP

#include "Plateau.hpp"
#include "../tuile/TuileCarcassonne.hpp"

template<typename V>
class PlateauCarcassonne final: Plateau<V> {


    ostream & operator<<(ostream& os);

public:
    /* Constructeur & Destructeur */
    PlateauCarcassonne();
    ~PlateauCarcassonne();
    /* define function */
    virtual bool placeFirstTuile() = 0;

    /* override function */
    int calculPoint(const Tuile<FragmentTuile<V>> & t, int x, int y);

};
#include "../../src/plateau/PlateauCarcassonne.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
