#ifndef CPP_PROJET_2022_JEU_TUILECARCASSONNEOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILECARCASSONNEOBJVIEW_H


#include "../composant/ComposantView.hpp"
#include "../../../model/tuile/TuileCarcassonne.hpp"

class TuileCarcassonneObjView final : public ComposantView {

    mutable Texture texture;
    mutable Sprite bg_tuile;

public:
    TuileCarcassonne * tuileCarcassonne;
    TuileCarcassonneObjView(TuileCarcassonne * tuileCarcassonne);
    ~TuileCarcassonneObjView();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateTuile();

    void setTuile(TuileCarcassonne *pCarcassonne);
};


#endif