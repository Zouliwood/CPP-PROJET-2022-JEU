//
// Created by david on 18/11/22.
//

#include "../../hrc/plateau/PlateauDominos.hpp"

//TODO: https://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c
// pour calculer les points en fonction du type de l'objet
template<typename T>
int PlateauDominos<T>::calculPoint(const Tuile<T> & t, int x, int y) {
    Tuile<FragmentTuile<T>> & tuileUp = this->getTuileAt(x,y+1);
    Tuile<FragmentTuile<T>> & tuileDown = this->getTuileAt(x,y-1);
    Tuile<FragmentTuile<T>> & tuileRight= this->getTuileAt(x+1,y);
    Tuile<FragmentTuile<T>> & tuileLeft= this->getTuileAt(x-1,y);
    int somme = 0;
    if(tuileUp->up == t->down)somme+=t->up.getPoint();
    if(tuileDown->down == t->up)somme+=t->down.getPoint();
    if(tuileRight->right == t->left)somme+=t->right.getPoint();
    if(tuileLeft->left == t->left)somme+=t->left.getPoint();
    return somme;
}

template<typename T>
ostream &PlateauDominos<T>::operator<<(ostream &os) {
    return os << "TODO";
}
