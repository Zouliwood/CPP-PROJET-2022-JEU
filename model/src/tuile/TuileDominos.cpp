//
// Created by david on 13/11/22.
//

#include "../../hrc/tuile/TuileDominos.hpp"

template<typename T>
void TuileDominos<T>::rotate() {
    FragmentTriple<int> & tmp = *(this->up);
    swapTab(this->up, this->left);
    swapTab(this->left, this->down);
    swapTab(this->down, this->right);
    swapTab(this->right, tmp);
}

template<typename T>
void TuileDominos<T>::swapTab(FragmentTriple<int> & first , FragmentTriple<int> & second) {
    first.setFragmentDroit(second.getFragmentDroit());
    first.setFragmentGauche(second.getFragmentGauche());
    first.setFragmentCentre(second.getFragmentCentre());
}

/*
bool TuileDominos::isValide(TuileDominos, enum directionTuile) {
    switch (directionTuile) {

    }
    return equals(up., ) || equals(right, tuile.left) || equals(down, tuile.up) || equals(left, tuile.right);
}
*/