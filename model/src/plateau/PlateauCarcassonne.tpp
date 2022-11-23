#include "../../hrc/plateau/PlateauCarcassonne.hpp"

template<typename T>


ostream &PlateauCarcassonne<T>::operator<<(ostream &os) {
    return os << "TODO";
}

template<typename V>
PlateauCarcassonne<V>::PlateauCarcassonne() = default;

template<typename V>
int PlateauCarcassonne<V>::calculPoint(const Tuile<FragmentTuile<V>> & t, int x, int y){
    return 0;
}

template<typename V>
PlateauCarcassonne<V>::~PlateauCarcassonne() = default;
