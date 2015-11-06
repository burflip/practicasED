/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
 */
#ifndef __CRIMEN_H
#define __CRIMEN_H

#include <iostream>
#include <string>
#include "string.h"


#include "fecha.h"
//! Clase crimen, asociada a la definición de un crimen 

/*! crimen::crimen,  .....
 * Descripción contiene toda la información asociada a un crimen.
 
 @todo Implementa esta clase, junto con su documentación asociada

 */


class crimen {
public:
    crimen();
    crimen(const crimen& x);
    void setID(long int id);
    void setCaseNumber(const string & s);
    void setDate(const fecha & d);
    void setBlock(const string & s);
    void setIUCR(const string & iucr);
    void setPrimaryType(const string & s);
    void setDescription(const string & s);
    void setLocationDescription(const string & s);
    void setArrest(bool a);
    void setDomestic(bool d);
    void setBeat(int b);
    void setDistrict(int d);
    void setWard(int w);
    void setCommunityArea(int c);
    void setFBICode(string f);
    void setXCoord(long int x);
    void setYCoord(long int y);
    void setYear(int y);
    void setUpdatedOn(const fecha &f);
    void setLatitude(float l);
    void setLongitude(float l);


    long int getID() const;
    string getCaseNumber() const;
    fecha getDate() const;
    string getBlock() const;
    string getIUCR() const;
    string getPrimaryType() const;
    string getDescription() const;
    string getLocationDescription() const;
    bool getArrest() const;
    bool getDomestic() const;
    int getBeat() const;
    int getDistrict() const;
    int getWard() const;
    int getCommunityArea() const;
    string getFBICode() const;
    long int getXCoord() const;
    long int getYCoord() const;
    int getYear() const;
    fecha getUpdatedOn() const;
    float getLatitude() const;
    float getLongitude() const;


    crimen & operator=(const crimen & c);
    bool operator==(const crimen & x) const;
    bool operator<(const crimen & x) const;
    bool operator<=(const crimen & x) const;
    bool operator>(const crimen & x) const;
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
