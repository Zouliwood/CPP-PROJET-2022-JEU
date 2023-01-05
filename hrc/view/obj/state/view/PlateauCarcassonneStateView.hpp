#ifndef CPP_PROJET_2022_JEU_PLATEAUCARCASSONNESTATEVIEW_HPP
#define CPP_PROJET_2022_JEU_PLATEAUCARCASSONNESTATEVIEW_HPP

#include "../State.hpp"
#include "../../composant/ButtonObj.hpp"
#include "../../../../model/plateau/PlateauCarcassonne.hpp"
#include "../../../../model/tuile/TuileTrax.hpp"
#include "../../tuile/TuileDominosObjView.hpp"
#include "../../plateau/PlateauObjView.hpp"
#include "../../tuile/TuileTraxObjView.hpp"
#include "../../tuile/TuileCarcassonneObjView.hpp"
#include "../../plateau/PanelPionObjView.hpp"
#include "../../../../controller/ControllerCarcassonne.hpp"

class PlateauCarcassonneStateView final : public State{

    /* Objetc */
    RenderWindow & app;
    stack<State *> * stack_display;
    ControllerCarcassonne & controllerCarcassonne;

    /*Graphique view */
    PlateauObjView parent;
    ButtonObj bouton;
    ButtonObj bouton_defausser;
    TuileCarcassonneObjView tuileEnMainObjView;
    RectangleShape shape; //{Vector2f (1280, 270)};
    Text textMaTuile;
    Text positionText;
    PanelPionObjView * panelPion;

    /* Paremetre */
    float gridSizeF;
    int grideSizeU;
    Vector2f mousePosWindow;
    Vector2f mousePosView;
    Vector2i mousePosGrid;
    bool pressedGame;
    bool notKeyPressedGame;

public:
    PlateauCarcassonneStateView(RenderWindow & window, std::stack<State *> * stack_display, ControllerCarcassonne  & controllerCarcassonne);
    virtual ~PlateauCarcassonneStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;

};

#endif
