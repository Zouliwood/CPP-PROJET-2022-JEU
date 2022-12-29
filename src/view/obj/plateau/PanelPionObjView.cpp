#include "PanelPionObjView.hpp"


PanelPionObjView::PanelPionObjView(TuileCarcassonneObjView * tuileCarcassonneObjView):
    tuilEnMain{tuileCarcassonneObjView},
    panel(*new RectangleShape(Vector2f(300,300))),
    annuler{*new ButtonObj("Annuler")},
    text(createText("Placement d'un partisant", 20, Color::White)){
    panel.setPosition(-500, -500);
    panel.setFillColor(Color::Black);
    text.setPosition(-500, -500);
    addDrawable(0, 0, tuilEnMain);
    addDrawable(0, 300, &annuler);
    setPosition(-500, -500);

}
PanelPionObjView::~PanelPionObjView(){
    delete &annuler;
    delete &text;
}

void PanelPionObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    target.draw(panel);
    target.draw(text);
    ComposantView::draw(target, states);
}

void PanelPionObjView::show() {
    setPosition(350, 150);
    text.setPosition(330, 50);
    panel.setPosition(300, 20);

}
void PanelPionObjView::hide() {
    setPosition(-500, -500);
    panel.setPosition(-500, -500);
    text.setPosition(-500, -500);
}

void PanelPionObjView::updateAction(Vector2f mouse) {
    annuler.update(mouse);
    if(annuler.isPressed()){
        hide();
    }
}