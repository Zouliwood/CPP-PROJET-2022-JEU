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

bool PlateauTrax::isFirstTuile(const TuileTrax *tuileUp, const TuileTrax *tuileDown, const TuileTrax *tuileRight,
                               const TuileTrax *tuileLeft) {
    return (listTuile.getPositif().size()+listTuile.getNegatif().size())>0 && tuileDown == nullptr && tuileUp == nullptr && tuileRight == nullptr && tuileLeft == nullptr;
}

//coordonnée
bool PlateauTrax::isLoop(int x, int y, colorTrax color, int from, int startX, int startY) { // NOLINT(misc-no-recursion)
    if (x==startX && y==startY)return true;
    auto * currTuile = getTuileAt(x, y);
    if(from!=1 && getTuileAt(x+1, y) && currTuile->getRight().getFragmentCentre()==color) {
        return isLoop(x+1, y, color, 3, startX, startY);
    } else if (from!=2 && getTuileAt(x, y-1) && currTuile->getDown().getFragmentCentre()==color) {
        return isLoop(x, y-1, color, 0, startX, startY);
    } else if (from!=3 && getTuileAt(x-1, y) && currTuile->getLeft().getFragmentCentre()==color){
        return isLoop(x-1, y, color, 1, startX, startY);
    }else if (from!=0 && getTuileAt(x, y+1) && currTuile->getUp().getFragmentCentre()==color){
        return isLoop(x, y+1, color, 2, startX, startY);
    }else return false;
}

bool PlateauTrax::isLine(int x, int y, colorTrax color, int from, int startX, int startY) { // NOLINT(misc-no-recursion)
    if (abs(x)+abs(startX)==8 || abs(y)+abs(startY)==8)return true;
    auto * currTuile = getTuileAt(x, y);
    if(from!=1 && getTuileAt(x+1, y) && currTuile->getRight().getFragmentCentre()==color) {
        return isLoop(x+1, y, color, 3, startX, startY);
    } else if (from!=2 && getTuileAt(x, y-1) && currTuile->getDown().getFragmentCentre()==color) {
        return isLoop(x, y-1, color, 0, startX, startY);
    } else if (from!=3 && getTuileAt(x-1, y) && currTuile->getLeft().getFragmentCentre()==color){
        return isLoop(x-1, y, color, 1, startX, startY);
    }else if (from!=0 && getTuileAt(x, y+1) && currTuile->getUp().getFragmentCentre()==color){
        return isLoop(x, y+1, color, 2, startX, startY);
    }else return false;
}



//TODO: fonction isForced indique si la position courante correspond à un coup forcé
bool PlateauTrax::isForced(int x, int y) {
    auto * topTuile = getTuileAt(x, y+1);
    auto * rightTuile = getTuileAt(x+1, y);
    auto * bottomTuile = getTuileAt(x, y-1);
    auto * leftTuile = getTuileAt(x-1, y);

    if (bottomTuile &&
        (  (topTuile && bottomTuile->getUp()==topTuile->getDown())
        || (leftTuile && bottomTuile->getUp()==leftTuile->getRight())
        || (rightTuile && bottomTuile->getUp()==rightTuile->getLeft())
        ))return true;

    if (leftTuile &&
        (  (rightTuile && leftTuile->getRight()==rightTuile->getLeft())
        || (topTuile && leftTuile->getRight()==topTuile->getDown())
        || (bottomTuile && leftTuile->getRight()==bottomTuile->getUp())
        ))return true;

    if (topTuile &&
        (  (bottomTuile &&topTuile->getDown()==bottomTuile->getUp())
        || (leftTuile && topTuile->getDown()==leftTuile->getRight())
        || (rightTuile && topTuile->getDown()==rightTuile->getLeft())
        ))return true;

    if (rightTuile &&
        (  (leftTuile && rightTuile->getLeft()==leftTuile->getRight())
        || (topTuile && rightTuile->getLeft()==topTuile->getDown())
        || (bottomTuile && rightTuile->getLeft()==bottomTuile->getUp())
        ))return true;

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
    for (int i = 0; i < listTuile.getNegatif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *)listTuile.getNegatif().at(i))->getNegatif().size(); ++j) {
            if (isLoop(i*-1, j*-1, colorTrax::BLANC, 0, i*-1, j*-1)
            || ((i==0 || j==0) && isLine(i*-1, j*-1, colorTrax::BLANC, 0, i*-1, j*-1))) return true;
            if (isLoop(i*-1, j*-1, colorTrax::NOIR, 0, i*-1, j*-1)
                || ((i==0 || j==0) && isLine(i*-1, j*-1, colorTrax::NOIR, 0, i*-1, j*-1))) return true;
        }
    }
    for (int i = 0; i < listTuile.getNegatif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *) listTuile.getNegatif().at(i))->getPositif().size(); ++j) {
            if (isLoop(i*-1, j, colorTrax::NOIR, 0, i*-1, j)
            || ((i==0 || j==0) && isLine(i*-1, j, colorTrax::NOIR, 0, i*-1, j)))return true;
            if (isLoop(i*-1, j, colorTrax::BLANC, 0, i*-1, j)
                || ((i==0 || j==0) && isLine(i*-1, j, colorTrax::BLANC, 0, i*-1, j)))return true;
        }
    }
    for (int i = 0; i < listTuile.getPositif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *) listTuile.getPositif().at(i))->getPositif().size(); ++j) {
            if (isLoop(i, j, colorTrax::NOIR, 0, i, j)
                || ((i==0 || j==0) && isLine(i, j, colorTrax::NOIR, 0, i, j)))return true;
            if (isLoop(i, j, colorTrax::BLANC, 0, i, j)
                || ((i==0 || j==0) && isLine(i, j, colorTrax::BLANC, 0, i, j)))return true;
        }
    }
    for (int i = 0; i < listTuile.getPositif().size(); ++i) {
        for (int j = 0; j < ((AxeVector<TuileTrax> *) listTuile.getPositif().at(i))->getNegatif().size(); ++j) {
            if (isLoop(i, j*-1, colorTrax::NOIR, 0, i, j*-1)
                || ((i==0 || j==0) && isLine(i, j*-1, colorTrax::NOIR, 0, i, j*-1)))return true;
            if (isLoop(i, j*-1, colorTrax::BLANC, 0, i, j*-1)
                || ((i==0 || j==0) && isLine(i, j*-1, colorTrax::BLANC, 0, i, j*-1)))return true;
        }
    }
    return false;
}

PlateauTrax::~PlateauTrax() = default;
