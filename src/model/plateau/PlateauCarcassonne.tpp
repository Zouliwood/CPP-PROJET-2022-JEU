#include "../../hrc/model/plateau/PlateauCarcassonne.hpp"

template<typename F>
bool PlateauCarcassonne<F>::checkVictory() {
    return false;
}

template<typename TF>
ostream &PlateauCarcassonne<TF>::operator<<(ostream &os) {
    return os << "TODO";
}

template<typename TF>
PlateauCarcassonne<TF>::PlateauCarcassonne() = default;

template<typename TF>
int PlateauCarcassonne<TF>::calculPoint(const TF * t, int x, int y){
    return 0;
}
template<typename TF>
bool PlateauCarcassonne<TF>::placeFirstTuile() {
    return true;
}

template<typename F>
bool PlateauCarcassonne<F>::compareTuile(TuileCarcassonne<F> *courant, TuileCarcassonne<F> *tuileUp,
                                         TuileCarcassonne<F> *tuileDown, TuileCarcassonne<F> *tuileRight,
                                         TuileCarcassonne<F> *tuileLeft) {
    return false;
}

template<typename TF>
PlateauCarcassonne<TF>::~PlateauCarcassonne() = default;