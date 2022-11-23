#include "../../hrc/joueurs/Player.hpp"


template<typename V>
Player<V>::~Player() = default;

template<typename V>
Tuile<FragmentTuile<V>> Player<V>::getTuile() const {
    return Tuile<FragmentTuile<V>>();
}

template<typename V>
int Player<V>::getPoints() {
    return points;
}

template<typename V>
Player<V>::Player(){}


