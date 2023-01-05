#include "../../../../../hrc/view/obj/state/view/SettingsStateView.hpp"
#include "../../../../../hrc/view/obj/state/view/PlateauDominoStateView.hpp"
#include "../../../../../hrc/view/obj/state/view/PlateauCarcassonneStateView.hpp"
#include "../../../../../hrc/controller/ControllerDominos.hpp"

SettingsStateView::~SettingsStateView() {
    delete &nombre_j;
    delete &nombre_tuile;
    delete &button_jouer;
    delete background.getTexture();
    delete &background;
    delete &button_plus_j;
    delete &button_moins_j;
    delete &button_plus_t;
    delete &button_moins_t;
}

void SettingsStateView::processInput(sf::Event & event) {
    if (event.type == sf::Event::MouseButtonReleased) pressedGame = true;
    if (event.type == sf::Event::KeyReleased) keyPressed = true;

    if(Mouse::isButtonPressed(Mouse::Left)) {
        if (pressedGame) {
            pressedGame = false;
            if(button_jouer.isPressed()){
                if(gameEnum == CARCASSONNE){
                    stack_display->push(new PlateauCarcassonneStateView(app, stack_display, *new ControllerCarcassonne(nombre_j_game, nombre_t_game)));
                }else{
                    stack_display->push(new PlateauDominoStateView(app, stack_display, *new ControllerDominos(nombre_j_game, nombre_t_game)));
                }
            }else if(button_moins_t.isPressed()){
                if(nombre_t_game > 10)nombre_t_game--;
            }else if(button_plus_t.isPressed()){
                if(nombre_t_game <= 120)nombre_t_game++;
            }else if(button_moins_j.isPressed()){
                if(nombre_j_game> 2)nombre_j_game--;
            }else if(button_plus_j.isPressed()){
                if(nombre_j_game < 5)nombre_j_game++;
            }
        }
    }
    if(Keyboard::isKeyPressed(sf::Keyboard::Enter)){
        if(keyPressed){
            keyPressed = false;
            stack_display->push(new PlateauCarcassonneStateView(app, stack_display, *new ControllerCarcassonne(nombre_j_game, nombre_t_game)));
        }
    }

    if(Keyboard::isKeyPressed(sf::Keyboard::LControl)){
        if(Keyboard::isKeyPressed(sf::Keyboard::Up)){
            if(keyPressed){
                keyPressed = false;
                if(nombre_t_game <= 120)nombre_t_game++;
            }
        }
        if(Keyboard::isKeyPressed(sf::Keyboard::Down)){
            if(keyPressed){
                keyPressed = false;
                if(nombre_t_game > 10)nombre_t_game--;
            }
        }
    }else if(Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(keyPressed){
            keyPressed = false;
            if(nombre_j_game < 5)nombre_j_game++;
        }
    }else if(Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(keyPressed){
            keyPressed = false;
            if(nombre_j_game> 2)nombre_j_game--;
        }
    }

    }

void SettingsStateView::update() {
    button_jouer.update(Vector2f(Mouse::getPosition(app)));
    button_plus_j.update(Vector2f(Mouse::getPosition(app)));
    button_moins_j.update(Vector2f(Mouse::getPosition(app)));
    button_plus_t.update(Vector2f(Mouse::getPosition(app)));
    button_moins_t.update(Vector2f(Mouse::getPosition(app)));
    nombre_tuile.setString("Nombre de tuile: " + to_string(nombre_t_game) );
    nombre_j.setString("Nombre de joueur : " + to_string(nombre_j_game));
}

void SettingsStateView::drawView() {
    app.clear(sf::Color::Black);
    app.draw(background);
    app.draw(nombre_j);
    app.draw(button_jouer);
    app.draw(button_moins_j);
    app.draw(button_plus_j);
    if(gameEnum == DOMINO){
        app.draw(nombre_tuile);
        app.draw(button_moins_t);
        app.draw(button_plus_t);
    }
}

void SettingsStateView::init() {
    Texture * textureBg = new Texture();
    textureBg->setSmooth(true);
    if(textureBg->loadFromFile("../ressources/img/setting/bg_settings.png")){
        background.setTexture(*textureBg);
    }else{
        cout << "erreur chargement des textures" << endl;
    }

    background.setOrigin(0,0);
    button_jouer.setPosition(550, 500);
    nombre_tuile.setString("Nombre de tuile: " + to_string(nombre_t_game) );
    nombre_j.setString("Nombre de joueur : " + to_string(nombre_j_game));
    nombre_j.setPosition(250, 300);
    nombre_tuile.setPosition(250, 400);
    button_moins_j.setPosition(650, 270);
    button_plus_j.setPosition(850, 270);
    button_moins_t.setPosition(650, 370);
    button_plus_t.setPosition(850, 370);
}

SettingsStateView::SettingsStateView(RenderWindow & window, std::stack<State * > * stack_display, StatGameEnum & gameEnum):
                gameEnum{gameEnum},
                app{window},
                stack_display{stack_display},
                nombre_j_game{2},
                nombre_t_game{16},
                pressedGame{true},
                keyPressed{true},
                nombre_j{ComposantView::createText("", 20, Color(236, 168, 48))},
                nombre_tuile{ComposantView::createText("", 20, Color(236, 168, 48))},
                button_jouer{*new ButtonObj(" Enter")},
                button_moins_j{*new ButtonObj("    [-]")},
                button_plus_j{*new ButtonObj("   [+]")},
                button_moins_t{*new ButtonObj("    [-]")},
                button_plus_t{*new ButtonObj("    [+]")},
                background{*new Sprite()}{
    init();
}


