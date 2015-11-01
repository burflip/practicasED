
#ifndef __FECHA_H
#define __FECHA_H

#include <string>
#include <iostream> 


//! Clase fecha, asociada a la 
/*! fecha::fecha,  .....
 * Descripción contiene toda la información asociada a una fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM
 @todo Escribe la documentación de la clase
 @todo Implementar esta clase

*/
using namespace std;

class fecha {

public:
 fecha (); //Constructor de fecha por defecto
 fecha (const string & s); // s es un string con el formato mm/dd/aaaa  hh:mm:ss AM/PM

 fecha & operator=(const fecha & f);
 fecha & operator=(const string & s); // s es un string con el formato mm/dd/aaaa hh:mm:ss AM/PM
 string toString() const; //convierte la fecha a un string

// Operadores relacionales
 bool operator==(const fecha & f) const;
 bool operator<(const fecha & f)const;
 bool operator>(const fecha & f) const;
 bool operator<=(const fecha & f)const;
 bool operator>=(const fecha & f) const;
 bool operator!=(const fecha & f)const;
 //Getters
  int getSec() const;
  int getMin() const;
  int getHour() const;
  int getDay() const;
  int getMon() const;
  int getYear() const;

private:
  int  sec;   // seconds of minutes from 0 to 61
  int  min;   // minutes of hour from 0 to 59
  int  hour;  // hours of day from 0 to 24
  int  mday;  // day of month from 1 to 31
  int  mon;   // month of year from 0 to 11
  int  year;  // year since 2000
              
  void parseString(const string & s);
  

friend ostream& operator<< ( ostream& os, const fecha & f);
friend ostream& operator<< ( ostream& os, const fecha * f);
};

/* @brief imprime fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM
*/
 ostream& operator<< ( ostream& os, const fecha & f);
 ostream& operator<< ( ostream& os, const fecha * f); 

#include "fecha.hxx" // Incluimos la implementacion.


#endif
