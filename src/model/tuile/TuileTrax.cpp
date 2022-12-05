#include "../../hrc/model/tuile/TuileTrax.hpp"

void TuileTrax::rotate() {
    FragmentSolo<colorTrax>* tmp = new FragmentSolo<colorTrax>(this->getUp().getFragmentCentre());
    this->up = this->left;
    this->left = this->down;
    this->down = this->right;
    this->right = *tmp;
    delete tmp;
}

TuileTrax::TuileTrax(FragmentSolo<colorTrax> & up,FragmentSolo<colorTrax> & right,FragmentSolo<colorTrax> & down ,FragmentSolo<colorTrax> & left): Tuile(up, right, down, left) {//TODO : à revoir
    cout << "TuileTrax " << endl;
}

TuileTrax::~TuileTrax() {
    cout << " destructeur TuileTrax " << endl;
}

ostream & operator<<(ostream &os, const TuileTrax & ttrax) {
    return os << "[U:"<< (FragmentSolo<colorTrax> &)(ttrax.getUp()) << ", R:" << (FragmentSolo<colorTrax> &)ttrax.getRight() << ", D:" << (FragmentSolo<colorTrax> &)ttrax.getDown() <<
              ", L:" << (FragmentSolo<colorTrax> &)ttrax.getLeft() << "]";
}

void TuileTrax::flipTuile() {

}


