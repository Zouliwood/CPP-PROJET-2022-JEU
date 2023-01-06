#ifndef CPP_PROJET_2022_JEU_PION_HPP
#define CPP_PROJET_2022_JEU_PION_HPP

#include "../enum/roleCarcassonne.hpp"
#include "../../../hrc/model/enum/environment.hpp"


class Pion final {

private:
    roleCarcassonne role;
    int x, y, pos;
    bool isPlaced;
public:

    Pion(roleCarcassonne role=roleCarcassonne::PARTISAN, bool isPlaced=false, int x=0, int y=0, int pos_frag=0);
    ~Pion();

    int getX() const;
    int getY() const;
    int getPos() const;
    bool getIsPlaced() const;
    void updatePion(environment env, bool isPlaced, int x, int y, int pos_frag);
    roleCarcassonne getRole() const;
    roleCarcassonne getRoleByEnv(environment env) const;
};


#endif //CPP_PROJET_2022_JEU_PION_HPP
