//
// Created by root0 on 10/12/22.
//

#ifndef CPP_PROJET_2022_JEU_TUILEVIDEOBJVIEW_H
#define CPP_PROJET_2022_JEU_TUILEVIDEOBJVIEW_H


#include "../TuileView.h"

class TuileVideObjView : public TuileView{

    enum tuileView {IDLE = 0, PRESSED, HOVER,};

public:
    TuileVideObjView();
    ~TuileVideObjView();

   // updateView();
};


#endif
