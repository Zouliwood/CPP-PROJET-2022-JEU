#ifndef CPP_PROJET_2022_JEU_TUILETRAXOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILETRAXOBJVIEW_H

#include "TuileView.h"
#include "../../hrc/model/tuile/TuileTrax.hpp"

class TuileTraxObjView final : public TuileView {

    mutable Texture texture;
    mutable Sprite bg_tuile;

public:
    int rotation_verso, rotation_recto = 0;
    TuileTrax * tuileTrax;
    TuileTraxObjView(TuileTrax * trax, int, int);
    ~TuileTraxObjView();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void resetFlip();
    void rotatationTuileObj();
};


#endif
