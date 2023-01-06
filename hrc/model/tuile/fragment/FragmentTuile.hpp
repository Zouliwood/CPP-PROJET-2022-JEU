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
    explicit FragmentTuile(V centreFragment);
    virtual ~FragmentTuile();

    virtual const V & getFragmentCentre()const=0;

    /* function to override */
    virtual int getPoint()=0;
};

#include "../../../../src/model/tuile/fragment/FragmentTuile.tpp"
#endif
