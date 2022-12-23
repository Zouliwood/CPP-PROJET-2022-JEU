#ifndef CPP_PROJET_2022_JEU_PLATEAUOBJVIEW_H
#define CPP_PROJET_2022_JEU_PLATEAUOBJVIEW_H


#include "../TuileView.h"
#include "../../../hrc/model/plateau/PlateauDominos.hpp"

class PlateauObjView: public TuileView {

    //PlateauDominos * plateauDominos;
    mutable Sprite background_plateau;
    mutable Texture texture_background;

    int x_back, y_back;

public:
    PlateauObjView();
    void draw(RenderTarget &target, sf::RenderStates states) const;
    void updateBackGround(int x, int y, int posx, int posy);
    /*
         void init();
         bool isPressed();
         bool isHover();
     */


};


#endif //CPP_PROJET_2022_JEU_PLATEAUOBJVIEW_H
