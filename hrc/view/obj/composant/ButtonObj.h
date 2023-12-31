#ifndef CPP_PROJET_2022_JEU_BUTTONOBJ_H
#define CPP_PROJET_2022_JEU_BUTTONOBJ_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/System.hpp>
#include "ComposantView.h"

enum button_status {IDLE = 0, PRESSED, HOVER,};

class ButtonObj final: public ComposantView {

    mutable Text textbutton;
    mutable Sprite fond_image;
    mutable Texture texture;
    short unsigned button_status;

public:
    ButtonObj(string string);
    ~ButtonObj();
    void update(Vector2f mouse);
    void draw(RenderTarget &target, RenderStates states) const;
    bool isPressed() const;
    void toPressed();
    void unPressed();
    void updateGraphique();
};


#endif //CPP_PROJET_2022_JEU_BUTTONOBJ_H
