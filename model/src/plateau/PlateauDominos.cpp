#include "../../hrc/plateau/PlateauDominos.hpp"


ostream &PlateauDominos::operator<<(ostream &os) {
    return os << "TODO";
}

int PlateauDominos::calculPoint(const Tuile<FragmentTuile<int>> & t, int x, int y) {
    return 0;
}

PlateauDominos::PlateauDominos(){
    cout << "Plateau domino " << endl;
}

PlateauDominos::~PlateauDominos(){
    cout << "destructeur Plateau domino " << endl;
}


/*
int PlateauDominos::calculPoint(const Tuile<FragmentTriple<int>> &t, int x, int y) {
    const TuileDominos & tuileUp = this->getTuileAt(x,y+1);
    const TuileDominos & tuileDown = this->getTuileAt(x,y-1);
    const TuileDominos & tuileRight= this->getTuileAt(x+1,y);
    const TuileDominos & tuileLeft= this->getTuileAt(x-1,y);
    int somme = 0;
    if(tuileUp->up == t->down)somme+=t->up.getPoint();
    if(tuileDown->down == t->up)somme+=t->down.getPoint();
    if(tuileRight->right == t->left)somme+=t->right.getPoint();
    if(tuileLeft->left == t->left)somme+=t->left.getPoint();
    return somme;
}
*/