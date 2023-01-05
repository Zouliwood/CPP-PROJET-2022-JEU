
#include "../../hrc/controller/ControllerCarcassonne.hpp"

void ControllerCarcassonne::init(int nombre_joueur, int nombre_tuile) {
    plateauCourant = new PlateauCarcassonne(nombre_joueur);
    (this->getPlateau()->getPlayerCourant())->setTuile(( (PlateauCarcassonne *) plateauCourant)->sac.getRandomTuile());
}

void ControllerCarcassonne::piocheCarte() {
    (this->getPlateau()->getPlayerCourant())->setTuile(((PlateauCarcassonne *) plateauCourant)->sac.getRandomTuile());
}

bool ControllerCarcassonne::placerTuile(TuileCarcassonne *t, int x, int y) {
    return plateauCourant->placeTuile(t, x, y);
}


void ControllerCarcassonne::generateRandomTuilePlateau() {

}

void ControllerCarcassonne::suivantJoueur(){
    cout << "Au suivant " << plateauCourant->getListPlayer().at(plateauCourant->getCurrentPlayer())->getName() << endl;
    cout << " current " << plateauCourant->getCurrentPlayer();
    cout << "TuileRestante" << plateauCourant->nombreSacRestant();
    if(plateauCourant->canPlay()) {
        plateauCourant->nextPlayer();
        piocheCarte();
    }else{
        cout << "fin de partie" << endl;
    }
}

void ControllerCarcassonne::defausserTuile(){
    suivantJoueur();
}

void ControllerCarcassonne::abandonnerParty(){
    //suivantJoueur();
}

TuileCarcassonne * ControllerCarcassonne::getTuileJoueurQuiJoue(){
    return plateauCourant->getPlayerCourant()->getTuile();
}

PlateauCarcassonne * ControllerCarcassonne::getPlateau() {
    return (PlateauCarcassonne *) plateauCourant;
}

ControllerCarcassonne::ControllerCarcassonne(int nombre_joueur, int nombre_tuile) {
    init(nombre_joueur, nombre_tuile);
}
