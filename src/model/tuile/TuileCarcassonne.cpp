#include "../../../hrc/model/tuile/TuileCarcassonne.hpp"

TuileCarcassonne::TuileCarcassonne(int x_view, int y_view, FragmentTriple<environment> &up, FragmentTriple<environment> &right, FragmentTriple<environment> &down,
                                   FragmentTriple<environment> &left, FragmentQuadruple<environment> &center) :
        Tuile<FragmentTriple<environment>>(up, right, down, left),
        centre{center},
        x_pos_view{x_view},
        y_pos_view{y_view},
        rotation{0}{}

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

environment TuileCarcassonne::transformNumToEnv(int pos) {
    switch (pos) {
        case 0: return up.getFragmentGauche();
        case 1: return up.getFragmentCentre();
        case 2: return up.getFragmentDroit();
        case 3: return left.getFragmentGauche();
        case 4: return centre.getFragmentTop();
        case 5: return right.getFragmentGauche();
        case 6: return left.getFragmentCentre();
        case 7: return centre.getFragmentLeft();
        case 8: return centre.getFragmentRight();
        case 9: return  right.getFragmentCentre();
        case 10: return left.getFragmentGauche();
        case 11: return centre.getFragmentDown();
        case 12: return right.getFragmentDroit();
        case 13: return down.getFragmentGauche();
        case 14: return down.getFragmentCentre();
        default : return down.getFragmentDroit();
    }
}

const FragmentQuadruple<environment> &TuileCarcassonne::getCentre() const {
    return this->centre;
}
