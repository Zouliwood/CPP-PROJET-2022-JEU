#include "../../../hrc/model/plateau/PlateauTrax.hpp"

int PlateauTrax::calculPoint(const TuileTrax * t, int x, int y) {
    return 0;
}

bool PlateauTrax::placeFirstTuile() {
    return true;
}

PlateauTrax::PlateauTrax() = default;

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
/*
    bool existFrd = canReplay();
    bool isCurrFrd = isForced(x, y);
    cout << "existFrd (canReplay) " << existFrd << " isCurrFrd (isForced)" << !isCurrFrd << endl;
    if (existFrd && !isCurrFrd){
        cout << "c" << endl;
        return false;
    }


    //check largeur et hauteur
if (x>=0){
        if ((listTuile.getNegatif().size()+x)>8){
            cout << "d" << endl;
            return false;
        }

        if (listTuile.getPositif().size()>x){
            auto el = ((AxeVector<TuileTrax> *) listTuile.getPositif().at(x));
            if (y>=0){
                if (el->getNegatif().size()+y>8){
                    cout << "e" << endl;
                    return false;
                }
            }else{
                if (el->getPositif().size()+(y+1)*-1>8){
                    cout << "f" << endl;
                    return false;
                }
            }
        }

    }else{
        if ((listTuile.getPositif().size()+(x+1)*-1)>8){
            cout << "g" << endl;
            return false
        }

        if (listTuile.getNegatif().size()>((x+1)*-1)){
            auto el = ((AxeVector<TuileTrax> *) listTuile.getNegatif().at((x+1)*-1));
            if (y>=0){
                if (el->getNegatif().size()+y>8){
                    cout << "h" << endl;
                    return false;
                }
            }else{
                if (el->getPositif().size()+(y+1)*-1>8){
                    cout << "i" << endl;
                    return false;
                }
            }
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

bool PlateauTrax::isLine(int x, int y, colorTrax color, int from, int startX, int startY) { // NOLINT(misc-no-recursion)
    if (abs(x-startX)==8 || abs(y-startY)==8)return true;
    auto * currTuile = getTuileAt(x, y);
    if (!currTuile)return false;//premiere appel case nullptdr return false
    if(from!=1 && getTuileAt(x+1, y) && currTuile->getRight().getFragmentCentre()==color) {
        return isLine(x+1, y, color, 3, startX, startY);
    } else if (from!=2 && getTuileAt(x, y-1) && currTuile->getDown().getFragmentCentre()==color) {
        return isLine(x, y-1, color, 0, startX, startY);
    } else if (from!=3 && getTuileAt(x-1, y) && currTuile->getLeft().getFragmentCentre()==color){
        return isLine(x-1, y, color, 1, startX, startY);
    }else if (from!=0 && getTuileAt(x, y+1) && currTuile->getUp().getFragmentCentre()==color){
        return isLine(x, y+1, color, 2, startX, startY);
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


bool PlateauTrax::existForcedAction(int x, int y){ // on part de 0 0
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
        cout << "cas top " << x<<" / " << y << endl;
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
        if (cptBlanc==2 || cptNoir==2)return true;

    }
    if(rightTuile == nullptr){
        cout << "cas right " << x<<" / " << y << endl;

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
        if (cptBlanc==2 || cptNoir==2)return true;

    }
    if(bottomTuile == nullptr){
        cout << "cas down " << x<<" / " << y << endl;

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
        if (cptBlanc==2 || cptNoir==2)return true;
    }
    if(leftTuile == nullptr){
        cout << "cas left " << x<<" / " << y << endl;

        auto * rightTuileRight = getTuileAt(x-1, y+1);
        auto * rightTuileLeft = getTuileAt(x-1, y-1);
        auto * leftTuileTop = getTuileAt(x-2, y);

        int cptBlanc{0};
        if (leftTuileTop && leftTuileTop->getRight().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (rightTuileRight && rightTuileRight->getUp().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (courtantTuile && courtantTuile->getLeft().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;
        if (rightTuileLeft && rightTuileLeft->getDown().getFragmentCentre() == colorTrax::BLANC)cptBlanc++;

        int cptNoir{0};
        if (leftTuileTop && leftTuileTop->getRight().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (rightTuileRight && rightTuileRight->getUp().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (courtantTuile && courtantTuile->getLeft().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;
        if (rightTuileLeft && rightTuileLeft->getDown().getFragmentCentre()  == colorTrax::NOIR)cptNoir++;

        //if (cptBlanc==3 || cptNoir==3)return false;
        if (cptBlanc==2 || cptNoir==2)return true;
    }
    cout << "On sort " << x<<" / " << y << endl;
    return existForcedAction(x, y+1) ||  existForcedAction(x+1, y) || existForcedAction(x, y-1) ||  existForcedAction(x-1, y); // left
}

bool PlateauTrax::isUnTruc(colorTrax color1, colorTrax color2, colorTrax color3, colorTrax color4){
    int cptBlanc{0};
    if (color1 == colorTrax::BLANC)cptBlanc++;
    if (color2 == colorTrax::BLANC)cptBlanc++;
    if (color3 == colorTrax::BLANC)cptBlanc++;
    if (color4 == colorTrax::BLANC)cptBlanc++;

    int cptNoir{0};
    if (color1 == colorTrax::NOIR)cptNoir++;
    if (color2 == colorTrax::NOIR)cptNoir++;
    if (color3 == colorTrax::NOIR)cptNoir++;
    if (color4 == colorTrax::NOIR)cptNoir++;

    if (cptBlanc==3 || cptNoir==3)return false;
    if (cptBlanc==2 || cptNoir==2)return true;
}

//TODO: fonction isForced indique si la position courante correspond à un coup forcé
bool PlateauTrax::isForced(int x, int y) {
    if(getTuileAt(x,y) != nullptr) return false;

    auto * topTuile = getTuileAt(x, y+1);
    auto * rightTuile = getTuileAt(x+1, y);
    auto * bottomTuile = getTuileAt(x, y-1);
    auto * leftTuile = getTuileAt(x-1, y);

    if (bottomTuile &&
        (  (topTuile && bottomTuile->getUp()==topTuile->getDown())
        || (leftTuile && bottomTuile->getUp()==leftTuile->getRight())
        || (rightTuile && bottomTuile->getUp()==rightTuile->getLeft())
        )){
        cout << "-- 1:"  << x << " " << y << endl;
        return true;
    }

    if (leftTuile &&
        (  (rightTuile && leftTuile->getRight()==rightTuile->getLeft())
        || (topTuile && leftTuile->getRight()==topTuile->getDown())
        || (bottomTuile && leftTuile->getRight()==bottomTuile->getUp())
        )){
        cout << "-- 2:"  << x << " " << y << endl;
        return true;
    }

    if (topTuile &&
        (  (bottomTuile &&topTuile->getDown()==bottomTuile->getUp())
        || (leftTuile && topTuile->getDown()==leftTuile->getRight())
        || (rightTuile && topTuile->getDown()==rightTuile->getLeft())
        )){
        cout << "-- 3:"  << x << " " << y << endl;
        return true;
    }

    if (rightTuile &&
        (  (leftTuile && rightTuile->getLeft()==leftTuile->getRight())
        || (topTuile && rightTuile->getLeft()==topTuile->getDown())
        || (bottomTuile && rightTuile->getLeft()==bottomTuile->getUp())
        )){
        cout << "-- 4 :"  << x << " " << y << endl;
        return true;
    }

    cout << "on sort:"  << x << " " << y << endl;
    return false;
}

//TODO: fonction canReplay : return true si il existe un coup forcé
bool PlateauTrax::canReplay() {
    for (int i = 0; i < listTuile.getNegatif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *)listTuile.getNegatif().at(i))->getNegatif().size(); ++j) {
            if (isForced(i*-1, j*-1))return true;
        }
    }
    for (int i = 0; i < listTuile.getPositif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *)listTuile.getPositif().at(i))->getNegatif().size(); ++j) {
            if (isForced(i, j*-1))return true;
        }
    }
    for (int i = 0; i < listTuile.getNegatif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *)listTuile.getNegatif().at(i))->getPositif().size(); ++j) {
            if (isForced(i*-1, j))return true;
        }
    }
    for (int i = 0; i < listTuile.getPositif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *)listTuile.getPositif().at(i))->getPositif().size(); ++j) {
            if (isForced(i, j))return true;
        }
    }
    return false;
}
//TODO: si fonction return existe coup forcé, aors vérifier place tuile va bien placé un coup forcé

bool PlateauTrax::checkVictory() {//TODO: au lieu de renvoyer un bool renvoyer un int -> si ==, numéro gagnant...

    int cpt = 0;
    for (int i = 0; i < listTuile.getNegatif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *)listTuile.getNegatif().at(i))->getNegatif().size(); ++j) {
            if (isLoop(i*-1, j*-1, colorTrax::BLANC, 0, i*-1, j*-1)
            || ((i==0 || j==0) && isLine(i*-1, j*-1, colorTrax::BLANC, 0, i*-1, j*-1))) return true;
            if (isLoop(i*-1, j*-1, colorTrax::NOIR, 0, i*-1, j*-1)
                || ((i==0 || j==0) && isLine(i*-1, j*-1, colorTrax::NOIR, 0, i*-1, j*-1))) return true;
            if (getTuileAt(i*-1, j*-1)) cpt++;
        }
    }
    for (int i = 0; i < listTuile.getNegatif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *) listTuile.getNegatif().at(i))->getPositif().size(); ++j) {
            if (isLoop(i*-1, j, colorTrax::NOIR, 0, i*-1, j)
            || ((i==0 || j==0) && isLine(i*-1, j, colorTrax::NOIR, 0, i*-1, j)))return true;
            if (isLoop(i*-1, j, colorTrax::BLANC, 0, i*-1, j)
                || ((i==0 || j==0) && isLine(i*-1, j, colorTrax::BLANC, 0, i*-1, j)))return true;
            cpt++;
        }
    }
    for (int i = 0; i < listTuile.getPositif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *) listTuile.getPositif().at(i))->getPositif().size(); ++j) {
            //cout << "f---" << isLine(i, j, colorTrax::NOIR, 0, i, j) << endl;
            if (isLoop(i, j, colorTrax::NOIR, 0, i, j)
                || (/*(i==0 && j==0) &&*/ isLine(i, j, colorTrax::NOIR, -1, i, j))){
                return true;
            }
            if (isLoop(i, j, colorTrax::BLANC, 0, i, j)
                || (/*(i==0 && j==0) &&*/ isLine(i, j, colorTrax::BLANC, -1, i, j))){
                return true;
            }
            cpt++;
        }
    }
    for (int i = 0; i < listTuile.getPositif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *) listTuile.getPositif().at(i))->getNegatif().size(); ++j) {
            if (isLoop(i, j*-1, colorTrax::NOIR, 0, i, j*-1)
                || ((i==0 || j==0) && isLine(i, j*-1, colorTrax::NOIR, 0, i, j*-1)))return true;
            if (isLoop(i, j*-1, colorTrax::BLANC, 0, i, j*-1)
                || ((i==0 || j==0) && isLine(i, j*-1, colorTrax::BLANC, 0, i, j*-1)))return true;
            cpt++;
        }
    }
    return cpt==64;
}

PlateauTrax::~PlateauTrax() = default;
