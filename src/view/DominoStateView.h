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

class DominoStateView : public State{

private:
    RenderWindow & app;
    mutable Text centerText;
    mutable ButtonObj buttonDomino;

public:
    DominoStateView(sf::RenderWindow & window);
    virtual void processInput(sf::Event & event) override;
    virtual void update() override;
    virtual void draw() override;

};


#endif