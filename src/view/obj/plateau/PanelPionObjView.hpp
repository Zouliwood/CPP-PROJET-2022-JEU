
#ifndef CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP
#define CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP


#include "../../../../hrc/view/obj/composant/ComposantView.h"
#include "../../../../hrc/view/obj/tuile/TuileCarcassonneObjView.hpp"
#include "../../../../hrc/view/obj/composant/ButtonObj.h"

class PanelPionObjView final : public ComposantView{

    mutable TuileCarcassonneObjView * tuilEnMain;
    mutable ButtonObj * annuler;
    mutable RectangleShape panel;
    mutable Text text;
    bool isOpenStatus;
    mutable Texture texture;
    mutable Sprite zone;

public:
    PanelPionObjView(TuileCarcassonneObjView *);
    ~PanelPionObjView();
    bool isOpen();
    void draw(RenderTarget &target, sf::RenderStates states) const;
    void show(TuileCarcassonne * tuile);
    void hide();
    void updateAction(Vector2f mouse);
};


#endif //CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP
