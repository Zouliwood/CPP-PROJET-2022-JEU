#include "../../hrc/controler/Controller.hpp"

template<typename T>
void Controller<T>::init() {
    this->plateauCourant = new Plateau<T>; // pas oublie de faire une fonction free()
    for(int x = 0; x < 10; x++){
        vector<Tuile<T>> ligne = new vector<Tuile<T>>;
        for(int y = 0; y < 10; y++){
            ligne.push_back(new Tuile<T>);
        }
        this->plateauCourant.listTuile.push_back(ligne);
    }
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
    this->plateauCourant.nextPlayer();
}

template<typename T>
void Controller<T>::defausserTuile(){
    this->plateauCourant.getPlayerCourant().setTuile(nullptr);
    suivantJoueur();
}



