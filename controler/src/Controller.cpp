//
// Created by david on 18/11/22.
//

#include "../hrc/Controller.hpp"

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
bool Controller<T>::placerTuileDomino(const Tuile<T> t,int x, int y){
    if(this->plateauCourant.placeTuile(t, x,y)){
        //calcul point
    }
    //passer le joueur et passer au suivant
    return false;
}

template<typename T>
bool Controller<T>::placerTuileCarcasonne(const Tuile<T> t,int x, int y){
    if(this->plateauCourant.placeTuile(t, x,y)){
        //proposition de Placer ses pions
    }
    //passer joueur et passer au suivant
    return false;
}

template<typename T>
bool Controller<T>::placerTuileTrax(const Tuile<T> t,int x, int y){
    if(this->plateauCourant.placeTuile(t, x,y)){
        //Verifier s'il ça ne forme pas un circuit ou une ligne droite de bout en bout
    }
    //passer joueur et passer au suivant
    return false;
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



