//
// Created by david on 13/11/22.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/hrc/plateau/PlateauDominos.hpp"
#include "model/hrc/tuile/TuileDominos.hpp"

using namespace sf;

int main(){

    Plateau<Tuile<FragmentTuile<int>>> plateau() ;
    plateau.init(2,2);

    /*

    PlateauDominos<TuileDominos<FragmentTriple<int>>> & plateau ();

    cout << "hheohohoho" << &plateau() << "hohoohoh" <<endl;

    //init(0, 0);

//    plateau.firstPos(); //place l'element;
     //demande au joueur de joueur;
 /*    RenderWindow app(VideoMode(800, 600, 32), "Test ");

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

    }

    //fin de partie;

*/
/*

    } // fermeture de la fenêtre
    */
    return EXIT_SUCCESS;
}
