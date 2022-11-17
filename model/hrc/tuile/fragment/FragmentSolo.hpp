//
// Created by david on 17/11/22.
//

#ifndef CPP_PROJET_2022_JEU_FRAGMENTSOLO_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTSOLO_HPP


#include "FragmentTuile.hpp"

template<typename T>
class FragmentSolo final: protected FragmentTuile<T> {

//REDEFINTION DE L'OPERATEUR == ;
public:
    bool operator==(const FragmentSolo<T> & );
    bool operator!=(const FragmentSolo<T> & );

};


#endif
