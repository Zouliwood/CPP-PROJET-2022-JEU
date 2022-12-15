#include "../../../hrc/model/tuile/TuileCarcassonne.hpp"

template<typename TF>
TuileCarcassonne<TF>::TuileCarcassonne(FragmentTriple<TF> &up, FragmentTriple<TF> &right, FragmentTriple<TF> &down,
                                       FragmentTriple<TF> &left, FragmentQuadruple<TF> &center) :
    Tuile<TF>(up, right, down, left),
    centre{center} {}

template<typename TF>
TuileCarcassonne<TF>::~TuileCarcassonne() = default;

template<typename V>
void TuileCarcassonne<V>::rotate() {
    FragmentTriple<V>* tmp = new FragmentTriple<V>(this->getUp().getFragmentDroit(), this->getUp().getFragmentCentre(), this->getUp().getFragmentGauche()) ;
    this->up = this->left;
    this->left = this->down;
    this->down = this->right;
    this->right = *tmp;
    delete tmp;
}

template<typename TF>
const TF &TuileCarcassonne<TF>::getCentre() const {
    return this->centre;
}
