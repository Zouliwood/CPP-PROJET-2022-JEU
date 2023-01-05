#include "../../../hrc/model/joueurs/Player.hpp"


template<typename TF>
Player<TF>::Player() {

}

template<typename TF>
Player<TF>::~Player() {
    if(tuilecourante != nullptr) delete tuilecourante;
}

template<typename TF>
TF & Player<TF>::getTuile() const {
    return tuilecourante;
}

template<typename TF>
void Player<TF>::setTuile(TF & tuile ) const {
    tuilecourante = tuile;
}

template<typename TF>
int Player<TF>::getPoints() {
    return points;
}


