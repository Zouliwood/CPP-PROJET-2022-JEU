#include "../../../hrc/model/plateau/Pion.hpp"

Pion::Pion(int x, int y, int pos_frag, roleCarcassonne role, PlayerCarcassonne<TuileCarcassonne> * playerCarcassonne):
    x{x}, y{y}, pos{pos_frag}, role{role}, playerCarcassonne{playerCarcassonne}{
}

Pion::~Pion() {

}
