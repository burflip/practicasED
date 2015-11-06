#include "conjunto.h"
#include "crimen.h"
#include "fecha.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
	
	/** @brief lee un fichero de delitos, linea a linea
	@param[in] s nombre del fichero
        @param[in,out] C conjunto sobre el que se lee
	@return true si la lectura ha sido correcta, false en caso contrario
	*/

bool load(conjunto &  C, const string & s) {
 ifstream fe;
 string cadena;
 crimen crim;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())    
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   cout << "leo:: "<< cadena << endl;

 	size_t pos = 0;
	size_t pos_bus = cadena.find_first_of(",");
	string cad = cadena.substr (pos, (pos_bus - pos));
	crim.setID(stol(cad));
	
	pos = pos_bus+1;
	pos_bus = cadena.find_first_of( ",", pos);
	crim.setCaseNumber(cadena.substr (pos, (pos_bus - pos)));

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of( ",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	fecha fecha1 (cad);
	crim.setDate(fecha1);

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	crim.setBlock (cadena.substr (pos, (pos_bus - pos)));

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	crim.setIUCR (cadena.substr(pos, (pos_bus - pos)));

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	crim.setPrimaryType (cadena.substr(pos, (pos_bus - pos)));

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	if (cadena.compare(pos_bus+1, 1, "\"") == 0) {
		pos_bus = cadena.find_first_of("\"",pos+1);
		crim.setDescription (cadena.substr(pos+1, (pos_bus-(pos+1))));
	}
	else {
		crim.setDescription (cadena.substr(pos, (pos_bus - pos)));
	}
	
	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	crim.setLocationDescription (cadena.substr(pos, (pos_bus - pos)));

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	crim.setLocationDescription (cadena.substr(pos, (pos_bus - pos)));

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	bool arrest = (cad == "true");
	crim.setArrest(arrest); 

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	bool domestic = (cad == "true");
	crim.setDomestic(domestic);

	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setBeat(stoi(cad));
	
	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setDistrict(stoi(cad));

	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setWard(stoi(cad));	

	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setCommunityArea(stoi(cad));

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	crim.setFBICode (cadena.substr(pos, (pos_bus - pos)));

	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setXCoord(stol(cad));

	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setYCoord(stol(cad));

	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setYear(stoi(cad));

	pos = pos_bus+1;
	pos_bus = cadena.find_first_of( ",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	fecha fecha2(cad);
	crim.setUpdatedOn(fecha2);

	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setLatitude(stof(cad));

	pos=pos_bus+1;
	pos_bus = cadena.find_first_of(",", pos);
	cad = cadena.substr (pos, (pos_bus - pos));
	crim.setLongitude(stof(cad));
	

	C.insert (crim);
         }
     }
    fe.close();
    return true;
    } // else
  fe.close();
  return false;
 }

int main()
{
    conjunto ChicagoDB;
    crimen d;
    fecha f;

    load(ChicagoDB, "crimenes100.csv");

    /* cout << ChicagoDB << endl; */

   return 0;
}
