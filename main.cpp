#include <iostream>
#include <SFML/Graphics.hpp>
#include "hrc/model/plateau/PlateauDominos.hpp"
#include "hrc/model/plateau/PlateauTrax.hpp"
#include "src/view/TuileView.h"
#include "src/view/obj/TuileDominosObjView.h"

using namespace sf;


int main(){

    auto plateau = PlateauDominos();
    plateau.placeFirstTuile();
    cout << "FIn de placefirstTuile()" << endl;

    TuileDominos * tuileD = plateau.generateRandomTuile();
    TuileDominos * tuileD2 = plateau.generateRandomTuile();
    TuileDominos * tuileD3 = plateau.generateRandomTuile();
    TuileDominos * tuileD4 = plateau.generateRandomTuile();

/*
    auto plateau = PlateauTrax();

    auto * t = new FragmentSolo<colorTrax>(colorTrax::NOIR);

    new TuileTrax(*t, *t, *t, *t);
    //TODO: fonction qui créer une tuile
    // fonction qui flipe une tuile dans TuileTrax
    // fonction qui permet de poser la premiere tuile
    // fonction qui detecte la fin de partie
    // redéfinir fonction principale place tuile en y ajoutant un fonction comme


    /*
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
    string os = (el.getListTuile().at(2).at(2))->toString();
    cout << os << endl;

    Text text;
    text.setString("blalblalblalbblal");
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




    } // fermeture de la fenêtre
*/
    // Create a new render-window
    //const String & file = (String &) "image.png";
    TuileView parent{};
    TuileDominosObjView tuileDominosObjView{*tuileD};
    TuileDominosObjView tuileDominosObjView2{*tuileD2};
    TuileDominosObjView tuileDominosObjView3{*tuileD3};
    TuileDominosObjView tuileDominosObjView4{*tuileD4};

    parent.addDrawable(0, 0, &tuileDominosObjView);
    parent.addDrawable(100, 120, &tuileDominosObjView2);
    parent.addDrawable(200, 210, &tuileDominosObjView3);
    parent.addDrawable(1200, 350, &tuileDominosObjView4);

    // TuileView tuileRender{*tuileD, "../image.png"};
    // definition de la fenêtre
    RenderWindow app(VideoMode(800, 600, 32), "Ma premiere fenetre SFML ! ");
    // Hello world
    Font font;
    font.loadFromFile("../Agatha.ttf");
    Text text;
    text.setFont(font);
    text.setString("  Hello world");
    text.setCharacterSize(100); // in pixels, not points!
    text.setFillColor(Color::Red);
    //text.setStyle(Text::Bold | Text::Underlined);

    // Un element graphique, associé à une image
/*
    Sprite tuile;

    tuile.setScale(Vector2f(0.5,0.5));
    tuile.move(Vector2f(200, 200));
*/
// idem pour une seconde tuile :
    //Texture tex;
    //tex.loadFromFile("../fleur2.png");
    //Sprite tuile2;
    //tuile2.setTexture(tex);

// pour une petite animation
    //* current = &tuileRender;
    // Boucle principale

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
        app.clear(Color::Blue);


        // Store the bounding box of the sprite
   //     FloatRect bounds_t1 = tuile.getGlobalBounds();
     //   FloatRect bounds_t2 = tuile2.getGlobalBounds();
        // rq: je l'ai mis là et pas dans la gestion des évenements... surement que ce serait mieux là bas
        if(Mouse::isButtonPressed(Mouse::Left)) {
            // transform the mouse position from window coordinates to world coordinates
            Vector2f mouse = app.mapPixelToCoords(Mouse::getPosition(app));
            // select the current Sprite
          //  if (bounds_t1.contains(mouse)) current = & tuile;
          //  if (bounds_t2.contains(mouse)) current = & tuile2;
        }

        // dessin en interne de nos Sprites
      //  app.draw(tuile);
      //  app.draw(tuile2);
        parent.setOrigin(app.getPosition().x, app.getPosition().y);
        //   app.draw(text);
        app.draw(parent);

        // Affichage de la fenêtre à l'écran
        app.display();
    }
    return EXIT_SUCCESS;
}
