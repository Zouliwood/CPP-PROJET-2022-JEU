//
// Created by root0 on 21/12/22.
//

#ifndef CPP_PROJET_2022_JEU_MENUVIEW_H
#define CPP_PROJET_2022_JEU_MENUVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.h"
#include <stack>
#include "TuileView.h"
#include "obj/ButtonObj.h"
#include "DominoStateView.h"

using namespace std;

enum StatGameEnum {
    TRAX,
    DOMINO,
    CARCASSONNE,

};
class MenuView final : public State{

private:
    RenderWindow & app;
    stack<State *>  * stack_display;
    ButtonObj buttonDomino;
    ButtonObj button_precedent;
    ButtonObj button_suivant;
    mutable Sprite background;
    mutable Texture texture_bg;
    StatGameEnum statgame = DOMINO;
    bool pressedGame = true;

public:
    MenuView(sf::RenderWindow  & window, stack<State *> * stack_display);
    virtual ~MenuView();
    void init() override;
    void processInput(sf::Event & event) override;
    void update() override;
    void drawView() override;
};


#endif //CPP_PROJET_2022_JEU_MENUVIEW_H
