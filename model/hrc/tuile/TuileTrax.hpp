#ifndef CPP_PROJET_2022_JEU_TUILETRAX_HPP
#define CPP_PROJET_2022_JEU_TUILETRAX_HPP

#include "../enum/colorTrax.hpp"
#include "Tuile.hpp"
#include "fragment/FragmentSolo.hpp"

class TuileTrax final: public Tuile<FragmentSolo<colorTrax>>{

public:
    /* Constructeur & Destructeur*/
    TuileTrax();
    ~TuileTrax() override;

    /*function override*/
    void rotate() override;
};

#endif
