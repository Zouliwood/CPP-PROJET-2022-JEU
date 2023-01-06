#include "../../hrc/model/plateau/PlateauCarcassonne.hpp"

bool PlateauCarcassonne::checkVictory() {
    return false;
}

PlateauCarcassonne::PlateauCarcassonne(int nombre_joueur): Plateau(nombre_joueur, 72), sac{*new Sac()}{
    for(int i = 0; i < nbr_player; i++){
        string s = "Player " + to_string(i);
        listPlayer.push_back(new PlayerCarcassonne(*new string(s)));
    }
    courant = listPlayer.at(current_player);
}

int PlateauCarcassonne::calculPoint(const TuileCarcassonne * t, int x, int y){
    return 0;
}
TuileCarcassonne *PlateauCarcassonne::getFirstTuilePose() {
    return tuile_initial;
}

bool PlateauCarcassonne::placeFirstTuile() {
    tuile_initial = sac.getRandomTuile();
    this->listTuile.addElement(0, new AxeVector<TuileCarcassonne>());
    ((AxeVector<TuileCarcassonne> *)this->listTuile.getAt(0))->addElement(0, tuile_initial);
    return ((AxeVector<TuileDominos> *) this->listTuile.getAt(0))->getAt(0) != nullptr;
}

//TODO: add fragment centre - FragmentQuadruple -
bool PlateauCarcassonne::compareTuile(const TuileCarcassonne *courant, const TuileCarcassonne *tuileUp,
                                      const TuileCarcassonne *tuileDown, const TuileCarcassonne *tuileRight,
                                      const TuileCarcassonne *tuileLeft) {
    return (!tuileUp || *(&(FragmentTriple<environment> &)courant->getUp()) == *(&(FragmentTriple<environment> &)tuileUp->getDown()))
           &&  (!tuileRight || *(&(FragmentTriple<environment> &)courant->getRight()) == *(&(FragmentTriple<environment> &)tuileRight->getLeft()))
           && (!tuileLeft || *(&(FragmentTriple<environment> &)courant->getLeft()) == *(&(FragmentTriple<environment> &)tuileLeft->getRight()))
           && (!tuileDown || *(&(FragmentTriple<environment> &)courant->getDown()) == *(&(FragmentTriple<environment> &)tuileDown->getUp()));
}

bool PlateauCarcassonne::pionPresent(int x, int y, int posFrag, environment env){
    solution = false;
    pionPresentAux(x, y, posFrag, env);
    dejaVu.clear();
    cout << "SIZE" << dejaVu.size() << endl;
    return solution;
}

string envToString(environment e)
{
    switch (e)
    {
        case environment::ABAYES: return "ABAYES";
        case environment::INVALIDE: return "INVALIDE";
        case environment::VILLAGE: return "VILLAGE";
        case environment::CHAMPS: return "CHAMPS";
        case environment::ROUTE: return "ROUTE";
        default: return "error";
    }
}

bool PlateauCarcassonne::isDejaVu(int x, int y, int pos){
    for(auto item : dejaVu) if(item->x == x && item->y == y && item->pos == pos)return true;
    return false;
}

void PlateauCarcassonne::pionPresentAux(int x, int y, int posFrag, environment env){
    if(solution)return;
    TuileCarcassonne * currTuile = const_cast<TuileCarcassonne *>(this->getTuileAt(x, y));
    //TODO: vérifier si un pion est présent sur la Tuile courante en position posFrag - return true -

    if (currTuile){


        for (int i = 0; i < listPlayer.size(); ++i) {
            //cout << "_ _ _ _ listPlayer.size() " << ((PlayerCarcassonne *) listPlayer.at(i))->listPion.size() << " " << endl;
            for (int j = 0; j < ((PlayerCarcassonne *) listPlayer.at(i))->getListPion().size(); ++j) {
                Pion * p = ((PlayerCarcassonne *) listPlayer.at(i))->getListPion().at(j);
                if(p->getIsPlaced()){
                    cout << endl;
                    cout << p->getX() << " " << x << endl;
                    cout << p->getY() << " " << y << endl;
                    cout << p->getPos() << " " << posFrag << endl;
                }
                if (p->getIsPlaced() && p->getX() == x && p->getY() == y && p->getPos() == posFrag){
                    cout << "TRUEEEEEEEEEEEEEEEEEEEEEEEEE" << endl;
                    solution = true;
                    return;
                }
            }
        }
        //TODO: fermé - herbe et ville - si les voisins ne sont pas nuls.
        // compter les routes, algo style loop de trax

        /* top droit */
        auto currFrag0 =  ((FragmentTriple<environment>) currTuile->getUp()).getFragmentDroit();
        if (posFrag==0 && !isDejaVu(x, y, 0)){
            dejaVu.push_back(new FragElement(x,y,0));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentTop()==env
                && !isDejaVu(x, y, 4)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 4, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 4, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentLeft()==env
                && !isDejaVu(x, y, 7)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 7, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 7, env);
            }
            /* top */
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentCentre()==env
                && !isDejaVu(x, y, 1)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 1, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 1, env);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentGauche()==env
                && !isDejaVu(x, y, 3)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 3, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 3, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y+1);
            if (getExt && ((FragmentTriple<environment>) getExt->getDown()).getFragmentGauche()==env
                && !isDejaVu(x, y+1, 13)){
                cout << "[REC] ext: " << envToString(env) << ", numeros: 13, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y+1, 13, env);
            }
        }
        /* top centre */
        auto currFrag1 =  ((FragmentTriple<environment>) currTuile->getUp()).getFragmentCentre();
        if (posFrag==1 && !isDejaVu(x, y, 1)){
            dejaVu.push_back(new FragElement(x, y, 1));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentTop()==env
                && !isDejaVu(x, y, 4)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 4, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 4, env);
            }
            /* top */
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentGauche()==env
                && !isDejaVu(x, y, 2)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 2, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 2, env);
            }
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentDroit()==env
                && !isDejaVu(x, y, 0)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 0, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 0, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y+1);
            if (getExt && ((FragmentTriple<environment>) getExt->getDown()).getFragmentCentre()==env
                && !isDejaVu(x, y+1, 14)){
                cout << "[REC] ext: " << envToString(env) << ", numeros: 14, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y+1, 14, env);
            }
        }
        /* top gauche */
        auto currFrag2 =  ((FragmentTriple<environment>) currTuile->getUp()).getFragmentGauche();
        if (posFrag==2 && !isDejaVu(x, y, 2)){
            dejaVu.push_back(new FragElement(x, y, 2));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentTop()==env
                && !isDejaVu(x, y, 4)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 4, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 4, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentRight()==env
                && !isDejaVu(x, y, 8)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 8, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 8, env);
            }
            /* top */
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentCentre()==env
                && !isDejaVu(x, y, 1)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 1, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 1, env);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentDroit() == env
                && !isDejaVu(x, y, 5)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 5, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 5, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y+1);
            if (getExt && ((FragmentTriple<environment>) getExt->getDown()).getFragmentDroit()==env
                && !isDejaVu(x, y+1, 15)){
                cout << "[REC] ext: " << envToString(env) << ", numeros: 15, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y+1, 15, env);
            }
        }
        /* gauche gauche */
        auto currFrag3 = ((FragmentTriple<environment>) currTuile->getLeft()).getFragmentGauche();
        if (posFrag==3 && !isDejaVu(x, y, 3)){
            dejaVu.push_back(new FragElement(x, y, 3));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentTop()==env
                && !isDejaVu(x, y, 4)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 4, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 4, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentLeft()==env
                && !isDejaVu(x, y, 7)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 7, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 7, env);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentDroit()==env
                && !isDejaVu(x, y, 0)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 0, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 0, env);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentCentre() ==env
                && !isDejaVu(x, y, 6)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 6, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 6, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x-1, y);
            if (getExt && ((FragmentTriple<environment>) getExt->getRight()).getFragmentDroit()==env
                && !isDejaVu(x-1, y, 5)){
                cout << "[REC] ext: " << envToString(env) << ", numeros: 5, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x-1, y, 5, env);
            }
        }
        /* center haut */
        auto currFrag4 = ((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentTop();
        if (posFrag==4 && !isDejaVu(x, y, 4)){
            dejaVu.push_back(new FragElement(x, y, 4));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentRight()==env
                && !isDejaVu(x, y, 8)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 8, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 8, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentLeft()==env
                && !isDejaVu(x, y, 7)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 7, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 7, env);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentGauche()==env
                && !isDejaVu(x, y, 2)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 2, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 2, env);
            }
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentCentre()==env
                && !isDejaVu(x, y, 1)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 1, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 1, env);
            }
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentDroit()==env
                && !isDejaVu(x, y, 0)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 0, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 0, env);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentGauche()==env
                && !isDejaVu(x, y, 3)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 3, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 3, env);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentDroit()==env
                && !isDejaVu(x, y, 5)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 5, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 5, env);
            }
        }
        /* droit droit */
        auto currFrag5 = ((FragmentTriple<environment>) currTuile->getRight()).getFragmentDroit();
        if (posFrag==5 && !isDejaVu(x, y, 5)){
            dejaVu.push_back(new FragElement(x, y, 5));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentTop()==env
                && !isDejaVu(x, y, 4)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 4, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 4, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentRight()==env
                && !isDejaVu(x, y, 8)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 8, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 8, env);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentGauche()==env
                && !isDejaVu(x, y, 2)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 2, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 2, env);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentCentre()==env
                && !isDejaVu(x, y, 9)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 9, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 9, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x+1, y);
            if (getExt && ((FragmentTriple<environment>) getExt->getLeft()).getFragmentGauche()==env
                && !isDejaVu(x+1, y, 3)){
                cout << "[REC] ext: " << envToString(env) << ", numeros: 3, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x+1, y, 3, env);
            }
        }
        /* gauche centre */
        auto currFrag6 =  ((FragmentTriple<environment>) currTuile->getLeft()).getFragmentCentre();
        if (posFrag==6 && !isDejaVu(x, y, 6)){
            dejaVu.push_back(new FragElement(x, y, 6));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentLeft()==env
                && !isDejaVu(x, y, 7)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 7, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 7, env);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentGauche()==env
                && !isDejaVu(x, y, 3)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 3, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 3, env);
            }
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentDroit()==env
                && !isDejaVu(x, y, 10)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 10, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 10, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x-1, y);
            if (getExt && ((FragmentTriple<environment>) getExt->getRight()).getFragmentCentre()==env
                && !isDejaVu(x-1, y, 9)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 9, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x-1, y, 9, env);
            }
        }
        /* center gauche */
        auto currFrag7 = ((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentLeft();
        if (posFrag==7 && !isDejaVu(x, y, 7)){
            dejaVu.push_back(new FragElement(x, y, 7));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentTop()==env
                && !isDejaVu(x, y, 4)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 4, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 4, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentDown()==env
                && !isDejaVu(x, y, 11)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 11, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 11, env);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentGauche()==env
                && !isDejaVu(x, y, 3)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 3, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 3, env);
            }
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentCentre()==env
                && !isDejaVu(x, y, 6)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 6, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 6, env);
            }
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentDroit()==env
                && !isDejaVu(x, y, 10)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 10, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 10, env);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentDroit()==env
                && !isDejaVu(x, y, 0)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 0, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 0, env);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentGauche()==env
                && !isDejaVu(x, y, 13)){
                cout << "[REC] env: " << envToString(env) << ", numeros: ext, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 13, env);
            }
        }
        /* center droit */
        auto currFrag8 = ((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentRight();
        if (posFrag==8 && !isDejaVu(x, y, 8)){
            dejaVu.push_back(new FragElement(x,y,8));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentTop()==env
                && !isDejaVu(x, y, 4)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 4, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 4, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentDown()==env
                && !isDejaVu(x, y, 11)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 11, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 11, env);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentGauche()==env
                && !isDejaVu(x, y, 12)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 12, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 12, env);
            }
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentCentre()==env
                && !isDejaVu(x, y, 9)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 9, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 9, env);
            }
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentDroit()==env
                && !isDejaVu(x, y, 5)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 5, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 5, env);
            }
            /* haut */
            if (((FragmentTriple<environment>) currTuile->getUp()).getFragmentGauche()==env
                && !isDejaVu(x, y, 2)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 2, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 2, env);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentDroit()==env
                && !isDejaVu(x, y, 15)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 15, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 15, env);
            }
        }
        /* droit centre */
        auto currFrag9 =  ((FragmentTriple<environment>) currTuile->getRight()).getFragmentCentre();
        if (posFrag==9 && !isDejaVu(x, y, 9)){
            dejaVu.push_back(new FragElement(x,y,9));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentRight()==env
                && !isDejaVu(x, y, 8)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 8, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 8, env);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentGauche()==env
                && !isDejaVu(x, y, 12)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 12, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 12, env);
            }
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentDroit()==env
                && !isDejaVu(x, y, 5)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 5, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 5, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x+1, y);
            cout << "BOOL" << (getExt && ((FragmentTriple<environment>) getExt->getLeft()).getFragmentCentre()==env) << !isDejaVu(x, y, 6) << endl;
            if (getExt && ((FragmentTriple<environment>) getExt->getLeft()).getFragmentCentre()==env
                && !isDejaVu(x+1, y, 6)){
                cout << "[REC] env: " << envToString(env) << ", numeros: ext, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x+1, y, 6, env);
            }
        }
        /* gauche droit */
        auto currFrag10 = ((FragmentTriple<environment>) currTuile->getLeft()).getFragmentDroit();
        if (posFrag==10 && !isDejaVu(x, y, 10)){
            dejaVu.push_back(new FragElement(x,y,10));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentDown()==env
                && !isDejaVu(x, y, 11)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 11, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 11, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentLeft()==env
                && !isDejaVu(x, y, 7)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 7, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 7, env);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentGauche()==env
                && !isDejaVu(x, y, 13)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 13, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 13, env);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentCentre()==env
                && !isDejaVu(x, y, 6)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 6, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 6, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x-1, y);
            if (getExt && ((FragmentTriple<environment>) getExt->getRight()).getFragmentGauche()==env
                && !isDejaVu(x-1, y, 12)){
                cout << "[REC] env: " << envToString(env) << ", numeros: ext, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x-1, y, 12, env);
            }
        }
        /* center bas */
        auto currFrag11 = ((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentDown();
        if (posFrag==11 && !isDejaVu(x, y, 11)){
            dejaVu.push_back(new FragElement(x,y,11));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentRight()==env
                && !isDejaVu(x, y, 8)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 8, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 8, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentLeft()==env
                && !isDejaVu(x, y, 7)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 7, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 7, env);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentGauche()==env
                && !isDejaVu(x, y, 13)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 13, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 13, env);
            }
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentCentre()==env
                && !isDejaVu(x, y, 14)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 14, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 14, env);
            }
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentDroit()==env
                && !isDejaVu(x, y, 15)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 15, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 15, env);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentGauche()==env
                && !isDejaVu(x,y, 12)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 12, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 12, env);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentDroit()==env
                && !isDejaVu(x,y, 10)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 10, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 10, env);
            }
        }
        /* droit gauche */
        auto currFrag12 =  ((FragmentTriple<environment>) currTuile->getRight()).getFragmentGauche();
        if (posFrag==12 && !isDejaVu(x, y, 12)){
            dejaVu.push_back(new FragElement(x,y,12));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentDown()==env
                && !isDejaVu(x,y, 11)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 11, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 11, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentRight()==env
                && !isDejaVu(x,y, 8)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 8, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 8, env);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentCentre()==env
                && !isDejaVu(x,y, 9)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 9, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 9, env);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentDroit() == env
                && !isDejaVu(x,y, 15)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 15, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 15, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x+1, y);
            if (getExt && ((FragmentTriple<environment>) getExt->getLeft()).getFragmentDroit()==env
                && !isDejaVu(x+1,y, 10)){
                cout << "[REC] env: " << envToString(env) << ", numeros: ext, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x+1, y, 10, env);
            }
        }
        /* bas gauche */
        auto currFrag13 =  ((FragmentTriple<environment>) currTuile->getDown()).getFragmentGauche();
        if (posFrag==13 && !isDejaVu(x, y, 13)){
            dejaVu.push_back(new FragElement(x,y,13));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentDown()==env
                && !isDejaVu(x,y, 11)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 11, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 11, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentLeft()==env
                && !isDejaVu(x,y, 7)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 7, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 7, env);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentCentre()==env
                && !isDejaVu(x,y, 14)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 14, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 14, env);
            }
            /* gauche */
            if (((FragmentTriple<environment>) currTuile->getLeft()).getFragmentDroit()==env
                && !isDejaVu(x,y, 10)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 10, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 10, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y-1);
            if (getExt && ((FragmentTriple<environment>) getExt->getUp()).getFragmentDroit()==env
                && !isDejaVu(x,y-1, 0)){
                cout << "[REC] env: " << envToString(env) << ", numeros: ext, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y-1, 0, env);
            }
        }
        /* bas centre */
        auto currFrag14 = ((FragmentTriple<environment>) currTuile->getDown()).getFragmentCentre();
        if (posFrag==14 && isDejaVu(x,y, 14)){
            dejaVu.push_back(new FragElement(x,y,14));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentDown()==env
                && !isDejaVu(x,y, 11)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 11, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 11, env);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentGauche()==env
                && !isDejaVu(x,y, 13)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 13, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 13, env);
            }
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentDroit()==env
                && !isDejaVu(x,y, 15)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 15, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 15, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y-1);
            if (getExt && ((FragmentTriple<environment>) getExt->getUp()).getFragmentCentre()==env
                && !isDejaVu(x,y-1, 1)){
                cout << "[REC] env: " << envToString(env) << ", numeros: ext, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y-1, 1, env);
            }
        }
        /* bas droit */
        auto currFrag15 = ((FragmentTriple<environment>) currTuile->getDown()).getFragmentDroit();
        if (posFrag==15 && isDejaVu(x,y, 15)){
            dejaVu.push_back(new FragElement(x,y,15));
            /* centre */
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentDown()==env
                && !isDejaVu(x,y, 11)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 11, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 11, env);
            }
            if (((FragmentQuadruple<environment>) currTuile->getCentre()).getFragmentRight()==env
                && !isDejaVu(x,y, 8)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 8, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 8, env);
            }
            /* bas */
            if (((FragmentTriple<environment>) currTuile->getDown()).getFragmentCentre()==env
                && !isDejaVu(x,y, 14)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 14, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 14, env);
            }
            /* droit */
            if (((FragmentTriple<environment>) currTuile->getRight()).getFragmentGauche() == env
                && !isDejaVu(x,y, 12)){
                cout << "[REC] env: " << envToString(env) << ", numeros: 12, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y, 12, env);
            }
            /* ext */
            auto getExt=this->getTuileAt(x, y-1);
            if (getExt && ((FragmentTriple<environment>) getExt->getUp()).getFragmentGauche()==env && !isDejaVu(x,y-1, 2)){
                cout << "[REC] env: " << envToString(env) << ", numeros: ext, posfrag:" << posFrag << "x: " << x << ", y:" << y << endl;
                pionPresentAux(x, y-1, 2, env);
            }
        }
    }
}

PlateauCarcassonne::~PlateauCarcassonne() = default;