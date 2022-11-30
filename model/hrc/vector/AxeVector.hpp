#ifndef CPP_PROJET_2022_JEU_AXEVECTOR_HPP
#define CPP_PROJET_2022_JEU_AXEVECTOR_HPP

#include <vector>
#define TAUX 10

using namespace std;

template<typename T>
class AxeVector {



private:
    vector<T *> positif;
    vector<T *> negatif;

public:
    T * getAt(int pos);
    void addElement(int pos, T * element);
    vector<T*> getPositif();
    vector<T*> getNegatif();

};

#include "AxeVector.tpp"

#endif