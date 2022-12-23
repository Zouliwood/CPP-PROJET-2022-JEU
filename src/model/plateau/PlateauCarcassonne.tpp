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

template<typename TF>
TuileCarcassonne *PlateauCarcassonne<TF>::generateRandomTuile() {
    return new TuileCarcassonne(
        *new FragmentTriple<environment>(environment::ABAYES, environment::ABAYES, environment::ABAYES),
        *new FragmentTriple<environment>(environment::ABAYES , environment::ABAYES, environment::ABAYES),
        *new FragmentTriple<environment>(environment::ABAYES, environment::ABAYES, environment::ABAYES),
        *new FragmentQuadruple<environment>(environment::ABAYES ,environment::ABAYES ,environment::ABAYES, environment::ABAYES)
    );
}

template<typename TF>
bool PlateauCarcassonne<TF>::placeFirstTuile() {
    TuileCarcassonne * carcassonne =  generateRandomTuile();
    this->listTuile.addElement(0, new AxeVector<TuileDominos>());
    cout << "Ligne ajoutée !" << endl;
    ((AxeVector<TuileCarcassonne> *)this->listTuile.getAt(0))->addElement(0, carcassonne);
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>" << *(this->listTuile.getAt(0)->getAt(0)) << endl;
    return ((AxeVector<TuileDominos> *) this->listTuile.getAt(0))->getAt(0) != nullptr;
}

//TODO: add fragment centre - FragmentQuadruple -
template<typename F>
bool PlateauCarcassonne<F>::compareTuile(TuileCarcassonne *courant, TuileCarcassonne *tuileUp,
                                         TuileCarcassonne *tuileDown, TuileCarcassonne *tuileRight,
                                         TuileCarcassonne *tuileLeft) {
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

    auto currTuile = this->getTuileAt(x, y);
    //TODO: vérifier si un pion est présent sur la Tuile courante en position posFrag - return true -

    if (currTuile){
        /* top droit */
        auto currFrag0 =  ((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit();
        if (posFrag==0 && find(dejaVu.begin(), dejaVu.end(), currFrag0)==dejaVu.end()){
            dejaVu.push_back(currFrag0);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop())==dejaVu.end()){
                pionPresentAux(x, y, 4, env, dejaVu);
            }
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft())==dejaVu.end()){
                pionPresentAux(x, y, 7, env, dejaVu);
            }
            /* top */
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 1, env, dejaVu);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 3, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y+1);
            if (getExt && ((FragmentTriple<environment>) getExt.getDown()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getDown()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y+1, 13, env, dejaVu);
            }
        }
        /* top centre */
        auto currFrag1 =  ((FragmentTriple<environment>) currTuile.getUp()).getFragmentCentre();
        if (posFrag==1 && find(dejaVu.begin(), dejaVu.end(), currFrag1)==dejaVu.end()){
            dejaVu.push_back(currFrag1);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop())==dejaVu.end()){
                pionPresentAux(x, y, 4, env, dejaVu);
            }
            /* top */
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 2, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 0, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y+1);
            if (getExt && ((FragmentTriple<environment>) getExt.getDown()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getDown()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y+1, 14, env, dejaVu);
            }
        }
        /* top gauche */
        auto currFrag2 =  ((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche();
        if (posFrag==2 && find(dejaVu.begin(), dejaVu.end(), currFrag2)==dejaVu.end()){
            dejaVu.push_back(currFrag2);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop())==dejaVu.end()){
                pionPresentAux(x, y, 4, env, dejaVu);
            }
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight())==dejaVu.end()){
                pionPresentAux(x, y, 8, env, dejaVu);
            }
            /* top */
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 1, env, dejaVu);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit()
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 5, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y+1);
            if (getExt && ((FragmentTriple<environment>) getExt.getDown()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getDown()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y+1, 15, env, dejaVu);
            }
        }
        /* gauche gauche */
        auto currFrag3 = ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche();
        if (posFrag==3 && find(dejaVu.begin(), dejaVu.end(), currFrag3)==dejaVu.end()){
            dejaVu.push_back(currFrag3);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop())==dejaVu.end()){
                pionPresentAux(x, y, 4, env, dejaVu);
            }
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft())==dejaVu.end()){
                pionPresentAux(x, y, 7, env, dejaVu);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 0, env, dejaVu);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentCentre()
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 6, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x-1, y);
            if (getExt && ((FragmentTriple<environment>) getExt.getRight()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getRight()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x-1, y, 5, env, dejaVu);
            }
        }
        /* center haut */
        auto currFrag4 = ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop();
        if (posFrag==4 && find(dejaVu.begin(), dejaVu.end(), currFrag4)==dejaVu.end()){
            dejaVu.push_back(currFrag4);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight())==dejaVu.end()){
                pionPresentAux(x, y, 8, env, dejaVu);
            }
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft())==dejaVu.end()){
                pionPresentAux(x, y, 7, env, dejaVu);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 2, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 1, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 0, env, dejaVu);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 3, env, dejaVu);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 5, env, dejaVu);
            }
        }
        /* droit droit */
        auto currFrag5 = ((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit();
        if (posFrag==5 && find(dejaVu.begin(), dejaVu.end(), currFrag5)==dejaVu.end()){
            dejaVu.push_back(currFrag5);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop())==dejaVu.end()){
                pionPresentAux(x, y, 4, env, dejaVu);
            }
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight())==dejaVu.end()){
                pionPresentAux(x, y, 8, env, dejaVu);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 2, env, dejaVu);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentCentre()
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 9, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x+1, y);
            if (getExt && ((FragmentTriple<environment>) getExt.getLeft()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getLeft()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x+1, y, 3, env, dejaVu);
            }
        }
        /* gauche centre */
        auto currFrag6 =  ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentCentre();
        if (posFrag==6 && find(dejaVu.begin(), dejaVu.end(), currFrag6)==dejaVu.end()){
            dejaVu.push_back(currFrag6);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft())==dejaVu.end()){
                pionPresentAux(x, y, 7, env, dejaVu);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 3, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 10, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x-1, y);
            if (getExt && ((FragmentTriple<environment>) getExt.getRight()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getRight()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x-1, y, 9, env, dejaVu);
            }
        }
        /* center gauche */
        auto currFrag7 = ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentLeft();
        if (posFrag==7 && find(dejaVu.begin(), dejaVu.end(), currFrag7)==dejaVu.end()){
            dejaVu.push_back(currFrag7);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop())==dejaVu.end()){
                pionPresentAux(x, y, 4, env, dejaVu);
            }
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown())==dejaVu.end()){
                pionPresentAux(x, y, 11, env, dejaVu);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 3, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 6, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 10, env, dejaVu);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 0, env, dejaVu);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 13, env, dejaVu);
            }
        }
        /* center droit */
        auto currFrag8 = ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight();
        if (posFrag==8 && find(dejaVu.begin(), dejaVu.end(), currFrag8)==dejaVu.end()){
            dejaVu.push_back(currFrag8);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentTop())==dejaVu.end()){
                pionPresentAux(x, y, 4, env, dejaVu);
            }
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown())==dejaVu.end()){
                pionPresentAux(x, y, 11, env, dejaVu);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 12, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 9, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 5, env, dejaVu);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getUp()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 2, env, dejaVu);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 15, env, dejaVu);
            }
        }
        /* droit centre */
        auto currFrag9 =  ((FragmentTriple<environment>) currTuile.getRight()).getFragmentCentre();
        if (posFrag==9 && find(dejaVu.begin(), dejaVu.end(), currFrag9)==dejaVu.end()){
            dejaVu.push_back(currFrag9);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight())==dejaVu.end()){
                pionPresentAux(x, y, 8, env, dejaVu);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 12, env, dejaVu);
            }
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 5, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x+1, y);
            if (getExt && ((FragmentTriple<environment>) getExt.getLeft()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getLeft()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x+1, y, 6, env, dejaVu);
            }
        }
        /* gauche droit */
        auto currFrag10 = ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentDroit();
        if (posFrag==10 && find(dejaVu.begin(), dejaVu.end(), currFrag10)==dejaVu.end()){
            dejaVu.push_back(currFrag10);
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
            if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y, 13, env, dejaVu);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile.getLeft()).getFragmentCentre()
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getLeft()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 6, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x-1, y);
            if (getExt && ((FragmentTriple<environment>) getExt.getRight()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getRight()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x-1, y, 12, env, dejaVu);
            }
        }
        /* center bas */
        auto currFrag11 = ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown();
        if (posFrag==11 && find(dejaVu.begin(), dejaVu.end(), currFrag11)==dejaVu.end()){
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
        /* droit gauche */
        auto currFrag12 =  ((FragmentTriple<environment>) currTuile.getRight()).getFragmentGauche();
        if (posFrag==12 && find(dejaVu.begin(), dejaVu.end(), currFrag12)==dejaVu.end()){
            dejaVu.push_back(currFrag12);
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentDown())==dejaVu.end()){
                pionPresentAux(x, y, 11, env, dejaVu);
            }
            if (((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentQuadruple<environment>) currTuile.getCentre()).getFragmentRight())==dejaVu.end()){
                pionPresentAux(x, y, 8, env, dejaVu);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile.getRight()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getRight()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y, 9, env, dejaVu);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit()
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y, 15, env, dejaVu);
            }
            /* ext */
            auto getExt=this->getTuileAt(x+1, y);
            if (getExt && ((FragmentTriple<environment>) getExt.getLeft()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getLeft()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x+1, y, 10, env, dejaVu);
            }
        }
        /* bas gauche */
        auto currFrag13 =  ((FragmentTriple<environment>) currTuile.getDown()).getFragmentGauche();
        if (posFrag==13 && find(dejaVu.begin(), dejaVu.end(), currFrag13)==dejaVu.end()){
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
            auto getExt=this->getTuileAt(x, y-1);
            if (getExt && ((FragmentTriple<environment>) getExt.getUp()).getFragmentDroit()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getUp()).getFragmentDroit())==dejaVu.end()){
                pionPresentAux(x, y-1, 0, env, dejaVu);
            }
        }
        /* bas centre */
        auto currFrag14 = ((FragmentTriple<environment>) currTuile.getDown()).getFragmentCentre();
        if (posFrag==14 && find(dejaVu.begin(), dejaVu.end(), currFrag14)==dejaVu.end()){
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
            auto getExt=this->getTuileAt(x, y-1);
            if (getExt && ((FragmentTriple<environment>) getExt.getUp()).getFragmentCentre()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getUp()).getFragmentCentre())==dejaVu.end()){
                pionPresentAux(x, y-1, 1, env, dejaVu);
            }
        }
        /* bas droit */
        auto currFrag15 = ((FragmentTriple<environment>) currTuile.getDown()).getFragmentDroit();
        if (posFrag==15 && find(dejaVu.begin(), dejaVu.end(), currFrag15)==dejaVu.end()){
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
            auto getExt=this->getTuileAt(x, y-1);
            if (getExt && ((FragmentTriple<environment>) getExt.getUp()).getFragmentGauche()==env
                && find(dejaVu.begin(), dejaVu.end(), ((FragmentTriple<environment>) getExt.getUp()).getFragmentGauche())==dejaVu.end()){
                pionPresentAux(x, y-1, 2, env, dejaVu);
            }
        }
    }


    return false;

}

template<typename TF>
PlateauCarcassonne<TF>::~PlateauCarcassonne() = default;