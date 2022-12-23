#include <iostream>
#include <SFML/Graphics.hpp>
#include <stack>
#include "src/view/State.h"
#include "src/view/MenuView.h"
#include "hrc/model/tuile/TuileTrax.hpp"
#include "hrc/model/plateau/PlateauTrax.hpp"

using namespace sf;
using namespace std;


int main(){
/*
    RenderWindow app(VideoMode(1280, 720, 32), "Projet Master M1 CPP | Benakli Saad", sf::Style::Titlebar | sf::Style::Close);
    stack<State *> * stack_display = new stack<State *>;

    MenuView menu{app, stack_display};
    stack_display->push(&menu);

    while (app.isOpen()) {

        Event event;
        while (app.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    app.close();
                    break;
                default:
                    break;
            }
        }
        stack_display->top()->update();
        stack_display->top()->processInput(event);

        if(Keyboard::isKeyPressed((sf::Keyboard::Escape))){
            if(stack_display->size() > 1) stack_display->pop();
        }

        stack_display->top()->drawView();
        app.display();
    }
    */

    /*auto plateau = PlateauDominos();
    plateau.placeFirstTuile();
    cout << "FIn de placefirstTuile()" << endl;

    TuileDominos * tuile = plateau.generateRandomTuile();*/

    auto plateau = PlateauTrax();


    TuileTrax * tuile  = new TuileTrax(*(new FragmentSolo<colorTrax>(colorTrax::NOIR)), *(new FragmentSolo<colorTrax>(colorTrax::BLANC)), *(new FragmentSolo<colorTrax>(colorTrax::NOIR)), *(new FragmentSolo<colorTrax>(colorTrax::BLANC)));
    //TODO: fonction qui detecte la fin de partie

    //fonction qui permet de poser la premiere tuile
    //redéfinir fonction principale place tuile en y ajoutant un fonction comme

    while(!plateau.checkVictory()){
        //TODO: next player
        cout << plateau << endl;
        cout << "Votre tuile en main : " << endl;

        cout << *tuile<< endl;

        cout << "1 - Jouer " << "2- Rotate ma tuile " <<"3-Flip  " <<" 4-Defausser " <<endl;
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
                    tuile  = new TuileTrax(*(new FragmentSolo<colorTrax>(colorTrax::NOIR)), *(new FragmentSolo<colorTrax>(colorTrax::BLANC)), *(new FragmentSolo<colorTrax>(colorTrax::NOIR)), *(new FragmentSolo<colorTrax>(colorTrax::BLANC)));
                }
                break;
            case 2:
                tuile->rotate();
                continue;
            case 3:
                cout << "on flip" << endl;
                tuile->flipTuile();
                break;
            case 4:
                tuile   = new TuileTrax(*(new FragmentSolo<colorTrax>(colorTrax::NOIR)), *(new FragmentSolo<colorTrax>(colorTrax::BLANC)), *(new FragmentSolo<colorTrax>(colorTrax::NOIR)), *(new FragmentSolo<colorTrax>(colorTrax::BLANC)));
                break;
            default:
                continue;
        }

    }

    return EXIT_SUCCESS;

}