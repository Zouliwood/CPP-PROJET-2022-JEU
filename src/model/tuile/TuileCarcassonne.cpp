#include "../../../hrc/model/tuile/TuileCarcassonne.hpp"

TuileCarcassonne::TuileCarcassonne(int x_view, int y_view, FragmentTriple<environment> &up, FragmentTriple<environment> &right, FragmentTriple<environment> &down,
                                   FragmentTriple<environment> &left, FragmentQuadruple<environment> &center) :
        Tuile<FragmentTriple<environment>>(up, right, down, left),
        x_pos_view{x_view},
        y_pos_view{y_view},
        centre{center} {}

TuileCarcassonne::~TuileCarcassonne() = default;

void TuileCarcassonne::rotate() {
    rotation = (rotation+90)%360;
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
