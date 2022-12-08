#include "TuileDominosObjView.h"

TuileDominosObjView::TuileDominosObjView(TuileDominos &tuile) : tuileDominos{tuile}, shape(RectangleShape(Vector2f(250.0f,250.0f))){
    font.loadFromFile("../Agatha.ttf");
    textDown.setString("[1, 5, 6]");
    textDown.setFont(font);
    textDown.setFillColor(Color::Blue);
    shape.setFillColor(Color::White);
}

void TuileDominosObjView::draw(RenderTarget &target, sf::RenderStates states) const { TuileView::draw(target, states);
    shape.setPosition(getPosition());
    textDown.setPosition(getPosition());
    target.draw(shape);
    target.draw(textDown);
}


