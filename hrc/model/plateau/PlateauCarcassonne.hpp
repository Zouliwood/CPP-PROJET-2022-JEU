#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP

#include "Plateau.hpp"
#include "../tuile/TuileCarcassonne.hpp"
#include "../Sac.hpp"
#include "Pion.hpp"
#include "../joueurs/PlayerCarcassonne.hpp"

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
    TuileCarcassonne * tuile_initial;
    bool solution = false;

public:
    /* Constructeur & Destructeur */
    Sac sac;

    PlateauCarcassonne(int nombre_joueur);
    PlateauCarcassonne(const PlateauCarcassonne &) = delete;
    ~PlateauCarcassonne();

    /* define function */
    bool placeFirstTuile();

    /* override function */
    int calculPoint(const TuileCarcassonne * t, int x, int y) override;
    bool compareTuile(const TuileCarcassonne * courant, const TuileCarcassonne * tuileUp, const TuileCarcassonne * tuileDown, const TuileCarcassonne  * tuileRight, const TuileCarcassonne  * tuileLeft) override;
    bool checkVictory() override;
    bool pionPresent(int x, int y, int posFrag, environment env);
    void pionPresentAux(int x, int y, int posFrag, environment env);
    bool isDejaVu(int x, int y, int pos);
    TuileCarcassonne * getFirstTuilePose() override;
};


#endif //CPP_PROJET_2022_JEU_PLATEAUCARCASSONNE_HPP
