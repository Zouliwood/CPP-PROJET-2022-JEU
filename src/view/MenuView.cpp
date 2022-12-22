#include "MenuView.h"
#include "SettingsStateView.h"

void MenuView::processInput(sf::Event & event) {
    if (event.type == sf::Event::MouseButtonReleased) pressedGame = true;

    if(Mouse::isButtonPressed(Mouse::Left)) {
        if (pressedGame) {
            pressedGame = false;
            if (buttonDomino.isPressed()) {
                stack_display->push(new SettingsStateView(app, stack_display));
                pressedGame = true;
            }
        }
    }
}

void MenuView::update() {
    buttonDomino.update(Vector2f(Mouse::getPosition(app)));

}

void MenuView::drawView() {
    app.clear(sf::Color::Magenta);
    app.draw(centerText);
    app.draw(buttonDomino);
}

MenuView::MenuView(sf::RenderWindow & window, stack<State * > * stack_display) :
    app{window},
    stack_display{stack_display}, buttonDomino{"Domino"},
    centerText{TuileView::createText("Jeu video", 50, Color::Black)}
    {
    init();
}

MenuView::~MenuView() {

}

void MenuView::init() {
    centerText.setPosition(500, 150);
    buttonDomino.setPosition(500, 300);
}

