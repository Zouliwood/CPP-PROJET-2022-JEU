//
// Created by david on 13/11/22.
//

#include "../../hrc/plateau/Plateau.hpp"
#include "../../hrc/tuile/Tuile.hpp"

//TODO: constant de condition

template <typename T>
bool Plateau<T>::placeTuile(const Tuile<FragmentTuile<T>> t, int x, int y){

    if(x > this->listTuile.size() || y > this->listTuile.at(0).size() || x<0 || y<0){
        return false;
    }
    Tuile<FragmentTuile<T>> up = getTuileAt(x,y+1);
    Tuile<FragmentTuile<T>> down = getTuileAt(x,y-1);
    Tuile<FragmentTuile<T>> right= getTuileAt(x+1,y);
    Tuile<FragmentTuile<T>> left= getTuileAt(x-1,y);

    if(up == nullptr && down == nullptr && right == nullptr && left == nullptr){
            return false;
    }
    bool flag = false;
    /* Redefinition de l'operateur '==' */
    if(!up || t.up == up.down){
        flag = true;
    }
    if(!right || t.right ==  right.left){
        flag = true;
    }
    if(!left || t.left ==  left.right){
        flag = true;
    }
    if(!down || t.down ==  down.up){
        flag = true;
    }
    this->listTuile.at(x).at(y) = t;
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
