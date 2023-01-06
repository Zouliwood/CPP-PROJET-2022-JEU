#ifndef CPP_PROJET_2022_JEU_PIONOBJVIEW_HPP
#define CPP_PROJET_2022_JEU_PIONOBJVIEW_HPP


#include "../composant/ComposantView.hpp"

class PionObjView final: public ComposantView {

    CircleShape & partisant;

public:
    PionObjView();
    void draw(RenderTarget &target, sf::RenderStates states) const override;
    void setColor(int r, int g, int b);
};


#endif
