#include "../../hrc/model/joueurs/Player.hpp"


template<typename TF>
Player<TF>::~Player() = default;

template<typename TF>
TF Player<TF>::getTuile() const {
    return TF();
}

template<typename TF>
int Player<TF>::getPoints() {
    return points;
}

template<typename TF>
Player<TF>::Player(){}


