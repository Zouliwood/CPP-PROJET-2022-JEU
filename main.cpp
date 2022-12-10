#include <iostream>
#include <SFML/Graphics.hpp>
#include "hrc/model/plateau/PlateauDominos.hpp"
#include "hrc/model/plateau/PlateauTrax.hpp"
#include "src/view/TuileView.h"
#include "src/view/obj/TuileDominosObjView.h"
#include "src/view/obj/ButtonObj.h"

using namespace sf;

void miseAJourPlateauView(PlateauDominos * plateau, TuileView * parent, TuileDominosObjView tuileNul) {

    auto pos = plateau->getListTuile().getPositif();
    auto neg = plateau->getListTuile().getNegatif();

    cout << "Coter positif grand tableau Positif " << pos.size() << endl;
    for (int i = 0; i < pos.size(); ++i) { // colonne
        for (int j = pos.at(i)->getNegatif().size() - 1; j >= 0; --j) { //les lignes*
            auto tuile = ((TuileDominos *) pos.at(i)->getNegatif().at(j));
            if (tuile == nullptr) {
                parent->addDrawable(j * 160, -i * 160, &tuileNul);
            } else {
                auto tuileDominosObjView4 = new TuileDominosObjView(*tuile);
                parent->addDrawable(j * 160, -i * 160, tuileDominosObjView4);
            }
        }
        for (int j = 0; j < pos.at(i)->getPositif().size(); ++j) {
            auto tuile = ((TuileDominos *) pos.at(i)->getPositif().at(j));
            if (tuile == nullptr) {
                parent->addDrawable(j * 160, i * 160, &tuileNul);
            } else {
                auto tuileDominosObjView4 = new TuileDominosObjView(*tuile);
                parent->addDrawable(j * 160, i * 160, tuileDominosObjView4);
                cout << "######################## " << i << j << endl;
            }
        }
    }
    cout << "Coter Grand tableau Negatif : " << neg.size() << endl;
    for (int i = neg.size() - 1; i >= 0; --i) {
        for (int j = neg.at(i)->getNegatif().size() - 1; j >= 0; --j) {
            auto tuile = ((TuileDominos *) neg.at(i)->getNegatif().at(j));
            if (tuile == nullptr) {
                parent->addDrawable(-j * 160, -i * 160, &tuileNul);
            } else {
                auto tuileDominosObjView4 = new TuileDominosObjView(*tuile);
                parent->addDrawable(-j * 160, -i * 160, tuileDominosObjView4);
            }
        }

        for (int j = 0; j < neg.at(i)->getPositif().size(); ++j) {
            auto tuile = ((TuileDominos *) neg.at(i)->getPositif().at(j));
            if (tuile == nullptr) {
                parent->addDrawable(-j * 160, i * 160, &tuileNul);
            } else {
                auto tuileDominosObjView4 = new TuileDominosObjView(*tuile);
                parent->addDrawable(-j + 160, i * 160, tuileDominosObjView4);
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
    auto tuileNul = TuileDominosObjView(*tuileDominoNul);

    RectangleShape shape{Vector2f (1280, 270)};
    shape.setFillColor(Color::Black);
    shape.setPosition(0, 450);

    TuileView parent{};
    parent.setOrigin(550, 350);
    ButtonObj bouton{"Defausser"};
    bouton.setPosition(30, 550);

    TuileDominosObjView tuileEnMain{*tuileEnMainObj};
    tuileEnMain.setPosition(550, 540);

    Text textMaTuile = TuileView::createText("Ma tuile", 23, Color::White);
    textMaTuile.setPosition(540, 510);

    miseAJourPlateauView(&plateau, &parent, tuileNul);

    RenderWindow app(VideoMode(1280, 720, 32), "Ma premiere fenetre SFML ! ");

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
        if (Keyboard::isKeyPressed(Keyboard::Right))  parent.move(1, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left))  parent.move(-1, 0);
        if (Keyboard::isKeyPressed(Keyboard::Up))  parent.move(0, -1);
        if (Keyboard::isKeyPressed(Keyboard::Down)) parent.move(0, 1);

        // Remplissage de l'écran (couleur noire par défaut)
        app.clear(Color::Magenta);
       // cout << plateau << endl;
        if(Mouse::isButtonPressed(Mouse::Left)) {
            cout << "tu clique appui"<<endl;
        }


        app.draw(parent);
        app.draw(shape);
        app.draw(bouton);
        cout << Mouse::getPosition().x << " " << Mouse::getPosition().y << " notre boutton " << bouton.getPosition().x << " " <<bouton.getPosition().y << endl;
        bouton.update(Vector2f (Mouse::getPosition(app)));
        app.draw(tuileEnMain);
        app.draw(textMaTuile);

        // Affichage de la fenêtre à l'écran
        app.display();
/*
        cout << "1 - Jouer " << "2- Rotate ma tuile " <<" 3 - defausser " <<endl;
        int rep;
        cin >> rep;

        switch(rep){
            case 1:
                int x, y;
                cout << "entrez vos coordonnées" << endl;
                cout << "x: " << endl;
                cin >> x;
                cout << "y: " << endl;
                cin >> y;
                if(!plateau.placeTuile(tuileEnMainObj, x, y)){
                    cout << "Placement impossible ressayer !" << endl;
                }else{
                    tuileEnMainObj = plateau.generateRandomTuile();
                    miseAJourPlateauView(&plateau, &parent, tuileNul);
                }
                break;
            case 2:
                tuileEnMainObj->rotate();
                continue;
            case 3:
                tuileEnMainObj = plateau.generateRandomTuile();
                break;
            default:
                continue;
        }
        */
    }
    return EXIT_SUCCESS;

}

