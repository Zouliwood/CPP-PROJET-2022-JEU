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
    //int middle = listTuile.size()/2;
    //  listTuile.at(middle).at(middle) = domino;
    TuileDominos * domino =  generateRandomTuile();
    listTuile.addElement(0, new AxeVector<TuileDominos>());
    cout << "Ligne ajoutée !" << endl;
    ((AxeVector<TuileDominos> *)listTuile.getAt(0))->addElement(0, domino);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>" << listTuile.getAt(0)->getAt(0) << endl;
    return ((AxeVector<TuileDominos> *) listTuile.getAt(0))->getAt(0) != nullptr;
}


TuileDominos * PlateauDominos::generateRandomTuile() const{
    /*return new TuileDominos(
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2)
    );*/
    return new TuileDominos(
            *new FragmentTriple<int>(1,1,1),
            *new FragmentTriple<int>(2,2,2),
            *new FragmentTriple<int>(3,3,3),
            *new FragmentTriple<int>(4,4,4)
    );
}

ostream &operator<<(ostream &os, PlateauDominos & plateauDominos){
    string res;
    int size = plateauDominos.getListTuile().getNegatif().size() + plateauDominos.getListTuile().getPositif().size();
    cout << "Taille du grand tableau : " << size << endl;
    for (int i = 0; i < size; ++i) {
        AxeVector<TuileDominos> * ligne = plateauDominos.getListTuile().getAt(0);
        int size_ligne = ligne->getPositif().size() + ligne->getNegatif().size();
        for (int j = 0; j < size_ligne; ++j) {
                if(ligne->getAt(0) == nullptr){
                    os << "[U:0.0.0, R:0.0.0, D:0.0.0, L:0.0.0]";
                }else {
                    os << ((TuileDominos*) ligne->getAt(0))->toString();
                }
        }
        os << "\n";
    }
    return os << endl;
}

bool PlateauDominos::compareTuile(const TuileDominos * courant, const TuileDominos * tuileUp, const TuileDominos * tuileDown, const TuileDominos * tuileRight, const TuileDominos * tuileLeft){
    return (!tuileUp || *(&(FragmentTriple<int> &)courant->getUp()) == *(&(FragmentTriple<int> &)tuileUp->getDown()))
           &&  (!tuileRight || *(&(FragmentTriple<int> &)courant->getRight()) == *(&(FragmentTriple<int> &)tuileRight->getLeft()))
           && (!tuileLeft || *(&(FragmentTriple<int> &)courant->getLeft()) == *(&(FragmentTriple<int> &)tuileLeft->getRight()))
           && (!tuileDown || *(&(FragmentTriple<int> &)courant->getDown()) == *(&(FragmentTriple<int> &)tuileDown->getUp()));
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