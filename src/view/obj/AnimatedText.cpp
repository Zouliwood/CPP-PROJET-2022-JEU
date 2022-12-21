//
// Created by root0 on 15/12/22.
//

#include "AnimatedText.h"

AnimatedText::AnimatedText(string str, Font font, unsigned int size) : text{str, font, size}{

}

void AnimatedText::show(string newstr, float time) {
    float count{time};// = time;
    int color_alpha = 255;
    timer = cl.restart();
    while(count > 0){
        timer = cl.restart();
        count -= timer.asSeconds();
        text.setString(newstr);
        text.setFillColor(Color(text.getFillColor().r, text.getFillColor().g, text.getFillColor().b, color_alpha));
    }
    text.setFillColor(Color(text.getFillColor().r, text.getFillColor().g, text.getFillColor().b));

}
