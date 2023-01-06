#include "../../hrc/controller/ControllerDominos.hpp"
#include "../../hrc/model/joueurs/PlayerDominos.hpp"


void ControllerDominos::piocheCarte() {
     (this->getPlateau()->getPlayerCourant())->setTuile(((PlateauDominos *) plateauCourant)->generateRandomTuile());
    plateauCourant->piocheCarte();
}

bool ControllerDominos::placerTuile(TuileDominos *t, int x, int y) {
    return plateauCourant->placeTuile(t, x, y);
}


void ControllerDominos::generateRandomTuilePlateau() {

}

void ControllerDominos::suivantJoueur(){
    if(plateauCourant->canPlay()) {
        plateauCourant->nextPlayer();
        piocheCarte();
    }else{
        cout << "Fin de partie" << endl;
    }
}

void ControllerDominos::defausserTuile(){
    suivantJoueur();
}

TuileDominos * ControllerDominos::getTuileJoueurQuiJoue(){
    return plateauCourant->getPlayerCourant()->getTuile();
}

PlateauDominos * ControllerDominos::getPlateau() {
    return (PlateauDominos *) plateauCourant;
}

ControllerDominos::ControllerDominos(int nombre_joueur, int nombre_tuile){
    plateauCourant = new PlateauDominos(nombre_joueur, nombre_tuile);
    piocheCarte();
}
