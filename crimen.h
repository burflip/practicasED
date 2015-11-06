#ifndef __CRIMEN_H
#define __CRIMEN_H

#include <iostream>
#include <string>
#include "string.h"


#include "fecha.h"
//! Clase crimen, asociada a la definición de un crimen 

/*! crimen::crimen, 
 * Métodos--> conjunto:: crimen(), crimen(const crimen& x), setID(long int id), setCaseNumber(const string & s), setDate(const fecha & d), setBlock(const string & s), setIUCR(const string & iucr), setPrimaryType(const string & s), setDescription(const string & s), setLocationDescription(const string & s), setArrest(bool a), setDomestic(bool d), setBeat(int b), setDistrict(int d), setWard(int w), setCommunityArea(int c), setFBICode(string f), setXCoord(long int x), setYCoord(long int y), setYear(int y), setUpdatedOn(const fecha &f), setLatitude(float l), setLongitude(float l),
 * Descripción 
 * Un crimen es un objeto que permite almacenar la información relacionada con un crimen de la base de datos de Miami.
 * Si no se da ningún dato, se crea un crimen con datos por defecto
 * Se puede crear un crimen a partir de otro o de cada una de sus componentes, a través de sus setters.
 */


class crimen {
public:
    /**
     * @brief Constructor primitivo
     */
    crimen();
    /** @brief constructor de copia
     * @param[in] x crimen a copiar
     */
    crimen(const crimen& x);
    /**
     * @brief Método set para id
     * @param id del crimen
     */
    void setID(long int id);
    /**
     * @brief Método set para el número del caso
     * @param s Número del caso
     */
    void setCaseNumber(const string & s);
    /**
     * @brief Método set para la fecha
     * @param d fecha del crimen
     */
    void setDate(const fecha & d);
    /**
     * @brief Método set para el bloque
     * @param s bloque del crimen
     */
    void setBlock(const string & s);
    /**
     * @brief Método set para el IUCR
     * @param iucr del crimen
     */
    void setIUCR(const string & iucr);
    /**
     * @brief Método set para el tipo principal
     * @param s con el tipo principal
     */
    void setPrimaryType(const string & s);
    /**
     * @brief Método set para la descripción
     * @param s con la descripción
     */
    void setDescription(const string & s);
    /**
     * @brief Método set para la descripción de la ubicación
     * @param s con la descripción de la ubicación
     */
    void setLocationDescription(const string & s);
    /**
     * @brief Método set para saber si hubo arresto
     * @param a true si hubo arresto, false si no
     */
    void setArrest(bool a);
    /**
     * @brief Método set para saber si fue un crimen doméstico
     * @param d true si fue doméstico, false si no
     */
    void setDomestic(bool d);
    /**
     * @brief Método set para la ronda
     * @param entero con la ronda
     */
    void setBeat(int b);
    /**
     * @brief Método set para el distrito
     * @param d entero con el distrito
     */
    void setDistrict(int d);
    /**
     * @brief Método set para el ward
     * @param w entero con el ward
     */
    void setWard(int w);
    /**
     * @brief Método set para la community area
     * @param c entero con la community area
     */
    void setCommunityArea(int c);
    /**
     * @brief Método set para el código del FBI
     * @param f string con el código del FBI
     */
    void setFBICode(string f);
    /**
     * @brief Método set para las coordenadas x
     * @param x long int con las coordenadas x
     */
    void setXCoord(long int x);
    /**
     * @brief Método set para las coordenadas y
     * @param x long int con las coordenadas y
     */
    void setYCoord(long int y);
    /**
     * @brief Método set para el año
     * @param y entero con el año
     */
    void setYear(int y);
    /**
     * @brief Método set para la fecha de actualización
     * @param f objeto fecha con la fecha de actualización
     */
    void setUpdatedOn(const fecha &f);
    /**
     * @brief Método set para la latitud
     * @param l float con la latitud
     */
    void setLatitude(float l);
    /**
     * @brief Método set para la longitud
     * @param l float con la longitud
     */
    void setLongitude(float l);

     /**
     * @brief Método get para id
     * @return id del crimen
     */
    long int getID() const;
    /**
     * @brief Método get para el número del caso
     * @return Número del caso
     */
    string getCaseNumber() const;
        /**
     * @brief Método get para la fecha
     * @return fecha del crimen
     */
    fecha getDate() const;
        /**
     * @brief Método get para el bloque
     * @return bloque del crimen
     */
    string getBlock() const;
    /**
     * @brief Método get para el IUCR
     * @return iucr del crimen
     */
    string getIUCR() const;
     /**
     * @brief Método get para el tipo principal
     * @return Tipo principal
     */
    string getPrimaryType() const;
    /**
     * @brief Método get para la descripción
     * @return Descripción
     */
    string getDescription() const;
    /**
     * @brief Método get para la descripción de la ubicación
     * @return Descripción de la ubicación
     */
    string getLocationDescription() const;
    /**
     * @brief Método get para saber si hubo arresto
     * @return true si hubo arresto, false si no
     */
    bool getArrest() const;
    /**
     * @brief Método get para saber si fue un crimen doméstico
     * @return true si fue doméstico, false si no
     */
    bool getDomestic() const;
    /**
     * @brief Método get para la ronda
     * @return entero con la ronda
     */
    int getBeat() const;
    /**
     * @brief Método get para el distrito
     * @return entero con el distrito
     */
    int getDistrict() const;
    /**
     * @brief Método get para el ward
     * @return entero con el ward
     */
    int getWard() const;
    /**
     * @brief Método get para la community area
     * @return entero con la community area
     */
    int getCommunityArea() const;
    /**
     * @brief Método get para el código del FBI
     * @return string con el código del FBI
     */
    string getFBICode() const;
     /**
     * @brief Método get para las coordenadas x
     * @return long int con las coordenadas x
     */
    long int getXCoord() const;
    /**
     * @brief Método get para las coordenadas y
     * @return long int con las coordenadas y
     */
    long int getYCoord() const;
    /**
     * @brief Método get para el año
     * @return entero con el año
     */
    int getYear() const;
    /**
     * @brief Método get para la fecha de actualización
     * @return objeto fecha con la fecha de actualización
     */
    fecha getUpdatedOn() const;
    /**
     * @brief Método get para la latitud
     * @return float con la latitud
     */
    float getLatitude() const;
    /**
     * @brief Método get para la longitud
     * @return float con la longitud
     */
    float getLongitude() const;

    /**
     * @brief Iguala un crimen a lo que haya a la derecha del operador
     * @param crimen a la derecha del operador
     * @return devuelve this a la izquierda del operador
     */
    crimen & operator=(const crimen & c);
    /**
     * @brief Comprueba que todos los elementos de dos crímenes sean iguales entre sí
     * @param crimen a la derecha del operador
     * @return devuelve true si son iguales, false si distintos
     */
    bool operator==(const crimen & x) const;
    /**
     * @brief Comprueba que la id de un crimen sea menor a la de otro
     * @param crimen a la derecha del operador
     * @return devuelve true si la id del crimen de la derecha es menor, false si es mayor o igual
     */
    bool operator<(const crimen & x) const;
    /**
     * @brief Comprueba que la id de un crimen sea menor o igual a la de otro
     * @param crimen a la derecha del operador
     * @return devuelve true si la id del crimen de la derecha es menor o igual, false si es mayor
     */
    bool operator<=(const crimen & x) const;
    /**
     * @brief Comprueba que la id de un crimen sea mayor a la de otro
     * @param crimen a la derecha del operador
     * @return devuelve true si la id del crimen de la derecha es mayor, false si es menor o igual
     */
    bool operator>(const crimen & x) const;
    /**
     * @brief Comprueba que la id de un crimen sea mayor o igual a la de otro
     * @param crimen a la derecha del operador
     * @return devuelve true si la id del crimen de la derecha es mayor o igual, false si es menor
     */
    bool operator>=(const crimen & x) const;
private:
    friend ostream& operator<<(ostream& os, const crimen& c);
    //Atributos 
    long int ID;
    string case_number;
    fecha date;
    string block;
    string IUCR;
    string primary_type;
    string description;
    string location_description;
    bool arrest;
    bool domestic;
    int beat;
    int district;
    int ward;
    int community_area;
    string FBI_code;
    long int x_coord;
    long int y_coord;
    int year;
    fecha updated_on;
    float latitude;
    float longitude;
};

ostream& operator<<(ostream& os, const crimen& c);


#include "crimen.hxx"
#endif
