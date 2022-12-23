#ifndef CPP_PROJET_2022_JEU_SETTINGSSTATEVIEW_H
#define CPP_PROJET_2022_JEU_SETTINGSSTATEVIEW_H

#include "State.h"
#include "obj/ButtonObj.h"

class SettingsStateView final : public State{

    RenderWindow & app;
    stack<State *> * stack_display;
    Sprite background;
    Text nombre_j, nombre_tuile;
    ButtonObj button_jouer, button_plus_j, button_moins_j, button_plus_t, button_moins_t;
    bool pressedGame = true;
    int nombre_j_game = 2;
    int nombre_t_game = 10;


public:
    SettingsStateView(RenderWindow & window, std::stack<State * > * stack_display);
    ~SettingsStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};


#endif
