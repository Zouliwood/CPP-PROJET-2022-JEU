//
// Created by david on 13/11/22.
//

#include "../../hrc/tuile/TuileDominos.hpp"

void TuileDominos::rotate() {
    FragmentTriple<int> & tmp = this->up;
    this->up= (this->left);
    this->left= (this->down);
    this->down= (this->right);
    this->right=tmp;
}

/*template<typename T>
void TuileDominos<T>::swapTab(FragmentTriple<int> & first , FragmentTriple<int> & second) {
    first=second;
}*/

/*
bool TuileDominos::isValide(TuileDominos, enum directionTuile) {
    switch (directionTuile) {

    }
    return equals(up., ) || equals(right, tuile.left) || equals(down, tuile.up) || equals(left, tuile.right);
}
*/