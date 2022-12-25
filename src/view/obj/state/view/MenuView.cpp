#include "../../../../../hrc/view/obj/state/view/MenuView.h"
#include "../../../../../hrc/view/obj/state/view/SettingsStateView.h"
#include "../../../../../hrc/view/obj/state/view/PlateauTraxStateView.h"

void MenuView::processInput(sf::Event & event) {

    if (event.type == sf::Event::MouseButtonReleased) pressedGame = true;
    if (event.type == sf::Event::KeyReleased) pressedGame = true;

    if(Mouse::isButtonPressed(Mouse::Left)) {
        if(pressedGame){
            pressedGame= false;
            if (buttonDomino.isPressed()) {
                if(statgame == CARCASSONNE){
                    stack_display->push(new SettingsStateView(app, stack_display));
                }else if(statgame == DOMINO){
                    stack_display->push(new SettingsStateView(app, stack_display));
                }else if(statgame == TRAX){
                    stack_display->push(new PlateauTraxStateView(app, stack_display));
                }
            }else if (button_precedent.isPressed()) {
                if(statgame == DOMINO){
                    background.setTextureRect(IntRect {0,0, 1280, 720});
                    statgame = TRAX;
                }else if(statgame == CARCASSONNE){
                    background.setTextureRect(IntRect {1280,0, 1280, 720});
                    statgame = DOMINO;
                }else {
                    background.setTextureRect(IntRect{2*1280, 0, 1280, 720});
                    statgame = CARCASSONNE;
                }
            }else if(button_suivant.isPressed()){
                if(statgame == DOMINO){
                    background.setTextureRect(IntRect {1280*2,0, 1280, 720});
                    statgame = CARCASSONNE;
                }else if(statgame == CARCASSONNE){
                    background.setTextureRect(IntRect {0,0, 1280, 720});
                    statgame = TRAX;
                }else {
                    background.setTextureRect(IntRect{1280, 0, 1280, 720});
                    statgame = DOMINO;
                }
            }
        }
    }
    if(pressedGame) {
        pressedGame = false;
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (statgame == DOMINO) {
                background.setTextureRect(IntRect{1280 * 2, 0, 1280, 720});
                statgame = CARCASSONNE;
            } else if (statgame == CARCASSONNE) {
                background.setTextureRect(IntRect{0, 0, 1280, 720});
                statgame = TRAX;
            } else {
                background.setTextureRect(IntRect{1280, 0, 1280, 720});
                statgame = DOMINO;
            }
        } else if (Keyboard::isKeyPressed(Keyboard::Left)) {
            if (statgame == DOMINO) {
                background.setTextureRect(IntRect{0, 0, 1280, 720});
                    statgame = TRAX;
            } else if (statgame == CARCASSONNE) {
                background.setTextureRect(IntRect{1280, 0, 1280, 720});
                statgame = DOMINO;
            } else {
                background.setTextureRect(IntRect{2 * 1280, 0, 1280, 720});
                statgame = CARCASSONNE;
            }
        }else if(Keyboard::isKeyPressed(Keyboard::Enter)){
            if(statgame == CARCASSONNE){
                stack_display->push(new SettingsStateView(app, stack_display));
            }else if(statgame == DOMINO){
                stack_display->push(new SettingsStateView(app, stack_display));
            }else if(statgame == TRAX){
                stack_display->push(new PlateauTraxStateView(app, stack_display));
            }
        }
    }
}

void MenuView::update() {
    buttonDomino.update(Vector2f(Mouse::getPosition(app)));
    button_precedent.update(Vector2f(Mouse::getPosition(app)));
    button_suivant.update(Vector2f(Mouse::getPosition(app)));
}

void MenuView::drawView() {
    app.clear(sf::Color::Black);
    app.draw(background);
    app.draw(button_suivant);
    app.draw(button_precedent);
    app.draw(buttonDomino);
}

MenuView::MenuView(sf::RenderWindow & window, stack<State * > * stack_display) :
    app{window},
    stack_display{stack_display},
    statgame{TRAX},
    buttonDomino{*new ButtonObj("Enter")},
    button_precedent{*new ButtonObj("     <")},
    button_suivant{*new ButtonObj("     >")},
    background{*new Sprite()},
    texture_bg{*new Texture()}
    {
    init();
}

MenuView::~MenuView() {
    delete &buttonDomino;
    delete &button_precedent;
    delete &button_suivant;
    delete &background;
    delete &texture_bg;
}

void MenuView::init() {
    button_suivant.setPosition(1000, 600);
    button_precedent.setPosition(20, 600);
    buttonDomino.setPosition(525, 350);
    texture_bg.loadFromFile("../ressources/img/menu/image_bg_menu.png");
    texture_bg.setSmooth(true);
    background.setTexture(texture_bg);
}

