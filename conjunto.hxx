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
	if (this->itv!=(*this).puntero->vc.end())
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
	if (this->itv!=(*this).puntero->vc.begin())
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
	if (this->c_itv!=(*this).punt_const->vc.end())
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
	if (this->c_itv!=(*this).punt_const->vc.begin())
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

conjunto::const_arrest_iterator conjunto::cabegin()
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

conjunto::const_arrest_iterator conjunto::caend()
{
	conjunto::const_arrest_iterator sal;
	
	sal.ca_itv = vc.end();
	
	bool encontrado = false;
	while (sal.ca_itv != vc.begin() && !encontrado){
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

const conjunto::entrada & conjunto::const_arrest_iterator::operator*() const
{
	return *(this->ca_itv);
}

conjunto::const_arrest_iterator & conjunto::const_arrest_iterator::operator = (const conjunto::const_arrest_iterator & i)
{
	conjunto::const_arrest_iterator iterador;
	iterador.ca_itv = i.ca_itv;
	return iterador;
}

conjunto::const_arrest_iterator conjunto::const_arrest_iterator::operator++(int)
{
	conjunto::const_arrest_iterator antiguo;
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
		(aux.ca_itv)++;
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
		(aux.ca_itv)--;
	}while (aux.ca_itv!=(*this).punt_carr->vc.begin() || ((*aux.ca_itv).getArrest() == false));
	
	return aux;
}

bool conjunto::const_arrest_iterator::operator == (const conjunto::const_arrest_iterator & it)
{
	return (this->ca_itv==it.ca_itv);
}
bool conjunto::const_arrest_iterator::operator!=(const conjunto::const_arrest_iterator & it)
{
	return (this->ca_itv!=it.ca_itv);
}
	
// DESCRIPTION BEGIN Y END

conjunto::description_iterator conjunto::dbegin(const string & descr)
{
	
	conjunto::description_iterator sal;
	
	sal.d_itv = vc.begin();
	sal.setDescr(descr);
	
	bool encontrado = false;
	while (sal.d_itv != vc.end() && !encontrado){
		if ((*sal.d_itv).getDescription() == descr)
			encontrado = true;
		else
			sal.d_itv++;
	}
	
        return sal;
}
	
conjunto::description_iterator conjunto::dend()
{
	conjunto::description_iterator sal;
	
	sal.d_itv = vc.end();
	
	bool encontrado = false;
	while (sal.d_itv != vc.begin() && !encontrado){
		if ((*sal.d_itv).getDescription() == sal.descr)
			encontrado = true;
		else
			sal.d_itv--;
	}
	
        return sal;
}	
	
// DESCRIPTION ITERATOR ------------------------------------------------------------

conjunto::description_iterator::description_iterator()
{
}

conjunto::description_iterator::description_iterator(const description_iterator & i)
{
	this->d_itv = i.d_itv;
}

void conjunto::description_iterator::setDescr (const string & descr)
{
	this->descr = descr;
}

const conjunto::entrada & conjunto::description_iterator::operator*() const
{
	return *(this->d_itv);
}

conjunto::description_iterator & conjunto::description_iterator::operator = (const conjunto::description_iterator & i)
{
	conjunto::description_iterator iterador;
	iterador.d_itv = i.d_itv;
	return iterador;
}

conjunto::description_iterator conjunto::description_iterator::operator++(int)
{
	conjunto::description_iterator antiguo;
	antiguo.d_itv = this->d_itv;
	
	bool encontrado = false;
	
	
	do {
		(this->d_itv)++;
	}while (this->d_itv!=(*this).punt_desc->vc.end() ||
					((*this->d_itv).getDescription() == descr));

	return antiguo;
}

conjunto::description_iterator & conjunto::description_iterator::operator ++()
{
	conjunto::description_iterator aux;
	do {
		(aux.d_itv)++;
	} while (aux.d_itv!=(*this).punt_desc->vc.end() || ((*aux.d_itv).getDescription() == descr));
	
	return aux;
}

conjunto::description_iterator conjunto::description_iterator::operator--(int)
{
	conjunto::description_iterator antiguo;
	antiguo.d_itv = this->d_itv;
	
	bool encontrado = false;
	
	
	do {
		(this->d_itv)--;
	}while (this->d_itv!=(*this).punt_desc->vc.begin() ||
					((*this->d_itv).getDescription() == descr));

	return antiguo;
}

conjunto::description_iterator & conjunto::description_iterator::operator --()
{
	conjunto::description_iterator aux;
	do {
		(aux.d_itv)--;
	}while (aux.d_itv!=(*this).punt_desc->vc.begin() || ((*aux.d_itv).getDescription() == descr));
	
	return aux;
}

bool conjunto::description_iterator::operator == (const conjunto::description_iterator & it)
{
	return (this->d_itv==it.d_itv);
}
bool conjunto::description_iterator::operator!=(const conjunto::description_iterator & it)
{
	return (this->d_itv!=it.d_itv);
}
	
// CONST DESCRIPTION BEGIN Y END

conjunto::const_description_iterator conjunto::cdbegin(const string & descr)
{
	
	conjunto::const_description_iterator sal;
	
	sal.cd_itv = vc.begin();
	sal.setDescr(descr);
	
	bool encontrado = false;
	while (sal.cd_itv != vc.end() && !encontrado){
		if ((*sal.cd_itv).getDescription() == descr)
			encontrado = true;
		else
			sal.cd_itv++;
	}
	
        return sal;
}
	
conjunto::const_description_iterator conjunto::cdend()
{
	conjunto::const_description_iterator sal;
	
	sal.cd_itv = vc.end();
	
	bool encontrado = false;
	while (sal.cd_itv != vc.begin() && !encontrado){
		if ((*sal.cd_itv).getDescription() == sal.descr)
			encontrado = true;
		else
			sal.cd_itv--;
	}
	
        return sal;
}	
	
// CONST DESCRIPTION ITERATOR ------------------------------------------------------------

conjunto::const_description_iterator::const_description_iterator()
{
}

conjunto::const_description_iterator::const_description_iterator(const iterator & i)
{
	this->cd_itv = i.itv;
}


conjunto::const_description_iterator::const_description_iterator(const const_description_iterator & i)
{
	this->cd_itv = i.cd_itv;
}

void conjunto::const_description_iterator::setDescr (const string & descr)
{
	this->descr = descr;
}

const conjunto::entrada & conjunto::const_description_iterator::operator*() const
{
	return *(this->cd_itv);
}

conjunto::const_description_iterator & conjunto::const_description_iterator::operator=(const conjunto::const_description_iterator & i)
{
	conjunto::const_description_iterator iterador;
	iterador.cd_itv = i.cd_itv;
	return iterador;
}

conjunto::const_description_iterator conjunto::const_description_iterator::operator++(int)
{
	conjunto::const_description_iterator antiguo;
	antiguo.cd_itv = this->cd_itv;
	
	bool encontrado = false;
	
	
	do {
		(this->cd_itv)++;
	}while (this->cd_itv!=(*this).punt_cdesc->vc.end() ||
					((*this->cd_itv).getDescription() == descr));

	return antiguo;
}

conjunto::const_description_iterator & conjunto::const_description_iterator::operator ++()
{
	conjunto::const_description_iterator aux;
	do {
		(aux.cd_itv)++;
	} while (aux.cd_itv!=(*this).punt_cdesc->vc.end() || ((*aux.cd_itv).getDescription() == descr));
	
	return aux;
}

conjunto::const_description_iterator conjunto::const_description_iterator::operator--(int)
{
	conjunto::const_description_iterator antiguo;
	antiguo.cd_itv = this->cd_itv;
	
	bool encontrado = false;
	
	
	do {
		(this->cd_itv)--;
	}while (this->cd_itv!=(*this).punt_cdesc->vc.begin() ||
					((*this->cd_itv).getDescription() == descr));

	return antiguo;
}

conjunto::const_description_iterator & conjunto::const_description_iterator::operator --()
{
	conjunto::const_description_iterator aux;
	do {
		(aux.cd_itv)--;
	}while (aux.cd_itv!=(*this).punt_cdesc->vc.begin() || ((*aux.cd_itv).getDescription() == descr));
	
	return aux;
}

bool conjunto::const_description_iterator::operator == (const conjunto::const_description_iterator & it)
{
	return (this->cd_itv==it.cd_itv);
}
bool conjunto::const_description_iterator::operator!=(const conjunto::const_description_iterator & it)
{
	return (this->cd_itv!=it.cd_itv);
}
	

