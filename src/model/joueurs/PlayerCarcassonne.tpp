#include "../../hrc/model/joueurs/PlayerCarcassonne.hpp"


template<typename TF>
PlayerCarcassonne<TF>::~PlayerCarcassonne() = default;

template<typename TF>
vector<Pion> PlayerCarcassonne<TF>::getListPions() {
    return listePionsJoueur;
}

template<typename TF>
PlayerCarcassonne<TF>::PlayerCarcassonne() = default;
