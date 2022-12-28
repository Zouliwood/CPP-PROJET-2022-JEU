#include "../../../../hrc/model/tuile/fragment/FragmentQuadruple.hpp"

template<typename V>
FragmentQuadruple<V>::FragmentQuadruple(V hautFragment, V droitFragment, V basFragment, V gaucheFragment) :
        FragmentTuile<V>(basFragment),
        hautFragment{hautFragment}, droitFragment{droitFragment},
        gaucheFragment{gaucheFragment}
{}

template<typename V>
bool operator==(const FragmentQuadruple<V> & a, const FragmentQuadruple<V> & b) {
    return b.gaucheFragment==a.gaucheFragment && b.centreFragment==a.centreFragment && b.droitFragment==a.droitFragment;
}

template<typename V>
bool operator!=(const FragmentQuadruple<V> & a,const FragmentQuadruple<V> & b) {
    return b.gaucheFragment!=a.gaucheFragment ||b.centreFragment!=a.centreFragment || b.droitFragment!=a.droitFragment;
}

template<typename V>
int FragmentQuadruple<V>::getPoint() {
    return 0;
}

template<typename V>
const V &FragmentQuadruple<V>::getFragmentCentre() const {
    return this->centreFragment;
}

template<typename V>
FragmentQuadruple<V>::~FragmentQuadruple() {

}