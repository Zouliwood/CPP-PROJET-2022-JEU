#include <iostream>
#include <SFML/Graphics.hpp>
#include "hrc/model/plateau/PlateauDominos.hpp"
#include "hrc/model/plateau/PlateauTrax.hpp"

using namespace sf;


int main(){

    /*auto plateau = PlateauDominos();
    plateau.placeFirstTuile();
    cout << "FIn de placefirstTuile()" << endl;

    TuileDominos * tuile = plateau.generateRandomTuile();*/

    auto plateau = PlateauTrax();

    auto * t = new FragmentSolo<colorTrax>(colorTrax::NOIR);

    TuileTrax * tuile = new TuileTrax(*t, *t, *t, *t);
    //TODO: fonction qui créer une tuile
    // fonction qui flipe une tuile dans TuileTrax
    // fonction qui permet de poser la premiere tuile
    // fonction qui detecte la fin de partie
    // redéfinir fonction principale place tuile en y ajoutant un fonction comme

    while(1){

        cout << plateau << endl;
        cout << "Votre tuile en main : " << endl;

        cout << *tuile<< endl;

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
                if(!plateau.placeTuile(tuile, x, y)){
                    cout << "Placement impossible ressayer !" << endl;
                }else{
                    tuile = new TuileTrax(*t, *t, *t, *t);
                }
                break;
            case 2:
                tuile->rotate();
                continue;
            case 3:
                tuile = new TuileTrax(*t, *t, *t, *t);
                break;
            default:
                continue;
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
