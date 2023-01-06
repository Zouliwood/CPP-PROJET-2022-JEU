
#ifndef CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP
#define CPP_PROJET_2022_JEU_PANELPIONOBJVIEW_HPP


#include "../composant/ComposantView.hpp"
#include "../tuile/TuileCarcassonneObjView.hpp"
#include "../composant/ButtonObj.hpp"
#include "../../../controller/ControllerCarcassonne.hpp"

class PanelPionObjView final : public ComposantView {
    mutable TuileCarcassonneObjView *tuilEnMain;
    mutable ButtonObj *annuler, *valider;
    mutable RectangleShape panel;
    mutable Text text, position;
    bool isOpenStatus, pressedGame, pressedGameMouse;
    mutable Texture texture;
    mutable Sprite zone;
    int position_value, posx, posy;
    ControllerCarcassonne & controllerCarcassonne;
    TuileCarcassonneObjView * tuiledejaplace;
    TuileCarcassonneObjView * tuileCarcassonneObjView;
    TuileCarcassonneObjView * tuileEnmain;

public:
    PanelPionObjView(TuileCarcassonneObjView *, ControllerCarcassonne & carcassonnecontroller, TuileCarcassonneObjView * tuileEnmain);
    ~PanelPionObjView();
    bool isOpen();
    void draw(RenderTarget &target, sf::RenderStates states) const;
    void show(TuileCarcassonne *tuile);
    void hide();
    void updateAction(Vector2f mouse, Event &event);
    void updatePosition(int x, int y);
    void updateTuile(TuileCarcassonneObjView * tuiledejaplace);
};
#endif