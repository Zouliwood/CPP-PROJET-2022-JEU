#include "../../../hrc/model/plateau/Plateau.hpp"
#include "../../../hrc/model/tuile/Tuile.hpp"
#include "../../../hrc/model/tuile/TuileDominos.hpp"

//TODO: constant de condition

template <typename TF>
Plateau<TF>::Plateau(): current_player{0}{}

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

    /*cout << "Up" << (const_cast<TuileDominos*>(tuileUp))
    << " D" << (const_cast<TuileDominos*>(tuileDown))
    << " R" << (const_cast<TuileDominos*>(tuileRight))
    << " L" << (const_cast<TuileDominos*>(tuileLeft)) << endl;*/

    /* Redefinition de l'operateur '==' */
    bool flag = this->compareTuile(t, tuileUp, tuileDown, tuileRight, tuileLeft);
    if (flag) {
        cout << "Compare Place tuile ok " << endl;
        if(y >= 0){
            if(y >= this->listTuile.getPositif().size()){
                this->listTuile.addElement(y, new AxeVector<TF>());
            }
        }else{
            if((y*-1)-1 >= this->listTuile.getNegatif().size()){
                cout << "Creation nouvelle tuile" << endl;
                this->listTuile.addElement(y, new AxeVector<TF>());
            }
        }
        cout <<"On vient de poser la tuile correctement en position x:" << x << " y : "<< y << " ?:" << (y*-1)-1 << endl;
        //TODO: faire neg ca marche passssssssssssssssss
        ((AxeVector<TF> *)this->listTuile.getAt(y))->addElement(x, t);
    }
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

