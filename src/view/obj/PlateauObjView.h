//
// Created by root0 on 09/12/22.
//

#ifndef CPP_PROJET_2022_JEU_PLATEAUOBJVIEW_H
#define CPP_PROJET_2022_JEU_PLATEAUOBJVIEW_H


#include "../TuileView.h"
#include "../../hrc/model/plateau/PlateauDominos.hpp"

class PlateauObjView: public TuileView {

    PlateauDominos * plateauDominos;

public:
    PlateauObjView(PlateauDominos * pLateauDominos);


};


#endif //CPP_PROJET_2022_JEU_PLATEAUOBJVIEW_H
