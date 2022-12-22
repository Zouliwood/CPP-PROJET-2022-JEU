#include <iostream>
#include <SFML/Graphics.hpp>
#include <stack>
#include "src/view/State.h"
#include "src/view/MenuView.h"

using namespace sf;
using namespace std;


int main(){

    RenderWindow app(VideoMode(1280, 720, 32), "Projet Master M1 CPP | Benakli Saad");
    stack<State *> * stack_display = new stack<State *>;

    MenuView menu{app, stack_display};
    stack_display->push(&menu);

    while (app.isOpen()) {

        Event event;
        while (app.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    app.close();
                    break;
                default:
                    break;
            }
        }
        stack_display->top()->update();
        stack_display->top()->processInput(event);

        if(Keyboard::isKeyPressed((sf::Keyboard::Escape))){
            if(stack_display->size() > 1) stack_display->pop();
        }

        stack_display->top()->drawView();
        app.display();
    }
    return EXIT_SUCCESS;

}