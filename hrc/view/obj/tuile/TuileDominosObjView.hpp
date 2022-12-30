#ifndef CPP_PROJET_2022_JEU_TUILEDOMINOSOBJVIEW_HPP
#define CPP_PROJET_2022_JEU_TUILEDOMINOSOBJVIEW_HPP

#include "../../../model/tuile/TuileDominos.hpp"
#include "../composant/ComposantView.hpp"
#include "../../../model/tuile/TuileTrax.hpp"

class TuileDominosObjView final: public ComposantView {
    Font font;
    mutable RectangleShape shape;
    mutable Text textUp;
    mutable Text textDown;
    mutable Text textRight;
    mutable Text textLeft;
    TuileDominos * tuileDominos;

public:
    TuileDominosObjView(TuileDominos * tuile);
    ~TuileDominosObjView();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateTuile() const;
    void updatePosition() const;
    void setTuile(TuileDominos *newtuile);
};


#endif
