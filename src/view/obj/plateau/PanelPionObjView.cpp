#include "../../../../hrc/view/obj/plateau/PanelPionObjView.hpp"

PanelPionObjView::PanelPionObjView(TuileCarcassonneObjView * tuileCarcassonneObjView):
    tuilEnMain{tuileCarcassonneObjView},
    panel(*new RectangleShape(Vector2f(600,380))),
    annuler{new ButtonObj("Annuler")},
    valider{new ButtonObj("Valider")},
    position_value{0},
    isWantToPos{false},
    isOpenStatus{false},
    pressedGame{true},
    pressedGameMouse{true},
    zone{*new Sprite()},
    texture{*new Texture()},
    text{createText("     Placement d'un partisant \n Utilisez Up ou Down pour choisir", 16, Color::White)},
    position{createText("0", 20, Color::White)}{
        texture.loadFromFile("../ressources/img/menu/image_bg_menu.png");
        zone.setTexture(texture);
        zone.setTextureRect(IntRect(0, 850, 150,150));
        zone.setPosition(-500, -500);
        panel.setPosition(-500, -500);
        panel.setFillColor(Color(10, 10, 10, 230));
        panel.setOutlineColor(Color::Black);
        text.setPosition(-500, -500);
        addDrawable(250, 50, tuilEnMain);
        addDrawable(250, 150, annuler);
        addDrawable(15, 150, valider);
        setPosition(-500, -500);
};

PanelPionObjView::~PanelPionObjView(){
    delete valider;
    delete annuler;
    delete &text;
    delete &zone;
}

void PanelPionObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    target.draw(panel);
    ComposantView::draw(target, states);
    target.draw(*tuilEnMain);
    target.draw(zone);
    target.draw(text);
    target.draw(position);

}

void PanelPionObjView::show(TuileCarcassonne * tuile) {
    tuilEnMain->tuileCarcassonne = tuile;
    tuilEnMain->updateTuile();
    setPosition(380, 150);
    text.setPosition(400, 50);
    position.setPosition(750, 200);
    panel.setPosition(330, 20);
    zone.setPosition(555, 125);
    isOpenStatus = true;
    isWantToPos = false;
    position_value = 0;
}
void PanelPionObjView::hide() {
    setPosition(-500, -500);
    panel.setPosition(-500, -500);
    text.setPosition(-500, -500);
    zone.setPosition(-500, -500);
    position.setPosition(-500, -500);
    isOpenStatus = false;
}

bool PanelPionObjView::isWantToPosPartisant(){
    return isWantToPos;
}

void PanelPionObjView::updateAction(Vector2f mouse, Event & event) {
    annuler->update(mouse);
    valider->update(mouse);
    if (event.type == sf::Event::KeyReleased)pressedGame = true;

    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (annuler->isPressed()) {
            hide();
            isWantToPos = false;
        }else if(valider->isPressed()){
            hide();
            isWantToPos = true;
        }
    }

    if(pressedGame){
        if(Keyboard::isKeyPressed(sf::Keyboard::Up)){
            position.setString(to_string(position_value));
            position_value = (position_value+1)%16;
        }else if(Keyboard::isKeyPressed(sf::Keyboard::Down)){
            position.setString(to_string(position_value));
            if(position_value <= 0) position_value = 15;
            else position_value = (position_value-1)%16;
        }
        pressedGame = false;
    }

}

bool PanelPionObjView::isOpen() {
    return isOpenStatus;
}

int PanelPionObjView::getPartisantPos() {
    return position_value;
}
