#include "../../hrc/model/joueurs/PlayerCarcassonne.hpp"


PlayerCarcassonne::~PlayerCarcassonne(){

}

/*
template<typename TF>
vector<Pion> PlayerCarcassonne<TF>::getListPions() {
    return listePionsJoueur;
}*/

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

int PlayerCarcassonne::getR(){
    return r;
}
int PlayerCarcassonne::getG(){
    return g;
}
int PlayerCarcassonne::getB(){
    return b;
}
