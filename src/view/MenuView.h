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

class MenuView final : public State{

private:
    RenderWindow & app;
    stack<State *>  & stack_display;
    Text centerText;
    ButtonObj buttonDomino;

    bool pressedGame = true;

public:
    MenuView(sf::RenderWindow  & window, stack<State *> & stack_display);
    virtual void processInput(sf::Event & event) override;
    virtual void update() override;
    virtual void draw() override;


};


#endif //CPP_PROJET_2022_JEU_MENUVIEW_H
