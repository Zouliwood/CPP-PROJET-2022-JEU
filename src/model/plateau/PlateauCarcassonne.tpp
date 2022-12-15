#include "../../hrc/model/plateau/PlateauCarcassonne.hpp"

template<typename F>
bool PlateauCarcassonne<F>::checkVictory() {
    return false;
}

template<typename TF>
ostream &PlateauCarcassonne<TF>::operator<<(ostream &os) {
    return os << "TODO";
}

template<typename TF>
PlateauCarcassonne<TF>::PlateauCarcassonne() = default;

template<typename TF>
int PlateauCarcassonne<TF>::calculPoint(const TF * t, int x, int y){
    return 0;
}

template<typename F>
TuileCarcassonne<F> *PlateauCarcassonne<F>::generateRandomTuile() {
    return new TuileCarcassonne<F>(
        *new FragmentTriple<int>(1,1,1),
        *new FragmentTriple<int>(2,2,2),
        *new FragmentTriple<int>(3,3,3),
        *new FragmentTriple<int>(4,4,4)
    );
}

template<typename TF>
bool PlateauCarcassonne<TF>::placeFirstTuile() {
    TuileCarcassonne<TF> * carcassonne =  generateRandomTuile();
    this->listTuile.addElement(0, new AxeVector<TuileDominos>());
    cout << "Ligne ajoutée !" << endl;
    ((AxeVector<TuileDominos> *)this->listTuile.getAt(0))->addElement(0, carcassonne);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>" << *(this->listTuile.getAt(0)->getAt(0)) << endl;
    return ((AxeVector<TuileDominos> *) this->listTuile.getAt(0))->getAt(0) != nullptr;
}

//TODO: add fragment centre - FragmentQuadruple -
template<typename F>
bool PlateauCarcassonne<F>::compareTuile(TuileCarcassonne<F> *courant, TuileCarcassonne<F> *tuileUp,
                                         TuileCarcassonne<F> *tuileDown, TuileCarcassonne<F> *tuileRight,
                                         TuileCarcassonne<F> *tuileLeft) {
    return (!tuileUp || *(&(FragmentTriple<environment> &)courant->getUp()) == *(&(FragmentTriple<environment> &)tuileUp->getDown()))
           &&  (!tuileRight || *(&(FragmentTriple<environment> &)courant->getRight()) == *(&(FragmentTriple<environment> &)tuileRight->getLeft()))
           && (!tuileLeft || *(&(FragmentTriple<environment> &)courant->getLeft()) == *(&(FragmentTriple<environment> &)tuileLeft->getRight()))
           && (!tuileDown || *(&(FragmentTriple<environment> &)courant->getDown()) == *(&(FragmentTriple<environment> &)tuileDown->getUp()));
}

template<typename F>
bool PlateauCarcassonne<F>::pionPresent(int x, int y, int posFrag, environment env){

    vector<FragmentTuile<F>> dejaVu;

    return pionPresentAux(x, y, posFrag, env, dejaVu);

}

template<typename F>
bool PlateauCarcassonne<F>::pionPresentAux(int x, int y, int posFrag, environment env, vector<FragmentTuile<F>> dejaVu){
    /*Procedure explorer(Graphe G) {
       Pour chaque noeud N de G
          Si N non visite
             DFS(G, N)
    }
    Procedure DFS(Graphe G, Noeud N) {
       Marquer N comme visite
       Pour chaque voisin V de N
          Si V non visite
             DFS(G, V)
    }*/

    //TODO: changer le system de check avec le vecteur ?

    auto currTuile = (TuileCarcassonne<F>)this->getTuileAt(x, y);//TODO: check != NULL
    /* center bas */
    auto currFrag11 = ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown();
    if (posFrag==11 && find(dejaVu.begin(), dejaVu.end(), currFrag11)==dejaVu.end()){
        //TODO: vérifier si un pion est présent sur la Tuile courante en position 11 - return true -
        dejaVu.push_back(currFrag11);
        /* centre */
        if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight()==env
        && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight())==dejaVu.end()){
            pionPresentAux(x, y, 8, env, dejaVu);
        }
        if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft()==env
        && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft())==dejaVu.end()){
            pionPresentAux(x, y, 7, env, dejaVu);
        }
        /* bas */
        if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche()==env
        && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche())==dejaVu.end()){
            pionPresentAux(x, y, 13, env, dejaVu);
        }
        if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentCentre()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentCentre())==dejaVu.end()){
            pionPresentAux(x, y, 14, env, dejaVu);
        }
        if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit())==dejaVu.end()){
            pionPresentAux(x, y, 15, env, dejaVu);
        }
        /* droit */
        if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche())==dejaVu.end()){
            pionPresentAux(x, y, 12, env, dejaVu);
        }
        /* gauche */
        if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit())==dejaVu.end()){
            pionPresentAux(x, y, 10, env, dejaVu);
        }
    }
    /* bas centre */
    auto currFrag14 = ((FragmentTriple<environment>) currTuile.getDown()).getFragmentCentre();
    if (posFrag==14 && find(dejaVu.begin(), dejaVu.end(), currFrag14)==dejaVu.end()){
        //TODO: vérifier si un pion est présent sur la Tuile courante en position 14 - return true -
        dejaVu.push_back(currFrag14);
        /* centre */
        if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown()==env
        && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown())==dejaVu.end()){
            pionPresentAux(x, y, 11, env, dejaVu);
        }
        /* bas */
        if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche()==env
        && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche())==dejaVu.end()){
            pionPresentAux(x, y, 13, env, dejaVu);
        }
        if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit()
        && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit())==dejaVu.end()){
            pionPresentAux(x, y, 15, env, dejaVu);
        }
        /* ext */
        auto getExt=(TuileCarcassonne<F>) this->getTuileAt(x, y-1);
        if (getExt && ((FragmentTriple<environment>) getExt.getUp()).getFragmentCentre()==env
        && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getUp()).getFragmentCentre())==dejaVu.end()){
            pionPresentAux(x, y-1, 1, env, dejaVu);
        }
    }
    /* bas droit */
    auto currFrag15 = ((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit();
    if (posFrag==15 && find(dejaVu.begin(), dejaVu.end(), currFrag15)==dejaVu.end()){
        //TODO: vérifier si un pion est présent sur la Tuile courante en position 14 - return true -
        dejaVu.push_back(currFrag15);
        /* centre */
        if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown())==dejaVu.end()){
            pionPresentAux(x, y, 11, env, dejaVu);
        }
        if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight())==dejaVu.end()){
            pionPresentAux(x, y, 8, env, dejaVu);
        }
        /* bas */
        if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentCentre()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentCentre())==dejaVu.end()){
            pionPresentAux(x, y, 14, env, dejaVu);
        }
        /* droit */
        if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche()
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche())==dejaVu.end()){
            pionPresentAux(x, y, 12, env, dejaVu);
        }
        /* ext */
        auto getExt=(TuileCarcassonne<F>) this->getTuileAt(x, y-1);
        if (getExt && ((FragmentTriple<environment>) getExt.getUp()).getFragmentDroit()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getUp()).getFragmentDroit())==dejaVu.end()){
            pionPresentAux(x, y-1, 2, env, dejaVu);
        }
    }
    /* bas gauche */
    auto currFrag13 =  ((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche();
    if (posFrag==13 && find(dejaVu.begin(), dejaVu.end(), currFrag13)==dejaVu.end()){
        //TODO: vérifier si un pion est présent sur la Tuile courante en position 14 - return true -
        dejaVu.push_back(currFrag13);
        /* centre */
        if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown())==dejaVu.end()){
            pionPresentAux(x, y, 11, env, dejaVu);
        }
        if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft())==dejaVu.end()){
            pionPresentAux(x, y, 7, env, dejaVu);
        }
        /* bas */
        if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentCentre()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentCentre())==dejaVu.end()){
            pionPresentAux(x, y, 14, env, dejaVu);
        }
        /* gauche */
        if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit()
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit())==dejaVu.end()){
            pionPresentAux(x, y, 10, env, dejaVu);
        }
        /* ext */
        auto getExt=(TuileCarcassonne<F>) this->getTuileAt(x, y-1);
        if (getExt && ((FragmentTriple<environment>) getExt.getUp()).getFragmentGauche()==env
            && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getUp()).getFragmentGauche())==dejaVu.end()){
            pionPresentAux(x, y-1, 0, env, dejaVu);
        }
    }
    //TODO: continuer :'

    return false;

}

template<typename TF>
PlateauCarcassonne<TF>::~PlateauCarcassonne() = default;