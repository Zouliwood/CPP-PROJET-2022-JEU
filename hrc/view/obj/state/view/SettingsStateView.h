#ifndef CPP_PROJET_2022_JEU_SETTINGSSTATEVIEW_H
#define CPP_PROJET_2022_JEU_SETTINGSSTATEVIEW_H

#include "../State.h"
#include "../../composant/ButtonObj.h"

class SettingsStateView final : public State{

    /* Object */
    RenderWindow & app;
    stack<State *> * stack_display;

    /* Graphic */
    Sprite background;
    Text nombre_j, nombre_tuile;
    ButtonObj button_jouer, button_plus_j, button_moins_j, button_plus_t, button_moins_t;

    /* Parametre */
    bool pressedGame, keyPressed;
    int nombre_j_game, nombre_t_game;


public:
    SettingsStateView(RenderWindow & window, std::stack<State * > * stack_display);
    virtual ~SettingsStateView();

    void init() override;
    void processInput(Event & event) override;
    void update() override;
    void drawView() override;
};

#endif
