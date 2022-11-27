#include <iostream>
#include <SFML/Graphics.hpp>
#include "model/hrc/plateau/PlateauDominos.hpp"
#include "model/hrc/tuile/TuileDominos.hpp"

using namespace sf;

/*template<typename  T>
bool operator==(const FragmentTriple<T> & a, const FragmentTriple<T> & b){
    cout << "test ############" << endl;
    return true;
}*/

bool compareTuile(const TuileDominos * courant, const TuileDominos * tuileUp, const TuileDominos * tuileDown, const TuileDominos * tuileRight, const TuileDominos * tuileLeft){
    return (!tuileUp || (&(FragmentTriple<int> &)courant->getUp())->compareFragment(&(FragmentTriple<int> &)tuileUp->getDown()))
        ||  (!tuileRight || (&(FragmentTriple<int> &)courant->getRight())->compareFragment(&(FragmentTriple<int> &)tuileRight->getLeft()))
        || (!tuileLeft || (&(FragmentTriple<int> &)courant->getLeft())->compareFragment(&(FragmentTriple<int> &)tuileLeft->getRight()))
        || (!tuileDown || (&(FragmentTriple<int> &)courant->getDown())->compareFragment(&(FragmentTriple<int> &)tuileDown->getUp()));
}

int main(){

    auto plateau = PlateauDominos();
    plateau.init(5,5);
    plateau.placeFirstTuile();

    TuileDominos * tuile = plateau.generateRandomTuile();

    while(1){
        cout << plateau << endl;
        cout << "Votre tuile en main : " << endl;

        cout << tuile->toString() << endl;

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
                if(!plateau.placeTuile(tuile, x, y, compareTuile)){
                    cout << "Placement impossible ressayer !" << endl;
                }
                break;
            case 2:
                tuile->rotate();
                continue;
            case 3:
                tuile = plateau.generateRandomTuile();
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
