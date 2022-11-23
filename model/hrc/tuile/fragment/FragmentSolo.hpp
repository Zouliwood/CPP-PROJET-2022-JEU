//
// Created by david on 17/11/22.
//

#ifndef CPP_PROJET_2022_JEU_FRAGMENTSOLO_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTSOLO_HPP


#include "FragmentTuile.hpp"

template<typename T>
class FragmentSolo final: public FragmentTuile<T> {

public:
    /* Constructeur & Destructeur */
    FragmentSolo();
    ~FragmentSolo();

    /* override functions */
    bool operator==(const FragmentSolo<T> & );
    bool operator!=(const FragmentSolo<T> & );
    FragmentSolo<T> & operator=(const FragmentSolo<T> &);
    int getPoint();

};
#include "../../../src/tuile/fragment/FragmentSolo.tpp"
#endif
