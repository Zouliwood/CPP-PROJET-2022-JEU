//
// Created by david on 17/11/22.
//

#include "../../../hrc/tuile/fragment/FragmentSolo.hpp"

template<typename T>

bool FragmentSolo<T>::operator==(const FragmentSolo<T> & fragment) {
    return this->centreFragment==fragment->centreFragment;
}

template<typename T>
bool FragmentSolo<T>::operator!=(const FragmentSolo<T> & fragment) {
    return this->centreFragment!=fragment->centreFragment;
}
