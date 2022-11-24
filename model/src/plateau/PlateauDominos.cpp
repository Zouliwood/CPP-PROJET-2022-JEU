#include "../../hrc/plateau/PlateauDominos.hpp"


int PlateauDominos::calculPoint(const TuileDominos & t, int x, int y) {
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
    FragmentTriple<int> fragment = FragmentTriple<int>(5,5,5);//TODO : à revoir
    listTuile.at(middle).at(middle) = new TuileDominos(fragment,fragment,fragment,fragment);
    return (listTuile.at(middle).at(middle) != nullptr);
}

ostream &operator<<(ostream &os, PlateauDominos & plateauDominos){
    string res;
    for (int i = 0; i < plateauDominos.getListTuile().size(); ++i) {
        for (int j = 0; j < plateauDominos.getListTuile().at(i).size(); ++j) {
                if(plateauDominos.getListTuile().at(i).at(j) == nullptr){
                    res+="[X]";
                }else res+="[ T ]";
        }
        res+="\n";
    }
    return os << res << endl;
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