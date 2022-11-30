#include "../../hrc/model/tuile/TuileTrax.hpp"

void TuileTrax::rotate() {

}

TuileTrax::TuileTrax(FragmentSolo<colorTrax> & up,FragmentSolo<colorTrax> & right,FragmentSolo<colorTrax> & down ,FragmentSolo<colorTrax> & left): Tuile(up, right, down, left) {//TODO : à revoir
    cout << "TuileTrax " << endl;
}

TuileTrax::~TuileTrax() {
    cout << " destructeur TuileTrax " << endl;
}


