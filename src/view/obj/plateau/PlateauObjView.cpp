#include "../../../../hrc/view/obj/plateau/PlateauObjView.h"

PlateauObjView::PlateauObjView():
/*        plateauDominos{plateauDominos},*/
        texture_background{*new Texture},
        background_plateau{*new Sprite()}
        {
        y_back = 2000;
        x_back = 2000;
        texture_background.loadFromFile("../ressources/img/plateau/bg_game.png");
        texture_background.setRepeated(true);
        background_plateau.setTexture(texture_background);
        background_plateau.setTextureRect(IntRect(0,0,x_back, y_back));

        }

void PlateauObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    target.draw(background_plateau);
    //background_plateau.setPosition(getPosition().x - 700, getPosition().y -350);
    ComposantView::draw(target, states);
}

void PlateauObjView::updateBackGround(int x, int y, int posx, int posy){
            x_back+=x;
            y_back+=y;
    //background_plateau.setPosition(getPosition().x - x, getPosition().y -y);
    //background_plateau.setOrigin(0,0);
    background_plateau.setTextureRect(IntRect(0,0,x_back, y_back));
}

PlateauObjView::~PlateauObjView() {
            delete &background_plateau;
            delete &texture_background;
}
