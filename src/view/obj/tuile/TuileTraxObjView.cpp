#include "../../../../hrc/view/obj/tuile/TuileTraxObjView.hpp"

void TuileTraxObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    ComposantView::draw(target, states);
    if(tuileTrax->flip == 1) bg_tuile.setTextureRect(IntRect(150,0, 150, 150));
    else bg_tuile.setTextureRect(IntRect(0,0, 150, 150));
    bg_tuile.setPosition(getPosition());
    bg_tuile.setOrigin(75,75);
    bg_tuile.setRotation(tuileTrax->rotation);
    target.draw(bg_tuile);
}

TuileTraxObjView::~TuileTraxObjView() {
    delete &bg_tuile;
}

TuileTraxObjView::TuileTraxObjView(TuileTrax * trax) :  texture{*new Texture()}, bg_tuile{*(new Sprite())}, tuileTrax{trax}{
    texture.loadFromFile("ressources/img/plateau/tuileTrax.png");
    texture.setSmooth(true);
    bg_tuile.setTexture(texture);

}
