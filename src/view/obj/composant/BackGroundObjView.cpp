//
// Created by root0 on 23/12/22.
//

#include "../../../../hrc/view/obj/composant/BackGroundObjView.h"

BackGroundObjView::BackGroundObjView() {

}

void BackGroundObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    ComposantView::draw(target, states);

}

BackGroundObjView::~BackGroundObjView() {
    delete &background_plateau;
    delete &texture_background;
}
