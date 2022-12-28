#ifndef CPP_PROJET_2022_JEU_FRAGMENTQUADRUPLE_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTQUADRUPLE_HPP


#include "FragmentTuile.hpp"

template<typename V>
class FragmentQuadruple final : public FragmentTuile<V> {

    /* override functions */
    template<typename T>
    friend bool operator==(const FragmentQuadruple<T> & a, const FragmentQuadruple<T> & b);// override;

    template<typename T>
    friend bool operator!=(const FragmentQuadruple<T> & a, const FragmentQuadruple<T> & b);// override;

private:
    V gaucheFragment;
    V droitFragment;
    V hautFragment;

public:
    /* Constructeur & Destructeur */
    FragmentQuadruple(V hautFragment, V droitFragment, V basFragment, V gaucheFragment);
    ~FragmentQuadruple() override;


    const V & getFragmentCentre()const;
    const V & getFragmentTop() const;
    const V & getFragmentRight() const;
    const V & getFragmentDown() const;
    const V & getFragmentLeft() const;

    FragmentQuadruple<V> & operator=(const FragmentQuadruple<V> *) const;// override;

    int getPoint() override;

    /* void setFragmentDroit(const V &fragment) const;
     void setFragmentGauche(const V &fragment) const;
     void setFragmentCentre(const V &fragment) const;
 */

};

#include "../../../../src/model/tuile/fragment/FragmentQuadruple.tpp"



#endif //CPP_PROJET_2022_JEU_FRAGMENTQUADRUPLE_HPP
