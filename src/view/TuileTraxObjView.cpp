#include "TuileTraxObjView.h"

void TuileTraxObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    TuileView::draw(target, states);
    if(tuileTrax->flip == 1){
      //  cout << "oui" << tuileTrax->flip << endl;
        bg_tuile.setTextureRect(IntRect(150,0, 150, 150));
    }else{
        //cout << "non" << endl;
        bg_tuile.setTextureRect(IntRect(0,0, 150, 150));
    }
    bg_tuile.setPosition(getPosition());
    bg_tuile.setOrigin(75,75);
    bg_tuile.setRotation(tuileTrax->rotation);
    target.draw(bg_tuile);
}

TuileTraxObjView::~TuileTraxObjView() {
    cout << "destruction obj tuileTrax" << endl;

}

TuileTraxObjView::TuileTraxObjView(TuileTrax * trax) : tuileTrax{trax}, bg_tuile{*(new Sprite())}, texture{*new Texture()}{
    texture.loadFromFile("../ressources/img/plateau/tuileTrax.png");
    texture.setSmooth(true);
    bg_tuile.setTexture(texture);

}
