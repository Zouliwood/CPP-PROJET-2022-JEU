#ifndef CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP

#include "FragmentTuile.hpp"

template<typename T>
class FragmentTriple final : public FragmentTuile<T>{

private:
    /* attributs de la classe */
    T gaucheFragment;
    T droitFragment;

public:
    /* Constructeur & Destructeur */
    FragmentTriple();
    ~FragmentTriple() override;

    /* override functions */
    bool operator==(const FragmentTriple<T> &);
    bool operator!=(const FragmentTriple<T> &);
    FragmentTriple<T> & operator=(const FragmentTriple<T> *) const;
    int getPoint();

    /* other functions */

    const T & getFragmentGauche()const;
    const T & getFragmentDroit()const;
    const T & getFragmentCentre()const;

    void setFragmentDroit(const T &fragment) const;
    void setFragmentGauche(const T &fragment) const;
    void setFragmentCentre(const T &fragment) const;

};
#include "../../../src/tuile/fragment/FragmentTriple.tpp"


#endif //CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP
