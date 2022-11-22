    //
// Created by david on 13/11/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILETRAX_HPP
#define CPP_PROJET_2022_JEU_TUILETRAX_HPP

#include "../enum/colorTrax.hpp"
#include "Tuile.hpp"
#include "fragment/FragmentSolo.hpp"

class TuileTrax final: protected Tuile<FragmentSolo<colorTrax>>{

public:
    ~TuileTrax();
};


#endif //CPP_PROJET_2022_JEU_TUILETRAX_HPP
