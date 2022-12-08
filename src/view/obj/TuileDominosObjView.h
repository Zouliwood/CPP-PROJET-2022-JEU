#ifndef CPP_PROJET_2022_JEU_TUILEDOMINOSOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILEDOMINOSOBJVIEW_H

#include "../../../hrc/model/tuile/TuileDominos.hpp"
#include "../TuileView.h"

class TuileDominosObjView : public TuileView {
    Font font;
    TuileDominos tuileDominos;
    mutable RectangleShape shape;
    mutable Text textUp;
    mutable Text textLeft;
    mutable Text textRight;
    mutable Text textDown;


public:
    TuileDominosObjView(TuileDominos & tuile);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};


#endif
