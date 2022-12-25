#include "../../../../hrc/view/obj/composant/ComposantView.h"

ComposantView::ComposantView(){}

void ComposantView::draw(RenderTarget &target, sf::RenderStates states) const {
    for(auto it : position_element) {
        it.first->setPosition(getPosition().x+ it.second.first, getPosition().y + it.second.second);
        target.draw(*it.first);
    }
}

void ComposantView::addDrawable(int x, int y, ComposantView * obj_view) {
    position_element.insert({obj_view, pair<int,int>(x,y)});
}

Text ComposantView::createText(const string& text, string font, unsigned size_font, Color color) {
    Font * createFont = new Font();
    Text * createText = new Text();
    createFont->loadFromFile(font);//);
    createText->setCharacterSize(size_font);
    createText->setFont(*createFont);
    createText->setFillColor(color);
    createText->setString(text);
    return *createText;
}

Text ComposantView::createText(const string& text) {
    return createText(text, "../ressources/font/8bits.ttf", 40, Color::Black);
}

Text ComposantView::createText(const string& text, unsigned size_font, Color color) {
    return createText(text, "../ressources/font/8bits.ttf", size_font, color);
}

ComposantView::~ComposantView() {
    while (!position_element.empty()) delete position_element.end()->first;
    delete &position_element;
}


