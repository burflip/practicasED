#include "conjunto.h"
#include "crimen.h"
#include "fecha.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

/** @brief lee un fichero de delitos, linea a linea
@param[in] s nombre del fichero
@param[in,out] C conjunto sobre el que se lee
@return true si la lectura ha sido correcta, false en caso contrario
 */

bool load(conjunto & C, const string & s, int times) {
    ifstream fe;
    string cadena;
    crimen crim;

    fe.open(s.c_str(), ifstream::in);
    if (fe.fail()) {
        cerr << "Error al abrir el fichero " << s << endl;
    } else {
        getline(fe, cadena, '\n'); //leo la cabecera del fichero
        int i = 0;
        while (i < times && !fe.eof()) {
            getline(fe, cadena, '\n');
            if (!fe.eof()) {
                //cout << "#" << i << ":" << cadena << endl;
                //cout << endl;


                //cout << "CAD" << endl;
                size_t pos = 0;
                size_t pos_bus = cadena.find_first_of(",");
                string cad = cadena.substr(pos, (pos_bus - pos));
                //cout << "id:" << cad << endl;
                crim.setID(stol(cad));

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                crim.setCaseNumber(cad);
                //cout << "casenumber:" << cad << endl;

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                fecha fecha1(cad);
                crim.setDate(fecha1);
                //cout << "date:" << cad << endl;



                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                crim.setBlock(cad);
                //cout << "block:" << cad << endl;

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                crim.setIUCR(cad);
                //cout << "iucr:" << cad << endl;

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                crim.setPrimaryType(cad);
                //cout << "primaryType:" << cad << endl;

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                unsigned int pos_comm = cadena.find_first_of("\"", pos);
                //cout << "thechar:" << cadena.substr(pos_bus, (pos_bus - (pos + 1))) << endl;
                if (pos_bus > pos_comm) {
                    pos_bus = cadena.find_first_of("\"", pos + 1);
                    cad = cadena.substr(pos + 1, (pos_bus - (pos + 1)));
                    crim.setDescription(cad);
                    //cout << "IF" << endl;
                    pos_bus++;
                } else {
                    //cout << "ELSE" << endl;
                    cad = cadena.substr(pos, (pos_bus - pos));
                    crim.setDescription(cad);
                }
                //cout << "description:" << cad << endl;

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                pos_comm = cadena.find_first_of("\"", pos);
                //cout << "thechar:" << cadena.substr(pos_bus, (pos_bus - (pos + 1))) << endl;
                if (pos_bus > pos_comm) {
                    pos_bus = cadena.find_first_of("\"", pos + 1);
                    cad = cadena.substr(pos + 1, (pos_bus - (pos + 1)));
                    crim.setLocationDescription(cad);
                    //cout << "IF" << endl;
                    pos_bus++;
                } else {
                    //cout << "ELSE" << endl;
                    cad = cadena.substr(pos, (pos_bus - pos));
                    crim.setLocationDescription(cad);
                }

                //cout << "location_desc:" << cad << endl;

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << cad << endl;
                bool arrest = (cad == "true");
                crim.setArrest(arrest);

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << cad << endl;
                bool domestic = (cad == "true");
                crim.setDomestic(domestic);

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << "beat:" << cad << endl;
                if (cad != "") {
                    crim.setBeat(stoi(cad));
                }


                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << cad << endl;
                if (cad != "") {
                    crim.setDistrict(stoi(cad));
                }


                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << cad << endl;
                if (cad != "") {
                    crim.setWard(stoi(cad));
                }


                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << cad << endl;
                if (cad != "") {
                    crim.setCommunityArea(stoi(cad));
                }


                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << cad << endl;
                crim.setFBICode(cad);

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << "xc:" << cad << endl;
                if (cad != "") {
                    crim.setXCoord(stol(cad));
                }

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << "yc:" << cad << endl;
                if (cad != "") {
                    crim.setYCoord(stol(cad));

                }

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << "y:" << cad << endl;
                if (cad != "") {
                    crim.setYear(stoi(cad));
                }




                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << "upd:" << cad << endl;
                fecha fecha2(cad);
                crim.setUpdatedOn(fecha2);
                

                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << "lat:" << cad << endl;
                if (cad != "") {
                    crim.setLatitude(stof(cad));
                }



                pos = pos_bus + 1;
                pos_bus = cadena.find_first_of(",", pos);
                cad = cadena.substr(pos, (pos_bus - pos));
                //cout << "long:" << cad << endl;
                if (cad != "") {
                    crim.setLongitude(stof(cad));
                }
                
                C.insert(crim);
                i++;


            }
        }
        fe.close();
        return true;
    } // else
    fe.close();
    return false;
}

int main(int argc, char* argv[]) {
    
    crimen d;
    fecha f;
    chrono::high_resolution_clock::time_point t1,t2;
    chrono::duration<double> time_span;
    
    for(int i=0; i<=100000; i=i+1000) {
        conjunto ChicagoDB;
        load(ChicagoDB, "crimenes.csv", i);
        long int id = 10230986; //Elegimos una id al azar
        t1 = chrono::high_resolution_clock::now();
    
        ChicagoDB.find(id);

        t2 = chrono::high_resolution_clock::now();
        
        time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
        cout << i << " " << time_span.count() << endl;
    }
    

    return 0;
}
