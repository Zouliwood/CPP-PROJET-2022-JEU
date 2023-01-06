#ifndef CPP_PROJET_2022_JEU_BACKGROUNDOBJVIEW_HPP
#define CPP_PROJET_2022_JEU_BACKGROUNDOBJVIEW_HPP


#include "ComposantView.hpp"
#include "../../../model/plateau/PlateauDominos.hpp"

class BackGroundObjView : public ComposantView {
    mutable Sprite background_plateau;
    mutable Texture  texture_background;
    int x_back, y_back;

public:
    BackGroundObjView();
    ~BackGroundObjView();
    void draw(RenderTarget &target, sf::RenderStates states) const;
};

#endif
