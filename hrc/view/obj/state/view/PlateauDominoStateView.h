#ifndef CPP_PROJET_2022_JEU_PLATEAUDOMINOSTATEVIEW_H
#define CPP_PROJET_2022_JEU_PLATEAUDOMINOSTATEVIEW_H


#include "../State.h"
#include "../../composant/ButtonObj.h"
#include "../../../../model/plateau/PlateauDominos.hpp"
#include "../../../../model/tuile/TuileDominos.hpp"
#include "../../tuile/TuileDominosObjView.h"
#include "../../plateau/PlateauObjView.h"

class PlateauDominoStateView final : public State{

    /* Object */
    RenderWindow & app;
    stack<State *> * stack_display;
    PlateauDominos plateau;
    TuileDominos * tuileEnMainObj;

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
    PlateauDominoStateView(RenderWindow & window, std::stack<State *> * stack_display);
    virtual ~PlateauDominoStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};



#endif //CPP_PROJET_2022_JEU_PLATEAUDOMINOSTATEVIEW_H
