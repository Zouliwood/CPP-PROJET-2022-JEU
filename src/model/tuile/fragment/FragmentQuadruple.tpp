//
// Created by david on 11/12/22.
//

#include "../../../../hrc/model/tuile/fragment/FragmentQuadruple.hpp"

template<typename V>
const V &FragmentQuadruple<V>::getFragmentTop() const {
    return this->hautFragment;
}

template<typename V>
const V &FragmentQuadruple<V>::getFragmentRight() const {
    return this->droitFragment;
}

template<typename V>
const V &FragmentQuadruple<V>::getFragmentDown() const {
    return this->centreFragment;
}

template<typename V>
const V &FragmentQuadruple<V>::getFragmentLeft() const {
    return this->gaucheFragment;
}


template<typename V>
FragmentQuadruple<V>::FragmentQuadruple(V hautFragment, V droitFragment, V basFragment, V gaucheFragment) :
            hautFragment{hautFragment}, droitFragment{droitFragment},
            gaucheFragment{gaucheFragment}, FragmentTuile<V>(basFragment)
            {}



template<typename V>
FragmentQuadruple<V>::~FragmentQuadruple() {

}