
#ifndef CPP_PROJET_2022_JEU_PLATEAUTRAXSTATEVIEW_H
#define CPP_PROJET_2022_JEU_PLATEAUTRAXSTATEVIEW_H

#include "State.h"
#include "obj/ButtonObj.h"
#include "../../hrc/model/plateau/PlateauTrax.hpp"
#include "../../hrc/model/tuile/TuileTrax.hpp"
#include "obj/TuileDominosObjView.h"
#include "obj/PlateauObjView.h"
#include "TuileTraxObjView.h"

class PlateauTraxStateView  final : public State{

    RenderWindow & app;
    stack<State *> stack_display;
    PlateauTrax plateau;
    TuileTrax * tuileEnMain;

    /*Graphique view */
    PlateauObjView parent;
    ButtonObj bouton;
    ButtonObj bouton_defausser;
    ButtonObj boutton_flip;
    TuileTraxObjView tuileEnMainObjView;
    RectangleShape shape; //{Vector2f (1280, 270)};

    float gridSizeF = 150.0f;
    int grideSizeU = static_cast<int>(gridSizeF);

    Vector2f mousePosWindow;
    Vector2f mousePosView;
    Vector2i mousePosGrid;

    Text textMaTuile; //= TuileView::createText("Ma tuile", 23, Color::White);
    Text positionText; // = TuileView::createText("x : y : ", 12, Color::White);
    bool pressedGame = true;
    bool notKeyPressedGame = true;


public:
    PlateauTraxStateView(RenderWindow & window, std::stack<State *> * stack_display);
    ~PlateauTraxStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};

#endif
