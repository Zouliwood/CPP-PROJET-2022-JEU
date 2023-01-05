#include "../../../hrc/model/plateau/PlateauTrax.hpp"

int PlateauTrax::calculPoint(const TuileTrax * t, int x, int y) {
    return 0;
}

bool PlateauTrax::placeFirstTuile() {
    return true;
}

PlateauTrax::PlateauTrax(): Plateau(2, 64){
    for(int i = 0; i < nbr_player; i++){
        string s = "Player  " + to_string(i);
        listPlayer.push_back(new PlayerTrax(s));
    }
    courant = listPlayer.at(current_player);
}


ostream & operator<<(ostream& os, PlateauTrax & plateauTrax) {
    auto pos = plateauTrax.getListTuile().getPositif();
    auto neg = plateauTrax.getListTuile().getNegatif();

    cout << "Coter positif grand tableau Positif " <<  pos.size() << endl;
    os << endl;
    for (int i = 0; i < pos.size(); ++i) { // colonne
        for (int j = pos.at(i)->getNegatif().size()-1; j>= 0; --j) { //les lignes* NOLINT(cppcoreguidelines-narrowing-conversions)
            auto tuile = ((TuileTrax *) pos.at(i)->getNegatif().at(j));
            if (tuile == nullptr) {
                os << "(x:" << j  << ":y:"<< i << ")" << "[U:NONE, R:NONE, D:NONE, L:NONE]";
            } else {
                os << "(x:" << j  << ":y:"<< i << ")" << *tuile;
            }
        }
        os <<"|";
        for (int j =  0; j < pos.at(i)->getPositif().size(); ++j) {
            auto tuile = ((TuileTrax *) pos.at(i)->getPositif().at(j));
            if(tuile == nullptr){
                os << "(x:" << j  << ":y:"<< i << ")" << "[U:NONE, R:NONE, D:NONE, L:NONE]";
            }else {
                os << "(x:" << j  << ":y:"<< i << ")" << *tuile;
            }
        }
        os << endl;
    }
    os << endl;
    cout << "Coter Grand tableau Negatif : " <<  neg.size() << endl;
    os << endl;
    for (int i = neg.size()-1; i >= 0; --i) { // NOLINT(cppcoreguidelines-narrowing-conversions)
        for (int j = neg.at(i)->getNegatif().size()-1; j >= 0; --j) { // NOLINT(cppcoreguidelines-narrowing-conversions)
            auto tuile = ((TuileTrax*)neg.at(i)->getNegatif().at(j));
            if(tuile == nullptr){
                os << "(x:" << j  << ":y:"<< i << ")" << "[U:NONE, R:NONE, D:NONE, L:NONE]";
            }else{
                os << "(x:" << j  << ":y:"<< i << ")" << *tuile;
            }
        }
        os << "|";
        for (int j = 0; j < neg.at(i)->getPositif().size(); ++j) {
            auto tuile = ((TuileTrax*)neg.at(i)->getPositif().at(j));
            if(tuile == nullptr){
                os << "(x:" << j  << ":y:"<< i << ")" << "[U:NONE, R:NONE, D:NONE, L:NONE]";
            }else{
                os << "(x:" << j  << ":y:"<< i << ")" << *tuile;
            }
        }
        os << endl;
        //os << plateauDominos.getListTuile().getNegatif().at(i);
    }

    os << "- affichage terminé - ";

    return os << endl;
}

bool PlateauTrax::compareTuile(const TuileTrax *courant, const TuileTrax *tuileUp, const TuileTrax *tuileDown,
                               const TuileTrax *tuileRight, const TuileTrax *tuileLeft) {
    return (!tuileUp || *(&(FragmentSolo<colorTrax> &)courant->getUp()) == *(&(FragmentSolo<colorTrax> &)tuileUp->getDown()))
           &&  (!tuileRight || *(&(FragmentSolo<colorTrax> &)courant->getRight()) == *(&(FragmentSolo<colorTrax> &)tuileRight->getLeft()))
           && (!tuileLeft || *(&(FragmentSolo<colorTrax> &)courant->getLeft()) == *(&(FragmentSolo<colorTrax> &)tuileLeft->getRight()))
           && (!tuileDown || *(&(FragmentSolo<colorTrax> &)courant->getDown()) == *(&(FragmentSolo<colorTrax> &)tuileDown->getUp()));
}

bool PlateauTrax::placeTuile(TuileTrax *t, int x, int y) {
    if(getTuileAt(x, y) != nullptr) return false;

    const TuileTrax * tuileUp = getTuileAt(x, y + 1);
    const TuileTrax * tuileDown = getTuileAt(x, y - 1);
    const TuileTrax * tuileRight = getTuileAt(x + 1, y);
    const TuileTrax * tuileLeft = getTuileAt(x - 1, y);


    if((listTuile.getPositif().size()+listTuile.getNegatif().size())>0 && tuileDown == nullptr && tuileUp == nullptr && tuileRight == nullptr && tuileLeft == nullptr) {
        //  cout << "a" << endl;
        return false;
    }
    if ((listTuile.getPositif().size()+listTuile.getNegatif().size())==0){
        if (x!=0 || y!=0){
            //     cout << "b" << endl;
            return false; //obliger de placer le premier coup en (0, 0)
        }
    }

    if((listTuile.getPositif().size()+listTuile.getNegatif().size())> 0){
        bool isForcedCoup = existForcedAction(0,0);
        deja_vu.clear();
        if(isForcedCoup && !coupIsOk(x,y)){
            cout << "Il y a un ou plusieurs cours forcés à faire";
            return false;
        }
    }

    /* Redefinition de l'operateur '==' */
    bool flag = this->compareTuile(t, tuileUp, tuileDown, tuileRight, tuileLeft);
    if (flag) {
        cout << "Compare Place tuile ok " << endl;
        if(y >= 0){
            if(y >= this->listTuile.getPositif().size()){
                this->listTuile.addElement(y, new AxeVector<TuileTrax>());
            }
        }else{
            if((y*-1)-1 >= this->listTuile.getNegatif().size()){
                cout << "Creation nouvelle tuile" << endl;
                this->listTuile.addElement(y, new AxeVector<TuileTrax>());
            }
        }
        ((AxeVector<TuileTrax> *)this->listTuile.getAt(y))->addElement(x, t);
    }
    return flag;
}

//coordonnée
bool PlateauTrax::isLoop(int x, int y, colorTrax color, int from, int startX, int startY, int cpt=0) { // NOLINT(misc-no-recursion)
    if (x==startX && y==startY && cpt>1) return true;
    auto * currTuile = getTuileAt(x, y);
    if (!currTuile)return false;//si premiere case de l'appel nullptr return false
    if(from!=1 && getTuileAt(x+1, y) && currTuile->getRight().getFragmentCentre()==color) {
        return isLoop(x+1, y, color, 3, startX, startY, ++cpt);
    } else if (from!=2 && getTuileAt(x, y-1) && currTuile->getDown().getFragmentCentre()==color) {
        return isLoop(x, y-1, color, 0, startX, startY, ++cpt);
    } else if (from!=3 && getTuileAt(x-1, y) && currTuile->getLeft().getFragmentCentre()==color){
        return isLoop(x-1, y, color, 1, startX, startY, ++cpt);
    }else if (from!=0 && getTuileAt(x, y+1) && currTuile->getUp().getFragmentCentre()==color){
        return isLoop(x, y+1, color, 2, startX, startY, ++cpt);
    }else return false;
}

bool PlateauTrax::coupIsOk(int x, int y){

    auto * topTuileTop = getTuileAt(x, y+1);
    auto * topTuileLeft = getTuileAt(x-1, y);
    auto * topTuileRight = getTuileAt(x+1, y);
    auto * topTuileDown = getTuileAt(x, y-1);

    int cptBlanc{0};
    if (topTuileTop && topTuileTop->getDown().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
    if (topTuileRight && topTuileRight->getLeft().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
    if (topTuileDown && topTuileDown->getUp().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
    if (topTuileLeft && topTuileLeft->getRight().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;

    int cptNoir{0};
    if (topTuileTop && topTuileTop->getDown().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
    if (topTuileRight && topTuileRight->getLeft().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
    if (topTuileDown && topTuileDown->getUp().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
    if (topTuileLeft && topTuileLeft->getRight().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;

    //  if (cptBlanc==3 || cptNoir==3)return false;
    return (cptBlanc==2 || cptNoir==2);
}


bool PlateauTrax::existForcedAction(int x, int y){ // NOLINT(misc-no-recursion)
    // on part de 0 0
    auto * courtantTuile = getTuileAt(x, y);
    for(auto item : deja_vu) if(item == courtantTuile)return false;
    deja_vu.push_back(courtantTuile);

    /* if(find(const_cast<TuileTrax *>(deja_vu.begin()), const_cast<TuileTrax *>(deja_vu.end()), const_cast<TuileTrax *>(courtantTuile))!=const_cast<TuileTrax *>(deja_vu).end()){
         return false;
     }*/

    auto * topTuile = getTuileAt(x, y+1);
    auto * rightTuile = getTuileAt(x+1, y);
    auto * bottomTuile = getTuileAt(x, y-1);
    auto * leftTuile = getTuileAt(x-1, y);

    //if(topTuile && rightTuile && leftTuile && bottomTuile){
    //}

    if(topTuile == nullptr){
        //cout << "cas top " << x<<" / " << y << endl;
        //checkDigonalIsNotEmpty return false;
        auto * topTuileTop = getTuileAt(x, y+2);
        auto * topTuileLeft = getTuileAt(x-1, y+1);
        auto * topTuileRight = getTuileAt(x+1, y+1);

        int cptBlanc{0};
        if (topTuileTop && topTuileTop->getDown().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (topTuileRight && topTuileRight->getLeft().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (courtantTuile && courtantTuile->getUp().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (topTuileLeft && topTuileLeft->getRight().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;

        int cptNoir{0};
        if (topTuileTop && topTuileTop->getDown().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (topTuileRight && topTuileRight->getLeft().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (courtantTuile && courtantTuile->getUp().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (topTuileLeft && topTuileLeft->getRight().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;

        //  if (cptBlanc==3 || cptNoir==3)return false;
        if (cptBlanc==2 || cptNoir==2){
            cout << " forced A " << x << " " << y << " " << cptBlanc << " " << cptNoir << endl;
            return true;
        }

    }
    if(rightTuile == nullptr){
        //cout << "cas right " << x<<" / " << y << endl;

        //checkDigonalIsNotEmpty return false;
        auto * rightTuileTop = getTuileAt(x+1, y+1);
        auto * rightTuileRight = getTuileAt(x+2, y);
        auto * topTuileLeft = getTuileAt(x+1, y-1);

        int cptBlanc{0};
        if (rightTuileRight && rightTuileRight->getLeft().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (rightTuileTop && rightTuileTop->getDown().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (courtantTuile && courtantTuile->getRight().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (topTuileLeft && topTuileLeft->getUp().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;

        int cptNoir{0};
        if (rightTuileRight && rightTuileRight->getLeft().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (rightTuileTop && rightTuileTop->getDown().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (courtantTuile && courtantTuile->getRight().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (topTuileLeft && topTuileLeft->getUp().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;

        // if (cptBlanc==3 || cptNoir==3)return false;
        if (cptBlanc==2 || cptNoir==2){
            cout << "forced B " << x << " " << y << " " << cptBlanc << " " << cptNoir << endl;
            return true;
        }

    }
    if(bottomTuile == nullptr){
        //cout << "cas down " << x<<" / " << y << endl;

        auto * rightTuileBottom = getTuileAt(x, y-2);
        auto * rightTuileLeft = getTuileAt(x-1, y-1);
        auto * rightTuileRight = getTuileAt(x+1, y-1);

        int cptBlanc{0};
        if (rightTuileBottom && rightTuileBottom->getUp().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (rightTuileRight && rightTuileRight->getLeft().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (courtantTuile && courtantTuile->getDown().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (rightTuileLeft && rightTuileLeft->getRight().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;

        int cptNoir{0};
        if (rightTuileBottom && rightTuileBottom->getUp().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (rightTuileRight && rightTuileRight->getLeft().getFragmentCentre() == colorTrax::NOIR)cptNoir++;
        if (courtantTuile && courtantTuile->getDown().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (rightTuileLeft && rightTuileLeft->getRight().getFragmentCentre() == colorTrax::NOIR)cptNoir++;

        //  if (cptBlanc==3 || cptNoir==3)return false;
        if (cptBlanc==2 || cptNoir==2){
            cout << "forced C " << x << " " << y << " " << cptBlanc << " " << cptNoir << endl;
            return true;
        }
    }
    if(leftTuile == nullptr){
        //cout << "cas left " << x<<" / " << y << endl;

        auto * rightTuileTop = getTuileAt(x-1, y+1);
        auto * rightTuileDown = getTuileAt(x-1, y-1);
        auto * leftTuileLeft = getTuileAt(x-2, y);

        int cptBlanc{0};
        if (leftTuileLeft && leftTuileLeft->getRight().getFragmentCentre() == colorTrax::BLANC){
            cout << "--A" << cptBlanc << endl;
            cptBlanc++;
        }
        if (rightTuileTop && rightTuileTop->getDown().getFragmentCentre() == colorTrax::BLANC){
            cout << "--B" << cptBlanc << endl;
            cptBlanc++;
        }
        if (courtantTuile && courtantTuile->getLeft().getFragmentCentre() == colorTrax::BLANC){
            cout << "--C" << cptBlanc << endl;
            cptBlanc++;
        }
        if (rightTuileDown && rightTuileDown->getUp().getFragmentCentre() == colorTrax::BLANC){
            cout << "--D" << cptBlanc << endl;
            cptBlanc++;
        }

        int cptNoir{0};
        if (leftTuileLeft && leftTuileLeft->getRight().getFragmentCentre()  == colorTrax::NOIR){
            cout << "--" << cptNoir << endl;
            cptNoir++;
        }
        if (rightTuileTop && rightTuileTop->getDown().getFragmentCentre()  == colorTrax::NOIR){
            cout << "--" << cptNoir << endl;
            cptNoir++;
        }
        if (courtantTuile && courtantTuile->getLeft().getFragmentCentre()  == colorTrax::NOIR){
            cout << "--" << cptNoir << endl;
            cptNoir++;
        }
        if (rightTuileDown && rightTuileDown->getUp().getFragmentCentre()  == colorTrax::NOIR){
            cout << "--" << cptNoir << endl;
            cptNoir++;
        }

        //if (cptBlanc==3 || cptNoir==3)return false;
        if (cptBlanc==2 || cptNoir==2){
            cout << "forced D " << x << " " << y << " " << cptBlanc << " " << cptNoir << endl;
            return true;
        }
    }
    //cout << "On sort " << x<<" / " << y << endl;
    return existForcedAction(x, y+1) ||  existForcedAction(x+1, y) || existForcedAction(x, y-1) ||  existForcedAction(x-1, y); // left
}

bool PlateauTrax::checkVictory() {//TODO: au lieu de renvoyer un bool renvoyer un int -> si ==, numéro gagnant...

    //left bottom - left to right
    if ((int)listTuile.getNegatif().size()!=0){
        for (int i = 0; i < listTuile.getNegatif().size(); ++i) {//parcours y
            int sz = (int)listTuile.getNegatif().at(i)->getNegatif().size();
            if (sz>0){
                auto * currentTuile = listTuile.getNegatif().at(i)->getNegatif().at(sz-1);
                int x = ((int)listTuile.getNegatif().at(i)->getNegatif().size()-1)*-1;
                int y = (i+1)*-1;//(i+1)*-1
                cout << "'" << x <<" "<<y<<endl;
                if (currentTuile && (isLine(x, y, currentTuile->getUp().getFragmentCentre(), x, y, 2)
                                     || isLine(x, y, currentTuile->getRight().getFragmentCentre(), x, y, 3)
                                     || isLine(x, y, currentTuile->getDown().getFragmentCentre(), x, y, 0)))return true;
            }

        }
    }

    //left top - left to right
    if ((int)listTuile.getPositif().size()!=0){
        for (int i = 0; i < listTuile.getPositif().size(); ++i) {//parcours y
            //x, y, startX, startY
            int sz = (int)listTuile.getPositif().at(i)->getNegatif().size();
            if (sz>0){
                auto * currentTuile = listTuile.getPositif().at(i)->getNegatif().at(sz-1);
                int x = ((int)listTuile.getPositif().at(i)->getNegatif().size())*-1;
                int y = (i);
                if (currentTuile && (isLine(x, y, currentTuile->getUp().getFragmentCentre(), x, y, 2)
                                     || isLine(x, y, currentTuile->getRight().getFragmentCentre(), x, y, 3)
                                     || isLine(x, y, currentTuile->getDown().getFragmentCentre(), x, y, 0)))return true;
            }
        }
    }

    //top right - top to bottom
    if ((int)listTuile.getPositif().size()!=0){
        for (int i = 0; i < listTuile.getPositif().size(); ++i) {//parcours y
            //x, y, startX, startY
            int sz = (int)listTuile.getPositif().at(i)->getPositif().size();
            if (sz>0){
                auto * currentTuile = listTuile.getPositif().at(i)->getPositif().at(sz-1);
                int x = ((int)listTuile.getPositif().at(i)->getPositif().size()-1);
                int y = (i);
                if (currentTuile && (isLine(x, y, currentTuile->getUp().getFragmentCentre(), x, y, 1)
                                     || isLine(x, y, currentTuile->getRight().getFragmentCentre(), x, y, 3)
                                     || isLine(x, y, currentTuile->getDown().getFragmentCentre(), x, y, 0)))return true;
            }

        }
    }

    //top left - top to bottom
    if ((int)listTuile.getPositif().size()!=0){
        for (int i = 0; i < listTuile.getPositif().size(); ++i) {//parcours y
            //x, y, startX, startY
            int sz = (int)listTuile.getPositif().at(i)->getNegatif().size();
            if(sz>0){
                auto * currentTuile = listTuile.getPositif().at(i)->getNegatif().at(sz-1);
                int x = ((int)listTuile.getPositif().at(i)->getNegatif().size()-1)*-1;
                int y = (i);
                if (currentTuile && (isLine(x, y, currentTuile->getUp().getFragmentCentre(), x, y, 1)
                                     || isLine(x, y, currentTuile->getRight().getFragmentCentre(), x, y, 3)
                                     || isLine(x, y, currentTuile->getDown().getFragmentCentre(), x, y, 0)))return true;
            }

        }
    }


    //left bottom - check loop
    if ((int)listTuile.getNegatif().size()!=0){
        for (int i = 0; i < listTuile.getNegatif().size(); ++i) {//parcours y
            int sz = (int)listTuile.getNegatif().at(i)->getNegatif().size();
            for (int j = 0; j < sz; ++j) {
                auto * currentTuile = listTuile.getNegatif().at(i)->getNegatif().at(j);
                int x = (j)*-1;
                int y = (i+1)*-1;//(i+1)*-1
                if (currentTuile && isLoop(x, y, currentTuile->getUp().getFragmentCentre(), -1, x, y))return true;
            }

        }
    }

    //top right - check loop
    if ((int)listTuile.getPositif().size()!=0){
        for (int i = 0; i < listTuile.getPositif().size(); ++i) {//parcours y
            //x, y, startX, startY
            int sz = (int)listTuile.getPositif().at(i)->getPositif().size();
            for (int j = 0; j < sz; ++j) {
                auto * currentTuile = listTuile.getPositif().at(i)->getPositif().at(j);
                int x = (j);
                int y = (i);

                if (currentTuile && isLoop(x, y, currentTuile->getUp().getFragmentCentre(), -1, x, y))return true;
            }

        }
    }

    //top left - check loop
    if ((int)listTuile.getPositif().size()!=0){
        for (int i = 0; i < listTuile.getPositif().size(); ++i) {//parcours y
            //x, y, startX, startY
            int sz = (int)listTuile.getPositif().at(i)->getNegatif().size();
            for (int j = 0; j < sz; ++j) {
                auto * currentTuile = listTuile.getPositif().at(i)->getNegatif().at(j);
                int x = (j+1)*-1;
                int y = (i);

                if (currentTuile && isLoop(x, y, currentTuile->getUp().getFragmentCentre(), -1, x, y))return true;
            }

        }
    }

    //bottom right - check loop
    if ((int)listTuile.getNegatif().size()!=0){
        for (int i = 0; i < listTuile.getNegatif().size(); ++i) {//parcours y
            //x, y, startX, startY
            int sz = (int)listTuile.getNegatif().at(i)->getPositif().size();
            for (int j = 0; j < sz; ++j) {
                auto * currentTuile = listTuile.getNegatif().at(i)->getPositif().at(j);
                int x = (j);
                int y = (i)*-1;

                if (currentTuile && isLoop(x, y, currentTuile->getUp().getFragmentCentre(), -1, x, y))return true;
            }

        }
    }

    return false;
}

bool PlateauTrax::isLine(int x, int y, colorTrax color, int startX, int startY, int from, int cpt) { // NOLINT(misc-no-recursion)
    if (cpt!=0 && x==startX && y==startY)return false;
    if (abs(startX-x)==8 || abs(startY-y)==8) return true;
    auto * currTuile = getTuileAt(x, y);
    if (!currTuile)return false;//si premiere case de l'appel nullptr return false
    //cout << " *************************** " << startX << " " << startY << " * " << x << " " << y << " * " << abs(x-startX) << " " << abs(y-startY) << endl;
    if(from!=1 && getTuileAt(x+1, y) && currTuile->getRight().getFragmentCentre()==color) {
        return isLine(x+1, y, color, startX, startY, 3, ++cpt);
    } else if (from!=2 && getTuileAt(x, y-1) && currTuile->getDown().getFragmentCentre()==color) {
        return isLine(x, y-1, color, startX, startY, 0, ++cpt);
    } else if (from!=3 && getTuileAt(x-1, y) && currTuile->getLeft().getFragmentCentre()==color){
        return isLine(x-1, y, color, startX, startY, 1, ++cpt);
    }else if (from!=0 && getTuileAt(x, y+1) && currTuile->getUp().getFragmentCentre()==color){
        return isLine(x, y+1, color, startX, startY, 2, ++cpt);
    }else return false;
}

TuileTrax *PlateauTrax::getFirstTuilePose() {
    return nullptr;
}

PlateauTrax::~PlateauTrax() = default;