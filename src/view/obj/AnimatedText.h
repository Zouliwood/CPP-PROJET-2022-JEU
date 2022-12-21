//
// Created by root0 on 15/12/22.
//

#ifndef CPP_PROJET_2022_JEU_ANIMATEDTEXT_H
#define CPP_PROJET_2022_JEU_ANIMATEDTEXT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/System.hpp>
#include "../TuileView.h"

class AnimatedText {

    Time timer;
    Clock cl;

public :
    Text text;

    AnimatedText(string str, Font font, unsigned int size);
    void show(string newstr, float time);
    void show(float time);
};


#endif //CPP_PROJET_2022_JEU_ANIMATEDTEXT_H
