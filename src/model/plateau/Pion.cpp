#include "../../../hrc/model/plateau/Pion.hpp"

int Pion::getX() const{
    return this->x;
}

int Pion::getY() const{
    return this->y;
}

int Pion::getPos() const{
    return this->pos;
}

Pion::~Pion() {

}

Pion::Pion(roleCarcassonne role, bool isPlaced, int x, int y, int pos_frag): role{role},  x{x}, y{y}, pos{pos_frag},isPlaced{isPlaced} {

}

bool Pion::getIsPlaced() const {
    return this->isPlaced;
}

roleCarcassonne Pion::getRole() const {
    return this->role;
}

void Pion::updatePion(environment env, bool isPlaced, int x, int y, int pos_frag) {
    this->role=getRoleByEnv(env);
    this->isPlaced=isPlaced;
    this->x=x;
    this->y=y;
    this->pos=pos_frag;
}

roleCarcassonne Pion::getRoleByEnv(environment env) const{
    switch (env) {
        case environment::VILLAGE:
            return roleCarcassonne::CHEVALIER;
        case environment::ROUTE:
            return roleCarcassonne::VOLEUR;
        case environment::CHAMPS:
            return roleCarcassonne::PAYSAN;
        case environment::ABAYES:
            return roleCarcassonne::MOINE;
        default:
            return roleCarcassonne::PARTISAN;
    }
}