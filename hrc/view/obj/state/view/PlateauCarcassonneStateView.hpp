#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNESTATEVIEW_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNESTATEVIEW_HPP

#include "../State.h"
#include "../../composant/ButtonObj.h"
#include "../../../../model/plateau/PlateauCarcassonne.hpp"
#include "../../../../model/tuile/TuileTrax.hpp"
#include "../../tuile/TuileDominosObjView.h"
#include "../../plateau/PlateauObjView.h"
#include "../../tuile/TuileTraxObjView.h"

class PlateauCarcassonneStateView final : public State{

    /* Objetc */
    RenderWindow & app;
    stack<State *> * stack_display;
    PlateauCarcassonne plateau;
    // TuileCarcassonne * tuileEnMain;

    /*Graphique view */
    PlateauObjView parent;
    ButtonObj bouton;
    ButtonObj bouton_defausser;
    //  TuileDominosObjView tuileEnMainObjView;
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
    PlateauCarcassonneStateView(RenderWindow & window, std::stack<State *> * stack_display);
    virtual ~PlateauCarcassonneStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};

#endif
