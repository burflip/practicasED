#include <string>
#include <vector>
#include <iostream> 

#include "crimen.h"

conjunto::conjunto ()
{
}

conjunto::conjunto (const conjunto & d)
{
	for (int i=0; i<d.size(); i++)
		vc.at(i) = d.at(i);
}

pair <conjunto::entrada,bool> conjunto :: find( const long int & id) const
{
	pair<conjunto::entrada, bool> par;
	crimen c;
	par.second = false;
	
	if (this->cheq_rep())
	{
		for(int i = 0; i < vc.size() && !par.second; i++)
		{
			if (vc.at(i).get(ID) == id)
			{
				par.second = true;
				c = vc.at(i);
			}	
		}

	par.first = c;
	
	return par;
	
}

conjunto  conjunto :: findIUCR( const string & iucr) const
{
	vector <crimen> mismo_IUCR;
	
	for (int i=0; i<vc.size(); i++)
	{
		int j = 0;
		if (this.at(i).getIUCR() == iucr)
		{
			mismo_IUCR.at(j) = vc.at(i);
			j++;
		}

	return mismo_IUCR;
 
}	

conjunto conjunto :: findDESCR( const string & descr) const
{
	vector <crimen> misma_descripcion;
	
	for (int i=0; i<vc.size(); i++)
	{
		int j = 0;
		if (vc.at(i).getDescription() == descr)
		{
			misma_descripcion.at(j) = vc.at(i);
			j++;
		}
	}

	return misma_descripcion;
 
}	


bool conjunto :: insert( const conjunto::entrada & e)
{
	
	bool insertado = false;
	vector<conjunto::entrada>::iterator it = vc.begin();

	

	if (vc.empty())
	{
		vc.push_back(e);
		insertado = true;
	}	
	else {
		if (!find(e.getID()).second) 
		{

			while (it!=vc.end() && !insertado)
			{
				if ((*it).getID() > e.getID()) {
					vc.insert(it, e);
					insertado = true;
				}
				else
					it++;
			}

		}

		if(!insertado)
		{
			vc.push_back(e);
			insertado = true;
		}

	}

	return insertado;
}


bool coonjunto :: erase(const long int & id)
{
	bool borrado = false;
	
	
	for (int i=0; i<vc.size() && !borrado; i++)
	{
		if (vc.getID()==id) {
			vc.erase(vc.begin()+i);
			borrado = true;
		}
	}
	
	return borrado;
		
}

/** @brief Borra una crimen con identificador dado por e.getID() en el vc.


Busca la entrada con id en el conjunto (o e.getID() en el segundo caso) y si la encuentra la borra

@param[in] entrada con e.getID() que geremos borrar, el resto de los valores no son tenidos en cuenta
@return true si la entrada se ha podido borrar con éxito. False en caso contrario
@post Si esta en el conjunto su tamaño se decrementa en 1.
*/

bool erase(const  conjunto::entrada & e) 
{
	bool borrado;

	for (int i=0; i<vc.size() && !borrado; i++)
	{
		if (vc.getID()==e.getID()) {
			vc.erase(vc.begin()+i);
			borrado = true;
		}
	}
	
	return borrado;

	
}

conjunto conjunto :: & operator=( const conjunto & org) 
{
	for (int i=0; i<vc.size(); i++)
		vc.at(i) = org.at(i);

	return conjunto;
}

size_type conjunto :: size() const 
{
	return vc.size();
}

bool conjunto :: empty() const 
{
	return vc.empty();
}
/** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
*/

// Devuelve si los ID son todos menores o iguales y que son mayores que 0.

bool conjunto :: cheq_rep( ) const 
{
	bool inv = false ;	
	
	for (int i=0; i<vc.size(); i++)
	{
		if ((vc.at(i).getID() < vc.at(i+1).getID()) && vc.at(i).getID() > 0)
			inv = true;
	}
		
	return inv;
			
}

ostream & operator << ( ostream & sal, const conjunto & D)
{
	for (int i=0; i<vc.size(); i++)
		sal << vc.at(i) << endl;

	return sal;
}
