#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/hrc/plateau/PlateauDominos.hpp"
#include "model/hrc/tuile/TuileDominos.hpp"

using namespace sf;

int main(){

    PlateauDominos plateau {};

    plateau.init(5,5);

    cout << plateau <<endl;

    auto el = PlateauDominos();
    el.init(5,5);
    cout << el << endl;
    el.placeFirstTuile();
    cout << el << endl;

    auto frag = FragmentTriple<int>(1, 2, 3);

    cout << frag << endl;

    auto Tuiled = TuileDominos(frag, frag, frag, frag);
    cout << Tuiled.toString() << endl;
    TuileDominos * tuile = plateau.generateRandomTuile();

    while(1){
        cout << "Votre tuile en main : " << endl;

        cout << tuile->toString() << endl;

        cout << "1 - Jouer " << " 2 - defausser "<<endl;
        int rep;
        cin >> rep;
        if(rep == 1){
            int x, y;
            cout << "entrez vos coordonnées" << endl;
            cout << "x: " << endl;
            cin >> x;
            cout << "y: " << endl;
            cin >> y;
            plateau.placeTuile(tuile, x,y);
        }else{
            tuile = plateau.generateRandomTuile();
        }

    }

    /*
    string os = (el.getListTuile().at(2).at(2))->toString();
    cout << os << endl;
    Text text;
    text.setString(os + "blalblalblalbblal");
    text.setFillColor(Color::Red);
    text.setPosition(0,0);
    text.setCharacterSize(200); // in pixels, not points!



    //plateau.firstPos(); //place l'element;

   // while(!plateau.victory()){
        //demande au joueur de joueur;
        RenderWindow app(VideoMode(1280, 720, 32), "Plateau test ");

        while (app.isOpen()){
            Event event;
            while (app.pollEvent(event)){
                switch (event.type) {
                    case Event::Closed:
                        app.close();
                        break;
                    default:
                        break;
                }}

            app.draw(text);
            app.display(); // Affichage effectif

    }

    //fin de partie;


/*

    } // fermeture de la fenêtre
    */
    return EXIT_SUCCESS;
}
