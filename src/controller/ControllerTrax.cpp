#include "../../hrc/controller/ControllerTrax.hpp"
#include "../../hrc/model/plateau/PlateauTrax.hpp"

bool ControllerTrax::placerTuile(TuileTrax *t, int x, int y) {
    return plateauCourant->placeTuile(t, x, y);
}

void ControllerTrax::piocheCarte() {}

void ControllerTrax::generateRandomTuilePlateau() {}

void ControllerTrax::suivantJoueur(){
    if(plateauCourant->canPlay()) {
        cout << "Place au joueur suivant " << endl;
        plateauCourant->nextPlayer();
        piocheCarte();
    }else{
        cout << "Fin de partie" << endl;
    }
}

void ControllerTrax::defausserTuile(){
    suivantJoueur();
}

TuileTrax * ControllerTrax::getTuileJoueurQuiJoue(){
    return plateauCourant->getPlayerCourant()->getTuile();
}

PlateauTrax * ControllerTrax::getPlateau() {
    return (PlateauTrax *) plateauCourant;
}

ControllerTrax::ControllerTrax() {
    plateauCourant = new PlateauTrax();
    piocheCarte();
}
