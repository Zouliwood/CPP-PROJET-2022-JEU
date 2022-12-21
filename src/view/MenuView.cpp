#include "MenuView.h"


void MenuView::processInput(sf::Event & event) {
    buttonDomino.update(Vector2f(Mouse::getPosition(app)));

    if(Mouse::isButtonPressed(Mouse::Left)) {
        if (pressedGame) {
            pressedGame = false;
            if (buttonDomino.isPressed()) {
                cout << "click" << endl;
                DominoStateView dominoParty{app};
                stack_display.push(&dominoParty);
                cout << "on sort correctement"  << stack_display.size() << endl;
                pressedGame = true;
            }
        }
    }
}

void MenuView::update() {

}

void MenuView::draw() {
    app.clear(sf::Color::Magenta);
    app.draw(centerText);
    app.draw(buttonDomino);
}

MenuView::MenuView(sf::RenderWindow & window, stack<State * > & stack_display) : app{window},
    stack_display{stack_display}, buttonDomino{"Domino"}, centerText{TuileView::createText("Jeu video", 50, Color::Black)}{
    //init ici;
    centerText.setPosition(500, 150);
    buttonDomino.setPosition(500, 300);
}

