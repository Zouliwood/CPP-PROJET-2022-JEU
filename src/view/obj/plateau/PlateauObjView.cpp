#include "../../../../hrc/view/obj/plateau/PlateauObjView.h"

PlateauObjView::PlateauObjView():
/*        plateauDominos{plateauDominos},*/
        texture_background{*new Texture},
        background_plateau{*new Sprite()},
        hover{*new RectangleShape(Vector2f(150, 150))}
        {
        hover.setFillColor(Color(156, 156, 150, 100));
        hover.setPosition(-300, -300); // faire dispairaitre
        y_back = 2000;
        x_back = 2000;
        texture_background.loadFromFile("../ressources/img/plateau/bg_game.png");
        texture_background.setRepeated(true);
        background_plateau.setTexture(texture_background);
        background_plateau.setTextureRect(IntRect(0,0,x_back, y_back));

        }

void PlateauObjView::draw(RenderTarget &target, sf::RenderStates states) const {
    target.draw(background_plateau);
    target.draw(hover);
    ComposantView::draw(target, states);
}

void PlateauObjView::updateBackGround(int x, int y, int posx, int posy){
            x_back+=x;
            y_back+=y;
    background_plateau.setTextureRect(IntRect(0,0,x_back, y_back));
}

PlateauObjView::~PlateauObjView() {
            delete &background_plateau;
            delete &hover;
}

void PlateauObjView::updateEvent(Event & event, Vector2i mouse) {

    hover.setPosition(((mouse.x+50 )/150)*150-50, ((mouse.y+100)/150)*150 - 100);

    if (event.type == sf::Event::MouseButtonPressed){

        if (Mouse::isButtonPressed(Mouse::Right)) {
            isScrooled= true;
            x = getPosition().x;
            y = getPosition().y;
            cout << "tu as bine cliqué je t'ai vu"<< endl;
        }
    }
    if(isScrooled){
       // setPosition(mouse.x-x , mouse.y-y);
        isScrooled=false;
    }

    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel){
            std::cout << "wheel type: vertical" << std::endl;
            //setPosition(getPosition().x, getPosition().y+150);
    }else if (event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel) {
            std::cout << "wheel type: horizontal" << std::endl;
          //  setPosition(getPosition().x+150, getPosition().y);
        }else
            std::cout << "wheel type: unknown" << std::endl;
        std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
        //std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
        std::cout << "getScale x: " << getScale().x <<  " getScale y: " << getScale().y << endl;//<< event.mouseWheelScroll.y << std::endl;
/*
        if(event.mouseWheelScroll.delta){
            setScale(getScale().x * 0.6, getScale().y * 0.6);
        }else{
            setScale(getScale().x * 1.2, getScale().y * 1.2);
        }
*/
    }


    if (event.type == sf::Event::MouseButtonReleased) {
        if (Mouse::isButtonPressed(Mouse::Right)) {
            isScrooled = false;
            x = getPosition().x;
            y = getPosition().y;
            cout << "tu as relaché droit "<< endl;
        }
        cout << "tu as bine relaché je t'ai vu"<< endl;

    }


    }