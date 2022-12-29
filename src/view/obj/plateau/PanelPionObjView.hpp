
#ifndef CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP
#define CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP


#include "../../../../hrc/view/obj/composant/ComposantView.h"
#include "../../../../hrc/view/obj/tuile/TuileCarcassonneObjView.hpp"
#include "../../../../hrc/view/obj/composant/ButtonObj.h"

class PanelPionObjView final : public ComposantView{

    mutable TuileCarcassonneObjView * tuilEnMain;
    mutable RectangleShape panel;
    mutable ButtonObj annuler;
    mutable Text text;

public:
    PanelPionObjView(TuileCarcassonneObjView *);
    ~PanelPionObjView();
    void draw(RenderTarget &target, sf::RenderStates states) const;
    void show();
    void hide();
    void updateAction(Vector2f mouse);
};


#endif //CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP
