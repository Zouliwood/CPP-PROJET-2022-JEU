#include "../../../hrc/model/joueurs/PlayerTrax.hpp"

PlayerTrax::PlayerTrax(string & pseudo): Player(pseudo){}
PlayerTrax::~PlayerTrax() {}
colorTrax PlayerTrax::getColor() {
    return this->couleur;
}

