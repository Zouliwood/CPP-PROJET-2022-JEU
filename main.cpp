//
// Created by david on 13/11/22.
//

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main(){
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
    } // fermeture de la fenêtre
    return EXIT_SUCCESS;
}
