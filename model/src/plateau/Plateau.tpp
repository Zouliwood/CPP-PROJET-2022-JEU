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
bool Plateau<TF>::placeTuile(const TF & t, int x, int y){

    if(x > this->listTuile.size() || y > this->listTuile.at(0).size() || x<0 || y<0){
        return false;
    }
    TF tuileUp = getTuileAt(x,y+1);
    TF tuileDown = getTuileAt(x,y-1);
    TF tuileRight= getTuileAt(x+1,y);
    TF tuileLeft= getTuileAt(x-1,y);

    if(tuileUp == nullptr && tuileDown == nullptr && tuileRight == nullptr && tuileLeft == nullptr){
            return false;
    }

    /* Redefinition de l'operateur '==' */
    bool flag = (!tuileUp || t.up == tuileUp.down) || (!tuileRight || t.right ==  tuileRight.left)
                || (!tuileLeft || t.left ==  tuileRight.right) || (!tuileDown || t.down ==  tuileDown.up);

    if(flag) this->listTuile.at(x).at(y) = t;
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
    for (int i = 0; i < l; ++i) {
        vector<TF *> ligne;
        for (int j = 0; j < L; ++j) {
            ligne.push_back(nullptr);
        }
        listTuile.push_back(ligne);
    }
}

template<typename TF>
const TF & Plateau<TF>::getTuileAt(int x, int y) const {
    if(x > this->listTuile.size() || y > this->listTuile.at(0).size() || x<0 || y<0){
        return nullptr;
    }else return listTuile.at(x).at(y);
}

template<typename TF>
ostream & Plateau<TF>::operator<<(ostream &os) {
    string res;
    for (int i = 0; i < listTuile.size(); ++i) {
        for (int j = 0; j < listTuile.at(i).size(); ++j) {
             res+="[X,X,X,X]";
        }
        res+="\n";
    }
    return os << "blalalalalla" << endl;
}

 template<typename TF>
 vector<const Player<TF> *> Plateau<TF>::getListPlayer() const {
     return this->listPlayer;
 }

 template<typename TF>
 vector<vector<TF *>> Plateau<TF>::getListTuile() const {
     return this->listTuile;
 }

 template<typename TF>
 int Plateau<TF>::getCurrentPlayer() {
     return this->current_player;
 }

