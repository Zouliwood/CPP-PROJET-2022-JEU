#include "../../../../hrc/view/obj/plateau/PanelPionObjView.hpp"

PanelPionObjView::PanelPionObjView(TuileCarcassonneObjView * tuileCarcassonneObjView, ControllerCarcassonne & controllerCarcassonne, TuileCarcassonneObjView * t):
    tuilEnMain{tuileCarcassonneObjView},
    annuler{new ButtonObj("Annuler")},
    valider{new ButtonObj("Valider")},
    panel{(*new RectangleShape(Vector2f(600,380)))},
    text{createText("     Placement d'un partisant \n Utilisez Up ou Down pour choisir", 16, Color::White)},
    position{createText("0", 20, Color::White)},
    isOpenStatus{false},
    pressedGame{true},
    pressedGameMouse{true},
    texture{*new Texture()},
    zone{*new Sprite()},
    position_value{0},
    posx{0},
    posy{0},
    controllerCarcassonne{controllerCarcassonne},
    tuiledejaplace{t},
    tuileCarcassonneObjView{tuileCarcassonneObjView},
    tuileEnmain{t}{
            texture.loadFromFile("ressources/img/menu/image_bg_menu.png");
    zone.setTexture(texture);
    zone.setTextureRect(IntRect(0, 850, 150,150));
    zone.setPosition(-500, -500);
    panel.setPosition(-500, -500);
    panel.setFillColor(Color(10, 10, 10, 230));
    panel.setOutlineColor(Color::Black);
    text.setPosition(-500, -500);
    position.setPosition(-500, -500);
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

string envToStrings(environment e)
{
    switch (e)
    {
        case environment::ABAYES: return "ABAYES";
        case environment::INVALIDE: return "INVALIDE";
        case environment::VILLAGE: return "VILLAGE";
        case environment::CHAMPS: return "CHAMPS";
        case environment::ROUTE: return "ROUTE";
        default: return "error";
    }
}


void PanelPionObjView::show(TuileCarcassonne * tuile) {
    text.setString("     Placement d'un partisant \n Utilisez Up ou Down pour choisir");
    text.setFillColor(Color::White);
    tuilEnMain->tuileCarcassonne = tuile;
    tuilEnMain->updateTuile();
    setPosition(380, 150);
    text.setPosition(400, 50);
    position.setPosition(750, 200);
    panel.setPosition(330, 20);
    zone.setPosition(555, 125);
    isOpenStatus = true;
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

void PanelPionObjView::updateAction(Vector2f mouse, Event & event) {
    annuler->update(mouse);
    valider->update(mouse);
    if (event.type == sf::Event::KeyReleased)pressedGame = true;
    if (event.type == sf::Event::MouseButtonReleased)pressedGameMouse = true;

    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (pressedGameMouse) {
            pressedGameMouse = false;
            if (annuler->isPressed()) {
                controllerCarcassonne.suivantJoueur();
                tuileEnmain->setTuile(controllerCarcassonne.getTuileJoueurQuiJoue());
                hide();
            } else if (valider->isPressed()) {
                environment env = controllerCarcassonne.getTuileJoueurQuiJoue()->transformNumToEnv(position_value);
                if (!controllerCarcassonne.getPlateau()->pionPresent(posx, posy, position_value,env)){
                    Pion * p = controllerCarcassonne.getJoueurQuiJoue()->getPionLibre();
                    if (p != nullptr) {
                        p->updatePion(env, true ,posx, posy, position_value);
                        tuiledejaplace->placePartisant(position_value,
                                                       controllerCarcassonne.getJoueurQuiJoue()->getR(),
                                                       controllerCarcassonne.getJoueurQuiJoue()->getG(),
                                                       controllerCarcassonne.getJoueurQuiJoue()->getB());
                        controllerCarcassonne.suivantJoueur();
                        tuileEnmain->setTuile(controllerCarcassonne.getTuileJoueurQuiJoue());
                        hide();
                    }else{
                        text.setFillColor(Color::Red);
                        text.setString("Tous les partisans occupent \n un deja un poste.");
                    }
                } else {
                    text.setFillColor(Color::Red);
                    text.setString("          Zone deja occupe");
                }
            }
        }
    }
        if(Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(pressedGame) {
                pressedGame = false;
                position_value = (position_value + 1) % 16;
                position.setString(to_string(position_value));
            }
        }else if(Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(pressedGame) {
                pressedGame = false;
                if (position_value <= 0) position_value = 15;
                else position_value = (position_value - 1) % 16;
                position.setString(to_string(position_value));
            }
        }
    }


bool PanelPionObjView::isOpen() {
    return isOpenStatus;
}
void PanelPionObjView::updatePosition(int x, int y){
    posx = x;
    posy = y;
}

void PanelPionObjView::updateTuile(TuileCarcassonneObjView * t){
    tuiledejaplace = t;
}
