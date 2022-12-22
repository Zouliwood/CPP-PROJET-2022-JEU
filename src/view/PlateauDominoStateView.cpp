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
    tuileEnMain{tuileEnMainObj},
    tuileDominoNul{new TuileDominos(*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)))},
    tuileNul{TuileDominosObjView(tuileDominoNul)}
{
    init();
}

PlateauDominoStateView::~PlateauDominoStateView() {

}

void PlateauDominoStateView::init() {

    cout << "construction " << endl;

    plateau.placeFirstTuile();
   // tuileEnMainObj = plateau.generateRandomTuile();
  //  tuileDominoNul = new TuileDominos(*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)));
   // tuileNul = TuileDominosObjView(tuileDominoNul);
    cout << "placement  " << endl;

    parent.move(550, 200);
    bouton_defausser.setPosition(30, 600);
    bouton.setPosition(30, 470);
    tuileEnMain.setPosition(550, 540);

    shape.setFillColor(Color::Black);
    shape.setPosition(0, 450);
    textMaTuile.setPosition(540, 510);
    positionText.setPosition(0, 20);
    cout << "good ?" << endl;
    miseAJourPlateauView(&plateau, &parent, tuileNul);
    cout << "good ?" << endl;

}

void PlateauDominoStateView::processInput(Event &event) {

    if(event.type == sf::Event::KeyReleased)notKeyPressedGame = true;

    if (Keyboard::isKeyPressed(Keyboard::Right))  {
        if(notKeyPressedGame){
            notKeyPressedGame = false;
            parent.move(151, 0);
            parent.updateBackGround(150, 0);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))  {
        if(notKeyPressedGame){
            notKeyPressedGame = false;
            parent.move(-151, 0);
            parent.updateBackGround(150, 0);

        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))   {
        if(notKeyPressedGame){
            notKeyPressedGame = false;
            parent.move(0, -151);
            parent.updateBackGround(0, 150);
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))   {
        if(notKeyPressedGame){
            notKeyPressedGame = false;
            parent.move(0, 151);
            parent.updateBackGround(0, 150);
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
            }else{//TODO: verifier si le plateau est clické
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

void PlateauDominoStateView::miseAJourPlateauView(PlateauDominos * plateau, TuileView * parent, TuileDominosObjView tuileNul) {

    auto pos = plateau->getListTuile().getPositif();
    auto neg = plateau->getListTuile().getNegatif();

    cout << "Coter positif grand tableau Positif " << pos.size() << endl;
    for (int i = 0; i < pos.size(); ++i) { // colonne
        for (int j = pos.at(i)->getNegatif().size() - 1; j >= 0; --j) { //les lignes*
            auto tuile = ((TuileDominos *) pos.at(i)->getNegatif().at(j));
            if (tuile == nullptr) {
                parent->addDrawable(j * 151, -i * 151, &tuileNul);
            } else {
                auto tuileDominosObjView4 = new TuileDominosObjView(tuile);
                parent->addDrawable(j * 151, -i * 151, tuileDominosObjView4);
            }
        }
        for (int j = 0; j < pos.at(i)->getPositif().size(); ++j) {
            auto tuile = ((TuileDominos *) pos.at(i)->getPositif().at(j));
            if (tuile == nullptr) {
                parent->addDrawable(j * 151, i * 151, &tuileNul);
            } else {
                auto tuileDominosObjView4 = new TuileDominosObjView(tuile);
                parent->addDrawable(j * 151, i * 151, tuileDominosObjView4);
                cout << "######################## " << i << j << endl;
            }
        }
    }
    cout << "Coter Grand tableau Negatif : " << neg.size() << endl;
    for (int i = neg.size() - 1; i >= 0; --i) {
        for (int j = neg.at(i)->getNegatif().size() - 1; j >= 0; --j) {
            auto tuile = ((TuileDominos *) neg.at(i)->getNegatif().at(j));
            if (tuile == nullptr) {
                parent->addDrawable(-j * 151, -i * 151, &tuileNul);
            } else {
                auto tuileDominosObjView4 = new TuileDominosObjView(tuile);
                parent->addDrawable(-j * 151, -i * 151, tuileDominosObjView4);
            }
        }

        for (int j = 0; j < neg.at(i)->getPositif().size(); ++j) {
            auto tuile = ((TuileDominos *) neg.at(i)->getPositif().at(j));
            if (tuile == nullptr) {
                parent->addDrawable(-j * 151, i * 151, &tuileNul);
            } else {
                auto tuileDominosObjView4 = new TuileDominosObjView(tuile);
                parent->addDrawable(-j + 151, i * 151, tuileDominosObjView4);
            }
        }
    }
}