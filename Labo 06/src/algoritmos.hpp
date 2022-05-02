#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>




template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    typename Contenedor::value_type minimo = *c.begin();
    for ( auto it = c.begin(); it != c.end(); it++){
        if (*it < minimo){
            minimo = *it;
        }
    }
    return minimo;
}

template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::value_type sum = 0;
    for ( auto it = c.begin(); it != c.end(); it++){
        sum += *it;
    }
    return sum / c.size();
}

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type minimo = *desde;
    for ( auto it = desde; it != hasta; ++it){
        if (*it < minimo){
            minimo = *it;
        }
    }
    return minimo;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta) {
    typename Iterator::value_type sum = 0;
    typename Iterator::value_type cant = 0;
    for (auto it = desde; it != hasta; ++it) {
        sum += *it;
        cant +=1;
    }
    return sum / cant;
}

template<class Contenedor>
        void filtrar(Contenedor &c, const typename Contenedor::value_type &elem) {
    for (typename Contenedor::iterator it = c.begin(); it != c.end(); ++it) {
        if (elem == *it) {
            c.erase(it--);
        }
    }
}

template<class Contenedor>
bool ordenado(Contenedor &c) {
    bool res = true;
    typename Contenedor::const_iterator mayor = c.begin();
    mayor++;
    for (typename Contenedor::const_iterator menor = c.begin(); mayor != c.end(); ++menor) {
        if (*menor > *mayor) {
            res = false;
            break;
        }
        ++mayor;
    }
    return res;
}

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor &c, const typename Contenedor::value_type &elem) {
    Contenedor prim;
    Contenedor seg;
    for (typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it) {
        if (*it < elem) {
            prim.insert(prim.end(), *it);
        } else {
            seg.insert(seg.end(), *it);
        }
    }
    std::pair<Contenedor, Contenedor> res = make_pair(prim, seg);
    return res;
}


template<class Contenedor>
    void merge(const Contenedor &c1, const Contenedor &c2, Contenedor &res) {
    typename Contenedor::const_iterator itc1 = c1.begin();
    typename Contenedor::const_iterator itc2 = c2.begin();
    while (itc1 != c1.end() and itc2 != c2.end()) {
        if (*itc1 <= *itc2) {
            res.insert(res.end(), *itc1);
            itc1++;
        } else {
            res.insert(res.end(), *itc2);
            itc2++;
        }
    }
    if (itc1 == c1.end() and itc2 != c2.end()) {
        while (itc2 != c2.end()) {
            res.insert(res.end(), *itc2);
            itc2++;
        }
    } else {
        while (itc1 != c1.end()) {
            res.insert(res.end(), *itc1);
            itc1++;
        }
    }
}



#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
