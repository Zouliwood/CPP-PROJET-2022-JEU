//
// Created by root0 on 21/12/22.
//

#ifndef CPP_PROJET_2022_JEU_DOMINOSTATEVIEW_H
#define CPP_PROJET_2022_JEU_DOMINOSTATEVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <stack>
#include "obj/ButtonObj.h"
#include "State.h"

using namespace sf;
using namespace std;

class DominoStateView final : public State{

private:
    RenderWindow & app;
    Text centerText;
    ButtonObj buttonDomino;

public:
    DominoStateView(sf::RenderWindow & window);
    void processInput(sf::Event & event) override;
    void update() override;
    void drawView() override;

    virtual ~DominoStateView();
};


#endif