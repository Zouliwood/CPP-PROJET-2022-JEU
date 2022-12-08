#ifndef CPP_PROJET_2022_JEU_TUILEVIEW_H
#define CPP_PROJET_2022_JEU_TUILEVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "../../hrc/model/tuile/Tuile.hpp"

using namespace sf;
using namespace std;

class TuileView : public Drawable, public Transformable {

private:
    map<TuileView *, int> position_x;
    map<TuileView *, int> position_y;

public:

    /* Frabrique statique pour faciliter les choses */
    TuileView();
    void addDrawable(int x, int y, TuileView * element);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif