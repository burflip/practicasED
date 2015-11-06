#ifndef FECHA
#define FECHA

#include <iostream>
#include <string>

using namespace std;

//! Clase fecha, asociada a la 
/*! fecha::fecha,  .....
 * Descripción contiene toda la información asociada a una fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM
 @todo Escribe la documentación de la clase
 @todo Implementar esta clase

*/

class fecha {

public:
	/**
	 * @brief     Crea una instancia del objeto fecha
	 */

 fecha (); //Constructor de fecha por defecto
 

 fecha (const string & s); // s es un string con el formato mm/dd/aaaa  hh:mm:ss AM/PM
 
 /**
  * @brief      Coge un string que se le pasa como argumento y lo almacena en la instancia del tipo fecha
  *
  * @param[in]  x     string con la fecha en formato MM/DD/YYYY hh:mm:ss AM ó MM/DD/YYYY hh:mm:ss PM
  */

 void stringToFecha(const string & x);


 /**
  * @brief      Convierte una instancia del objeto en una cadena de caracteres
  *
  * @return     Devuelve la instancia convertida en un string
  */
 string toString() const;

 /**
  * @brief      Devuelve el año de la fecha en cuestión
  *
  * @return     int con el año
  */
 int getYear();
  /**
  * @brief      Devuelve el mes de la fecha en cuestión
  *
  * @return     int con el mes
  */
 int getMonth();
  /**
  * @brief      Devuelve el day de la fecha en cuestión
  *
  * @return     int con el day
  */
 int getDay();
  /**
  * @brief      Devuelve la hora de la fecha en cuestión
  *
  * @return     int con la hora
  */
 int getHour();
  /**
  * @brief      Devuelve el minuto de la fecha en cuestión
  *
  * @return     int con el minuto
  */
 int getMinute();
  /**
  * @brief      Devuelve el segundo de la fecha en cuestión
  *
  * @return     int con el segundo
  */
 int getSec();


/**
 * @brief      Sobrecarga el operador de igualción y permite utilizarlo con una fecha
 *
 * @param[in]  f     una instancia del tipo fecha
 *
 * @return     Devuelve el propio objeto fecha para que la sobrecarga del operador lo almacene a la izquierda del operador
 */
 fecha & operator=(const fecha & f);

 /**
  * @brief      Sobrecarga el operador de igualción y permite utilizarlo con una fecha
  *
  * @param[in]  s    s es un string con el formato mm/dd/aaaa hh:mm:ss AM/PM
  *
  * @return      Devuelve el propio objeto fecha para que la sobrecarga del operador lo almacene a la izquierda del operador
  */
 fecha & operator=(const string & s);
 

// Operadores relacionales

/**
 * @brief      Operador de comparación
 *
 * @param[in]  f     instancia de fecha
 *
 * @return     Devuelve true si son iguales o false si no
 */
 bool operator==(const fecha & f) const;

 /**
  * @brief      Operador de comparación
  * 
  * @param[in]  f     instancia de fecha
 *
 * @return     Devuelve true si el operando de la izquierda es menor que el de la derecha o false si no
  */

 bool operator<(const fecha & f)const;

 /**
  * @brief      Operador de comparación
  * 
  * @param[in]  f     instancia de fecha
 *
 * @return     Devuelve true si el operando de la izquierda es mayor que el de la derecha o false si no
  */

 bool operator>(const fecha & f) const;

 /**
  * @brief      Operador de comparación
  *
  * @param[in]  f     instancia de fecha
  *
  * @return     Devuelve true si el operando de la izquierda es menor o igual que el de la derecha o false si no
  */

 bool operator<=(const fecha & f)const;

  /**
  * @brief      Operador de comparación
  *
  * @param[in]  f     instancia de fecha
  *
  * @return     Devuelve true si el operando de la izquierda es mayor o igual que el de la derecha o false si no
  */

 bool operator>=(const fecha & f) const;

  /**
  * @brief      Operador de comparación
  *
  * @param[in]  f     instancia de fecha
  *
  * @return     Devuelve true si el operando de la izquierda distinto al del de la derecha o false si no
  */

 bool operator!=(const fecha & f)const;

private:
  int  sec;   // seconds of minutes from 0 to 61
  int  min;   // minutes of hour from 0 to 59
  int  hour;  // hours of day from 0 to 24
  int  mday;  // day of month from 1 to 31
  int  mon;   // month of year from 0 to 11
  int  year;  // year since 2000
 
/**
 * @brief      Sobrecarga el operador de cauce para poder monstrar por pantalla el 
 *
 * @param      os    instancia de ostream, a la izquierda del operador
 * @param[in]  f     instancia del objeto fecha, a la derecha del operador
 *
 * @return     Devuelve la instancia de ostream.
 */
 friend  ostream& operator << ( ostream& os, const fecha & f); 
};

/* @brief imprime fecha con el formato  mm/dd/aaaa hh:mm:ss AM/PM
*/
// ostream& operator<< ( ostream& os, const fecha & f); 

#include "fecha.hxx"

#endif
