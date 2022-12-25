#ifndef CPP_PROJET_2022_JEU_TUILETRAXOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILETRAXOBJVIEW_H

#include "../composant/ComposantView.h"
#include "../../../model/tuile/TuileTrax.hpp"

class TuileTraxObjView final : public ComposantView {

    mutable Texture texture;
    mutable Sprite bg_tuile;

public:
    TuileTrax * tuileTrax;
    TuileTraxObjView(TuileTrax * trax);
    ~TuileTraxObjView();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
