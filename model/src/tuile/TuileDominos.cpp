#include "../../hrc/tuile/TuileDominos.hpp"


void TuileDominos::rotate() {
    FragmentTriple<int> & tmp = this->up;
    this->up = this->left;
    this->left = this->down;
    this->down = this->right;
    this->right = tmp;
}

ostream &TuileDominos::operator<<(ostream &os) {
    return os << "[TUILE DOMINOS]" <<endl;
}

//TODO: revoir
TuileDominos::TuileDominos(FragmentTriple<int> & up,FragmentTriple<int> & right,FragmentTriple<int> & down ,FragmentTriple<int> & left): Tuile(up, down, right, left) {
    cout << "TuileDominos " << endl;
}

TuileDominos::~TuileDominos() {
    cout << " destructeur TuileDominos " << endl;
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