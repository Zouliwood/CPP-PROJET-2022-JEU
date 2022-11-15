//
// Created by david on 13/11/22.
//

#include "../../hrc/tuile/TuileDominos.hpp"

void TuileDominos::rotate() {
    int tmp[3];
    swapTab(tmp, up);
    swapTab(up, left);
    swapTab(left, down);
    swapTab(down, right);
    swapTab(right, tmp);
}

void TuileDominos::swapTab(int tab[], int tab2[]){
    for(int i = 0; i < LEN_TUILE; i++) tab[i] = tab2[i];
}

/*
bool TuileDominos::isValide(TuileDominos, enum directionTuile) {
    switch (directionTuile) {

    }
    return equals(up., ) || equals(right, tuile.left) || equals(down, tuile.up) || equals(left, tuile.right);
}
*/

bool TuileDominos::operator==(const int arr[]){
    bool flag = true;
    for (int i = 0; i < LEN_TUILE; ++i) {
        if(up[i] != arr[i]) flag = false;
    }
    return flag;
}

bool TuileDominos::operator!=(const int arr[]){
    return !(up == arr); //!(down == arr); !(right == arr); !(left == arr);
}