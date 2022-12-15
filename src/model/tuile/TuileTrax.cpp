#include "../../../hrc/model/tuile/TuileTrax.hpp"

void TuileTrax::rotate() {
    FragmentSolo<colorTrax>* tmp = new FragmentSolo<colorTrax>(this->getUp().getFragmentCentre());
    this->up = this->left;
    this->left = this->down;
    this->down = this->right;
    this->right = *tmp;
    delete tmp;
}

void TuileTrax::flipTuile() {
    if (this->getUp()==this->getDown()){
        //cas tuile recto
        this->up.setFragmentCentre(colorTrax::NOIR);
        this->right.setFragmentCentre(colorTrax::BLANC);
        this->down.setFragmentCentre(colorTrax::BLANC);
        this->left.setFragmentCentre(colorTrax::NOIR);
    }else{
        this->up.setFragmentCentre(colorTrax::NOIR);
        this->right.setFragmentCentre(colorTrax::BLANC);
        this->down.setFragmentCentre(colorTrax::NOIR);
        this->left.setFragmentCentre(colorTrax::BLANC);
    }
}

TuileTrax::TuileTrax(FragmentSolo<colorTrax> & up,FragmentSolo<colorTrax> & right,FragmentSolo<colorTrax> & down ,FragmentSolo<colorTrax> & left):
    Tuile(up, right, down, left) {//TODO : à revoir
    cout << "TuileTrax " << endl;
}

TuileTrax::~TuileTrax() {
    cout << " destructeur TuileTrax " << endl;
}

ostream & operator<<(ostream &os, const TuileTrax & ttrax) {
    return os << "[U:"<< (FragmentSolo<colorTrax> &)(ttrax.getUp()) << ", R:" << (FragmentSolo<colorTrax> &)ttrax.getRight() << ", D:" << (FragmentSolo<colorTrax> &)ttrax.getDown() <<
              ", L:" << (FragmentSolo<colorTrax> &)ttrax.getLeft() << "]";
}
