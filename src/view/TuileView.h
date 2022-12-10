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
    map<TuileView *, pair<int, int>> position_element;

public:

    TuileView();
    void addDrawable(int x, int y, TuileView * element);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /* Frabrique statique pour faciliter les choses */
    /* TEXT ELEMENT */
    static Text createText(const string& text, string font, unsigned size_font, Color color);
    static Text createText(const string &text, unsigned int size_font, Color color);
    static Text createText(const string& text);
};



#endif