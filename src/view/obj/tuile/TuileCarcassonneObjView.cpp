#include "../../../../hrc/view/obj/tuile/TuileCarcassonneObjView.hpp"

TuileCarcassonneObjView::TuileCarcassonneObjView(TuileCarcassonne *tuileCarcassonne) : bg_tuile{*new Sprite()}, texture{*new Texture()}, tuileCarcassonne{tuileCarcassonne}{
    texture.setSmooth(true);
    texture.loadFromFile("../ressources/img/menu/image_bg_menu.png");
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
}

void TuileCarcassonneObjView::updateTuile() {
    bg_tuile.setTextureRect(IntRect(1280*2+ tuileCarcassonne->x_pos_view,720+tuileCarcassonne->y_pos_view, 150, 150));
    bg_tuile.setRotation(tuileCarcassonne->rotation);
}
