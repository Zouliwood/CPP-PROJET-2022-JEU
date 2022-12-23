#include "DominoStateView.h"


void DominoStateView::processInput(sf::Event & event) {
    //buttonDomino.update(Vector2f(Mouse::getPosition(app)));
    buttonDomino.update(Vector2f(Mouse::getPosition(app)));

}

void DominoStateView::update() {

}

void DominoStateView::drawView() {
    app.clear(sf::Color::Blue);
    app.draw(centerText);
    app.draw(buttonDomino);
}

DominoStateView::DominoStateView(sf::RenderWindow & window) : app{window},
    buttonDomino{"Domino"}, centerText{TuileView::createText("Domino", 50, Color::Black)}{

    //init ici;
    centerText.setPosition(500, 150);
    buttonDomino.setPosition(500, 300);

}

DominoStateView::~DominoStateView() {

}

