#ifndef CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP

#include "FragmentTuile.hpp"

template<typename V>
class FragmentTriple final : public FragmentTuile<V>{

private:
    /* attributs de la classe */
    V gaucheFragment;
    V droitFragment;

public:
    /* Constructeur & Destructeur */
    FragmentTriple(V droitFragment,V centreFragment, V gaucheFragment);
    ~FragmentTriple() override;

    /* override functions */
    int getPoint() override;

    /* other functions */
    bool operator==(const FragmentTriple<V> *); //override;
    bool operator!=(const FragmentTriple<V> *); //override;
    FragmentTriple<V> & operator=(const FragmentTriple<V> *) const;// override;
    string toString();

    const V & getFragmentGauche()const;
    const V & getFragmentDroit()const;
    const V & getFragmentCentre()const;

    void setFragmentDroit(const V &fragment) const;
    void setFragmentGauche(const V &fragment) const;
    void setFragmentCentre(const V &fragment) const;

};

template<typename V>
ostream & operator<<(ostream &out, FragmentTriple<V> & fragment);

#include "../../../src/tuile/fragment/FragmentTriple.tpp"

#endif //CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP
