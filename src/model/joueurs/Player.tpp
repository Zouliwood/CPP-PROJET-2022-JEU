#include "../../../hrc/model/joueurs/Player.hpp"


template<typename TF>
Player<TF>::~Player() = default;

template<typename TF>
TF * Player<TF>::getTuile() {
    return tuilecourante;
}

template<typename TF>
void Player<TF>::setTuile(TF * newTuile) {
    tuilecourante = newTuile;
}

template<typename TF>
string Player<TF>::getName() {
    return pseudo;
}

template<typename TF>
int Player<TF>::getPoints() {
    return points;
}

template<typename TF>
Player<TF>::Player(string & pseudo): pseudo{pseudo} , tuilecourante{nullptr} {}