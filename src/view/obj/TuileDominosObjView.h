#ifndef CPP_PROJET_2022_JEU_TUILEDOMINOSOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILEDOMINOSOBJVIEW_H

#include "../../../hrc/model/tuile/TuileDominos.hpp"
#include "../TuileView.h"
#include "../../../hrc/model/tuile/TuileTrax.hpp"

class TuileDominosObjView final: public TuileView {
    Font font;
    mutable RectangleShape shape;
    mutable Text textUp;
    mutable Text textDown;
    mutable Text textRight;
    mutable Text textLeft;

public:
    TuileDominos * tuileDominos;
    TuileDominosObjView(TuileDominos * tuile);
    ~TuileDominosObjView();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateTuile() const;
    void updatePosition() const;
};


#endif
