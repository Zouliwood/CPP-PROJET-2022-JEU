#include "../../../hrc/model/plateau/Plateau.hpp"

template<typename TF>
Plateau<TF>::Plateau(int nbr_player, int nbr_tuile): nbr_player{nbr_player}, current_player{0}, nbr_tuile{nbr_tuile} {}

template <typename TF>
Plateau<TF>::~Plateau(){
    cout << "destructeur plateau " << endl;
}

template <typename TF>
bool Plateau<TF>::placeTuile(TF * t, int x, int y) {

    if(getTuileAt(x, y) != nullptr) return false;

   const TF * tuileUp = getTuileAt(x, y + 1);
   const TF * tuileDown = getTuileAt(x, y - 1);
   const TF * tuileRight = getTuileAt(x + 1, y);
   const TF * tuileLeft = getTuileAt(x - 1, y);

   if(tuileLeft == nullptr && tuileRight == nullptr && tuileUp == nullptr && tuileDown == nullptr) {
       return false;
   }
    /* Redefinition de l'operateur '==' */
    bool flag = this->compareTuile(t, tuileUp, tuileDown, tuileRight, tuileLeft);
    if (flag) {
        if(y >= 0){
            if(y >= this->listTuile.getPositif().size()){
                this->listTuile.addElement(y, new AxeVector<TF>());
            }
        }else{
            if((y*-1)-1 >= this->listTuile.getNegatif().size()){
                this->listTuile.addElement(y, new AxeVector<TF>());
            }
        }
        ((AxeVector<TF> *)this->listTuile.getAt(y))->addElement(x, t);
    }
    return flag;
}

template<typename TF>
void Plateau<TF>::nextPlayer() {
    current_player= (current_player+1)%listPlayer.size();
    courant = listPlayer.at(current_player);
}

template<typename TF>
Player<TF>* Plateau<TF>::getPlayerCourant(){
    return listPlayer.at(current_player);
}

template<typename TF>
void Plateau<TF>::init(int l, int L){
    return;
}

template<typename TF>
int Plateau<TF>::nombreCarteRestant() {
    return nbr_tuile;
}

template<typename TF>
const TF * Plateau<TF>::getTuileAt(int x, int y) const{
    AxeVector<TF> * ligne = getListTuile().getAt(y);
    if(ligne == nullptr) {
        //cout << "#####Plateau getTuileAt NullPtr ######" << endl;
        return nullptr;
    }
    return (ligne->getAt(x));
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
 vector<Player<TF> *> Plateau<TF>::getListPlayer() {
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


template<typename TF>
bool Plateau<TF>::canPlay() {
    return nbr_tuile > 0 && listPlayer.size() > 1;
}

template<typename TF>
void Plateau<TF>::piocheCarte() {
    if(nbr_tuile > 0) nbr_tuile--;
}