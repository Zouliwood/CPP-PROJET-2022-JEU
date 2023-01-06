#ifndef CPP_PROJET_2022_JEU_FRAGMENTSOLO_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTSOLO_HPP

#include "FragmentTuile.hpp"
#include "../../enum/colorTrax.hpp"

template<typename V>
class FragmentSolo final: public FragmentTuile<V> {

    /* override functions */
    template<typename T>
    friend bool operator==(const FragmentSolo<V> & a, const FragmentSolo<V> & b);// override;

    template<typename T>
    friend bool operator!=(const FragmentSolo<V> & a, const FragmentSolo<V> & b);// override;

public:
    /* Constructeur & Destructeur */
    explicit FragmentSolo(V centreFragment);
    ~FragmentSolo();

    const V & getFragmentCentre() const;

    FragmentSolo<V> & operator=(const FragmentSolo<V> *) const;// override;

    int getPoint();

    void setFragmentCentre(V element);
};

template<typename V>
ostream & operator<<(ostream &out, const FragmentSolo<V> & fragment);

#include "../../../../src/model/tuile/fragment/FragmentSolo.tpp"
#endif
