#include "TuileTraxObjView.h"

void TuileTraxObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    TuileView::draw(target, states);
    if(tuileTrax->flip == 1){
      //  cout << "oui" << tuileTrax->flip << endl;
        bg_tuile.setTextureRect(IntRect(150,rotation_recto, 150, 150));
    }else{
        //cout << "non" << endl;
        bg_tuile.setTextureRect(IntRect(0,rotation_verso, 150, 150));
    }
    bg_tuile.setPosition(getPosition());
    target.draw(bg_tuile);
}

TuileTraxObjView::~TuileTraxObjView() {
    cout << "destruction obj tuileTrax" << endl;

}

TuileTraxObjView::TuileTraxObjView(TuileTrax * trax, int verso, int recto) : tuileTrax{trax}, bg_tuile{*(new Sprite())}, texture{*new Texture()}{
    texture.loadFromFile("../ressources/img/plateau/tuileTrax.png");
    texture.setSmooth(true);
    bg_tuile.setTexture(texture);
    rotation_verso= verso;
    rotation_recto = recto;
    bg_tuile.setTextureRect(IntRect(0,rotation_verso, 150, 150));

}

void TuileTraxObjView::rotatationTuileObj(){
    if(tuileTrax->flip == 1){
        rotation_recto = (rotation_recto+150)%600;
    }else{
        rotation_verso = (rotation_verso+150)%600;
    }
}

void TuileTraxObjView::resetFlip(){
    rotation_recto = 0;
    rotation_verso = 0;
}
