#include "ButtonObj.h"

ButtonObj::ButtonObj(string string) {
    textbutton = createText(string,20, Color::Black);
    shape.setSize(Vector2f(250, 100));
}

ButtonObj::~ButtonObj() {
    delete &textbutton;
    delete &shape;
}

void ButtonObj::update(Vector2f mouse) {
    button_status = IDLE;
    if(shape.getGlobalBounds().contains(mouse)){
        button_status = HOVER;
        if(Mouse::isButtonPressed(Mouse::Left)){
            button_status = PRESSED;
        }
    }
    switch (button_status) {
        case IDLE:
            shape.setFillColor(Color::Red);
            break;
        case HOVER:
            shape.setFillColor(Color::Yellow);
            break;
        case PRESSED:
            shape.setFillColor(Color::Green);
            break;
    }
}

bool ButtonObj::isPressed() const{
    return button_status == PRESSED;
}

void ButtonObj::draw(RenderTarget &target, sf::RenderStates states) const {
    TuileView::draw(target, states);
    shape.setPosition(getPosition());
    textbutton.setPosition(getPosition().x + 50, getPosition().y + shape.getSize().y/2); // à changer par setOrigin();//
    target.draw(shape);
    target.draw(textbutton);
}

void ButtonObj::swipeAlsgoPressed() {
    alsoPressed = (!alsoPressed);
}

bool ButtonObj::getAlsoPressed() const {
    return alsoPressed;
}

