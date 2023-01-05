#ifndef CPP_PROJET_2022_JEU_PLATEAU_HPP
#define CPP_PROJET_2022_JEU_PLATEAU_HPP


#include <vector>
#include <iostream>
#include "../joueurs/Player.hpp"
#include "../tuile/Tuile.hpp"
#include "../vector/AxeVector.hpp"

template <typename TF>
class Plateau {

protected:
    /* attributs */
    vector<Player<TF> *> listPlayer;
    Player<TF> * courant;
    AxeVector<AxeVector<TF>> listTuile;
    int current_player, nombreTuile;

public:
    /* Constructeur & Destructeur */
    Plateau(int, int);
    virtual ~Plateau();

    /* to override function */
    virtual int calculPoint(const TF * value, int x, int y)=0;
    virtual bool placeFirstTuile() = 0;
    virtual bool checkVictory() = 0;

    virtual bool compareTuile(const TF *courant, const TF *tuileUp, const TF *tuileDown, const TF *tuileRight, const TF *tuileLeft) = 0;
 //TODO: Check si carcassonne en a besoin sinon supprimer   virtual const Tuile<TF> & generateRandomTuile() const = 0;

    /* define function */
    bool placeTuile(TF * t, int x, int y);
    void nextPlayer();
    bool partyIsRunning();
    bool piocheCarte();
    const Player<TF> * getPlayerCourant() const;
    const TF * getTuileAt(int x, int y)const;
    vector<const Player<TF> *> getListPlayer() const;
    AxeVector<AxeVector<TF>> getListTuile()const;
    int getCurrentPlayer();
    ostream & operator<<(ostream &os);


};

#include "../../../src/model/plateau/Plateau.tpp"

#endif //CPP_PROJET_2022_JEU_PLATEAU_HPP
// virtual ostream & operator<<(ostream& os) const =0;//TODO: virtual??
