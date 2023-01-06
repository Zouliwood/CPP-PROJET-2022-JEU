#include "../../../hrc/model/plateau/PlateauDominos.hpp"
#include "../../../hrc/model/joueurs/PlayerDominos.hpp"


int PlateauDominos::calculPoint(const TuileDominos * t, int x, int y) {
    return 0;
}

PlateauDominos::PlateauDominos(int nombre_joueur, int nombre_tuile): Plateau(nombre_joueur, nombre_tuile) {
    for(int i = 0; i < nbr_player; i++){
        string s = " Player " + to_string(i);
        listPlayer.push_back(new PlayerDominos(*new string (s)));
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

bool PlateauDominos::compareTuile(const TuileDominos * courant, const TuileDominos * tuileUp, const TuileDominos * tuileDown, const TuileDominos * tuileRight, const TuileDominos * tuileLeft){
    return (!tuileUp || *(&(FragmentTriple<int> &)courant->getUp()) == *(&(FragmentTriple<int> &)tuileUp->getDown()))
           &&  (!tuileRight || *(&(FragmentTriple<int> &)courant->getRight()) == *(&(FragmentTriple<int> &)tuileRight->getLeft()))
           && (!tuileLeft || *(&(FragmentTriple<int> &)courant->getLeft()) == *(&(FragmentTriple<int> &)tuileLeft->getRight()))
           && (!tuileDown || *(&(FragmentTriple<int> &)courant->getDown()) == *(&(FragmentTriple<int> &)tuileDown->getUp()));
}

bool PlateauDominos::checkVictory() {
    return (listPlayer.size() >= 2);
}

TuileDominos *PlateauDominos::getFirstTuilePose() {
    return domino;
}
