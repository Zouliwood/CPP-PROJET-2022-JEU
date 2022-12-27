#include "../../../hrc/model/tuile/TuileCarcassonne.hpp"

TuileCarcassonne::TuileCarcassonne(FragmentTriple<environment> &up, FragmentTriple<environment> &right, FragmentTriple<environment> &down,
                                       FragmentTriple<environment> &left, FragmentQuadruple<environment> &center) :
    Tuile<FragmentTriple<environment>>(up, right, down, left),
    centre{center} {}

TuileCarcassonne::~TuileCarcassonne() = default;

void TuileCarcassonne::rotate() {
    FragmentTriple<environment>* tmp = new FragmentTriple<environment>(this->getUp().getFragmentDroit(), this->getUp().getFragmentCentre(), this->getUp().getFragmentGauche()) ;
    this->up = this->left;
    this->left = this->down;
    this->down = this->right;
    this->right = *tmp;
    delete tmp;
}

const FragmentQuadruple<environment> &TuileCarcassonne::getCentre() const {
    return this->centre;
}
