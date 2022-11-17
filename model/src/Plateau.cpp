//
// Created by david on 13/11/22.
//

#include "../hrc/Plateau.hpp"
#include "../hrc/tuile/Tuile.hpp"

//TODO: constant de condition

bool Plateau<T>::placeTuile(Tuile<T> t, int x, int y){
    if(x > this->listTuile.size() || y > this->listTuile.at(0).size() || x<0 || y<0){
        return false;
    }
    Tuile<T> up = getTuileAt(x,y+1);
    Tuile<T> down = getTuileAt(x,y-1);
    Tuile<T> right= getTuileAt(x+1,y);
    Tuile<T> left= getTuileAt(x-1,y);

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
const Player* Plateau<T>::getPlayerCourant() const{
    return  listPlayer.at(current_player);
}

//TODO: https://stackoverflow.com/questions/351845/finding-the-type-of-an-object-in-c
// pour calculer les points en fonction du type de l'objet
template<typename T>
int Plateau<T>::calculPoint(const Tuile<FragmentTuile<T>> t, int x, int y) {
    Tuile<FragmentTuile<T>> tuileUp = getTuileAt(x,y+1);
    Tuile<FragmentTuile<T>> tuileDown = getTuileAt(x,y-1);
    Tuile<FragmentTuile<T>> tuileRight= getTuileAt(x+1,y);
    Tuile<FragmentTuile<T>> tuileLeft= getTuileAt(x-1,y);
    int somme = 0;
    if(up)somme+=t.getPoint();
    if(down)somme+=t.getPoint();
    if(right)somme+=t.getPoint();
    if(left)somme+=t.getPoint();

    return somme;
}
