#ifndef CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP

#include "FragmentTuile.hpp"
#include <iostream>
using namespace std;

template<typename V>
class FragmentTriple final : public FragmentTuile<V>{

    template <typename T>
    friend bool operator==(const FragmentTriple<T> & a, const FragmentTriple<T> & b);

    template <typename T>
    friend bool operator!=(const FragmentTriple<T> & a, const FragmentTriple<T> & b);


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

    FragmentTriple<V> & operator=(const FragmentTriple<V> *) const;// override;
    string toString();

    bool compareFragment(const FragmentTriple<V> *);
    const V & getFragmentGauche()const;
    const V & getFragmentDroit()const;
    const V & getFragmentCentre()const;

    void setFragmentDroit(const V &fragment) const;
    void setFragmentGauche(const V &fragment) const;
    void setFragmentCentre(const V &fragment) const;


    /*friend bool operator==(FragmentTriple<int> & a, FragmentTriple<int> & b) {
        cout << "----------- on entre == --------------" << endl;
        return b.gaucheFragment==a.gaucheFragment && b.centreFragment==a.centreFragment && b.droitFragment==a.droitFragment;
    }


    friend bool operator!=(FragmentTriple<int> & a, FragmentTriple<int> & b) {
        cout << "----------- on entre != --------------" << endl;
        return b.gaucheFragment!=a.gaucheFragment ||b.centreFragment!=a.centreFragment || b.droitFragment!=a.droitFragment;
    }*/

   // friend bool operator==(const FragmentTriple<V> *a, const FragmentTriple<V> *b); //override;
   // friend bool operator!=(const FragmentTriple<V> *a,const FragmentTriple<V> *b); //override;
};



template<typename V>
ostream & operator<<(ostream &out, FragmentTriple<V> & fragment);



/*template<typename V>
bool operator==(const FragmentTriple<V> &a, const FragmentTriple<V> &b);

template<typename V>
bool operator!=(const FragmentTriple<V> &a,const FragmentTriple<V> &b);*/

#include "../../../../src/model/tuile/fragment/FragmentTriple.tpp"

#endif //CPP_PROJET_2022_JEU_FRAGMENTTRIPLE_HPP
