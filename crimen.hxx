#include <iostream>
#include <string>

#include "crimen.h"

using namespace std;

//CONSTRUCTORES

crimen::crimen() {
    fecha f;
    this->setID(0);
    this->setCaseNumber("");
    this->setDate(f);
    this->setBlock("");
    this->setIUCR("");
    this->setPrimaryType("");
    this->setDescription("");
    this->setLocationDescription("");
    this->setArrest(false);
    this->setDomestic(false);
    this->setBeat(0);
    this->setDistrict(0);
    this->setWard(0);
    this->setCommunityArea(0);
    this->setFBICode("");
    this->setXCoord(0);
    this->setYCoord(0);
    this->setYear(0);
    this->setUpdatedOn(f);
    this->setLatitude(1.0);
    this->setLongitude(1.0);
}

crimen::crimen(const crimen& x) {
    this->setID(x.getID());
    this->setCaseNumber(x.getCaseNumber());
    this->setDate(x.getDate());
    this->setBlock(x.getBlock());
    this->setIUCR(x.getIUCR());
    this->setPrimaryType(x.getPrimaryType());
    this->setDescription(x.getDescription());
    this->setLocationDescription(x.getLocationDescription());
    this->setArrest(x.getArrest());
    this->setDomestic(x.getDomestic());
    this->setBeat(x.getBeat());
    this->setDistrict(x.getDistrict());
    this->setWard(x.getWard());
    this->setCommunityArea(x.getCommunityArea());
    this->setFBICode(x.getFBICode());
    this->setXCoord(x.getXCoord());
    this->setYCoord(x.getYCoord());
    this->setYear(x.getYear());
    this->setUpdatedOn(x.getUpdatedOn());
    this->setLatitude(x.getLatitude());
    this->setLongitude(x.getLongitude());
}

//SETTERS

void crimen::setID(long int id) {
    this->ID = id;

}

void crimen::setCaseNumber(const string & s) {
    this->case_number = s;

}

void crimen::setDate(const fecha & d) {
    this->date = d;

}

void crimen::setBlock(const string & s) {
    this->block = s;

}

void crimen::setIUCR(const string & iucr) {
    this->IUCR = iucr;

}

void crimen::setPrimaryType(const string & s) {
    this->primary_type = s;

}

void crimen::setDescription(const string & s) {
    this->description = s;

}

void crimen::setLocationDescription(const string & s) {
    this->location_description = s;

}

void crimen::setArrest(bool a) {
    this->arrest = a;

}

void crimen::setDomestic(bool d) {
    this->domestic = d;

}

void crimen::setBeat(int b) {
    this->beat = b;

}

void crimen::setDistrict(int d) {
    this->district = d;

}

void crimen::setWard(int w) {
    this->ward = w;

}

void crimen::setCommunityArea(int c) {
    this->community_area = c;

}

void crimen::setFBICode(const string f) {
    this->FBI_code = f;
}

void crimen::setXCoord(long int x) {
    this->x_coord = x;

}

void crimen::setYCoord(long int y) {
    this->y_coord = y;

}

void crimen::setYear(int y) {
    this->year = y;

}

void crimen::setUpdatedOn(const fecha &f) {
    this->updated_on = f;

}

void crimen::setLatitude(float l) {
    this->latitude = l;

}

void crimen::setLongitude(float l) {
    this->longitude = l;
}

//GETTERS

long int crimen::getID() const {
    return this->ID;
}

string crimen::getCaseNumber() const {
    return this->case_number;
}

fecha crimen::getDate() const {
    return this->date;
}

string crimen::getBlock() const {
    return this->block;
}

string crimen::getIUCR() const {
    return this->IUCR;
}

string crimen::getPrimaryType() const {
    return this->primary_type;
}

string crimen::getDescription() const {
    return this->description;
}

string crimen::getLocationDescription() const {
    return this->location_description;
}

bool crimen::getArrest() const {
    return this->arrest;
}

bool crimen::getDomestic() const {
    return this->domestic;
}

int crimen::getBeat() const {
    return this->beat;
}

int crimen::getDistrict() const {
    return this->district;
}

int crimen::getWard() const {
    return this->ward;
}

int crimen::getCommunityArea() const {
    return this->community_area;
}

string crimen::getFBICode() const {
    return this->FBI_code;
}

long int crimen::getXCoord() const {
    return this->x_coord;
}

long int crimen::getYCoord() const {
    return this->y_coord;
}

int crimen::getYear() const {
    return this->year;
}

fecha crimen::getUpdatedOn() const {
    return this->updated_on;
}

float crimen::getLatitude() const {
    return this->latitude;
}

float crimen::getLongitude() const {
    return this->longitude;
}

//OPERADORES

crimen & crimen::operator=(const crimen & x) {
    this->setID(x.getID());
    this->setCaseNumber(x.getCaseNumber());
    this->setDate(x.getDate());
    this->setBlock(x.getBlock());
    this->setIUCR(x.getIUCR());
    this->setPrimaryType(x.getPrimaryType());
    this->setDescription(x.getDescription());
    this->setLocationDescription(x.getLocationDescription());
    this->setArrest(x.getArrest());
    this->setDomestic(x.getDomestic());
    this->setBeat(x.getBeat());
    this->setDistrict(x.getDistrict());
    this->setWard(x.getWard());
    this->setCommunityArea(x.getCommunityArea());
    this->setXCoord(x.getXCoord());
    this->setYCoord(x.getYCoord());
    this->setYear(x.getYear());
    this->setUpdatedOn(x.getUpdatedOn());
    this->setLatitude(x.getLatitude());
    this->setLongitude(x.getLongitude());
    return *this;
}

/*
 DUDAS:
 * 1º Aquí, lo que hay que comparar son las IDs? las fechas? miembro a miembro?
 */

bool crimen::operator==(const crimen & x) const {
    return (
            x.getID() == this->getID()
            && x.getCaseNumber() == this->getCaseNumber()
            && x.getDate() == this->getDate()
            && x.getBlock() == this->getBlock()
            && x.getIUCR() == this->getIUCR()
            && x.getPrimaryType() == this->getPrimaryType()
            && x.getDescription() == this->getDescription()
            && x.getLocationDescription() == this->getLocationDescription()
            && x.getArrest() == this->getArrest()
            && x.getDomestic() == this->getDomestic()
            && x.getBeat() == this->getBeat()
            && x.getDistrict() == this->getDistrict()
            && x.getWard() == this->getWard()
            && x.getCommunityArea() == this->getCommunityArea()
            && x.getFBICode() == this->getFBICode()
            && x.getXCoord() == this->getXCoord()
            && x.getYCoord() == this->getYCoord()
            && x.getYear() == this->getYear()
            && x.getUpdatedOn() == this->getUpdatedOn()
            && x.getLatitude() == this->getLatitude()
            && x.getLongitude() == this->getLongitude()
            );
}

bool crimen::operator<(const crimen & x) const {
    return (this->getID() < x.getID());
}

bool crimen::operator<=(const crimen & x) const {
    return (this->getID() < x.getID() || this->getID() == x.getID());
}

bool crimen::operator>(const crimen & x) const {
    return (this->getID() > x.getID());
}

bool crimen::operator>=(const crimen & x) const {
    return (this->getID() > x.getID() || this->getID() == x.getID());
}

class ComparacionPorFechaCreciente {
	public:
		bool operator()(const crimen &a, const crimen &b) {
			return (a.getDate() < b.getDate());
		}
};

class ComparacionPorFechaDecreciente {
	public:
	bool operator()(const crimen &a, const crimen &b) {
		return !(a.getDate() < b.getDate());
	}
};

class ComparacionPorIUCR {
	public:
		bool operator()(const crimen &a, const crimen &b) {
			return (a.getIUCR() < b.getIUCR());
		}
};

ostream& operator<<(ostream& os, const crimen& c) {
    os << "ID:" << c.getID() << " " <<
            "Case no:" << c.getCaseNumber() << " " <<
            "Date:" << c.getDate() << " " <<
            "Block:" << c.getBlock() << " " <<
            "IUCR:" << c.getIUCR() << " " <<
            "Primary T:" << c.getPrimaryType() << " " <<
            "Description:" << c.getDescription() << " " <<
            "Location D:" << c.getLocationDescription() << " " <<
            "Arrest:" << c.getArrest() << " " <<
            "Domestic:" << c.getDomestic() << " " <<
            "Beat:" << c.getBeat() << " " <<
            "District:" << c.getDistrict() << " " <<
            "Ward:" << c.getWard() << " " <<
            "Comm Area:" << c.getCommunityArea() << " " <<
            "X:" << c.getXCoord() << " " <<
            "Y:" << c.getYCoord() << " " <<
            "Year:" << c.getYear() << " " <<
            "Updated On:" << c.getUpdatedOn() << " " <<
            "Lat:" << c.getLatitude() << " " <<
            "Long:" << c.getLongitude() << endl;

    return os;
}
