#include "../../hrc/model/tuile/TuileDominos.hpp"



string TuileDominos::toString(){
    return "[U:"+ ((FragmentTriple<int> &) (this->getUp())).toString() + "\n"
           + ", R:" + ((FragmentTriple<int> &) (this->getRight())).toString() + "\n"
           +", D:" + ((FragmentTriple<int> &) (this->getDown())).toString() + "\n"
           + ", L:" + ((FragmentTriple<int> &) (this->getLeft())).toString() + "]";
}

ostream & operator<<(ostream &os, TuileDominos & tdomino) {
    return os << "[U:"<< (FragmentTriple<int> &)(tdomino.getUp()) << ", R:" << (FragmentTriple<int> &)tdomino.getRight() << ", D:" << (FragmentTriple<int> &)tdomino.getDown() <<
    ", L:" << (FragmentTriple<int> &)tdomino.getLeft() << "]";
}

void TuileDominos::rotate() {
    FragmentTriple<int>* tmp = new FragmentTriple<int>(this->getUp().getFragmentDroit(), this->getUp().getFragmentCentre(), this->getUp().getFragmentGauche()) ;
    this->up = this->left;
    this->left = this->down;
    this->down = this->right;
    this->right = *tmp;
    delete tmp;
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