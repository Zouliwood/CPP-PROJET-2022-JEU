//
// Created by david on 13/11/22.
//

#include "../../hrc/tuile/Tuile.hpp"



template<typename TF>
Tuile<TF>::~Tuile() {

}

template<typename TF>
void Tuile<TF>::rotate() {

}

template<typename TF>
Tuile<TF>::Tuile(TF & up, TF & down, TF & right, TF & left): up{up}, down{down}, right{right}, left{left} {}

/* https://stackoverflow.com/a/8752879/16440965 */
template class Tuile<FragmentTriple<int>>;
template class Tuile<FragmentTriple<environment>>;
template class Tuile<FragmentSolo<colorTrax>>;