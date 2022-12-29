#ifndef CPP_PROJET_2022_JEU_MENUVIEW_H
#define CPP_PROJET_2022_JEU_MENUVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../State.h"
#include <stack>
#include "../../composant/ComposantView.h"
#include "../../composant/ButtonObj.h"

using namespace std;

class MenuView final : public State{

    RenderWindow & app;
    stack<State *>  *stack_display;
    ButtonObj buttonDomino;
    ButtonObj button_precedent;
    ButtonObj button_suivant;
    mutable Sprite background;
    mutable Texture texture_bg;
    StatGameEnum & statgame;
    bool pressedGame, keyPressedGame;

public:
    MenuView(sf::RenderWindow  & window, stack<State *> * stack_display);
    virtual ~MenuView();
    void init() override;
    void processInput(sf::Event & event) override;
    void update() override;
    void drawView() override;
};

#endif
