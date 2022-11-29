#include "AxeVector.hpp"

template<typename T>
T * AxeVector<T>::getAt(int pos) {
    if(pos >= 0){
        if(pos >= positif.size()) return nullptr;
        return positif.at(pos);
    }else{
        pos = pos * (-1) -1;
        if(pos >= negatif.size()) return nullptr;
        return negatif.at(pos*-1-1);
    }
}

template<typename T>
void AxeVector<T>::addElement(int pos, T *element) {
   if(pos >= 0){
       if(pos >= positif.size()) positif.resize(pos + 1);
       positif.at(pos) = element;
   }else{
       pos = pos*(-1)-1;
       if(pos >= negatif.size()) negatif.resize(pos + 1);
       negatif.at(pos) = element;
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