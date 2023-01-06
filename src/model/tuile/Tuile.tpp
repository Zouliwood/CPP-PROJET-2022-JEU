#include "../../../hrc/model/tuile/Tuile.hpp"

template<typename TF>
Tuile<TF>::~Tuile() {}

template<typename TF>
void Tuile<TF>::rotate() {}

template<typename TF>
const TF & Tuile<TF>::getUp() const {
    return this->up;
}

template<typename TF>
const TF &Tuile<TF>::getLeft() const {
    return this->left;
}

template<typename TF>
const TF &Tuile<TF>::getRight() const {
    return this->right;
}

template<typename TF>
const TF &Tuile<TF>::getDown() const {
    return this->down;
}

template<typename TF>
Tuile<TF>::Tuile(TF & up,  TF & right, TF & down, TF & left): up{up}, right{right}, left{left}, down{down} {}

/* https://stackoverflow.com/a/8752879/16440965 */
template class Tuile<FragmentTriple<int>>;
template class Tuile<FragmentTriple<environment>>;
template class Tuile<FragmentSolo<colorTrax>>;