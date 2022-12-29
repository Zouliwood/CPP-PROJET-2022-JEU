#ifndef CPP_PROJET_2022_JEU_BACKGROUNDOBJVIEW_H
#define CPP_PROJET_2022_JEU_BACKGROUNDOBJVIEW_H


#include "ComposantView.h"
#include "../../../model/plateau/PlateauDominos.hpp"

class BackGroundObjView : public ComposantView {
    mutable Sprite background_plateau;
    mutable Texture texture_background;

    int x_back, y_back;

public:
    BackGroundObjView();
    ~BackGroundObjView();
    void draw(RenderTarget &target, sf::RenderStates states) const;
};

#endif
