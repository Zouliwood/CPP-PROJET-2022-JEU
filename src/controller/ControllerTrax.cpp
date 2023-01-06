#include "../../hrc/controller/ControllerTrax.hpp"
#include "../../hrc/model/plateau/PlateauTrax.hpp"


bool ControllerTrax::placerTuile(TuileTrax *t, int x, int y) {
    return plateauCourant->placeTuile(t, x, y);
}

void ControllerTrax::piocheCarte() {}

void ControllerTrax::generateRandomTuilePlateau() {}

void ControllerTrax::suivantJoueur(){
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

void ControllerTrax::defausserTuile(){
    suivantJoueur();
}

void ControllerTrax::abandonnerParty(){
    //suivantJoueur();
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
