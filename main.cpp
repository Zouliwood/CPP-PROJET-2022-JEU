#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/hrc/plateau/PlateauDominos.hpp"
#include "model/hrc/tuile/TuileDominos.hpp"

using namespace sf;

int main(){

    /*PlateauDominos plateau {};

    plateau.init(5,5);

    plateau.toprint();
    cout << plateau <<endl;*/

    auto el = PlateauDominos();
    el.init(5,5);
    cout << el << endl;
    el.placeFirstTuile();
    cout << el << endl;

    /*
    //plateau.firstPos(); //place l'element;

    while(!plateau.victory()){
        //demande au joueur de joueur;
        RenderWindow app(VideoMode(800, 600, 32), "Test ");

        while (app.isOpen()){
            Event event;
            while (app.pollEvent(event)){
                switch (event.type) {
                    case Event::Closed:
                        app.close(); break;
                    default: break;
                }}
            app.clear(); // Remplissage en noir
            app.display(); // Affichage effectif

    }*/

    //fin de partie;


/*

    } // fermeture de la fenêtre
    */
    return EXIT_SUCCESS;
}
