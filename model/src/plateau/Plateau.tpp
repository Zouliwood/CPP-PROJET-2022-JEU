#include "../../hrc/plateau/Plateau.hpp"
#include "../../hrc/tuile/Tuile.hpp"

//TODO: constant de condition

template <typename TF>
Plateau<TF>::Plateau(): current_player{0}{}

template <typename TF>
Plateau<TF>::~Plateau(){
    cout << "destructeur plateau " << endl;
}

template <typename TF>
bool Plateau<TF>::placeTuile(TF * t, int x, int y) {

   const TF * tuileUp = getTuileAt(x, y + 1);
   const TF * tuileDown = getTuileAt(x, y - 1);
   const TF * tuileRight = getTuileAt(x + 1, y);
   const TF * tuileLeft = getTuileAt(x - 1, y);

    if (tuileUp == nullptr && tuileDown == nullptr && tuileRight == nullptr && tuileLeft == nullptr) {
        return false;
    }

    /* Redefinition de l'operateur '==' */
    bool flag = this->compareTuile(t, tuileUp, tuileDown, tuileRight, tuileLeft);
    if (flag) ((AxeVector<TF> *)this->listTuile.getAt(y))->addElement(x, t);
    return flag;
}

template<typename TF>
void Plateau<TF>::nextPlayer() {
    current_player= (current_player+1)%listPlayer.size();
}

template<typename TF>
const Player<TF>* Plateau<TF>::getPlayerCourant() const{
    return  listPlayer.at(current_player);
}

template<typename TF>
void Plateau<TF>::init(int l, int L){
    return;
}

template<typename TF>
const TF * Plateau<TF>::getTuileAt(int x, int y) const{
    AxeVector<TF> * ligne = getListTuile().getAt(x);
    if(ligne == nullptr) return nullptr;
    return (ligne->getAt(y));
}

template<typename TF>
ostream & Plateau<TF>::operator<<(ostream &os) {
    string res;
    for (int i = 0; i < listTuile.size(); ++i) {
        for (int j = 0; j < listTuile.at(i).size(); ++j) {
            os << "[X,X,X,X]";
        }
        os << "\n";
    }
    return os << endl;
}

 template<typename TF>
 vector<const Player<TF> *> Plateau<TF>::getListPlayer() const {
     return this->listPlayer;
 }

 template<typename TF>
 AxeVector<AxeVector<TF>> Plateau<TF>::getListTuile() const {
     return this->listTuile;
 }

 template<typename TF>
 int Plateau<TF>::getCurrentPlayer() {
     return this->current_player;
 }

