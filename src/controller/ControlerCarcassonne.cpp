//
// Created by david on 05/01/23.
//

#include "../../hrc/controller/ControlerCarcassonne.hpp"


void ControlerCarcassonne::init(int nombre_joueur, int nombre_tuile) {
  //          plateauCourant = new PlateauDominos(nombre_joueur, nombre_tuile);
//            (this->getPlateau()->getPlayerCourant())->setTuile(( (PlateauDominos *) plateauCourant)->generateRandomTuile());
}

void ControlerCarcassonne::piocheCarte() {
  //  (this->getPlateau()->getPlayerCourant())->setTuile(((PlateauDominos *) plateauCourant)->generateRandomTuile());
}

bool ControlerCarcassonne::placerTuile(TuileCarcassonne *t, int x, int y) {
    return plateauCourant->placeTuile(t, x, y);
}


void ControlerCarcassonne:: generateRandomTuilePlateau() {

}

void ControlerCarcassonne::suivantJoueur(){
    cout << "yrdy" << endl;
    cout << "Au suivant " << plateauCourant->getListPlayer().at(plateauCourant->getCurrentPlayer())->getName() << endl;
    plateauCourant->nextPlayer();
    piocheCarte();
}

void ControlerCarcassonne::defausserTuile(){
    suivantJoueur();
}

void ControlerCarcassonne::abandonnerParty(){
    //suivantJoueur();
}

TuileCarcassonne * ControlerCarcassonne::getTuileJoueurQuiJoue(){
    cout << plateauCourant->getListPlayer().size() << " taille"  << endl;
    cout << plateauCourant->getCurrentPlayer() << " player " << endl;
    cout << plateauCourant->getListPlayer().at(plateauCourant->getCurrentPlayer())->getPoints()  << " pts" << endl;
    return (plateauCourant->getListPlayer().at(plateauCourant->getCurrentPlayer()))->getTuile();
}

PlateauCarcassonne * ControlerCarcassonne::getPlateau() {
    return (PlateauCarcassonne *) plateauCourant;
}
