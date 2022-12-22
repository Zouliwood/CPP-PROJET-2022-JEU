//
// Created by root0 on 09/12/22.
//

#include "PlateauObjView.h"

PlateauObjView::PlateauObjView():
/*        plateauDominos{plateauDominos},*/
        texture_background{*new Texture},
        background_plateau{*new Sprite()}{
    texture_background.loadFromFile("../ressources/img/plateau/bg_game.png");
    texture_background.setSmooth(true);
    texture_background.setRepeated(true);
    background_plateau.setTexture(texture_background);
}

void PlateauObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    target.draw(background_plateau);
    TuileView::draw(target, states);
}

void PlateauObjView::updateBackGround(int x, int y){
            //background_plateau.scale(background_plateau.getScale().x+ x, background_plateau.getScale().y + y);
            //background_plateau.setTexture(texture_background);
        }