//
// Created by david on 17/11/22.
//

#ifndef CPP_PROJET_2022_JEU_FRAGMENTSOLO_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTSOLO_HPP


#include "FragmentTuile.hpp"

template<typename V>
class FragmentSolo final: public FragmentTuile<V> {

public:
    /* Constructeur & Destructeur */
    FragmentSolo();
    ~FragmentSolo();

    /* override functions */
    bool operator==(const FragmentSolo<V> & );// override;
    bool operator!=(const FragmentSolo<V> & );// override;
    FragmentSolo<V> & operator=(const FragmentSolo<V> &);// override;
    int getPoint();

};
#include "../../../../src/model/tuile/fragment/FragmentSolo.tpp"
#endif
