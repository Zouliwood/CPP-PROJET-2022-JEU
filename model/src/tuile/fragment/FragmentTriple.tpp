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
    return *this;
}

template<typename T>
bool FragmentTriple<T>::compareFragment(const FragmentTriple<T> * fragment){
    cout << "----------- on entre == compaire fonction --------------" << endl;
    return this == fragment;
}


template<typename T>
FragmentTriple<T>::FragmentTriple(T droitFragment,T centreFragment, T gaucheFragment):
        FragmentTuile<T>(centreFragment),
        gaucheFragment{gaucheFragment},
        droitFragment{droitFragment} {}

template<typename T>
FragmentTriple<T>::~FragmentTriple() = default;


template<typename V>
ostream & operator<<(ostream &out, FragmentTriple<V> & fragment){
    return out << fragment.getFragmentGauche() << "." << fragment.getFragmentCentre()<<"." << fragment.getFragmentDroit();
}

template<typename V>
string FragmentTriple<V>::toString(){
    return to_string(getFragmentGauche()) + to_string(getFragmentCentre()) + to_string(getFragmentDroit());
}