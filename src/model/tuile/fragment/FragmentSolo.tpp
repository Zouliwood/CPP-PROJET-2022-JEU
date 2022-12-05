#include "../../../../hrc/model/tuile/fragment/FragmentSolo.hpp"

template<typename V>
const V &FragmentSolo<V>::getFragmentCentre() const {
    return this->centreFragment;
}

template<typename T>
bool operator==(const FragmentSolo<T> & a, const FragmentSolo<T> & b) {
    return a.getFragmentCentre()==b.getFragmentCentre();
}

template<typename T>
bool operator!=(const FragmentSolo<T> & a, const FragmentSolo<T> & b) {
    return a->centreFragment!=b->centreFragment;
}

template<typename T>
FragmentSolo<T> & FragmentSolo<T>::operator=(const FragmentSolo<T> * fragment) const { // override;
    this->centreFragment=fragment->centreFragment;
    return *this;
}

template<typename V>
ostream & operator<<(ostream &out, const FragmentSolo<V> & fragment){
    switch (fragment.getFragmentCentre()) {
        case colorTrax::NOIR:
            out << "NOIR";
            break;
        case colorTrax::BLANC:
            out << "BLANC";
            break;
    }
    return out;
}

template<typename T>
int FragmentSolo<T>::getPoint() {
    return 0;
}

template<typename V>
FragmentSolo<V>::~FragmentSolo() = default;

template<typename V>
FragmentSolo<V>::FragmentSolo(V centreFragment):
        FragmentTuile<V>(centreFragment) {}
