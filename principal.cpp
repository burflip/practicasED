#include "conjunto.h"
#include "crimen.h"
#include "fecha.h"
#include <iostream>
#include <fstream>

using namespace std;

/** @brief lee un fichero de delitos, linea a linea
@param[in] s nombre del fichero
      @param[in,out] C conjunto sobre el que se lee
@return true si la lectura ha sido correcta, false en caso contrario
*/

bool load(conjunto &  C, const string & s)
{
  ifstream fe;
  string cadena;

  cout << "Abrimos " << s << endl;
  fe.open(s.c_str(), ifstream::in);
  if (fe.fail())
  {
    cerr << "Error al abrir el fichero " << s << endl;
  } else {
    getline(fe, cadena, '\n'); //leo la cabecera del fichero
    cout << cadena << endl;
    while ( !fe.eof() )
    { 
      getline(fe, cadena, '\n');
      if (!fe.eof()) {
        cout << "leo:: " << cadena << endl;
        // Convertir cadena a crimen
        // crimen aux = cadena;
        // Insertar cadena en el conjunto
        // C.insert(aux);
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
  //conjunto ChicagoDB;
  //crimen d;
  //fecha f;

  /*echa f1;
  f1 = "09/10/2015 11:55:00 PM";
  fecha f2(f1);
  fecha f3 = "09/04/2010 11:55:00 PM";
  if (f1 < f3)
  cout << f1 << " es menor que " f3;*/

  //load(ChicagoDB, "crimenes.csv");
  
  fecha f;
  f = "09/04/2010 11:55:00 PM";
  fecha f3;
  f3 = f;
  fecha * f2 = new fecha();
  fecha f4;
  f4 = "09/12/2009 11:50:00 PM";
  cout << f << endl;
  return 0;
}
