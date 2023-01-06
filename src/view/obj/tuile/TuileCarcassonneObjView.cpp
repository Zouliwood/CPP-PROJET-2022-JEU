#include "../../../../hrc/view/obj/tuile/TuileCarcassonneObjView.hpp"

TuileCarcassonneObjView::TuileCarcassonneObjView(TuileCarcassonne *tuileCarcassonne) :
    bg_tuile{*new Sprite()},
    texture{*new Texture()},
    tuileCarcassonne{tuileCarcassonne},
    pion{*new PionObjView()}{
    texture.setSmooth(true);
    pion.setPosition(-500, -500);
    texture.loadFromFile("ressources/img/menu/image_bg_menu.png");
    bg_tuile.setTexture(texture);
    bg_tuile.setTextureRect(IntRect(1280*2+ tuileCarcassonne->x_pos_view,720 +tuileCarcassonne->y_pos_view, 150, 150));
    bg_tuile.setOrigin(75,75);
    bg_tuile.setRotation(tuileCarcassonne->rotation);
}

TuileCarcassonneObjView::~TuileCarcassonneObjView(){

}

void TuileCarcassonneObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    ComposantView::draw(target, states);
    bg_tuile.setPosition(getPosition());
    target.draw(bg_tuile);
    target.draw(pion);
}

void TuileCarcassonneObjView::updateTuile() {
    bg_tuile.setTextureRect(IntRect(1280*2+ tuileCarcassonne->x_pos_view,720+tuileCarcassonne->y_pos_view, 150, 150));
    bg_tuile.setRotation(tuileCarcassonne->rotation);
}

void TuileCarcassonneObjView::setTuile(TuileCarcassonne *pCarcassonne) {
    tuileCarcassonne = pCarcassonne;
    updateTuile();
}

void TuileCarcassonneObjView::placePartisant(int value, int r, int g , int b){
    switch(value){
        case 0: partisantposx =  0; partisantposy = 0; break;
        case 1: partisantposx =  50; partisantposy = 0; break;
        case 2: partisantposx =  100; partisantposy = 0; break;
        case 3: partisantposx =  5; partisantposy = 25; break;
        case 6: partisantposx =  0; partisantposy = 65; break;
        case 10: partisantposx =  0; partisantposy = 90;break;
        case 4: partisantposx =  75; partisantposy = 30;break;
        case 7: partisantposx =  30; partisantposy = 75; break;
        case 8: partisantposx =  70; partisantposy = 50;  break;
        case 11: partisantposx =  65; partisantposy = 80; break;
        case 5:  partisantposx =  110; partisantposy = 15;  break;
        case 9:  partisantposx =  100; partisantposy = 50; break;
        case 12: partisantposx =  100; partisantposy = 100; break;
        case 13: partisantposx =  10; partisantposy = 110; break;
        case 14: partisantposx =  55; partisantposy = 110; break;
        case 15: partisantposx =  140; partisantposy = 110; break;
    }
    pion.setColor(r,g,b);
    addDrawable(partisantposx-75, partisantposy-75, &pion);
}