#include "TuileView.h"

TuileView::TuileView(){

}

void TuileView::draw(RenderTarget &target, sf::RenderStates states) const {
    for(auto it : position_y)  {
        it.first->setPosition(getPosition().x, getPosition().y+it.second);
    }
    for(auto it : position_x){
    //    cout << "position 4 fils au depart " << (getPosition().x+it.second) << endl;
        it.first->setPosition(getPosition().x+it.second, getPosition().y);
    }

    for(auto it : position_x) target.draw(*it.first);
     cout << getPosition().x << " x, y" << getPosition().y << endl;

}

void TuileView::addDrawable(int x, int y, TuileView * obj_view) {
    position_y.insert({obj_view, y});
    position_x.insert({obj_view, x});
}

/*
 *
 *
 *  // Sprite sprite{};//sprite = new Sprite{};
    Texture texture{};
    Font font;
    font.loadFromFile("../Agatha.ttf");
    text.setFont(font);
    text.setString(to_string(tuileDominos.getUp().getFragmentGauche()) + to_string(tuileDominos.getUp().getFragmentCentre()) +  to_string(tuileDominos.getUp().getFragmentDroit()));
    text.setCharacterSize(40); // in pixels, not points!
    text.setFillColor(Color::Red);
   //text.setPosition(0, 0);
    if (!texture.loadFromFile("../image.png"))
    {
        cout << "Erreur lors du chargement du fichier" << endl;
    }
    sprite.setTexture(texture);
    target.draw(sprite, states);
    target.draw(text);
    cout << "#AVANT je dessine " << getPosition().x  << "yP: " << getPosition().y << " x:" << sprite.getPosition().x << " y" << sprite.getPosition().y <<endl;
    sprite.setPosition(getPosition());
    sprite.setRotation(getRotation());
    text.setPosition(getPosition().x+10, getPosition().y+5);
    texture.setSmooth(true);
    cout << "#APRES je dessine " << getPosition().x << "yp: " << getPosition().y << " x:" << sprite.getPosition().x << " y" << sprite.getPosition().y <<endl;
    getTransform().transformRect(sprite.getLocalBounds()); // axis-aligned global bounds
 */




