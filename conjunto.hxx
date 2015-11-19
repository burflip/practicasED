/*! Implementacion  de la clase conjunto
 */

/** @todo implementar la funcion
 */
#include <string>
#include <vector>
#include <iostream> 

#include "crimen.h"
#include "conjunto.h"

using namespace std;

conjunto::conjunto() {

}

conjunto::conjunto(const conjunto & d) {
    this->vc.clear();
    for (unsigned int i = 0; i < d.size(); i++) {
        this->vc.push_back(d.getAt(i));
    }
}

crimen conjunto::getAt(int i) const {
    crimen c;
    if (this->vc.size() > (unsigned) i) {
        c = this->vc.at(i);
    }
    return c;
}

conjunto::iterator conjunto::find(const long int & id){
    conjunto::iterator it;
    vector<conjunto::entrada>::iterator itvec = vc.begin();
    it.itv = vc.end();
    
    if (this->cheq_rep()) {
		int abajo = 0;
		int arriba = this->vc.size() - 1;
		int centro;
    
		while (abajo <= arriba) {
			centro = ((arriba-abajo) / 2) + abajo;
			if (this->vc.at(centro).getID() == id) {
				itvec = vc.begin() + centro;
				it.itv = itvec;
			}
			else {
				if (id < this->vc.at(centro).getID())
					arriba = centro-1;
				else
					abajo = centro +1;
			}
		}
	}

    return it;
}
		
conjunto::const_iterator conjunto::find(const long int & id) const{
    conjunto::const_iterator it;
    vector<conjunto::entrada>::const_iterator itvec = vc.begin();
    it.c_itv = vc.end();
    
    if (this->cheq_rep()) {
		int abajo = 0;
		int arriba = this->vc.size() - 1;
		int centro;
    
		while (abajo <= arriba) {
			centro = ((arriba-abajo) / 2) + abajo;
			if (this->vc.at(centro).getID() == id) {
				itvec = vc.begin() + centro;
				it.c_itv = itvec;
			}
			else {
				if (id < this->vc.at(centro).getID())
					arriba = centro-1;
				else
					abajo = centro +1;
			}
		}
	}

    return it;
}


string conjunto::zeroFill(const string & s, unsigned int n) const {
    string filled = s;
    int diff = n - s.size();
    for (int i = 0; i < diff; i++) {
        filled = "0" + filled;
    }
    return filled;
}

conjunto conjunto::findIUCR(const string & iucr) const {
    conjunto c;
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

conjunto conjunto::findDESCR(const string & descr) const {
    conjunto c;

    for (unsigned int i = 0; i < this->vc.size(); i++) {
        int j = 0;
        if (this->getAt(i).getDescription() == descr) {
            c.insert(vc.at(i));
            j++;
        }
    }


    return c;

}

bool conjunto::insert(const conjunto::entrada & e) {

    bool insertado = false;
    conjunto::iterator it;
    it.itv = this->vc.begin();
    
    conjunto::iterator it_final;
    it_final.itv = this->vc.end();

	conjunto::iterator it_find;
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
    
	if (!insertado){
		insertado = true;
		this->vc.push_back (e);
	} 
    return insertado;
    
}

bool conjunto::erase(const long int & id) {
    bool borrado = false;


    for (unsigned int i = 0; i < vc.size() && !borrado; i++) {
        if (vc.at(i).getID() == id) {
            vc.erase(vc.begin() + i);
            borrado = true;
        }
    }

    return borrado;

}

bool conjunto::erase(const conjunto::entrada & e) {
    bool borrado;

    for (unsigned int i = 0; i < vc.size() && !borrado; i++) {
        if (vc.at(i).getID() == e.getID()) {
            vc.erase(vc.begin() + i);
            borrado = true;
        }
    }

    return borrado;


}

conjunto & conjunto::operator=(const conjunto & org) {
    this->vc.clear();

    for (unsigned int i = 0; i < org.size(); i++) {
        this->vc.push_back(org.getAt(i));
    }


    return *this;
}

unsigned int conjunto::size() const {
    return vc.size();
}

bool conjunto::empty() const {
    return this->vc.size() == 0;
}
/** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
 */

// Devuelve si los ID son todos menores o iguales y que son mayores que 0.

bool conjunto::cheq_rep() const {
    bool inv = false;
    int size = vc.size();
    for (int i = 0; i < size - 1; i++) {
        if ((vc.at(i).getID() < vc.at(i + 1).getID()) && vc.at(i).getID() > 0)
            inv = true;
    }

    return inv;

}


conjunto::iterator conjunto::begin() {
    conjunto::iterator sal;
    sal.itv = vc.begin();
    sal.puntero = this;
    return sal;
}

conjunto::iterator conjunto::end() {
    conjunto::iterator sal;
    sal.itv = vc.end();
    return sal;
}
/** @brief constructor defecto iterator
 */

// CLASE ITERATOR -----------------------------------------------------

conjunto::iterator::iterator() {
}

/** @brief constructor copia iterator
 */
conjunto::iterator::iterator(const iterator & i) {
    this->itv = i.itv;
}

const conjunto::entrada & conjunto::iterator::operator*() const {
    return *(this->itv);
}
conjunto::iterator & conjunto::iterator::operator-(int i) {
    for (int j = 0; j < i; j++)
        (this->itv)++;

    return *this;
}
conjunto::iterator & conjunto::iterator::operator+(int i) {
    for (int j = 0; j < i; j++)
        (this->itv)++;

    return *this;
}

conjunto::iterator & conjunto::iterator::operator=(const conjunto::iterator & i) {
    this->itv = i.itv;
    return *this;
}

conjunto::iterator & conjunto::iterator::operator++() {
    conjunto::iterator antiguo;
    antiguo.itv = this->itv;
    if (this->itv != (*this).puntero->vc.end())
        (this->itv)++;

    return antiguo;
}

conjunto::iterator conjunto::iterator::operator++(int) {

    if (this->itv != (*this).puntero->vc.end())
        this->itv++;

    return *this;
}

conjunto::iterator & conjunto::iterator::operator--() {
    conjunto::iterator antiguo;
    antiguo.itv = this->itv;
    if (this->itv != (*this).puntero->vc.begin())
        (this->itv)--;

    return antiguo;
}

conjunto::iterator  conjunto::iterator::operator--(int) {
    if (this->itv != (*this).puntero->vc.begin())
        this->itv--;

    return *this;
}

bool conjunto::iterator::operator==(const conjunto::iterator & it) {
    return (this->itv == it.itv);
}

bool conjunto::iterator::operator!=(const conjunto::iterator & it) {
    return (this->itv != it.itv);
}
//CLASE CONJUNTO CONST BEGIN Y END --------------------------------------

conjunto::const_iterator conjunto::cbegin() {
    conjunto::const_iterator sal;
    sal.c_itv = vc.begin();
    sal.punt_const = this;
    return sal;
}

conjunto::const_iterator conjunto::cend() {
    conjunto::const_iterator sal;
    sal.c_itv = vc.end();
    return sal;
}

//CLASE CONST_ITERATOR ----------------------------------------------------

conjunto::const_iterator::const_iterator() {
}

conjunto::const_iterator::const_iterator(const iterator & i) {
    this->c_itv = i.itv;
}

conjunto::const_iterator::const_iterator(const const_iterator & i) {
    this->c_itv = i.c_itv;
}

const conjunto::entrada & conjunto::const_iterator::operator*() const {
    return *(this->c_itv);
}

conjunto::const_iterator & conjunto::const_iterator::operator+(int i) {
    for (int j = 0; j < i; j++)
        (this->c_itv)++;

    return *this;
}

conjunto::const_iterator & conjunto::const_iterator::operator=(const conjunto::const_iterator & i) {
    this->c_itv = i.c_itv;
    return *this;
}

conjunto::const_iterator & conjunto::const_iterator::operator++() {
    conjunto::const_iterator antiguo;
    antiguo.c_itv = this->c_itv;
    if (this->c_itv != (*this).punt_const->vc.end())
        (this->c_itv)++;

    return antiguo;
}

conjunto::const_iterator conjunto::const_iterator::operator++(int) {
    if (this->c_itv != (*this).punt_const->vc.end())
        this->c_itv++;

    return *this;
}

conjunto::const_iterator & conjunto::const_iterator::operator--() {
    conjunto::const_iterator antiguo;
    antiguo.c_itv = this->c_itv;
    if (this->c_itv != (*this).punt_const->vc.begin())
        (this->c_itv)--;

    return antiguo;
}

conjunto::const_iterator conjunto::const_iterator::operator--(int) {
    if (this->c_itv != (*this).punt_const->vc.begin())
        this->c_itv--;

    return *this;
}

bool conjunto::const_iterator::operator==(const conjunto::const_iterator & it) {
    return (this->c_itv == it.c_itv);
}

bool conjunto::const_iterator::operator!=(const conjunto::const_iterator & it) {
    return (this->c_itv != it.c_itv);
}
// ARREST BEGIN Y END ------------------------------------------------------------

conjunto::arrest_iterator conjunto::abegin() {
    conjunto::arrest_iterator sal;

    sal.a_itv = vc.begin();

    bool encontrado = false;
    while (sal.a_itv != vc.end() && !encontrado) {
        if ((*sal.a_itv).getArrest() == true)
            encontrado = true;
        else
            sal.a_itv++;
    }

    return sal;
}

conjunto::arrest_iterator conjunto::aend() {
    conjunto::arrest_iterator sal;

    sal.a_itv = vc.end();

    return sal;
}
// ARREST ITERATOR ----------------------------------------------------------------

conjunto::arrest_iterator::arrest_iterator() {
}

conjunto::arrest_iterator::arrest_iterator(const arrest_iterator & i) {
    this->a_itv = i.a_itv;
}

const conjunto::entrada & conjunto::arrest_iterator::operator*() const {
    return *(this->a_itv);
}

conjunto::arrest_iterator & conjunto::arrest_iterator::operator=(const conjunto::arrest_iterator & i) {
    this->a_itv = i.a_itv;
    return *this;
}

conjunto::arrest_iterator & conjunto::arrest_iterator::operator++() {
    conjunto::arrest_iterator antiguo;
    antiguo.a_itv = this->a_itv;
    		
    do {
        (this->a_itv)++;
    } while (this->a_itv != (*this).punt_arr->vc.end() || ((*this->a_itv).getArrest() == false));

    return antiguo;
}

conjunto::arrest_iterator  conjunto::arrest_iterator::operator++(int) {
	
    do {
        (this->a_itv)++;
        
    } while (this->a_itv < (*this).punt_arr->vc.end() && ((*this->a_itv).getArrest() == false)); 

    return *this;
}

conjunto::arrest_iterator & conjunto::arrest_iterator::operator--() {
    conjunto::arrest_iterator antiguo;
    antiguo.a_itv = this->a_itv;

    do {
        (this->a_itv)--;
    } while (this->a_itv != (*this).punt_arr->vc.begin() || ((*this->a_itv).getArrest() == false));

    return antiguo;
}

conjunto::arrest_iterator conjunto::arrest_iterator::operator--(int) {
    do {
        (this->a_itv)--;
    } while (this->a_itv != (*this).punt_arr->vc.begin() || ((*this->a_itv).getArrest() == false));

    return *this;
}

bool conjunto::arrest_iterator::operator==(const conjunto::arrest_iterator & it) {
    return (this->a_itv == it.a_itv);
}

bool conjunto::arrest_iterator::operator!=(const conjunto::arrest_iterator & it) {
    return (this->a_itv != it.a_itv);
}

// CONST_ARREST BEGIN Y END--------------------------------------------------------

conjunto::const_arrest_iterator conjunto::cabegin() {
    conjunto::const_arrest_iterator sal;

    sal.ca_itv = vc.begin();

    bool encontrado = false;
    while (sal.ca_itv != vc.end() && !encontrado) {
        if ((*sal.ca_itv).getArrest() == true)
            encontrado = true;
        else
            sal.ca_itv++;
    }

    return sal;
}

conjunto::const_arrest_iterator conjunto::caend() {
    conjunto::const_arrest_iterator sal;

    sal.ca_itv = vc.end();

    return sal;
}
// CONST ARREST ITERATOR ----------------------------------------------------------------

conjunto::const_arrest_iterator::const_arrest_iterator() {
}

conjunto::const_arrest_iterator::const_arrest_iterator(const arrest_iterator & i) {
    this->ca_itv = i.a_itv;
}

conjunto::const_arrest_iterator::const_arrest_iterator(const const_arrest_iterator & i) {
    this->ca_itv = i.ca_itv;
}

const conjunto::entrada & conjunto::const_arrest_iterator::operator*() const {
    return *(this->ca_itv);
}

conjunto::const_arrest_iterator & conjunto::const_arrest_iterator::operator=(const conjunto::const_arrest_iterator & i) {

    this->ca_itv = i.ca_itv;
    return *this;
}

conjunto::const_arrest_iterator & conjunto::const_arrest_iterator::operator++() {
    conjunto::const_arrest_iterator antiguo;
    antiguo.ca_itv = this->ca_itv;

    do {
        (this->ca_itv)++;
    } while (this->ca_itv != (*this).punt_carr->vc.end() || ((*this->ca_itv).getArrest() == false));

    return antiguo;
}

conjunto::const_arrest_iterator conjunto::const_arrest_iterator::operator++(int) {
    do {
        (this->ca_itv)++;
    } while (this->ca_itv != (*this).punt_carr->vc.end() || ((*this->ca_itv).getArrest() == false));

    return *this;
}

conjunto::const_arrest_iterator conjunto::const_arrest_iterator::operator--(int) {
    conjunto::const_arrest_iterator antiguo;
    antiguo.ca_itv = this->ca_itv;

    do {
        (this->ca_itv)--;
    } while (this->ca_itv != (*this).punt_carr->vc.begin() || ((*this->ca_itv).getArrest() == false));

    return antiguo;
}

conjunto::const_arrest_iterator & conjunto::const_arrest_iterator::operator--() {
    do {
        (this->ca_itv)--;
    } while (this->ca_itv != (*this).punt_carr->vc.begin() || ((*this->ca_itv).getArrest() == false));

    return *this;
}

bool conjunto::const_arrest_iterator::operator==(const conjunto::const_arrest_iterator & it) {
    return (this->ca_itv == it.ca_itv);
}

bool conjunto::const_arrest_iterator::operator!=(const conjunto::const_arrest_iterator & it) {
    return (this->ca_itv != it.ca_itv);
}

// DESCRIPTION BEGIN Y END

conjunto::description_iterator conjunto::dbegin(const string & descripcion){
    conjunto::description_iterator sal;
	sal.descr = descripcion;
	sal.d_itv = vc.begin();
    sal.punt_desc = this;

    bool encontrado = false;
    while (sal.d_itv != vc.end() && !encontrado) {
        if ((*sal.d_itv).getDescription() == descripcion)
            encontrado = true;
        else
            sal.d_itv++;
    }
        cout << "SAL DESCRIPTION" << sal.descr << endl;

    return sal;
}

conjunto::description_iterator conjunto::dend() {
    conjunto::description_iterator sal;
    
    sal.d_itv = vc.end();

    return sal;
}

// DESCRIPTION ITERATOR ------------------------------------------------------------

conjunto::description_iterator::description_iterator(){
	
}

conjunto::description_iterator::description_iterator(const description_iterator & i) {
    this->d_itv = i.d_itv;
    this->punt_desc = i.punt_desc;
    this->descr = i.descr;
}


const conjunto::entrada & conjunto::description_iterator::operator*() const {
    return *(this->d_itv);
}

conjunto::description_iterator & conjunto::description_iterator::operator=(const conjunto::description_iterator & i) {
    this->d_itv = i.d_itv;
    return *this;
}

conjunto::description_iterator conjunto::description_iterator::operator++(int) {
    conjunto::description_iterator antiguo;
    antiguo.d_itv = this->d_itv;
    

    do {
        (d_itv)++;
        // cout << *d_itv << endl << endl;
        cout << "Diiiigoooo: "<<  descr << endl;
    } while (d_itv < this->punt_desc->vc.end()  &&
            ((*d_itv).getDescription() != descr));

    return antiguo;
}

conjunto::description_iterator & conjunto::description_iterator::operator++() {
    conjunto::description_iterator aux;
    do {
        (this->d_itv)++;
    } while (this->d_itv < (*this).punt_desc->vc.end() && ((*this->d_itv).getDescription() != descr));

    return *this;
}

conjunto::description_iterator conjunto::description_iterator::operator--(int) {
    conjunto::description_iterator antiguo;
    antiguo.d_itv = this->d_itv;

    do {
        (this->d_itv)--;
    } while (this->d_itv != (*this).punt_desc->vc.begin() &&
            ((*this->d_itv).getDescription() != descr));

    return antiguo;
}

conjunto::description_iterator & conjunto::description_iterator::operator--() {
    do {
        (this->d_itv)--;
    } while (this->d_itv != (*this).punt_desc->vc.begin() && ((*this->d_itv).getDescription() != descr));

    return *this;
}

bool conjunto::description_iterator::operator==(const conjunto::description_iterator & it) {
    return (this->d_itv == it.d_itv);
}

bool conjunto::description_iterator::operator!=(const conjunto::description_iterator & it) {
    return (this->d_itv != it.d_itv);
}

// CONST DESCRIPTION BEGIN Y END

conjunto::const_description_iterator conjunto::cdbegin(const string & descr) {

    conjunto::const_description_iterator sal;
    sal.cd_itv = vc.begin();
    sal.setDescr(descr);

    bool encontrado = false;
    while (sal.cd_itv != vc.end() && !encontrado) {
        if ((*sal.cd_itv).getDescription() != descr)
            encontrado = true;
        else
            sal.cd_itv++;
    }

    return sal;
}

conjunto::const_description_iterator conjunto::cdend() {
    conjunto::const_description_iterator sal;

    sal.cd_itv = vc.end();

    return sal;
}

// CONST DESCRIPTION ITERATOR ------------------------------------------------------------

conjunto::const_description_iterator::const_description_iterator() {
}

conjunto::const_description_iterator::const_description_iterator(const iterator & i) {
    this->cd_itv = i.itv;
}

conjunto::const_description_iterator::const_description_iterator(const const_description_iterator & i) {
    this->cd_itv = i.cd_itv;
}

void conjunto::const_description_iterator::setDescr(const string & descr) {
    this->descr = descr;
}


const conjunto::entrada & conjunto::const_description_iterator::operator*() const {
    return *(this->cd_itv);
}

conjunto::const_description_iterator & conjunto::const_description_iterator::operator=(const conjunto::const_description_iterator & i) {
    this->cd_itv = i.cd_itv;
    return *this;
}

conjunto::const_description_iterator conjunto::const_description_iterator::operator++(int) {
    conjunto::const_description_iterator antiguo;
    antiguo.cd_itv = this->cd_itv;

    do {
        (this->cd_itv)++;
    } while (this->cd_itv != (*this).punt_cdesc->vc.end() &&
            ((*this->cd_itv).getDescription() != descr));

    return antiguo;
}

conjunto::const_description_iterator & conjunto::const_description_iterator::operator++() {
    do {
        (this->cd_itv)++;
    } while (this->cd_itv < (*this).punt_cdesc->vc.end() && ((*this->cd_itv).getDescription() == descr));

    return *this;
}

conjunto::const_description_iterator conjunto::const_description_iterator::operator--(int) {
    conjunto::const_description_iterator antiguo;
    antiguo.cd_itv = this->cd_itv;

    do {
        (this->cd_itv)--;
    } while (this->cd_itv != (*this).punt_cdesc->vc.begin() ||
            ((*this->cd_itv).getDescription() == descr));

    return antiguo;
}

conjunto::const_description_iterator & conjunto::const_description_iterator::operator--() {
    do {
        (this->cd_itv)--;
    } while (this->cd_itv != (*this).punt_cdesc->vc.begin() || ((*this->cd_itv).getDescription() == descr));

    return *this;
}

bool conjunto::const_description_iterator::operator==(const conjunto::const_description_iterator & it) {
    return (this->cd_itv == it.cd_itv);
}

bool conjunto::const_description_iterator::operator!=(const conjunto::const_description_iterator & it) {
    return (this->cd_itv != it.cd_itv);
}

ostream& operator<<(ostream& os, const conjunto& c) {
    
    for (int i = 0; i<c.size(); i++)
		os << "Conjunto " << i << endl << c.getAt(i) << endl;
		
	
    
    return os;
}
