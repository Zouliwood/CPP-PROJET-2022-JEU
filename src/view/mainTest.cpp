/*#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../hrc/model/plateau/PlateauDominos.hpp"
#include "../../hrc/model/plateau/PlateauTrax.hpp"
#include "../../src/view/TuileView.h"
#include "../../src/view/obj/TuileDominosObjView.h"
#include "../../src/view/obj/ButtonObj.h"

using namespace sf;

void miseAJourPlateauView(PlateauDominos * plateau, TuileView * parent, TuileDominosObjView tuileNul) {

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



int main(){

    auto plateau = PlateauDominos();
    plateau.placeFirstTuile();
    cout << "FIn de placefirstTuile()" << endl;

    TuileDominos * tuileEnMainObj = plateau.generateRandomTuile();
    TuileDominos * tuileDominoNul = new TuileDominos(*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)),*(new FragmentTriple<int> (0,0,0)));
    auto tuileNul = TuileDominosObjView(tuileDominoNul);

    RectangleShape shape{Vector2f (1280, 270)};
    shape.setFillColor(Color::Black);
    shape.setPosition(0, 450);

    tuileEnMainObj->rotate();
    tuileEnMainObj->rotate();
//    plateau.placeTuile(tuileEnMainObj, 1, 0);
    //plateau.placeTuile(tuileEnMainObj, 0, 2);


    TuileView parent{};
    parent.move(550, 200);
    ButtonObj bouton{"Rotate"};
    ButtonObj bouton_defausser{"Defausser"};

    bouton_defausser.setPosition(30, 600);
    bouton.setPosition(30, 470);

    //bouton.setAction(f);

    TuileDominosObjView tuileEnMain{tuileEnMainObj};
    tuileEnMain.setPosition(550, 540);

    float gridSizeF = 150.0f;
    int grideSizeU = static_cast<int>(gridSizeF);

    Vector2f mousePosWindow;
    Vector2f mousePosView;
    Vector2i mousePosGrid;

    Text textMaTuile = TuileView::createText("Ma tuile", 23, Color::White);
    textMaTuile.setPosition(540, 510);

    miseAJourPlateauView(&plateau, &parent, tuileNul);

    Text positionText = TuileView::createText("x : y : ", 12, Color::White);
    positionText.setPosition(0, 20);
    RenderWindow app(VideoMode(1280, 720, 32), "Domino Trax Carcasonne");

    bool pressedGame = true;
    bool notKeyPressedGame = true;

    while (app.isOpen())
    {

        Event event;
        while (app.pollEvent(event))
            switch (event.type) {
                case Event::Closed:
                    app.close();
                    break;

                case Event::KeyPressed:
                    if (event.key.code==Keyboard::Return){
                        cout << "salut"  << endl;
                        //tuile-setPosition(0,0);
                    }
                    break;

                default:
                    break;
            }
        // fin du while

//        tuileRender.setPos(140,130);
        //    tuileRender.setPosition(100,0);
        // en dehors de la gestion des événements c'est plus fluide
        if(event.type == sf::Event::KeyReleased)notKeyPressedGame = true;

        if (Keyboard::isKeyPressed(Keyboard::Right))  {
            if(notKeyPressedGame){
                notKeyPressedGame = false;
                parent.move(151, 0);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))  {
            if(notKeyPressedGame){
                notKeyPressedGame = false;
                parent.move(-151, 0);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Up))   {
            if(notKeyPressedGame){
                notKeyPressedGame = false;
                parent.move(0, -151);
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   {
            if(notKeyPressedGame){
                notKeyPressedGame = false;
                parent.move(0, 151);
            }
        }

        // Remplissage de l'écran (couleur noire par défaut)
        app.clear(Color::Magenta);

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

        app.draw(parent);

        //  cout << Mouse::getPosition().x << " " << parent.getPosition().x << " notre boutton " << parent.getPosition().y << " " <<bouton.getPosition().y << endl;
        bouton.update(Vector2f (Mouse::getPosition(app)));
        bouton_defausser.update(Vector2f (Mouse::getPosition(app)));
        if (event.type == sf::Event::MouseButtonReleased) pressedGame = true;

        if(Mouse::isButtonPressed(Mouse::Left)) {
            if(pressedGame){
                pressedGame= false;
                if(bouton.isPressed()){
                    tuileEnMainObj->rotate();
                    cout << "ça rotate" << endl;
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
        //if(plateau.placeTuile(tuileEnMainObj, mousePosGrid.x, mousePosGrid.y)){
        //   cout << "placement réussi bravo " << endl;
        // }else{
        cout << "placement click " << endl;
        //}

        app.draw(shape);
        app.draw(tuileEnMain);
        app.draw(textMaTuile);
        app.draw(positionText);
        app.draw(bouton);
        app.draw(bouton_defausser);

//        app.setView(app.getView());

        // Affichage de la fenêtre à l'écran
        app.display();

    }
    return EXIT_SUCCESS;

}*/