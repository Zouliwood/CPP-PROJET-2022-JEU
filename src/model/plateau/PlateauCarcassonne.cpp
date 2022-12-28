#include "../../hrc/model/plateau/PlateauCarcassonne.hpp"


bool PlateauCarcassonne::checkVictory() {
    return false;
}

PlateauCarcassonne::PlateauCarcassonne(){};

int PlateauCarcassonne::calculPoint(const TuileCarcassonne * t, int x, int y){
    return 0;
}

TuileCarcassonne *PlateauCarcassonne::generateRandomTuile() {
    //TODO: Récupérer une tuile du Sac
    return nullptr;
}

bool PlateauCarcassonne::placeFirstTuile() {
    TuileCarcassonne * carcassonne =  generateRandomTuile();
    this->listTuile.addElement(0, new AxeVector<TuileCarcassonne>());
    ((AxeVector<TuileCarcassonne> *)this->listTuile.getAt(0))->addElement(0, carcassonne);
    return ((AxeVector<TuileDominos> *) this->listTuile.getAt(0))->getAt(0) != nullptr;
}

//TODO: add fragment centre - FragmentQuadruple -
bool PlateauCarcassonne::compareTuile(const TuileCarcassonne *courant, const TuileCarcassonne *tuileUp,
                                      const TuileCarcassonne *tuileDown, const TuileCarcassonne *tuileRight,
                                      const TuileCarcassonne *tuileLeft) {
    return (!tuileUp || *(&(FragmentTriple<environment> &)courant->getUp()) == *(&(FragmentTriple<environment> &)tuileUp->getDown()))
           &&  (!tuileRight || *(&(FragmentTriple<environment> &)courant->getRight()) == *(&(FragmentTriple<environment> &)tuileRight->getLeft()))
           && (!tuileLeft || *(&(FragmentTriple<environment> &)courant->getLeft()) == *(&(FragmentTriple<environment> &)tuileLeft->getRight()))
           && (!tuileDown || *(&(FragmentTriple<environment> &)courant->getDown()) == *(&(FragmentTriple<environment> &)tuileDown->getUp()));
}

bool PlateauCarcassonne::pionPresent(int x, int y, int posFrag, environment env){
    bool reponse = pionPresentAux(x, y, posFrag, env);
    dejaVu.clear();
    return reponse;
}

bool PlateauCarcassonne::isDejaVu(int x, int y, int pos){
    for(auto item : dejaVu) if(item->x == x && item->y == y && item->pos == pos)return true;
    return false;
}

bool PlateauCarcassonne::pionPresentAux(int x, int y, int posFrag, environment env){
    return false;
}

PlateauCarcassonne::~PlateauCarcassonne() = default;