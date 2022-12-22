#ifndef CPP_PROJET_2022_JEU_SETTINGSSTATEVIEW_H
#define CPP_PROJET_2022_JEU_SETTINGSSTATEVIEW_H

#include "State.h"
#include "obj/ButtonObj.h"

class SettingsStateView final : public State{

    RenderWindow & app;
    stack<State *> * stack_display;
    Sprite background;
    Text nombre_j, nombre_tuile;
    ButtonObj jouer;

public:
    SettingsStateView(RenderWindow & window, std::stack<State * > * stack_display);
    ~SettingsStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};


#endif
