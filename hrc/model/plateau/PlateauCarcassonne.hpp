#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP

#include "Plateau.hpp"
#include "../tuile/TuileCarcassonne.hpp"

template<typename F>
class PlateauCarcassonne final: public Plateau<TuileCarcassonne> {


    ostream & operator<<(ostream& os);

public:
    /* Constructeur & Destructeur */
    PlateauCarcassonne();
    ~PlateauCarcassonne();

    /* define function */
    virtual bool placeFirstTuile() = 0;

    /* override function */
    int calculPoint(const F * t, int x, int y) override;
    bool compareTuile(TuileCarcassonne * courant, TuileCarcassonne * tuileUp, TuileCarcassonne * tuileDown, TuileCarcassonne  * tuileRight, TuileCarcassonne  * tuileLeft) override;
    bool checkVictory();
    // virtual const TuileCarcassonne<F> & generateRandomTuile() const override;
    TuileCarcassonne *generateRandomTuile();

    bool pionPresent(int x, int y, int posFrag, environment env);

    bool pionPresentAux(int x, int y, int posFrag, environment env, vector<FragmentTuile<F>> dejaVu);
};


#include "../../../src/model/plateau/PlateauCarcassonne.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
