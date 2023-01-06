
#ifndef CPP_PROJET_2022_JEU_PLATEAUTRAXSTATEVIEW_HPP
#define CPP_PROJET_2022_JEU_PLATEAUTRAXSTATEVIEW_HPP

#include "../State.hpp"
#include "../../composant/ButtonObj.hpp"
#include "../../../../model/plateau/PlateauTrax.hpp"
#include "../../../../model/tuile/TuileTrax.hpp"
#include "../../tuile/TuileDominosObjView.hpp"
#include "../../plateau/PlateauObjView.hpp"
#include "../../tuile/TuileTraxObjView.hpp"

class PlateauTraxStateView final : public State{

    /* Objetc */
    RenderWindow & app;
    stack<State *> * stack_display;
    PlateauTrax & plateau;
    TuileTrax * tuileEnMain;

    /*Graphique view */
    PlateauObjView parent;
    ButtonObj bouton;
    ButtonObj bouton_defausser;
    ButtonObj boutton_flip;
    TuileTraxObjView tuileEnMainObjView;
    RectangleShape shape; //{Vector2f (1280, 270)};
    Text textMaTuile;
    Text positionText;

    /* Paremetre */
    float gridSizeF;
    int grideSizeU;
    Vector2f mousePosWindow;
    Vector2f mousePosView;
    Vector2i mousePosGrid;
    bool pressedGame;
    bool notKeyPressedGame;

public:
    PlateauTraxStateView(RenderWindow & window, std::stack<State *> * stack_display);
    virtual ~PlateauTraxStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};

#endif
