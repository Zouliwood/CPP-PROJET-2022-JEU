#ifndef CPP_PROJET_2022_JEU_FRAGMENTTUILE_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTTUILE_HPP

#include "../../enum/directionTuile.hpp"
#include <ostream>

using namespace std;

template<typename V>
class FragmentTuile {

protected:
    /* attributs partage */
    V centreFragment;

public:
    /* Constructeur & Destructeur */
    FragmentTuile(V centreFragment);
    virtual ~FragmentTuile();

    /* function to override */
     //TODO: virtual bool operator==(const FragmentTuile<V> &)=0;
     //TODO: virtual bool operator!=(const FragmentTuile<V> &)=0;
     //TODO: virtual FragmentTuile<V> & operator=(const FragmentTuile<V> *) const = 0;
    virtual int getPoint()=0;
};

#include "../../../../src/model/tuile/fragment/FragmentTuile.tpp"
#endif
