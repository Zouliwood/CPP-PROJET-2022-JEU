#include "../../hrc/plateau/Plateau.hpp"
#include "../../hrc/tuile/Tuile.hpp"

//TODO: constant de condition

template <typename V, typename TF>
bool Plateau<V, TF>::placeTuile(const Tuile<FragmentTuile<V>> & t, int x, int y){

    if(x > this->listTuile.size() || y > this->listTuile.at(0).size() || x<0 || y<0){
        return false;
    }
    Tuile<FragmentTuile<V>> tuileUp = getTuileAt(x,y+1);
    Tuile<FragmentTuile<V>> tuileDown = getTuileAt(x,y-1);
    Tuile<FragmentTuile<V>> tuileRight= getTuileAt(x+1,y);
    Tuile<FragmentTuile<V>> tuileLeft= getTuileAt(x-1,y);

    if(tuileUp == nullptr && tuileDown == nullptr && tuileRight == nullptr && tuileLeft == nullptr){
            return false;
    }

    /* Redefinition de l'operateur '==' */
    bool flag = (!tuileUp || t.up == tuileUp.down) || (!tuileRight || t.right ==  tuileRight.left)
                || (!tuileLeft || t.left ==  tuileRight.right) || (!tuileDown || t.down ==  tuileDown.up);

    if(flag) this->listTuile.at(x).at(y) = t;
    return flag;
}

template<typename T, typename V>
void Plateau<T, V>::nextPlayer() {
    current_player= (current_player+1)%listPlayer.size();
}

template<typename V, typename TF>
const Player<TF>* Plateau<V, TF>::getPlayerCourant() const{
    return  listPlayer.at(current_player);
}

template<typename T, typename V>
void Plateau<T, V>::init(int l, int L){
    for (int i = 0; i < l; ++i) {
        vector<const T &> ligne;
        for (int j = 0; j < L; ++j) {
            ligne.push_back(nullptr);
        }
        listTuile.push_back(ligne);
    }
}

template<typename V, typename TF>
const Tuile<FragmentTuile<V>> Plateau<V, TF>::getTuileAt(int x, int y) const {
    if(x > this->listTuile.size() || y > this->listTuile.at(0).size() || x<0 || y<0){
        return nullptr;
    }else return listTuile.at(x).at(y);
}

template<typename T, typename V>
ostream &operator<<(ostream &os, Plateau<T,Tuile<FragmentTuile<V>>> &plateau) {
    string res;
    for (int i = 0; i < plateau.listTuile.size(); ++i) {
        for (int j = 0; j < plateau.listTuile.at(i).size(); ++j) {
            res+="[" + plateau.getTuileAt(i, j).up + ", ";
            res+=plateau.getTuileAt(i, j).right + ", ";
            res+=plateau.getTuileAt(i, j).down + ", ";
            res+=plateau.getTuileAt(i, j).left + "]";
        }
        res+="\n";
    }

    return os << res;
}
