#include "../../hrc/plateau/Plateau.hpp"
#include "../../hrc/tuile/Tuile.hpp"

//TODO: constant de condition

template <typename T>
bool Plateau<T>::placeTuile(const Tuile<FragmentTuile<T>> t, int x, int y){

    if(x > this->listTuile.size() || y > this->listTuile.at(0).size() || x<0 || y<0){
        return false;
    }
    Tuile<FragmentTuile<T>> tuileUp = getTuileAt(x,y+1);
    Tuile<FragmentTuile<T>> tuileDown = getTuileAt(x,y-1);
    Tuile<FragmentTuile<T>> tuileRight= getTuileAt(x+1,y);
    Tuile<FragmentTuile<T>> tuileLeft= getTuileAt(x-1,y);

    if(tuileUp == nullptr && tuileDown == nullptr && tuileRight == nullptr && tuileLeft == nullptr){
            return false;
    }

    /* Redefinition de l'operateur '==' */
    bool flag = (!tuileUp || t.up == tuileUp.down) || (!tuileRight || t.right ==  tuileRight.left)
                || (!tuileLeft || t.left ==  tuileRight.right) || (!tuileDown || t.down ==  tuileDown.up);

    if(flag) this->listTuile.at(x).at(y) = t;
    return flag;
}


template <typename T>
const Tuile<FragmentTuile<T>> Plateau<T>::getTuileAt(int x, int y) const{
    if(x > this->listTuile.size() || y > this->listTuile.at(0).size() || x<0 || y<0){
        return nullptr;
    }else return listTuile.at(x).at(y);
}

template<typename T>
void Plateau<T>::nextPlayer() {
    current_player= (current_player+1)%listPlayer.size();
}

template<typename T>
const Player<Tuile<FragmentTuile<T>>>* Plateau<T>::getPlayerCourant() const{
    return  listPlayer.at(current_player);
}

template<typename T>
void Plateau<T>::init(int l, int L){
    for (int i = 0; i < l; ++i) {
        vector<const T &> ligne;
        for (int j = 0; j < L; ++j) {
            ligne.push_back(nullptr);
        }
        listTuile.push_back(ligne);
    }
}

template<typename T>
ostream &operator<<(ostream &os, Plateau<Tuile<T>> &plateau) {
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
