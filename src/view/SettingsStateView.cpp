#include "SettingsStateView.h"
#include "PlateauDominoStateView.h"

SettingsStateView::~SettingsStateView() {
    delete &nombre_j;
    delete &nombre_tuile;
    delete &button_jouer;
    delete background.getTexture();
    delete &background;
}

void SettingsStateView::processInput(sf::Event & event) {
    if (event.type == sf::Event::MouseButtonReleased) pressedGame = true;

    if(Mouse::isButtonPressed(Mouse::Left)) {
        if (pressedGame) {
            pressedGame = false;
            if(button_jouer.isPressed()){

                stack_display->push(new PlateauDominoStateView(app, stack_display));
                cout << "stack setting " << stack_display->size() << endl;
            }else if(button_moins_t.isPressed()){
                if(nombre_t_game > 10)nombre_t_game--;
            }else if(button_plus_t.isPressed()){
                if(nombre_t_game <= 120)nombre_t_game++;
            }else if(button_moins_j.isPressed()){
                if(nombre_j_game> 2)nombre_j_game--;
            }else if(button_plus_j.isPressed()){
                if(nombre_j_game < 8)nombre_j_game++;
            }
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
    app.draw(nombre_tuile);
    app.draw(nombre_j);
    app.draw(button_jouer);
    app.draw(button_moins_j);
    app.draw(button_plus_j);
    app.draw(button_moins_t);
    app.draw(button_plus_t);
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

SettingsStateView::SettingsStateView(RenderWindow & window, std::stack<State * > * stack_display) :
                app{window},
                stack_display{stack_display},
                nombre_j{TuileView::createText("", 20, Color(236, 168, 48))},
                nombre_tuile{TuileView::createText("", 20, Color(236, 168, 48))},
                button_jouer{*new ButtonObj("Jouer")},
                button_moins_j{*new ButtonObj("    [-]")},
                button_plus_j{*new ButtonObj("   [+]")},
                button_moins_t{*new ButtonObj("    [-]")},
                button_plus_t{*new ButtonObj("    [+]")},
                background{*new Sprite()}{
    init();
}


