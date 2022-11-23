#include "../../../hrc/tuile/fragment/FragmentTriple.hpp"



template<typename T>
const T & FragmentTriple<T>::getFragmentGauche() const{
    return this->gaucheFragment;
}

template<typename T>
const T & FragmentTriple<T>::getFragmentDroit() const{
    return this->droitFragment;
}

template<typename T>
const T & FragmentTriple<T>::getFragmentCentre() const{
    return this->centreFragment;
}

template<typename T>
void FragmentTriple<T>::setFragmentDroit(const T & fragment) const{
    this->droitFragment=fragment;
}

template<typename T>
void FragmentTriple<T>::setFragmentGauche(const T &fragment) const {
    this->gaucheFragment=fragment;
}

template<typename T>
void FragmentTriple<T>::setFragmentCentre(const T &fragment) const {
    this->centreFragment=fragment;
}

template<typename T>
int FragmentTriple<T>::getPoint(){
    return this->gaucheFragment + this->centreFragment + this->droitFragment;
}

template<typename T>
FragmentTriple<T> & FragmentTriple<T>::operator=(const FragmentTriple<T> * fragment) const{
    this->gaucheFragment=fragment->gaucheFragment;
    this->centreFragment=fragment->centreFragment;
    this->droitFragment=fragment->droitFragment;
    return this;
}

template<typename T>
bool FragmentTriple<T>::operator==(const FragmentTriple<T> & fragment) {
    return this->gaucheFragment==fragment->gaucheFragment &&
           this->centreFragment==fragment->elementCentre &&
           this->droitFragment==fragment->droitFragment;
}

template<typename T>
bool FragmentTriple<T>::operator!=(const FragmentTriple<T> & fragment) {
    return this->gaucheFragment!=fragment->gaucheFragment ||
           this->centreFragment!=fragment->elementCentre ||
           this->droitFragment!=fragment->droitFragment;
}