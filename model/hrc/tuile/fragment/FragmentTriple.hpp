#ifndef CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP

#include "FragmentTuile.hpp"

template<typename T>
class  FragmentTriple final : FragmentTuile<T>{
    //REDEFINTION DE L'OPERATEUR == ;
    T gaucheFragment;
    T droitFragment;
public:
    bool operator==(const FragmentTriple<T> &);
    bool operator!=(const FragmentTriple<T> &);
    const FragmentTriple<int> operator=(const FragmentTriple<T> &);

    const T & getFragmentGauche()const;
    const T & getFragmentDroit()const;
    const T & getFragmentCentre()const;

    void setFragmentDroit(const T &fragment) const;
    void setFragmentGauche(const T &fragment) const;
    void setFragmentCentre(const T &fragment) const;
    int getPoint();


};
#include "../../../src/tuile/fragment/FragmentTriple.tpp"


#endif //CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP
