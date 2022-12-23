//
// Created by root0 on 22/12/22.
//

#include "PlateauDominoStateView.h"


PlateauDominoStateView::PlateauDominoStateView(RenderWindow &window, stack<State *> * stack_display) :
    app{window},
    stack_display{*stack_display},
    plateau{*new PlateauDominos()},
    parent{*new PlateauObjView()},
    bouton_defausser{*new ButtonObj("defausser")},
    bouton{*new ButtonObj("rotation")},
    shape{*new RectangleShape(Vector2f (1280, 270))},
    textMaTuile{TuileView::createText("Ma tuile", 23, Color::White)},
    positionText{TuileView::createText("x : y : ", 12, Color::White)},
    tuileEnMainObj{plateau.generateRandomTuile()},
    tuileEnMain{tuileEnMainObj}
{
    init();
}

PlateauDominoStateView::~PlateauDominoStateView() {

}

void PlateauDominoStateView::init() {
    plateau.placeFirstTuile();
    parent.move(550, 200);
    bouton_defausser.setPosition(30, 600);
    bouton.setPosition(30, 470);
    tuileEnMain.setPosition(550, 540);
    shape.setFillColor(Color::Black);
    shape.setPosition(0, 450);
    textMaTuile.setPosition(540, 510);
    positionText.setPosition(0, 20);
    TuileDominosObjView * firstTuileDomino = new TuileDominosObjView( plateau.getFirstTuilePose());
    parent.addDrawable(0,0, firstTuileDomino);
}

void PlateauDominoStateView::processInput(Event &event) {

    if(event.type == sf::Event::KeyReleased)notKeyPressedGame = true;

    if (Keyboard::isKeyPressed(Keyboard::Right))  {
        if(notKeyPressedGame){
            notKeyPressedGame = false;
            parent.move(151, 0);
            parent.updateBackGround(150, 0, mousePosGrid.x, mousePosGrid.y);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))  {
        if(notKeyPressedGame){
            notKeyPressedGame = false;
            parent.move(-151, 0);
            parent.updateBackGround(150, 0, mousePosGrid.x, mousePosGrid.y);

        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))   {
        if(notKeyPressedGame){
            notKeyPressedGame = false;
            parent.move(0, -151);
            parent.updateBackGround(0, 150, mousePosGrid.x, mousePosGrid.y);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))   {
        if(notKeyPressedGame){
            notKeyPressedGame = false;
            parent.move(0, 151);
            parent.updateBackGround(0, 150, mousePosGrid.x, mousePosGrid.y);
        }
    }
    if (event.type == sf::Event::MouseButtonReleased) pressedGame = true;

    if(Mouse::isButtonPressed(Mouse::Left)) {
        if(pressedGame){
            pressedGame= false;
            if(bouton.isPressed()){
                tuileEnMainObj->rotate();
            }if(bouton_defausser.isPressed()) {
                tuileEnMainObj = plateau.generateRandomTuile();
                tuileEnMain.tuileDominos = tuileEnMainObj;
                tuileEnMain.updateTuile();
            }else{
                if(plateau.placeTuile(tuileEnMainObj, mousePosGrid.x, mousePosGrid.y)){
                    TuileDominosObjView *tuileAdd = new TuileDominosObjView(tuileEnMainObj);
                    parent.addDrawable(mousePosGrid.x *151, mousePosGrid.y *151, *(&tuileAdd));
                    tuileEnMainObj = plateau.generateRandomTuile();
                    tuileEnMain.tuileDominos = tuileEnMainObj;
                    tuileEnMain.updateTuile();
                }
            }
        }
    }
}

void PlateauDominoStateView::update() {
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

void PlateauDominoStateView::drawView() {
    app.clear(sf::Color::Magenta);
    app.draw(parent);
    app.draw(shape);
    app.draw(tuileEnMain);
    app.draw(textMaTuile);
    app.draw(positionText);
    app.draw(bouton);
    app.draw(bouton_defausser);
}
