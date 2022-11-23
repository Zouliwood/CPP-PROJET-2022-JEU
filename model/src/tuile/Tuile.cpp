//
// Created by david on 13/11/22.
//

#include "../../hrc/tuile/Tuile.hpp"

template<typename TF>
Tuile<TF>::~Tuile() {

}

template<typename V>
void Tuile<V>::rotate() {

}

template<typename TF>
Tuile<TF>::Tuile(TF up, TF down, TF right, TF left): up{up}, down{down}, right{right}, left{left} {}
