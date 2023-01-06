#include "../../../hrc/model/joueurs/PlayerCarcassonne.hpp"


PlayerCarcassonne::~PlayerCarcassonne(){}

PlayerCarcassonne::PlayerCarcassonne(string & pseudo): Player(pseudo), r{(rand()%255)}, g{(rand()%255)}, b{(rand()%255)}{
    for (int i = 0; i < 8; ++i) {
        this->listPion.push_back(new Pion());
    }
}

Pion * PlayerCarcassonne::getPionLibre() {
    for (int i = 0; i < 8; ++i) {
        Pion * p = listPion.at(i);
        if (!p->getIsPlaced()){
            return p;
        }
    }
    return nullptr;
}

int PlayerCarcassonne::getR() const{
    return r;
}

int PlayerCarcassonne::getG() const{
    return g;
}

int PlayerCarcassonne::getB() const{
    return b;
}

vector<Pion *> PlayerCarcassonne::getListPion() const {
    return listPion;
}
