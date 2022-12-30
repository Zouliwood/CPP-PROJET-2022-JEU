#ifndef CPP_PROJET_2022_JEU_STATE_HPP
#define CPP_PROJET_2022_JEU_STATE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <stack>

using namespace sf;
using namespace std;

enum StatGameEnum {
    TRAX,
    DOMINO,
    CARCASSONNE
};

class State {

public:
    virtual void init() = 0;
    virtual void processInput(Event & event) = 0;
    virtual void update() = 0;
    virtual void drawView() = 0;
};


#endif
