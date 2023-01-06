#include "../../../../hrc/view/obj/plateau/PionObjView.hpp"


PionObjView::PionObjView(): partisant(*new CircleShape(15)) {
    partisant.setFillColor(Color(0,0,0,0));
}

void PionObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    ComposantView::draw(target, states);
    partisant.setPosition(getPosition());
    target.draw(partisant);
}
void PionObjView::setColor(int r, int g, int b){
    partisant.setFillColor(Color(r,g,b));
}
