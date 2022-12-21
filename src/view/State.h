#ifndef CPP_PROJET_2022_JEU_STATE_H
#define CPP_PROJET_2022_JEU_STATE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <stack>

using namespace sf;
using namespace std;

class State {



public:
    stack<State *> * stack_display = new stack<State *>;

    virtual void processInput(Event  & event) = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};


#endif //CPP_PROJET_2022_JEU_STATE_H
