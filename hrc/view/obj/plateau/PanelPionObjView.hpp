
#ifndef CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP
#define CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP


#include "../composant/ComposantView.h"
#include "../tuile/TuileCarcassonneObjView.hpp"
#include "../composant/ButtonObj.h"

class PanelPionObjView final : public ComposantView {
    mutable TuileCarcassonneObjView *tuilEnMain;
    mutable ButtonObj *annuler, *valider;
    mutable RectangleShape panel;
    mutable Text text, position;
    bool isOpenStatus, isWantToPos, pressedGame;
    mutable Texture texture;
    mutable Sprite zone;
    int position_value;

public:
    PanelPionObjView(TuileCarcassonneObjView *);
    ~PanelPionObjView();
    bool isWantToPosPartisant();
    bool isOpen();
    void draw(RenderTarget &target, sf::RenderStates states) const;
    void show(TuileCarcassonne *tuile);
    void hide();
    void updateAction(Vector2f mouse, Event &event);
    int getPartisantPos();
};
#endif