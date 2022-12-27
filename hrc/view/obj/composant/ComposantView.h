#ifndef CPP_PROJET_2022_JEU_COMPOSANTVIEW_H
#define CPP_PROJET_2022_JEU_COMPOSANTVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "../../../model/tuile/Tuile.hpp"

using namespace sf;
using namespace std;

class ComposantView : public Drawable, public Transformable {

protected:
    map<ComposantView *, pair<int, int>> position_element;

public:
    ComposantView();
    ~ComposantView() override;

    void addDrawable(int x, int y, ComposantView * element);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /* Frabrique statique pour faciliter les choses */
    static Text createText(const string& text, string font, unsigned size_font, Color color);
    static Text createText(const string &text, unsigned int size_font, Color color);
    static Text createText(const string& text);
};



#endif