#include "../../../hrc/model/vector/AxeVector.hpp"

template<typename T>
T * AxeVector<T>::getAt(int pos) {
    if(pos >= 0){
        if(pos >= positif.size()) return nullptr;
        return positif.at(pos);
    }else{
        int posx = pos * (-1) -1;
        if(posx >= negatif.size()) return nullptr;
        return negatif.at(posx);
    }
}

template<typename T>
void AxeVector<T>::addElement(int pos, T *element) {
    if(pos >= 0){
       if(pos >= positif.size()) positif.resize(pos + 1);
       positif.at(pos) = element;
   }else{
       int posx = (pos*-1)-1;//+du 0
       if(posx >= negatif.size()) {
           negatif.resize(posx+1);//ici +1 de avoir une place en plus
       }
       negatif.at(posx) = element;
   }
}

template<typename T>
vector<T *> AxeVector<T>::getPositif() {
    return this->positif;
}


template<typename T>
vector<T *> AxeVector<T>::getNegatif() {
    return this->negatif;
}
