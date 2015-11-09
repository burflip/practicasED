#ifndef CONJUNTO
#define CONJUNTO

#include <vector>
#include "conjunto.h"

/*! Implementacion  de la clase conjunto

*/

/** @todo implementar la funcion
*/

conjunto::conjunto(){
  //lo que se tenga que poner
}

conjunto::iterator conjunto::begin() const{
conjunto::iterator sal;
	sal.itv = vc.begin();
        return sal;
}


conjunto::iterator conjunto::end() const{
conjunto::iterator sal;
	sal.itv = vc.end();
        return sal;
}
/** @brief constructor defecto iterator
*/


conjunto::iterator::iterator(){

}

/** @brief constructor copia iterator
*/
conjunto::iterator::iterator(const conjunto::iterator & i){
  itv = i.itv;
}

const conjunto::entrada & conjunto::iterator::operator*() const
{
	return *itv;
}

conjunto::iterator conjunto::iterator::operator++(int)
{
	if(itv!=vc.end()){
		itv++;
	}

	return itv;
}

conjunto::iterator conjunto::iterator::operator++() 
{
	vector<entrada::iterator antiguo = itv;

	if (itv!=vc.end()){
		itv++;
	}

	return antiguo;
}

conjunto::iterator conjunto::iterator::operator--(int)
{
	if (itv!=vc.begin())
		itv--;

	return itv;
}

conjunto::iterator conjunto::iterator::operator--() 
{
	vector<entrada::iterator antiguo = itv;

	if (itv!=vc.end()){
		itv--;
	}

	return antiguo;
}

bool conjunto::iterator::operator==(const conjunto::iterator & it)
{
	return (itv==it.itv);
}

bool conjunto::iterator::operator!=(const conjunto::iterator & it)
{
	return (itv!=it.itv);
}


#endif
