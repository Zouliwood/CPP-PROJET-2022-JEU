#include "../../../../hrc/view/obj/composant/BackGroundObjView.h"

BackGroundObjView::BackGroundObjView() {

}

void BackGroundObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    ComposantView::draw(target, states);

}

BackGroundObjView::~BackGroundObjView() {
    delete &background_plateau;
}
