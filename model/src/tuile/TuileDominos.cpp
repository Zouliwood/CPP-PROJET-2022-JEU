#include "../../hrc/tuile/TuileDominos.hpp"


void TuileDominos::rotate() {
    FragmentTriple<int> & tmp = this->up;
    this->up = this->left;
    this->left = this->down;
    this->down = this->right;
    this->right = tmp;
}

string TuileDominos::toString(){
    return ((FragmentTriple<int> &) (this->getLeft())).toString()
    + ((FragmentTriple<int> &) (this->getDown())).toString()
    + ((FragmentTriple<int> &) (this->getUp())).toString()
    + ((FragmentTriple<int> &) (this->getRight())).toString();
}

ostream & operator<<(ostream &os, TuileDominos & tdomino) {
    return os << "[Up: "<< (FragmentTriple<int> &)(tdomino.getUp()) << ", Right: " << (FragmentTriple<int> &)tdomino.getRight() << ", Down:" << (FragmentTriple<int> &)tdomino.getDown() <<
    ", Left:" << (FragmentTriple<int> &)tdomino.getLeft() << "]" << endl;
}

//TODO: revoir
TuileDominos::TuileDominos(FragmentTriple<int> & up, FragmentTriple<int> & right, FragmentTriple<int> & down , FragmentTriple<int> & left): Tuile(up, down, right, left) {
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