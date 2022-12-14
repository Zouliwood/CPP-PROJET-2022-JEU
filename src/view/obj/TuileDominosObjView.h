#ifndef CPP_PROJET_2022_JEU_TUILEDOMINOSOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILEDOMINOSOBJVIEW_H

#include "../../../hrc/model/tuile/TuileDominos.hpp"
#include "../TuileView.h"
#include "../../../hrc/model/tuile/TuileTrax.hpp"

class TuileDominosObjView final: public TuileView {
    Font font;
    TuileDominos tuileDominos;
    mutable RectangleShape shape;
    mutable Text textUp;
    mutable Text textDown;
    mutable Text textRight;
    mutable Text textLeft;

public:
    TuileDominosObjView(TuileDominos & tuile);
    ~TuileDominosObjView();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    //TODO: à chaque destruction tuer les objets textUp etc...

};


#endif
