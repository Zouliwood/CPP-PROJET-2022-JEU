//
// Created by david on 11/12/22.
//

#ifndef CPP_PROJET_2022_JEU_FRAGMENTQUADRUPLE_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTQUADRUPLE_HPP

#include "FragmentTuile.hpp"

template<typename V>
class FragmentQuadruple : public FragmentTuile<V> {

    /* override functions */
    template<typename T>
    friend bool operator==(const FragmentQuadruple<V> & a, const FragmentQuadruple<V> & b);// override;

    template<typename T>
    friend bool operator!=(const FragmentQuadruple<V> & a, const FragmentQuadruple<V> & b);// override;

public:
    /* Constructeur & Destructeur */
    explicit FragmentQuadruple(V centreFragment);
    ~FragmentQuadruple();

    const V & getFragmentTop() const;
    const V & getFragmentRight() const;
    const V & getFragmentDown() const;
    const V & getFragmentLeft() const;

    FragmentQuadruple<V> & operator=(const FragmentQuadruple<V> *) const;// override;

    int getPoint();

    void setFragmentDroit(const V &fragment) const;
    void setFragmentGauche(const V &fragment) const;
    void setFragmentCentre(const V &fragment) const;
};

template<typename V>
ostream & operator<<(ostream &out, const FragmentQuadruple<V> & fragment);

#endif //CPP_PROJET_2022_JEU_FRAGMENTQUADRUPLE_HPP
