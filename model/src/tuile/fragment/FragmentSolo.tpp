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

template<typename T>
FragmentSolo<T> & FragmentSolo<T>::operator=(const FragmentSolo<T> & fragment) {
    this->centreFragment=fragment->centreFragment;
    return *this;
}

template<typename T>
int FragmentSolo<T>::getPoint() {
    return 0;
}

template<typename V>
FragmentSolo<V>::~FragmentSolo() {

}

template<typename T>
FragmentSolo<T>::FragmentSolo() = default;

