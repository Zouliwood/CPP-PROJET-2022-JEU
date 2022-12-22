#include "SettingsStateView.h"
#include "PlateauDominoStateView.h"

SettingsStateView::~SettingsStateView() {
    delete &nombre_j;
    delete &nombre_tuile;
    delete &jouer;
    delete background.getTexture();
    delete &background;
}

void SettingsStateView::processInput(sf::Event & event) {
    if (event.type == sf::Event::MouseButtonReleased) jouer.swipeAlsgoPressed();

    if(Mouse::isButtonPressed(Mouse::Left)) {
        if (jouer.getAlsoPressed()) {
            jouer.swipeAlsgoPressed();
            if(jouer.isPressed()){
                stack_display->push(new PlateauDominoStateView(app, stack_display));
                cout << "stack setting " << stack_display->size() << endl;
                jouer.swipeAlsgoPressed();
            }
        }
    }
}

void SettingsStateView::update() {
    jouer.update(Vector2f(Mouse::getPosition(app)));
}

void SettingsStateView::drawView() {
    app.clear(sf::Color::Black);
    app.draw(background);
    app.draw(nombre_tuile);
    app.draw(nombre_j);
    app.draw(jouer);
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
    jouer.setPosition(500, 500);
    nombre_tuile.setString("Nombre de tuile");
    nombre_j.setString("Nombre de joueur");
    nombre_j.setPosition(500, 300);
    nombre_tuile.setPosition(500, 400);
}

SettingsStateView::SettingsStateView(RenderWindow & window, std::stack<State * > * stack_display) :
                app{window},
                stack_display{stack_display},
                nombre_j{TuileView::createText("", 20, Color(236, 168, 48))},
                nombre_tuile{TuileView::createText("", 20, Color(236, 168, 48))},
                jouer{*new ButtonObj("Jouer")},
                background{*new Sprite()}{
    init();
}


