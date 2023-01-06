#ifndef CPP_PROJET_2022_JEU_PLATEAUDOMINOSSTATEVIEW_HPP
#define CPP_PROJET_2022_JEU_PLATEAUDOMINOSSTATEVIEW_HPP


#include "../State.hpp"
#include "../../composant/ButtonObj.hpp"
#include "../../../../model/plateau/PlateauDominos.hpp"
#include "../../../../model/tuile/TuileDominos.hpp"
#include "../../tuile/TuileDominosObjView.hpp"
#include "../../plateau/PlateauObjView.hpp"
#include "../../../../controller/Controller.hpp"

class PlateauDominosStateView final : public State{

    /* Object */
    RenderWindow & app;
    stack<State *> * stack_display;
    Controller<TuileDominos> & controller;

    /*
    PlateauDominos plateau;
    TuileDominos * tuileEnMainObj;
    */
    /* Graphique partie */
    PlateauObjView parent;
    TuileDominosObjView tuileEnMain;
    ButtonObj bouton;
    ButtonObj bouton_defausser;
    RectangleShape shape;
    Text textMaTuile;
    Text positionText;

    /* Parametre */
    float gridSizeF;
    int grideSizeU;
    Vector2f mousePosWindow;
    Vector2f mousePosView;
    Vector2i mousePosGrid;

    bool pressedGame, notKeyPressedGame;

public:
    PlateauDominosStateView(RenderWindow & window, std::stack<State *> * stack_display, Controller<TuileDominos> & controller);
    virtual ~PlateauDominosStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};



#endif //CPP_PROJET_2022_JEU_PLATEAUDOMINOSSTATEVIEW_HPP
