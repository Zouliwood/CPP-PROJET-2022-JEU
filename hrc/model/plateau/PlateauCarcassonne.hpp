#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP

#include "Plateau.hpp"
#include "../tuile/TuileCarcassonne.hpp"

class PlateauCarcassonne final: public Plateau<TuileCarcassonne> {

    class FragElement{
    public:
        int x;
        int y;
        int pos;

        FragElement(int x, int y, int pos): x{x}, y{y}, pos{pos}{

        }

        ~FragElement(){

        }

    };

    vector<FragElement *> dejaVu;

public:
    /* Constructeur & Destructeur */
    PlateauCarcassonne();
    ~PlateauCarcassonne();

    /* define function */
    bool placeFirstTuile();

    /* override function */
    int calculPoint(const TuileCarcassonne * t, int x, int y) override;
    bool compareTuile(const TuileCarcassonne * courant, const TuileCarcassonne * tuileUp, const TuileCarcassonne * tuileDown, const TuileCarcassonne  * tuileRight, const TuileCarcassonne  * tuileLeft) override;
    bool checkVictory();
    // virtual const TuileCarcassonne<F> & generateRandomTuile() const override;
    TuileCarcassonne *generateRandomTuile();

    bool pionPresent(int x, int y, int posFrag, environment env);

    bool pionPresentAux(int x, int y, int posFrag, environment env);

    bool isDejaVu(int x, int y, int pos);
};


#include "../../../src/model/plateau/PlateauCarcassonne.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
