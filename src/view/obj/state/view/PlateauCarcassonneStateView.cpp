#include "../../../../../hrc/view/obj/state/view/PlateauCarcassonneStateView.hpp"

PlateauCarcassonneStateView::PlateauCarcassonneStateView(RenderWindow &window, stack<State *> * stack_display, ControllerCarcassonne  & controllerCarcassonne) :
        app{window},
        stack_display{stack_display},
        controllerCarcassonne{controllerCarcassonne},
        gridSizeF{150.0f},
        grideSizeU{static_cast<int>(gridSizeF)},
        pressedGame{true},
        notKeyPressedGame{true},
        parent{*new PlateauObjView()},
        bouton_defausser{*new ButtonObj("defausser")},
        bouton{*new ButtonObj("rotation")},
        shape{*new RectangleShape(Vector2f (1280, 270))},
        textMaTuile{ComposantView::createText("Ma tuile", 23, Color::White)},
        positionText{ComposantView::createText("x : y : ", 12, Color::White)},
        tuileEnMainObjView{(TuileCarcassonne *) this->controllerCarcassonne.getTuileJoueurQuiJoue()},
        panelPion{new PanelPionObjView(new TuileCarcassonneObjView((TuileCarcassonne *) this->controllerCarcassonne.getTuileJoueurQuiJoue()))}
{
    init();
}

PlateauCarcassonneStateView::~PlateauCarcassonneStateView() {
    delete &parent;
    delete &bouton;
    delete &bouton_defausser;
    delete &tuileEnMainObjView;
    delete &shape;
    delete &textMaTuile;
    delete &positionText;
    delete panelPion;
}

void PlateauCarcassonneStateView::init() {
    controllerCarcassonne.getPlateau()->placeFirstTuile();
    parent.move(550, 200);
    bouton_defausser.setPosition(30, 600);
    bouton.setPosition(30, 470);
    shape.setFillColor(Color::Black);
    shape.setPosition(0, 450);
    textMaTuile.setPosition(540, 510);
    positionText.setPosition(0, 20);
    tuileEnMainObjView.setPosition(550+75, 540+75);
    TuileCarcassonneObjView * firstTuileDomino = new TuileCarcassonneObjView(controllerCarcassonne.getPlateau()->getFirstTuilePose());
    parent.addDrawable(75,75, firstTuileDomino);
}

void PlateauCarcassonneStateView::processInput(Event &event) {
    panelPion->updateAction(Vector2f(Mouse::getPosition(app)), event);
    parent.updateEvent(event, Mouse::getPosition(app));
    if (event.type == sf::Event::KeyReleased)notKeyPressedGame = true;

    if(!panelPion->isOpen()){
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            if (notKeyPressedGame) {
                notKeyPressedGame = false;
                parent.move(151, 0);
                parent.updateBackGround(150, 0, mousePosGrid.x, mousePosGrid.y);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            if (notKeyPressedGame) {
                notKeyPressedGame = false;
                parent.move(-151, 0);
                parent.updateBackGround(150, 0, mousePosGrid.x, mousePosGrid.y);

            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (notKeyPressedGame) {
                notKeyPressedGame = false;
                parent.move(0, -151);
                parent.updateBackGround(0, 150, mousePosGrid.x, mousePosGrid.y);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            if (notKeyPressedGame) {
                notKeyPressedGame = false;
                parent.move(0, 151);
                parent.updateBackGround(0, 150, mousePosGrid.x, mousePosGrid.y);
            }
        }
        if (event.type == sf::Event::MouseButtonReleased) pressedGame = true;

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (pressedGame) {
                pressedGame = false;
                if (bouton.isPressed()) {
                    controllerCarcassonne.getPlateau()->getPlayerCourant()->getTuile()->rotate();
                     tuileEnMainObjView.updateTuile();
                } else if (bouton_defausser.isPressed()) {
                    controllerCarcassonne.defausserTuile();
                    tuileEnMainObjView.setTuile(controllerCarcassonne.getTuileJoueurQuiJoue());
                }
            } else {
                if (controllerCarcassonne.placerTuile(controllerCarcassonne.getTuileJoueurQuiJoue(), mousePosGrid.x, mousePosGrid.y * -1)) {
                    parent.addDrawable(mousePosGrid.x * 151 + 75, mousePosGrid.y * 151 + 75, new TuileCarcassonneObjView(controllerCarcassonne.getTuileJoueurQuiJoue()));
                    panelPion->show(controllerCarcassonne.getTuileJoueurQuiJoue());
                    int pos_partisant = panelPion->getPartisantPos();
                    //ici le gars clické
                    cout << pos_partisant << endl;

                    if(panelPion->isWantToPosPartisant()){
                        cout << "on entre " << endl;
                        //plateau.pionPresent(mousePosGrid.x, mousePosGrid.y , pos_partisant, environment);
                    }
                    controllerCarcassonne.suivantJoueur();
                    tuileEnMainObjView.setTuile(controllerCarcassonne.getTuileJoueurQuiJoue());
                }
            }
        }
    }
}

void PlateauCarcassonneStateView::update() {
    bouton_defausser.update(Vector2f(Mouse::getPosition(app)));
    bouton.update(Vector2f(Mouse::getPosition(app)));

    mousePosWindow = Vector2<float>(Mouse::getPosition(app));
    mousePosView = app.mapPixelToCoords(Vector2i(mousePosWindow));

    if((mousePosView.x - parent.getPosition().x) >= 0 && (mousePosView.y - parent.getPosition().y) >= 0 ){
        mousePosGrid.x = (mousePosView.x - parent.getPosition().x)/ grideSizeU;
        mousePosGrid.y = (mousePosView.y - parent.getPosition().y)/ grideSizeU;
    } else if ((mousePosView.x - parent.getPosition().x) < 0 && (mousePosView.y - parent.getPosition().y) < 0 ){
        mousePosGrid.x = ((mousePosView.x - parent.getPosition().x) / grideSizeU)-1;
        mousePosGrid.y = ((mousePosView.y - parent.getPosition().y) / grideSizeU) -1;
    }else if ((mousePosView.x - parent.getPosition().x) < 0){
        mousePosGrid.x = ((mousePosView.x - parent.getPosition().x) / grideSizeU) -1;
        mousePosGrid.y = (mousePosView.y - parent.getPosition().y)/ grideSizeU ;
    }else if ((mousePosView.y - parent.getPosition().y) < 0){
        mousePosGrid.x = (mousePosView.x - parent.getPosition().x)/ grideSizeU;
        mousePosGrid.y = ((mousePosView.y - parent.getPosition().y)/ grideSizeU) -1;
    }

    positionText.setString(to_string(mousePosGrid.x) + " " + to_string(mousePosGrid.y)); //+ " / " + to_string(mousePosWindow.x) + " " + to_string(mousePosWindow.y) + " / " + to_string(mousePosView.x) + " " + to_string(mousePosView.y) );
}

void PlateauCarcassonneStateView::drawView() {
    app.clear(sf::Color::Black);
    app.draw(parent);
    app.draw(shape);
    app.draw(tuileEnMainObjView);
    app.draw(textMaTuile);
    app.draw(positionText);
    app.draw(bouton);
    app.draw(bouton_defausser);
    app.draw(*panelPion);
}