#ifndef CPP_PROJET_2022_JEU_TUILECARCASSONNEOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILECARCASSONNEOBJVIEW_H


#include "../composant/ComposantView.hpp"
#include "../../../model/tuile/TuileCarcassonne.hpp"
#include "../plateau/PionObjView.hpp"

class TuileCarcassonneObjView final : public ComposantView {

    mutable Texture texture;
    mutable Sprite bg_tuile;
    PionObjView & pion;
    int partisantposx, partisantposy;

public:
    TuileCarcassonne * tuileCarcassonne; //TODO mettre en private
    TuileCarcassonneObjView(TuileCarcassonne * tuileCarcassonne);
    ~TuileCarcassonneObjView();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateTuile();
    void setTuile(TuileCarcassonne *pCarcassonne);
    void placePartisant(int value, int r, int g, int b);
};


#endif