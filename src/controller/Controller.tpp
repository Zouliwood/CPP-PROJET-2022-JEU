#include "../../hrc/controller/Controller.hpp"

template<typename T>
void Controller<T>::init(int nombre_joueur, int nombre_tuile) {
    plateauCourant = new Plateau<T>(nombre_joueur, nombre_tuile);
}

template<typename T>
void Controller<T>::piocheCarte() {
    plateauCourant.piocheCarte();
}

template<typename T>
bool Controller<T>::placerTuile(Tuile<T> t, int x, int y) {
    return plateauCourant.placeTuile(t, x, y);
}

template<typename T>
void Controller<T>::deletePlateau() {
    for(int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            Tuile<FragmentTuile<T>> & tuile= this->plateauCourant.getTuileAt(x, y);
            if(tuile != nullptr) delete tuile;
        }
    }
    delete plateauCourant;
}


template<typename T>
void Controller<T>::suivantJoueur(){
    plateauCourant.nextPlayer();
    piocheCarte();
}

template<typename T>
void Controller<T>::defausserTuile(){
    suivantJoueur();
}

template<typename T>
void Controller<T>::abandonnerParty(){
    //suivantJoueur();
}