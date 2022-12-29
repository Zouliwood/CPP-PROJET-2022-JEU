#ifndef CPP_PROJET_2022_JEU_PION_HPP
#define CPP_PROJET_2022_JEU_PION_HPP

#include "../enum/roleCarcassonne.hpp"


class Pion final {

private:
    roleCarcassonne role;
    int x, y, pos;
public:

    Pion(int x, int y, int pos_frag, roleCarcassonne role);
    ~Pion();

    int getX() const;
    int getY() const;
    int getPos() const;

};


#endif //CPP_PROJET_2022_JEU_PION_HPP
