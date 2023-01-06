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
    cout << "Au suivant " << plateauCourant->getListPlayer().at(plateauCourant->getCurrentPlayer())->getName() << endl;
    cout << " current " << plateauCourant->getCurrentPlayer();
    cout << "TuileRestante" << plateauCourant->nombreCarteRestant();
    if(plateauCourant->canPlay()) {
        plateauCourant->nextPlayer();
        piocheCarte();
    }else{
        cout << "fin de partie" << endl;
    }
}

void ControllerDominos::defausserTuile(){
    suivantJoueur();
}

void ControllerDominos::abandonnerParty(){
    //suivantJoueur();
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
