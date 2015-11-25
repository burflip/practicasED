/*! Implementacion  de la clase conjunto<CMP>
 */

/** @todo implementar la funcion
 */
#include <string>
#include <vector>
#include <iostream> 
#include <functional>

#include "crimen.h"
#include "conjunto.h"

using namespace std;

template <typename CMP>
conjunto<CMP>::conjunto() {

}

template <typename CMP>
conjunto<CMP>::conjunto(const conjunto<CMP> & d) {
    this->vc.clear();
    for (unsigned int i = 0; i < d.size(); i++) {
        this->vc.push_back(d.getAt(i));
    }
}

template <typename CMP>
crimen conjunto<CMP>::getAt(int i) const {
    crimen c;
    if (this->vc.size() > (unsigned) i) {
        c = this->vc.at(i);
    }
    return c;
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::find(const long int & id) {
    conjunto<CMP>::iterator it;
    vector<conjunto<CMP>::entrada>::iterator itvec = vc.begin();
    it.itv = vc.end();

    if (this->cheq_rep()) {
        int abajo = 0;
        int arriba = this->vc.size() - 1;
        int centro;

        while (abajo <= arriba) {
            centro = ((arriba - abajo) / 2) + abajo;
            if (this->vc.at(centro).getID() == id) {
                itvec = vc.begin() + centro;
                it.itv = itvec;
            } else {
                if (id < this->vc.at(centro).getID())
                    arriba = centro - 1;
                else
                    abajo = centro + 1;
            }
        }
    }

    return it;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::find(const long int & id) const {
    conjunto<CMP>::const_iterator it;
    vector<conjunto<CMP>::entrada>::const_iterator itvec = vc.begin();
    it.c_itv = vc.end();
 
    if (this->cheq_rep()) {
        int abajo = 0;
        int arriba = this->vc.size() - 1;
        int centro;

        while (abajo <= arriba) {
            centro = ((arriba - abajo) / 2) + abajo;
            if (this->vc.at(centro).getID() == id) {
                itvec = vc.begin() + centro;
                it.c_itv = itvec;
            } else {
                if (id < this->vc.at(centro).getID())
                    arriba = centro - 1;
                else
                    abajo = centro + 1;
            }
        }
    }

    return it;
}

template <typename CMP>
string conjunto<CMP>::zeroFill(const string & s, unsigned int n) const {
    string filled = s;
    int diff = n - s.size();
    for (int i = 0; i < diff; i++) {
        filled = "0" + filled;
    }
    return filled;
}

template <typename CMP>
conjunto<CMP> conjunto<CMP>::findIUCR(const string & iucr) const {
    conjunto<CMP> c;
    string zfIUCR = zeroFill(iucr, 4);
    for (unsigned int i = 0; i < this->vc.size(); i++) {
        int j = 0;
        if (vc.at(i).getIUCR() == zfIUCR) {
            c.insert(vc.at(i));
            j++;
        }

    }
    cout << c << endl;
    return c;
}

template <typename CMP>
conjunto<CMP> conjunto<CMP>::findDESCR(const string & descr) const {
    conjunto<CMP> c;

    for (unsigned int i = 0; i < this->vc.size(); i++) {
        int j = 0;
        if (this->getAt(i).getDescription() == descr) {
            c.insert(vc.at(i));
            j++;
        }
    }


    return c;

}

template <typename CMP>
bool conjunto<CMP>::insert(const conjunto<CMP>::entrada & e) {

    bool insertado = false;
    conjunto<CMP>::iterator it;
    it.itv = this->vc.begin();

    conjunto<CMP>::iterator it_final;
    it_final.itv = this->vc.end();

    conjunto<CMP>::iterator it_find;
    it_find = this->find(e.getID());



    if (it_find == it_final) {

        while (it != it_final && !insertado) {
            if ((*it).getID() > e.getID()) {
                this->vc.insert((it.itv), e);
                insertado = true;
            } else
                it++;
        }
    }

    if (!insertado) {
        insertado = true;
        this->vc.push_back(e);
    }
    return insertado;

}

template <typename CMP>

bool conjunto<CMP>::erase(const long int & id) {
    bool borrado = false;


    for (unsigned int i = 0; i < vc.size() && !borrado; i++) {
        if (vc.at(i).getID() == id) {
            vc.erase(vc.begin() + i);
            borrado = true;
        }
    }

    return borrado;

}

template <typename CMP>
bool conjunto<CMP>::erase(const conjunto<CMP>::entrada & e) {
    bool borrado;

    for (unsigned int i = 0; i < vc.size() && !borrado; i++) {
        if (vc.at(i).getID() == e.getID()) {
            vc.erase(vc.begin() + i);
            borrado = true;
        }
    }

    return borrado;


}
template <typename CMP>
conjunto<CMP> & conjunto<CMP>::operator=(const conjunto<CMP> & org) {
    this->vc.clear();

    for (unsigned int i = 0; i < org.size(); i++) {
        this->vc.push_back(org.getAt(i));
    }


    return *this;
}

template <typename CMP>
unsigned int conjunto<CMP>::size() const {
    return vc.size();
}

template <typename CMP>
bool conjunto<CMP>::empty() const {
    return this->vc.size() == 0;
}
/** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
 */

// Devuelve si los ID son todos menores o iguales y que son mayores que 0.

template <typename CMP>
bool conjunto<CMP>::cheq_rep() const {
    bool inv = false;
    int size = vc.size();
    for (int i = 0; i < size - 1; i++) {
        if ((vc.at(i).getID() < vc.at(i + 1).getID()) && vc.at(i).getID() > 0)
            inv = true;
    }

    return inv;

}



// ----------------------------- BEGIN Y END----------------------------------

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::begin() {
    conjunto<CMP>::iterator sal;
    sal.itv = vc.begin();
    sal.puntero = this;
    return sal;
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::end() {
    conjunto<CMP>::iterator sal;
    sal.itv = vc.end();
    return sal;
}
/** @brief constructor defecto iterator
 */

// CLASE ITERATOR -----------------------------------------------------

template <typename CMP>
conjunto<CMP>::iterator::iterator() {
}

/** @brief constructor copia iterator
 */
 
 template <typename CMP>
conjunto<CMP>::iterator::iterator(const iterator & i) {
    this->itv = i.itv;
}

template <typename CMP>
 const typename conjunto<CMP>::entrada & conjunto<CMP>::iterator::operator*() const {
    return *(this->itv);
}

template <typename CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator-(int i) {
    for (int j = 0; j < i; j++)
        (this->itv)++;

    return *this;
}

template <typename CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator+(int i) {
    for (int j = 0; j < i; j++)
        (this->itv)++;

    return *this;
}

template <typename CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator=(const conjunto<CMP>::iterator & i) {
    this->itv = i.itv;
    return *this;
}

template <typename CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator++() {
    if (this->itv != (*this).puntero->vc.end())
        (this->itv)++;

    return (*this);
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::iterator::operator++(int) {

    if (this->itv != (*this).puntero->vc.end())
        this->itv++;

    return *this;
}

template <typename CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator--() {
    if (this->itv != (*this).puntero->vc.begin())
        (this->itv)--;

    return (*this);
}

template <typename CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::iterator::operator--(int) {
    if (this->itv != (*this).puntero->vc.begin())
        this->itv--;

    return *this;
}

template <typename CMP>
bool conjunto<CMP>::iterator::operator==(const conjunto<CMP>::iterator & it) {
    return (this->itv == it.itv);
}

template <typename CMP>
bool conjunto<CMP>::iterator::operator!=(const conjunto<CMP>::iterator & it) {
    return (this->itv != it.itv);
}
//CLASE conjunto<CMP> CONST BEGIN Y END --------------------------------------

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::cbegin() {
    conjunto<CMP>::const_iterator sal;
    sal.c_itv = vc.begin();
    sal.punt_const = this;
    return sal;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::cend() {
    conjunto<CMP>::const_iterator sal;
    sal.c_itv = vc.end();
    return sal;
}

//CLASE CONST_ITERATOR ----------------------------------------------------

template <typename CMP>
conjunto<CMP>::const_iterator::const_iterator() {
}

template <typename CMP>
conjunto<CMP>::const_iterator::const_iterator(const iterator & i) {
    this->c_itv = i.itv;
}

template <typename CMP>
conjunto<CMP>::const_iterator::const_iterator(const const_iterator & i) {
    this->c_itv = i.c_itv;
}

template <typename CMP>
const typename conjunto<CMP>::entrada & conjunto<CMP>::const_iterator::operator*() const {
    return *(this->c_itv);
}

template <typename CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator+(int i) {
    for (int j = 0; j < i; j++)
        (this->c_itv)++;

    return *this;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator=(const conjunto<CMP>::const_iterator & i) {
    this->c_itv = i.c_itv;
    return *this;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator++() {
    if (this->c_itv != (*this).punt_const->vc.end())
        (this->c_itv)++;

    return (*this);
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator::operator++(int) {
    if (this->c_itv != (*this).punt_const->vc.end())
        this->c_itv++;

    return *this;
}

template <typename CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator--() {
    if (this->c_itv != (*this).punt_const->vc.begin())
        (this->c_itv)--;

    return (*this);
}

template <typename CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator::operator--(int) {
    if (this->c_itv != (*this).punt_const->vc.begin())
        this->c_itv--;

    return *this;
}

template <typename CMP>
bool conjunto<CMP>::const_iterator::operator==(const conjunto<CMP>::const_iterator & it) {
    return (this->c_itv == it.c_itv);
}

template <typename CMP>
bool conjunto<CMP>::const_iterator::operator!=(const conjunto<CMP>::const_iterator & it) {
    return (this->c_itv != it.c_itv);
}

template <typename CMP>
ostream& operator<<(ostream& os, const conjunto<CMP>& c) {

    for (unsigned int i = 0; i < c.size(); i++)
        os << "conjunto<CMP> " << i << endl << c.getAt(i) << endl;



    return os;
}
