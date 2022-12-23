#include "TuileDominosObjView.h"

TuileDominosObjView::TuileDominosObjView(TuileDominos * tuile) : tuileDominos{tuile}, shape(RectangleShape(Vector2f(150.0f,150.0f))){

    string up = to_string(tuile->getUp().getFragmentGauche())  + to_string(tuile->getUp().getFragmentCentre()) + to_string(tuile->getUp().getFragmentDroit());
    string down = to_string(tuile->getDown().getFragmentGauche()) + to_string(tuile->getDown().getFragmentCentre()) + to_string(tuile->getDown().getFragmentDroit());
    string left = to_string(tuile->getLeft().getFragmentGauche()) + "\n"+  to_string(tuile->getLeft().getFragmentCentre()) + "\n"+ to_string(tuile->getLeft().getFragmentDroit());
    string right = to_string(tuile->getRight().getFragmentGauche()) + "\n" +to_string(tuile->getRight().getFragmentCentre())  +"\n"+ to_string(tuile->getRight().getFragmentDroit());

    textUp = createText(up,20, Color::Black );
    textDown = createText(down, 20, Color::Black );
    textLeft = createText(left, 20, Color::Black );
    textRight = createText(right, 20, Color::Black );

}

void TuileDominosObjView::draw(RenderTarget &target, sf::RenderStates states) const { TuileView::draw(target, states);
    shape.setPosition(getPosition());
    updateTuile();
    updatePosition();
    target.draw(shape);
    target.draw(textUp);
    target.draw(textDown);
    target.draw(textRight);
    target.draw(textLeft);

}
void TuileDominosObjView::updatePosition()const{
    textUp.setPosition(getPosition().x + 45, getPosition().y + 10 ); // à changer par setOrigin();//
    textDown.setPosition(getPosition().x + 45, getPosition().y + 120);
    textRight.setPosition(getPosition().x + 120, getPosition().y+25);
    textLeft.setPosition(getPosition().x + 10, getPosition().y+25);
}

void TuileDominosObjView::updateTuile() const{
    string up = to_string(tuileDominos->getUp().getFragmentGauche())  + to_string(tuileDominos->getUp().getFragmentCentre()) + to_string(tuileDominos->getUp().getFragmentDroit());
    string down = to_string(tuileDominos->getDown().getFragmentGauche()) + to_string(tuileDominos->getDown().getFragmentCentre()) + to_string(tuileDominos->getDown().getFragmentDroit());
    string left = to_string(tuileDominos->getLeft().getFragmentGauche()) + "\n"+  to_string(tuileDominos->getLeft().getFragmentCentre()) + "\n"+ to_string(tuileDominos->getLeft().getFragmentDroit());
    string right = to_string(tuileDominos->getRight().getFragmentGauche()) + "\n" +to_string(tuileDominos->getRight().getFragmentCentre())  +"\n"+ to_string(tuileDominos->getRight().getFragmentDroit());

    textUp.setString(up);
    textDown.setString(down);
    textLeft.setString(left);
    textRight.setString(right);
};

TuileDominosObjView::~TuileDominosObjView() {

}
/*
void TuileDominosObjView::setTuile(TuileDominos *newtuile) {
    this->tuileDominos = *newtuile;
}*/


