#include "conjunto.h"
#include "crimen.h"
#include "fecha.h"
#include "conjunto.h"
#include "crimen.h"
#include "fecha.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



using namespace std;

/** @brief Lee una columna a partir de un flujo de cadena, proviniente de un csv.
 * Comprueba también si se trata de una cadena con comas internas o sin ellas.
 * @param[in] ss stringstream de la linea
 * @return Columna en formato string
 */
string readItem(stringstream &ss) {
    string value;

    char c = ss.get();

    if (c == '"') {
        getline(ss, value, '"');
        ss.get();
    } else {
        ss.putback(c);
        getline(ss, value, ',');
    }

    if (value == "") {
        value = "0";
    }

    return value;
}

/** @brief lee un fichero de delitos, linea a linea
@param[in] s nombre del fichero
@param[in,out] C conjunto sobre el que se lee
@return true si la lectura ha sido correcta, false en caso contrario
 */
template <typename CMP>
bool load(conjunto<CMP> & C, const string & s) {
    ifstream fe;
    string cadena;
    crimen crim;

    fe.open(s.c_str(), ifstream::in);
    if (fe.fail()) {
        cerr << "Error al abrir el fichero " << s << endl;
    } else {
        getline(fe, cadena, '\n'); //leo la cabecera del fichero

        while (!fe.eof()) {
            getline(fe, cadena, '\n');
            stringstream ss;
            ss.str(cadena);
           
            crim.setID(stol(readItem(ss)));
            crim.setCaseNumber(readItem(ss));
            crim.setDate(fecha(readItem(ss)));
            crim.setBlock(readItem(ss));
            crim.setIUCR(readItem(ss));
            crim.setPrimaryType(readItem(ss));
            crim.setDescription(readItem(ss));
            crim.setLocationDescription(readItem(ss));
            crim.setArrest((readItem(ss) == "true"));
            crim.setDomestic((readItem(ss) == "true"));
            crim.setBeat(stoi(readItem(ss)));
            crim.setDistrict(stoi(readItem(ss)));
            crim.setWard(stoi(readItem(ss)));
            crim.setCommunityArea(stoi(readItem(ss)));
            crim.setFBICode(readItem(ss));
            crim.setXCoord(stol(readItem(ss)));
            crim.setYCoord(stol(readItem(ss)));
            crim.setYear(stoi(readItem(ss)));
            crim.setUpdatedOn(fecha(readItem(ss)));
            crim.setLatitude(stof(readItem(ss)));
            crim.setLongitude(stof(readItem(ss)));

            ss << endl;
            

            C.insert(crim);
        }

        fe.close();
        return true;
    } // else
    fe.close();
    return false;
}
int main(int argc, char* argv[]) {

    conjunto<greater<crimen>> ChicagoDB;
    load(ChicagoDB, "crimenes100.csv");

	conjunto<greater<crimen>>::const_iterator it;
	it = ChicagoDB.begin();
	it = it + 2;
	crimen c;
	c = (*it);
	cout << "CRIMEN" << endl << c << endl;
	it = ChicagoDB.find (c);
	
	cout << *it; 
	/*conjunto<greater<crimen>>::iterator it;
	it = ChicagoDB.begin();
	
	while (it != ChicagoDB.end()) {
		cout << *it << endl;
		it ++;
	} 
    return 0; */
}
