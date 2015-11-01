/** @brief fichero de implementacion de la clase fecha

*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

/**
 * @brief      El constructor por defecto. Genera una instancia de fecha con la fecha del momento en el que se crea
 */
fecha::fecha()
{
	time_t t = time(0);
	struct tm * now = localtime( & t );

	this->mon = (now->tm_mon + 1);
	this->mday = now->tm_mday;
	this->year = (now->tm_year + 1900);
	this->hour = now->tm_hour;
	this->min = now->tm_min;
	this->sec = now->tm_sec;
}

/**
 * @brief      Convierte el objeto fecha en una String con el formato MM/DD/YYYY HH:MM:SS AM
 *
 * @return     Un String con el formato MM/DD/YYYY HH:MM:SS AM
 * 
 * \code Uso
 * fecha * f = new fecha();
 * fecha * f2 = new fecha(f->toString());
 * cout << f2->toString() << endl;
 * \endcode
 */
string fecha::toString( ) const
{
	std::ostringstream ss;
	ss << std::setw(2) << std::setfill('0') << this->mon << "/";
	ss << std::setw(2) << std::setfill('0') << this->mday << "/";
	ss << std::setw(4) << this->year << " ";
	bool am_pm = (this->hour > 12);
	if(am_pm) {
		ss << std::setw(2) << std::setfill('0') << (this->hour-12) << ":";
	}

	ss << std::setw(2) << std::setfill('0') << this->min << ":";
	ss << std::setw(2) << std::setfill('0') << this->sec << " ";
	if(am_pm){
		ss << "PM";
	} else {
		ss << "AM";
	}
	
	return ss.str();
}

/**
 * @brief      Crea una fecha a partir de una String con el formato MM/DD/YYYY HH:MM:SS AM
 *
 * @param  s     String con el formato MM/DD/YYYY HH:MM:SS AM
 * \code Uso
 * fecha * f = new fecha();
 * fecha * f2 = new fecha(f->toString());
 * cout << f2->toString() << endl;
 * \endcode
 */
fecha::fecha (const string & s)
{
	parseString(s);
}

/**
 * @brief      Introduce los valores de una String con el formato MM/DD/YYYY HH:MM:SS AM en el objeto actual
 *
 * @param  s     String con el formato MM/DD/YYYY HH:MM:SS AM
 */
void fecha::parseString(const string & s)
{
	this->mon = stoi(s.substr(0,2));
	this->mday = stoi(s.substr(3,2));
	this->year = stoi(s.substr(6,4));
	this->hour = stoi(s.substr(11,2));
	this->min = stoi(s.substr(14,2));
	this->sec = stoi(s.substr(17,2));
	if(s.substr(20,2) == "PM") {
		this->hour += 12;	
	}
}

/**
 * @brief      Sobrecarga el operador << de ostream para usarlo con la clase fecha;
 *
 * @param os     String con el formato MM/DD/YYYY HH:MM:SS AM
 * @param f     String con el formato MM/DD/YYYY HH:MM:SS AM
 * 
 * \code Uso
 * fecha f;
 * f = "10/10/2015 12:00:00 AM"
 * cout << f << endl;
 * \endcode
 */
ostream& operator<< ( ostream& os, const fecha & f)
{
	os << f.toString() ;
	return os;
}

/**
 * @brief      Sobrecarga el operador << de ostream para usarlo con un puntero de un objeto de la clase fecha;
 *
 * @param os     String con el formato MM/DD/YYYY HH:MM:SS AM
 * @param f     String con el formato MM/DD/YYYY HH:MM:SS AM
 * 
 * \code Uso
 * fecha * f = new fecha();
 * cout << f << endl;
 * \endcode
 */
ostream& operator<< ( ostream& os, const fecha * f)
{
	os << f->toString() ;
	return os;
}


fecha & fecha::operator=(const string & s)
{
	parseString(s);
	return *this;
}

fecha & fecha::operator=(const fecha & f)
{
	parseString(f.toString());
	return *this;
}



bool fecha::operator==(const fecha & f) const {
	return (this->toString() == f.toString());
}

bool fecha::operator<(const fecha & f)const {
	bool igual = false;

	if(this->getYear() < f.getYear()){
		return true;
	} else if(this->getYear() == f.getYear()) {
		igual = true;
	}

	if(this->getMon() < f.getMon() && igual){
		return true;
	} else if(this->getMon() > f.getMon()) {
		igual = false;
	}

	if(this->getDay() < f.getDay() && igual){
		return true;
	} else if(this->getDay() > f.getDay()) {
		igual = false;
	}

	if(this->getHour() < f.getHour() && igual){
		return true;
	} else if(this->getHour() > f.getHour()) {
		igual = false;
	}

	if(this->getMin() < f.getMin() && igual){
		return true;
	} else if(this->getMin() > f.getMin()) {
		igual = false;
	}

	if(this->getSec() < f.getSec() && igual){
		return true;
	} else if(this->getSec() > f.getSec()) {
		igual = false;
	}
	
	return false;
	
}

bool fecha::operator>(const fecha & f) const
{
	fecha f_temp1, f_temp2;
	f_temp1 = this->toString();
	f_temp2 = f.toString();
	return !(f_temp1 < f_temp2 || f_temp1 == f_temp2);
}

bool fecha::operator<=(const fecha & f) const 
{
	fecha f_temp1, f_temp2;
	f_temp1 = this->toString();
	f_temp2 = f.toString();
	return (f_temp1 < f_temp2 || f_temp1 == f_temp2);
}

bool fecha::operator>=(const fecha & f) const 
{
	fecha f_temp1, f_temp2;
	f_temp1 = this->toString();
	f_temp2 = f.toString();
	return !(f_temp1 < f_temp2);
}

bool fecha::operator!=(const fecha & f) const 
{
	fecha f_temp1, f_temp2;
	f_temp1 = this->toString();
	f_temp2 = f.toString();
	return !(f_temp1 == f_temp2);
}

/**
 * @brief      Obtiene los segundos
 *
 * @return     Un int con los segundos
 */
int fecha::getSec() const
{
	return this->sec;
}
/**
 * @brief      Obtiene los minutos
 *
 * @return     Un int con los minutos
 */
int fecha::getMin() const
{
	return this->min;
}
/**
 * @brief      Obtiene las horas
 *
 * @return     Un int con las horas
 */
int fecha::getHour() const
{
	return this->hour;
}
/**
 * @brief      Obtiene los días
 *
 * @return     Un int con los días
 */
int fecha::getDay() const
{
	return this->mday;
}
/**
 * @brief      Obtiene los meses
 *
 * @return     Un int con los meses
 */
int fecha::getMon() const
{
	return this->mon;
}
/**
 * @brief      Obtiene los años
 *
 * @return     Un int con los años
 */
int fecha::getYear() const
{
	return this->year;
}