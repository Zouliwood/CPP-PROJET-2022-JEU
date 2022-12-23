//
// Created by root0 on 23/12/22.
//

#ifndef CPP_PROJET_2022_JEU_BACKGROUNDOBJVIEW_H
#define CPP_PROJET_2022_JEU_BACKGROUNDOBJVIEW_H


#include "../TuileView.h"
#include "../../../hrc/model/plateau/PlateauDominos.hpp"

class BackGroundObjVIew : public TuileView {

    //PlateauDominos * plateauDominos;
    mutable Sprite background_plateau;
    mutable Texture texture_background;

    int x_back, y_back;

public:
    BackGroundObjVIew();
    void draw(RenderTarget &target, sf::RenderStates states) const;
};

#endif //CPP_PROJET_2022_JEU_BACKGROUNDOBJVIEW_H
