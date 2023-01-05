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

void PlateauObjView::updateEvent(Event & event, Vector2i mouse) {
    hover.setPosition(((mouse.x+50 )/150)*150-50, ((mouse.y+100)/150)*150 - 100);
        }

PlateauObjView::~PlateauObjView() {
    delete &background_plateau;
    delete &hover;
}
