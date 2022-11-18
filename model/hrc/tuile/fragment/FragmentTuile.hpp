#ifndef CPP_PROJET_2022_JEU_FRAGMENTTUILE_HPP
#define CPP_PROJET_2022_JEU_FRAGMENTTUILE_HPP

template<typename T>
class FragmentTuile {

protected:
    T centreFragment;

public:
    virtual bool operator==(const FragmentTuile<T> &)=0;
    virtual bool operator!=(const FragmentTuile<T> &)=0;
};


#endif //CPP_PROJET_2022_JEU_FRAGMENTTUILE_HPP