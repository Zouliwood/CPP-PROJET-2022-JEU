#include "../../hrc/plateau/PlateauDominos.hpp"


int PlateauDominos::calculPoint(const TuileDominos * t, int x, int y) {
    return 0;
}

PlateauDominos::PlateauDominos(){
    cout << "Plateau domino " << endl;
}

PlateauDominos::~PlateauDominos(){
    cout << "destructeur Plateau domino " << endl;
}

bool PlateauDominos::placeFirstTuile(){
    int middle = listTuile.size()/2;
    TuileDominos * domino =  generateRandomTuile();
    listTuile.at(middle).at(middle) = domino;
    return (listTuile.at(middle).at(middle) != nullptr);
}


TuileDominos * PlateauDominos::generateRandomTuile() const{
    /*return new TuileDominos(
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2)
    );*/
    return new TuileDominos(
            *new FragmentTriple<int>(5,5,5),
            *new FragmentTriple<int>(1,1,1),
            *new FragmentTriple<int>(5,5,5),
            *new FragmentTriple<int>(5,5,5)
    );
}

ostream &operator<<(ostream &os, PlateauDominos & plateauDominos){
    string res;
    for (int i = 0; i < plateauDominos.getListTuile().size(); ++i) {
        for (int j = 0; j < plateauDominos.getListTuile().at(i).size(); ++j) {
                if(plateauDominos.getListTuile().at(i).at(j) == nullptr){
                    os << "[U:0.0.0, R:0.0.0, D:0.0.0, L:0.0.0]";
                }else {
                    os << *plateauDominos.getListTuile().at(i).at(j);
                }
        }
        os << "\n";
    }
    return os << endl;
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