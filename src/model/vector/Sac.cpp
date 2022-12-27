//
// Created by david on 23/12/22.
//

#include "Sac.hpp"

Sac::Sac() {
    for (int i = 0; i < 9; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::CHAMPS, environment::ROUTE, environment::ROUTE)
                )
        );
    }
    for (int i = 0; i < 3; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::ROUTE, environment::ROUTE, environment::CHAMPS)
                )
        );
    }
    for (int i = 0; i < 2; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::ROUTE, environment::ROUTE, environment::CHAMPS)
                )
        );
    }
    for (int i = 0; i < 1; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE, environment::VILLAGE)
                )
        );
    }
    for (int i = 0; i < 1; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE, environment::VILLAGE)
                )
        );
    }
    for (int i = 0; i < 3; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::ROUTE, environment::ROUTE, environment::CHAMPS)
                )
        );
    }
    for (int i = 0; i < 3; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::INVALIDE, environment::INVALIDE, environment::INVALIDE)
                )
        );
    }
    for (int i = 0; i < 8; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::ROUTE, environment::ROUTE, environment::ROUTE, environment::ROUTE)
                )
        );
    }
    for (int i = 0; i < 4; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::INVALIDE, environment::INVALIDE, environment::INVALIDE, environment::INVALIDE)
                )
        );
    }
    for (int i = 0; i < 5; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::CHAMPS, environment::CHAMPS, environment::CHAMPS)
                )
        );
    }
    for (int i = 0; i < 2; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS, environment::CHAMPS)
                )
        );
    }
    for (int i = 0; i < 3; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE, environment::VILLAGE)
                )
        );
    }
    for (int i = 0; i < 4; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::ABAYES, environment::ABAYES, environment::ABAYES, environment::ABAYES)
                )
        );
    }
    for (int i = 0; i < 2; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::ABAYES, environment::ABAYES, environment::ABAYES, environment::ABAYES)
                )
        );
    }
    //FIN CASES ABAYES
    for (int i = 0; i < 3; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS, environment::CHAMPS)
                )
        );
    }
    for (int i = 0; i < 2; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE, environment::VILLAGE)
                )
        );
    }
    for (int i = 0; i < 4; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::ROUTE, environment::ROUTE, environment::ROUTE)
                )
        );
    }
    for (int i = 0; i < 3; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::CHAMPS, environment::ROUTE, environment::ROUTE)
                )
        );
    }
    for (int i = 0; i < 1; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE, environment::VILLAGE)
                )
        );
    }
    for (int i = 0; i < 2; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE, environment::VILLAGE)
                )
        );
    }
    for (int i = 0; i < 1; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE, environment::VILLAGE)
                )
        );
    }
    for (int i = 0; i < 1; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::ROUTE, environment::CHAMPS),
                        *new FragmentQuadruple<environment>(environment::INVALIDE, environment::INVALIDE, environment::INVALIDE, environment::INVALIDE)
                )
        );
    }
    for (int i = 0; i < 2; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::VILLAGE, environment::CHAMPS, environment::CHAMPS, environment::VILLAGE)
                )
        );
    }
    for (int i = 0; i < 3; ++i) {
        sac.push_back(
                new TuileCarcassonne(
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentTriple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS),
                        *new FragmentTriple<environment>(environment::VILLAGE, environment::VILLAGE, environment::VILLAGE),
                        *new FragmentQuadruple<environment>(environment::CHAMPS, environment::CHAMPS, environment::CHAMPS, environment::CHAMPS)
                )
        );
    }
}

TuileCarcassonne *Sac::getRandomTuile() {
    swap(sac[rand()%sac.size()], sac.back());
    TuileCarcassonne *tc = sac.back();
    sac.pop_back();
    return tc;
}
