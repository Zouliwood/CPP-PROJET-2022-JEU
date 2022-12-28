#ifndef CPP_PROJET_2022_JEU_TUILECARCASSONNEOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILECARCASSONNEOBJVIEW_H


#include "../composant/ComposantView.h"
#include "../../../model/tuile/TuileCarcassonne.hpp"

class TuileCarcassonneObjView final : public ComposantView {

    mutable Texture texture;
    mutable Sprite bg_tuile;
    TuileCarcassonne * tuileCarcassonne;

public:
    TuileCarcassonneObjView(TuileCarcassonne * tuileCarcassonne);
    ~TuileCarcassonneObjView();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif