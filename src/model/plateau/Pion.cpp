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

Pion::Pion(int x, int y, int pos_frag, roleCarcassonne role):
    x{x}, y{y}, pos{pos_frag}, role{role}{
}

Pion::~Pion() {

}
