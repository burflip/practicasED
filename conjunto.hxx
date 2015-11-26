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

template <class CMP>
conjunto<CMP>::conjunto() {

}

template <class CMP>
conjunto<CMP>::conjunto(const conjunto<CMP> & d) {
    this->vc.clear();
    for (unsigned int i = 0; i < d.size(); i++) {
        this->vc.push_back(d.getAt(i));
    }
}

template <class CMP>
crimen conjunto<CMP>::getAt(int i) const {
    crimen c;
    if (this->vc.size() > (unsigned) i) {
        c = this->vc.at(i);
    }
    return c;
}

template <class CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::find(const long int & id) {
    conjunto<CMP>::iterator it;
	it.itv = vc.begin();

    bool encontrado = false;
    
    do {
		if ((*it).getID() == id)
			encontrado = true;
		else
			it++;
	}while ((it.itv != vc.end()) && !encontrado);
    
    return it;


    
}

template <class CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::find(const long int & id) const {
    conjunto<CMP>::iterator itc;
	itc.itv = vc.begin();

    bool encontrado = false;
    
    do {
		if ((*itc).getID == id)
			encontrado = true;
		else
			itc++;
	}while ((itc.itv != vc.end()) && !encontrado);
    
    return itc; 
}
/*bool conjunto<CMP>::busquedaBinaria (const crimen &d ){
    int sup=vc.size()-1;
    int inf = 0;
    while (sup > inf) {
      medio = (inf+sup)/2;
      if (!comp(vc[medio],d) && !comp(d,vc[medio]) ) return true;  // comparamos igualdad entre crimen
      else if (comp(vc[medio],d)) inf = medio+1; // comparamos menor entre crimen
      else sup = medio-1;
    }
    return false;
}
*/
template <class CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::find(const crimen & c) const {
    conjunto::const_iterator it;
    it.c_itv = vc.begin();
    bool encontrado = false;
    
    
    while (it.c_itv <= vc.end() && !encontrado)
	{
			if ((!comp((*it),c)) && !comp(c,(*it)))
				encontrado = true;
			else
				it++;
	}
}
	
template <class CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::find(const crimen & c) {
    conjunto::iterator it;
    it.itv = vc.begin();
    bool encontrado = false;
    
    
    while (it.itv <= vc.end() && !encontrado)
	{
			if ((!comp((*it),c)) && !comp(c,(*it)))
				encontrado = true;
			else
				it++;
	}
	
	return it;
}
			
    /* vector<conjunto::entrada>::const_iterator itvec = vc.begin();
    it.c_itv = vc.begin();
  
	int abajo = 0;
	int arriba = this->vc.size() - 1;
	int centro;
	bool encontrado = false;
    
	while (abajo <= arriba) {
		centro = (arriba+abajo) / 2;
		cout << "ADIOS" << endl;

		if ((!comp(vc.at(centro),c)) && !comp(c,vc.at(centro))) {
			it.c_itv = vc.begin() + centro; 
			encontrado = true;
		}
		else {
			if (comp(vc.at(centro), c)) {
				cout << "ARRIBA" << endl;
				arriba = centro - 1;
			}
			else {
				cout << "ABAJO" << endl;
				abajo = centro + 1;		
			}	
		}	
	}
	
	if (!encontrado)
		it.c_itv = vc.end();
	*/

template <class CMP>
string conjunto<CMP>::zeroFill(const string & s, unsigned int n) const {
    string filled = s;
    int diff = n - s.size();
    for (int i = 0; i < diff; i++) {
        filled = "0" + filled;
    }
    return filled;
}

template <class CMP>
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

template <class CMP>
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
/*conjunto::iterator conjunto::find(const long int & id) {
    conjunto::iterator it;
    vector<conjunto::entrada>::iterator itvec = vc.begin();
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
    */
template <class CMP>
bool conjunto<CMP>::insert(const conjunto<CMP>::entrada & e) {


	bool insertado = false;
    conjunto<CMP>::iterator it;
    it.itv = this->vc.begin();

    conjunto<CMP>::iterator it_final;
    it_final.itv = this->vc.end();


	while (it != it_final && !insertado) {
		if (!comp((*it), e)) {
			this->vc.insert((it.itv), e);
			insertado = true;
		} else
			it++;
        }


    if (!insertado) {
        insertado = true;
        this->vc.push_back(e);
    }
    return insertado; 
}

template <class CMP>

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

template <class CMP>
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
template <class CMP>
conjunto<CMP> & conjunto<CMP>::operator=(const conjunto<CMP> & org) {
    this->vc.clear();

    for (unsigned int i = 0; i < org.size(); i++) {
        this->vc.push_back(org.getAt(i));
    }


    return *this;
}

template <class CMP>
unsigned int conjunto<CMP>::size() const {
    return vc.size();
}

template <class CMP>
bool conjunto<CMP>::empty() const {
    return this->vc.size() == 0;
}
/** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
 */

// Devuelve si los ID son todos menores o iguales y que son mayores que 0.

template <class CMP>
bool conjunto<CMP>::cheq_rep() const {
    bool inv = false;
    int size = vc.size();
    for (int i = 0; i < size - 1; i++) {
        if ((vc.at(i).getID() < vc.at(i + 1).getID()) && vc.at(i).getID() > 0)
            inv = true;
    }

    return inv;

}

template <class CMP>
conjunto<CMP>::conjunto(iterator ini, iterator fin) {
	while (ini < fin) {
		this.insert(ini);
		ini++;
	}
}
	// Constructor de conjunto que contiene los elementos contenidos en el rango [ini,fin) 
template <class CMP>

typename conjunto<CMP>::iterator conjunto<CMP>::lower_bound (const conjunto<CMP>::entrada & x) {
	conjunto<CMP>::iterator it;
	
	it = find(x);
	
	if (it.itv != vc.end()){
		if (it.itv != vc.begin())
			it = it - 1;
	}	
	
		
	return it;
}
		
	
template <class CMP>

typename conjunto<CMP>::const_iterator conjunto<CMP>::lower_bound (const conjunto<CMP>::entrada & x) const {
	conjunto<CMP>::const_iterator itc;
	
	itc = find(x);
	
	/* if (itc.c_itv != vc.end()){
		if (itc.c_itv != vc.begin())
			itc = itc - 1;
	}
		
	return itc; 
	* */
}

template <class CMP>

typename conjunto<CMP>::iterator conjunto<CMP>::upper_bound (const conjunto<CMP>::entrada & x) {
	conjunto<CMP>::iterator it;
	
	it = find(x);
	
	if (it.itv != vc.end()){
		if (it.itv != vc.end() - 1)
			it = it + 1;
	}
		
	return it;
}


template <class CMP>

typename conjunto<CMP>::const_iterator conjunto<CMP>::upper_bound (const conjunto<CMP>::entrada & x) const {
	conjunto<CMP>::const_iterator cit;
	cout << "UPPERASDF" << endl;
	cit = find(x);
	
	cout << "UPPER" << endl;
	if (cit.c_itv != vc.end()){
		if (cit.c_itv < vc.end() - 1){
			cout << "ADIOS" << endl;
			cit = cit + 1;
		}
	}
		
	return cit;
}
// ----------------------------- BEGIN Y END----------------------------------

template <class CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::begin() {
    conjunto<CMP>::iterator sal;
    sal.itv = vc.begin();
    sal.puntero = this;
    return sal;
}

template <class CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::end() {
    conjunto<CMP>::iterator sal;
    sal.itv = vc.end();
    return sal;
}
/** @brief constructor defecto iterator
 */

// CLASE ITERATOR -----------------------------------------------------

template <class CMP>
conjunto<CMP>::iterator::iterator() {
}

/** @brief constructor copia iterator
 */
 
 template <class CMP>
conjunto<CMP>::iterator::iterator(const iterator & i) {
    this->itv = i.itv;
}

template <class CMP>
 const typename conjunto<CMP>::entrada & conjunto<CMP>::iterator::operator*() const {
    return *(this->itv);
}

template <class CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator-(int i) {
    for (int j = 0; j < i; j++)
        (this->itv)++;

    return *this;
}

template <class CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator+(int i) {
    for (int j = 0; j < i; j++)
        (this->itv)++;

    return *this;
}

template <class CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator=(const conjunto<CMP>::iterator & i) {
    this->itv = i.itv;
    return *this;
}

template <class CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator++() {
    if (this->itv != (*this).puntero->vc.end())
        (this->itv)++;

    return (*this);
}

template <class CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::iterator::operator++(int) {

    if (this->itv != (*this).puntero->vc.end())
        this->itv++;

    return *this;
}

template <class CMP>
typename conjunto<CMP>::iterator & conjunto<CMP>::iterator::operator--() {
    if (this->itv != (*this).puntero->vc.begin())
        (this->itv)--;

    return (*this);
}

template <class CMP>
typename conjunto<CMP>::iterator conjunto<CMP>::iterator::operator--(int) {
    if (this->itv != (*this).puntero->vc.begin())
        this->itv--;

    return *this;
}

template <class CMP>
bool conjunto<CMP>::iterator::operator==(const conjunto<CMP>::iterator & it) {
    return (this->itv == it.itv);
}

template <class CMP>
bool conjunto<CMP>::iterator::operator!=(const conjunto<CMP>::iterator & it) {
    return (this->itv != it.itv);
}
//CLASE conjunto<CMP> CONST BEGIN Y END --------------------------------------

template <class CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::cbegin() {
    conjunto<CMP>::const_iterator sal;
    sal.c_itv = vc.begin();
    sal.punt_const = this;
    return sal;
}

template <class CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::cend() {
    conjunto<CMP>::const_iterator sal;
    sal.c_itv = vc.end();
    return sal;
}

//CLASE CONST_ITERATOR ----------------------------------------------------

template <class CMP>
conjunto<CMP>::const_iterator::const_iterator() {
}

template <class CMP>
conjunto<CMP>::const_iterator::const_iterator(const iterator & i) {
    this->c_itv = i.itv;
}

template <class CMP>
conjunto<CMP>::const_iterator::const_iterator(const const_iterator & i) {
    this->c_itv = i.c_itv;
}

template <class CMP>
const typename conjunto<CMP>::entrada & conjunto<CMP>::const_iterator::operator*() const {
    return *(this->c_itv);
}

template <class CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator+(int i) {
    for (int j = 0; j < i; j++)
        (this->c_itv)++;

    return *this;
}

template <class CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator=(const conjunto<CMP>::const_iterator & i) {
    this->c_itv = i.c_itv;
    return *this;
}

template <class CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator++() {
    if (this->c_itv != (*this).punt_const->vc.end())
        (this->c_itv)++;

    return (*this);
}

template <class CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator::operator++(int) {
    if (this->c_itv != (*this).punt_const->vc.end())
        this->c_itv++;

    return *this;
}

template <class CMP>
typename conjunto<CMP>::const_iterator & conjunto<CMP>::const_iterator::operator--() {
    if (this->c_itv != (*this).punt_const->vc.begin())
        (this->c_itv)--;

    return (*this);
}

template <class CMP>
typename conjunto<CMP>::const_iterator conjunto<CMP>::const_iterator::operator--(int) {
    if (this->c_itv != (*this).punt_const->vc.begin())
        this->c_itv--;

    return *this;
}

template <class CMP>
bool conjunto<CMP>::const_iterator::operator==(const conjunto<CMP>::const_iterator & it) {
    return (this->c_itv == it.c_itv);
}

template <class CMP>
bool conjunto<CMP>::const_iterator::operator!=(const conjunto<CMP>::const_iterator & it) {
    return (this->c_itv != it.c_itv);
}

template <class CMP>
ostream& operator<<(ostream& os, const conjunto<CMP>& c) {

    for (unsigned int i = 0; i < c.size(); i++)
        os << "conjunto<CMP> " << i << endl << c.getAt(i) << endl;



    return os;
}
