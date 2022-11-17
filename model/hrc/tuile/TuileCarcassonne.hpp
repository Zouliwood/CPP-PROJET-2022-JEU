//
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP
#define CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP

#include <iostream>
#include <vector>
#include "Tuile.hpp"
#include "../enum/environment.hpp"

template <typename T>
class TuileCarcassonne final: protected Tuile<FragmentTuile<T>>{

public:
    ~TuileCarcassonne();

    bool operator==(const FragmentTuile<environment> &)=0;
    bool operator!=(const FragmentTuile<environment> &)=0;
};

// t.equals(t.up, t.down)
//t == t.down
// t.up == t.down


#endif //CPP_PROJET_2022_JEU_TUILECARCASSONNE_HPP
