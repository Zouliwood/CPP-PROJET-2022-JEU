#ifndef CPP_PROJET_2022_JEU_PLATEAUDOMINOSTATEVIEW_H
#define CPP_PROJET_2022_JEU_PLATEAUDOMINOSTATEVIEW_H


#include "State.h"
#include "obj/ButtonObj.h"
#include "../../hrc/model/plateau/PlateauDominos.hpp"
#include "../../hrc/model/tuile/TuileDominos.hpp"
#include "../../hrc/model/plateau/PlateauDominos.hpp"
#include "obj/TuileDominosObjView.h"
#include "obj/PlateauObjView.h"

class PlateauDominoStateView final : public State{

    RenderWindow & app;
    stack<State *> stack_display;
    PlateauDominos plateau;
    TuileDominos * tuileEnMainObj;
    TuileDominos * tuileDominoNul;
    TuileDominosObjView tuileNul;
    PlateauObjView parent;
    ButtonObj bouton;
    ButtonObj bouton_defausser;
    TuileDominosObjView tuileEnMain;
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

    void miseAJourPlateauView(PlateauDominos * plateau, TuileView * parent, TuileDominosObjView tuileNul);

public:
    PlateauDominoStateView(RenderWindow & window, std::stack<State *> * stack_display);
    ~PlateauDominoStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};



#endif //CPP_PROJET_2022_JEU_PLATEAUDOMINOSTATEVIEW_H
