#include "../../../../hrc/view/obj/composant/ButtonObj.hpp"

ButtonObj::ButtonObj(string string) : ComposantView{}, fond_image{*new Sprite()}, texture{*new Texture()}{
    texture.loadFromFile("../ressources/img/menu/image_bg_menu.png");
    textbutton = createText(string,18, Color::White);
    texture.setRepeated(true);
    texture.setSmooth(true);
    fond_image.setTexture(texture);
    fond_image.setTextureRect(IntRect{16,747,200,80});

}

ButtonObj::~ButtonObj() {
    delete &textbutton;
    delete &fond_image;
}

void ButtonObj::toPressed(){
    button_status = PRESSED;
}
void ButtonObj::unPressed(){
    button_status = IDLE;
}

void ButtonObj::update(Vector2f mouse) {
    button_status = IDLE;
    if(fond_image.getGlobalBounds().contains(mouse)){
        button_status = HOVER;
        if(Mouse::isButtonPressed(Mouse::Left)){
            button_status = PRESSED;
        }
    }
    updateGraphique();
}


void ButtonObj::updateGraphique(){
    switch (button_status) {
        case IDLE:
            textbutton.setScale(Vector2f(1, 1));
            fond_image.setTextureRect(IntRect{16,747,200,80});
            break;
        case HOVER:
            fond_image.setTextureRect(IntRect{223,747,200,80});
            break;
        case PRESSED:
            textbutton.setScale(Vector2f(0.9, 0.9));
            fond_image.setTextureRect(IntRect{430,747,200,80});
            break;
    }
}

bool ButtonObj::isPressed() const{
    return button_status == PRESSED;
}

void ButtonObj::draw(RenderTarget &target, sf::RenderStates states) const {
    ComposantView::draw(target, states);
    fond_image.setPosition(getPosition());
    textbutton.setPosition(getPosition().x + 40, getPosition().y + 25); // à changer par setOrigin();//
    target.draw(fond_image);
    target.draw(textbutton);
}

