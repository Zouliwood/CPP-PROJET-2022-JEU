#include "PanelPionObjView.hpp"


PanelPionObjView::PanelPionObjView(TuileCarcassonneObjView * tuileCarcassonneObjView):
    tuilEnMain{tuileCarcassonneObjView},
    panel(*new RectangleShape(Vector2f(600,380))),
    annuler{new ButtonObj("Annuler")},
    isOpenStatus{false},
    zone{*new Sprite()},
    texture{*new Texture()},
    text(createText("Placement d'un partisant", 20, Color::White)){

    panel.setPosition(-500, -500);
    panel.setFillColor(Color::Black);
    text.setPosition(-500, -500);
    addDrawable(250, 50, tuilEnMain);
    addDrawable(150, 150, annuler);
    setPosition(-500, -500);

}
PanelPionObjView::~PanelPionObjView(){
    delete annuler;
    delete &text;
}

void PanelPionObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    target.draw(panel);
    ComposantView::draw(target, states);
    target.draw(text);
}

void PanelPionObjView::show(TuileCarcassonne * tuile) {
    tuilEnMain->tuileCarcassonne = tuile;
    setPosition(380, 150);
    text.setPosition(400, 50);
    panel.setPosition(330, 20);
    isOpenStatus = true;

}
void PanelPionObjView::hide() {
    setPosition(-500, -500);
    panel.setPosition(-500, -500);
    text.setPosition(-500, -500);
    isOpenStatus = false;
}

void PanelPionObjView::updateAction(Vector2f mouse) {
    annuler->update(mouse);
    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (annuler->isPressed()) {
            hide();
        }
    }
}

bool PanelPionObjView::isOpen() {
    return isOpenStatus;
}
