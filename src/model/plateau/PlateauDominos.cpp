#include "../../../hrc/model/plateau/PlateauDominos.hpp"
#include "../../../hrc/model/joueurs/PlayerDominos.hpp"


int PlateauDominos::calculPoint(const TuileDominos * t, int x, int y) {
    return 0;
}

PlateauDominos::PlateauDominos(): Plateau(2, 2) {
    for(int i = 0; i < nbr_player; i++){
        listPlayer.push_back(new PlayerDominos());
    }
    courant = listPlayer.at(current_player);
}

PlateauDominos::~PlateauDominos() {
    cout << "destructeur Plateau domino " << endl;
}

bool PlateauDominos::placeFirstTuile() {
    domino =  generateRandomTuile();
    listTuile.addElement(0, new AxeVector<TuileDominos>());
    ((AxeVector<TuileDominos> *)listTuile.getAt(0))->addElement(0, domino);
    return ((AxeVector<TuileDominos> *) listTuile.getAt(0))->getAt(0) != nullptr;
}


TuileDominos * PlateauDominos::generateRandomTuile() const{
    return new TuileDominos(
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2),
            *new FragmentTriple<int>(rand()%2,rand()%2,rand()%2)
    );
}

ostream &operator<<(ostream &os, PlateauDominos & plateauDominos){

    auto pos = plateauDominos.getListTuile().getPositif();
    auto neg = plateauDominos.getListTuile().getNegatif();

    cout << "Coter positif grand tableau Positif " <<  pos.size() << endl;
    os << endl;
    for (int i = 0; i < pos.size(); ++i) { // colonne
        for (int j = pos.at(i)->getNegatif().size()-1; j>= 0; --j) { //les lignes*
            auto tuile = ((TuileDominos *) pos.at(i)->getNegatif().at(j));
            if (tuile == nullptr) {
                os << "(x:" << j  << ":y:"<< i << ")" << "[U:X.X.X, R:X.X.X, D:X.X.X, L:X.X.X]";
            } else {
                os << "(x:" << j  << ":y:"<< i << ")" << *tuile;
            }
        }
        os <<"|";
        for (int j =  0; j < pos.at(i)->getPositif().size(); ++j) {
            auto tuile = ((TuileDominos *) pos.at(i)->getPositif().at(j));
            if(tuile == nullptr){
                os << "(x:" << j  << ":y:"<< i << ")" << "[U:X.X.X, R:X.X.X, D:X.X.X, L:X.X.X]";
            }else {
                os << "(x:" << j  << ":y:"<< i << ")" << *tuile;
            }
        }
        os << endl;
    }
    os << endl;
    cout << "Coter Grand tableau Negatif : " <<  neg.size() << endl;
    os << endl;
    for (int i = neg.size()-1; i >= 0; --i) {
        for (int j = neg.at(i)->getNegatif().size()-1; j >= 0; --j) {
            auto tuile = ((TuileDominos*)neg.at(i)->getNegatif().at(j));
            if(tuile == nullptr){
                os << "(x:" << j  << ":y:"<< i << ")" << "[U:X.X.X, R:X.X.X, D:X.X.X, L:X.X.X]";
            }else{
                os << "(x:" << j  << ":y:"<< i << ")" << *tuile;
            }
        }
        os << "|";
        for (int j = 0; j < neg.at(i)->getPositif().size(); ++j) {
            auto tuile = ((TuileDominos*)neg.at(i)->getPositif().at(j));
            if(tuile == nullptr){
                os << "(x:" << j  << ":y:"<< i << ")" << "[U:X.X.X, R:X.X.X, D:X.X.X, L:X.X.X]";
            }else{
                os << "(x:" << j  << ":y:"<< i << ")" << *tuile;
            }
        }
        os << endl;
        //os << plateauDominos.getListTuile().getNegatif().at(i);
    }
    
    os << "- affichage terminé - ";

    return os << endl;
}

bool PlateauDominos::compareTuile(const TuileDominos * courant, const TuileDominos * tuileUp, const TuileDominos * tuileDown, const TuileDominos * tuileRight, const TuileDominos * tuileLeft){
    return (!tuileUp || *(&(FragmentTriple<int> &)courant->getUp()) == *(&(FragmentTriple<int> &)tuileUp->getDown()))
           &&  (!tuileRight || *(&(FragmentTriple<int> &)courant->getRight()) == *(&(FragmentTriple<int> &)tuileRight->getLeft()))
           && (!tuileLeft || *(&(FragmentTriple<int> &)courant->getLeft()) == *(&(FragmentTriple<int> &)tuileLeft->getRight()))
           && (!tuileDown || *(&(FragmentTriple<int> &)courant->getDown()) == *(&(FragmentTriple<int> &)tuileDown->getUp()));
}

bool PlateauDominos::checkVictory() {
    return (listPlayer.size() >= 2); //TODO: && ());
}

TuileDominos *PlateauDominos::getFirstTuilePose() {
    return domino;
}

/*string res;
int size = plateauDominos.getListTuile().getNegatif().size() + plateauDominos.getListTuile().getPositif().size();
cout << "Taille du grand tableau : " << size << "--" << plateauDominos.getListTuile().getNegatif().size() << "--" << plateauDominos.getListTuile().getPositif().size() << endl;
os << "\n";
cout << "Partie Positive du plateau "<< endl;


*//*vector<TuileDominos> tempo;

tempo.reserve( plateauDominos.getListTuile().getPositif().size() + plateauDominos.getListTuile().getNegatif().size() ); // preallocate memory
tempo.insert( tempo.end(), plateauDominos.getListTuile().getNegatif().begin(), plateauDominos.getListTuile().getNegatif().end() );
tempo.insert( tempo.end(),plateauDominos.getListTuile().getPositif().begin(), plateauDominos.getListTuile().getPositif().end() );*//*

for (int i = 0; i < plateauDominos.getListTuile().getNegatif().size(); ++i) {
AxeVector<TuileDominos> * ligne = plateauDominos.getListTuile().getAt(i);
for (int j = 0; j < ligne->getNegatif().size(); ++j) {
if (ligne->getAt(j) == nullptr) {
os << "[U:0.0.0, R:0.0.0, D:0.0.0, L:0.0.0]";
} else {
os << *((TuileDominos *) ligne->getAt(j));
}
}
for (int j = 0; j <  ligne->getPositif().size(); ++j) {
if(ligne->getAt(j) == nullptr){
os << "[U:0.0.0, R:0.0.0, D:0.0.0, L:0.0.0]";
}else {
os << *((TuileDominos*) ligne->getAt(j));
}
}
os << "\n";
}
os << "\n";

cout << "Partie Negative du plateau "<< endl;
for (int i = 0; i < plateauDominos.getListTuile().getNegatif().size(); ++i) {
AxeVector<TuileDominos> *ligne = plateauDominos.getListTuile().getAt(i);
for (int j = 0; j < ligne->getNegatif().size(); ++j) {
if (ligne->getAt(j) == nullptr) {
os << "[U:0.0.0, R:0.0.0, D:0.0.0, L:0.0.0]";
} else {
os << *((TuileDominos *) ligne->getAt(j));
}
}
for (int j = 0; j <  ligne->getPositif().size(); ++j) {
if(ligne->getAt(j) == nullptr){
os << "[U:0.0.0, R:0.0.0, D:0.0.0, L:0.0.0]";
}else {
os << *((TuileDominos*) ligne->getAt(j));
}
}
os << "\n";
}*/

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