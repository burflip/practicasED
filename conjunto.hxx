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

conjunto::conjunto(){
	
}

conjunto::iterator conjunto::begin(){
conjunto::iterator sal;
	sal.itv = vc.begin();
	sal.puntero = this;
        return sal;
}


conjunto::iterator conjunto::end(){
conjunto::iterator sal;
	sal.itv = vc.end();
        return sal;
}
/** @brief constructor defecto iterator
*/

// CLASE ITERATOR -----------------------------------------------------
conjunto::iterator::iterator(){
}

/** @brief constructor copia iterator
*/
conjunto::iterator::iterator(const iterator & i){
  this->itv = i.itv;
}

const conjunto::entrada & conjunto::iterator::operator*() const
{
	return *(this->itv);
}

conjunto::iterator & conjunto::iterator::operator = (const conjunto::iterator & i)
{
	conjunto::iterator iterador;
	iterador.itv = i.itv;
	return iterador;
}

conjunto::iterator conjunto::iterator::operator++(int)
{
	conjunto::iterator antiguo;
	antiguo.itv = this->itv;
	if (this->itv!=(*this).puntero->vc.end())
		(this->itv)++;
		
	return antiguo;
}

conjunto::iterator & conjunto::iterator::operator ++()
{
	conjunto::iterator aux;
	aux.itv++;
	return aux;
}

conjunto::iterator conjunto::iterator::operator--(int)
{
	conjunto::iterator antiguo;
	antiguo.itv = this->itv;
	if (this->itv!=(*this).puntero->vc.begin())
		(this->itv)--;
		
	return antiguo;
}

conjunto::iterator & conjunto::iterator::operator --()
{
	conjunto::iterator aux;
	aux.itv--;
	return aux;
}

bool conjunto::iterator::operator == (const conjunto::iterator & it)
{
	return (this->itv==it.itv);
}
bool conjunto::iterator::operator!=(const conjunto::iterator & it)
{
	return (this->itv!=it.itv);
}
//CLASE CONJUNTO CONST BEGIN Y END --------------------------------------
conjunto::const_iterator conjunto::cbegin(){
conjunto::const_iterator sal;
	sal.c_itv = vc.begin();
	sal.punt_const = this;
        return sal;
}


conjunto::const_iterator conjunto::cend(){
conjunto::const_iterator sal;
	sal.c_itv = vc.end();
        return sal;
}

//CLASE CONST_ITERATOR ----------------------------------------------------

conjunto::const_iterator::const_iterator()
{
}

conjunto::const_iterator::const_iterator(const iterator & i)
{
	this->c_itv = i.itv;
}

conjunto::const_iterator::const_iterator(const const_iterator & i)
{
	this->c_itv = i.c_itv;
}
	
const conjunto::entrada & conjunto::const_iterator::operator*() const
{
	return *(this->c_itv);
}

conjunto::const_iterator & conjunto::const_iterator::operator = (const conjunto::const_iterator & i)
{
	conjunto::const_iterator iterador;
	iterador.c_itv = i.c_itv;
	return iterador;
}

conjunto::const_iterator conjunto::const_iterator::operator++(int)
{
	conjunto::const_iterator antiguo;
	antiguo.c_itv = this->c_itv;
	if (this->c_itv!=(*this).punt_const->vc.end())
		(this->c_itv)++;
		
	return antiguo;
}

conjunto::const_iterator & conjunto::const_iterator::operator ++()
{
	conjunto::const_iterator aux;
	aux.c_itv++;
	return aux;
}

conjunto::const_iterator conjunto::const_iterator::operator--(int)
{
	conjunto::const_iterator antiguo;
	antiguo.c_itv = this->c_itv;
	if (this->c_itv!=(*this).punt_const->vc.begin())
		(this->c_itv)--;
		
	return antiguo;
}

conjunto::const_iterator & conjunto::const_iterator::operator --()
{
	conjunto::const_iterator aux;
	aux.c_itv--;
	return aux;
}

bool conjunto::const_iterator::operator == (const conjunto::const_iterator & it)
{
	return (this->c_itv==it.c_itv);
}
bool conjunto::const_iterator::operator!=(const conjunto::const_iterator & it)
{
	return (this->c_itv!=it.c_itv);
}
// ARREST BEGIN Y END ------------------------------------------------------------

conjunto::arrest_iterator conjunto::abegin()
{
	conjunto::arrest_iterator sal;
	
	sal.a_itv = vc.begin();
	
	bool encontrado = false;
	while (sal.a_itv != vc.end() && !encontrado){
		if ((*sal.a_itv).getArrest() == true)
			encontrado = true;
		else
			sal.a_itv++;
	}
	
        return sal;
}

conjunto::arrest_iterator conjunto::aend()
{
	conjunto::arrest_iterator sal;
	
	sal.a_itv = vc.end();
	
	bool encontrado = false;
	while (sal.a_itv != vc.begin() && !encontrado){
		if ((*sal.a_itv).getArrest() == true)
			encontrado = true;
		else
			sal.a_itv--;
	}
	
        return sal;
}
// ARREST ITERATOR ----------------------------------------------------------------

conjunto::arrest_iterator::arrest_iterator()
{
}

conjunto::arrest_iterator::arrest_iterator(const arrest_iterator & i)
{
	this->a_itv = i.a_itv;
}

const conjunto::entrada & conjunto::arrest_iterator::operator*() const
{
	return *(this->a_itv);
}

conjunto::arrest_iterator & conjunto::arrest_iterator::operator = (const conjunto::arrest_iterator & i)
{
	conjunto::arrest_iterator iterador;
	iterador.a_itv = i.a_itv;
	return iterador;
}

conjunto::arrest_iterator conjunto::arrest_iterator::operator++(int)
{
	conjunto::arrest_iterator antiguo;
	antiguo.a_itv = this->a_itv;
	
	bool encontrado = false;
	
	
	do {
		(this->a_itv)++;
	}while (this->a_itv!=(*this).punt_arr->vc.end() || ((*this->a_itv).getArrest() == false));

	return antiguo;
}

conjunto::arrest_iterator & conjunto::arrest_iterator::operator ++()
{
	conjunto::arrest_iterator aux;
	do {
		(aux.a_itv)++;
	} while (aux.a_itv!=(*this).punt_arr->vc.end() || ((*aux.a_itv).getArrest() == false));
	
	return aux;
}

conjunto::arrest_iterator conjunto::arrest_iterator::operator--(int)
{
	conjunto::arrest_iterator antiguo;
	antiguo.a_itv = this->a_itv;
	
	bool encontrado = false;
	
	
	do {
		(this->a_itv)--;
	}while (this->a_itv!=(*this).punt_arr->vc.begin() || ((*this->a_itv).getArrest() == false));

	return antiguo;
}

conjunto::arrest_iterator & conjunto::arrest_iterator::operator --()
{
	conjunto::arrest_iterator aux;
	do {
		(aux.a_itv)--;
	}while (aux.a_itv!=(*this).punt_arr->vc.begin() || ((*aux.a_itv).getArrest() == false));
	
	return aux;
}

bool conjunto::arrest_iterator::operator == (const conjunto::arrest_iterator & it)
{
	return (this->a_itv==it.a_itv);
}
bool conjunto::arrest_iterator::operator!=(const conjunto::arrest_iterator & it)
{
	return (this->a_itv!=it.a_itv);
}

// CONST_ARREST BEGIN Y END--------------------------------------------------------

conjunto::const_arrest_iterator conjunto::abegin()
{
	conjunto::const_arrest_iterator sal;
	
	sal.ca_itv = vc.begin();
	
	bool encontrado = false;
	while (sal.ca_itv != vc.end() && !encontrado){
		if ((*sal.ca_itv).getArrest() == true)
			encontrado = true;
		else
			sal.ca_itv++;
	}
	
        return sal;
}

conjunto::const_arrest_iterator conjunto::aend()
{
	conjunto::const_arrest_iterator sal;
	
	sal.ca_itv = vc.end();
	
	bool encontrado = false;
	while (sal.a_itv != vc.begin() && !encontrado){
		if ((*sal.ca_itv).getArrest() == true)
			encontrado = true;
		else
			sal.ca_itv--;
	}
	
        return sal;
}
// CONST ARREST ITERATOR ----------------------------------------------------------------

conjunto::const_arrest_iterator::const_arrest_iterator()
{
}

conjunto::const_arrest_iterator::const_arrest_iterator(const arrest_iterator & i)
{
	this->ca_itv = i.a_itv;
}

conjunto::const_arrest_iterator::const_arrest_iterator(const const_arrest_iterator & i)
{
	this->ca_itv = i.ca_itv;
}

const conjunto::entrada & conjunto::arrest_iterator::operator*() const
{
	return *(this->a_itv);
}

conjunto::arrest_iterator & conjunto::arrest_iterator::operator = (const conjunto::arrest_iterator & i)
{
	conjunto::arrest_iterator iterador;
	iterador.a_itv = i.a_itv;
	return iterador;
}

conjunto::arrest_iterator conjunto::arrest_iterator::operator++(int)
{
	conjunto::arrest_iterator antiguo;
	antiguo.ca_itv = this->ca_itv;
	
	bool encontrado = false;
	
	
	do {
		(this->ca_itv)++;
	}while (this->ca_itv!=(*this).punt_carr->vc.end() || ((*this->ca_itv).getArrest() == false));

	return antiguo;
}

conjunto::const_arrest_iterator & conjunto::const_arrest_iterator::operator ++()
{
	conjunto::const_arrest_iterator aux;
	do {
		(auxc.a_itv)++;
	} while (aux.ca_itv!=(*this).punt_carr->vc.end() || ((*aux.ca_itv).getArrest() == false));
	
	return aux;
}

conjunto::const_arrest_iterator conjunto::const_arrest_iterator::operator--(int)
{
	conjunto::const_arrest_iterator antiguo;
	antiguo.ca_itv = this->ca_itv;
	
	bool encontrado = false;
	
	
	do {
		(this->ca_itv)--;
	}while (this->ca_itv!=(*this).punt_carr->vc.begin() || ((*this->ca_itv).getArrest() == false));

	return antiguo;
}

conjunto::const_arrest_iterator & conjunto::const_arrest_iterator::operator --()
{
	conjunto::const_arrest_iterator aux;
	do {
		(aux.a_itv)--;
	}while (aux.ca_itv!=(*this).punt_carr->vc.begin() || ((*aux.ca_itv).getArrest() == false));
	
	return aux;
}

bool conjunto::const_arrest_iterator::operator == (const conjunto::const_arrest_iterator & it)
{
	return (this->ca_itv==it.ca_itv);
}
bool conjunto::const_arrest_iterator::operator!=(const conjunto::const_arrest_iterator & it)
{
	return (this->a_itv!=it.a_itv);
}
	
