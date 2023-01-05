#include "../../../hrc/model/joueurs/PlayerTrax.hpp"

PlayerTrax::~PlayerTrax() {
    std::cout << "TODO : destructeur Player Trax" << std::endl;
}

colorTrax PlayerTrax::getColor() {
    return this->couleur;
}

PlayerTrax::PlayerTrax(string & pseudo): Player(pseudo){

}
