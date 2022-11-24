#include "../../hrc/plateau/PlateauCarcassonne.hpp"

template<typename TF>
ostream &PlateauCarcassonne<TF>::operator<<(ostream &os) {
    return os << "TODO";
}

template<typename TF>
PlateauCarcassonne<TF>::PlateauCarcassonne() = default;

template<typename TF>
int PlateauCarcassonne<TF>::calculPoint(const TF & t, int x, int y){
    return 0;
}
template<typename TF>
bool PlateauCarcassonne<TF>::placeFirstTuile() {
    return true;
}

template<typename TF>
PlateauCarcassonne<TF>::~PlateauCarcassonne() = default;
