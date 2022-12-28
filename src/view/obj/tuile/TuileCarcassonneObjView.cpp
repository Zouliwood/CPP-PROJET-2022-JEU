#include "../../../../hrc/view/obj/tuile/TuileCarcassonneObjView.hpp"

TuileCarcassonneObjView::TuileCarcassonneObjView(TuileCarcassonne *tuileCarcassonne) : bg_tuile{*new Sprite()}, texture{*new Texture()}{
    texture.setSmooth(true);
    texture.loadFromFile("../ressources/img/menu/image_bg_menu.png");
    bg_tuile.setTexture(texture);
    bg_tuile.setTextureRect(IntRect(tuileCarcassonne->x_pos_view, tuileCarcassonne->y_pos_view, 150, 150));
    bg_tuile.setOrigin(75,75);

}

TuileCarcassonneObjView::~TuileCarcassonneObjView(){

}

void TuileCarcassonneObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    ComposantView::draw(target, states);
    bg_tuile.setPosition(getPosition());
    bg_tuile.setRotation(tuileCarcassonne->rotation);
    target.draw(bg_tuile);
}
