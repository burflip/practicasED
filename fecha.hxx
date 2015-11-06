#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "fecha.h"
using namespace std;

/** @brief fichero de implementacion de la clase fecha

 */
fecha::fecha() {

    // @todo implementar esta funcion
    year = 2000;
    mon = 1;
    mday = 1;
    hour = 0;
    min = 0;
    sec = 0;
}

fecha::fecha(const string & x) {
    // @todo implementar esta funcion
    stringToFecha(x);
}

int fecha::getYear() {
    return year;
}

int fecha::getMonth() {
    return mon;
}

int fecha::getDay() {
    return mday;
}

int fecha::getHour() {
    return hour;
}

int fecha::getMinute() {
    return min;
}

int fecha::getSec() {
    return sec;
}

string fecha::toString() const {
    ostringstream ss;
    if (this->mon <= 9)
        ss << "0" << this->mon << "/";

    else
        ss << this->mon << "/";

    if (this->mday <= 9)
        ss << "0" << this->mday << "/";
    else
        ss << this->mday << "/";


    ss << this->year << " ";

    bool am_pm = (this->hour > 12);

    if (am_pm) {
        if ((this->hour - 12) <= 9)
            ss << "0" << (this->hour - 12) << ":";
        else
            ss << (this->hour - 12) << ":";
    }
    else {
        if (this->hour <= 9)
            ss << "0" << (this->hour) << ":";
        else
            ss << (this->hour) << ":";
    }

    if (this->min <= 9)
        ss << "0" << this->min << ":";
    else
        ss << this->min << ":";


    if (this->sec <= 9)
        ss << "0" << this->sec << " ";
    else
        ss << this->sec << " ";
    if (am_pm) {
        ss << "PM";
    } else {
        ss << "AM";
    }

    return ss.str();

}

void fecha::stringToFecha(const string & x) {
    size_t pos = 0;
    size_t pos_bus = x.find_first_of("/");
    string month = x.substr(pos, (pos_bus - pos));
    this->mon = stoi(month);

    pos = pos_bus + 1;
    pos_bus = x.find_first_of("/", pos);
    string day = x.substr(pos, (pos_bus - pos));
    this->mday = stoi(day);

    pos = pos_bus + 1;
    pos_bus = x.find_first_of(" ", pos);
    string year1 = x.substr(pos, (pos_bus - pos));
    this->year = stoi(year1);

    pos = pos_bus + 1;
    pos_bus = x.find_first_of(":", pos);
    string hour1 = x.substr(pos, (pos_bus - pos));
    this->hour = stoi(hour1);

    pos = pos_bus + 1;
    pos_bus = x.find_first_of(":", pos);
    string minut = x.substr(pos, (pos_bus - pos));
    this->min = stoi(minut);

    pos = pos_bus + 1;
    pos_bus = x.find_first_of(" ", pos);
    string secnd = x.substr(pos, (pos_bus - pos));
    this->sec = stoi(secnd);

    pos = pos_bus + 1;
    pos_bus = x.front();
    string moment = x.substr(pos, pos_bus - pos);

    if (moment == "PM") {
        this->hour += 12;
    }
}

fecha & fecha::operator=(const fecha & f) {

    this->year = f.year;
    this->mon = f.mon;
    this->mday = f.mday;
    this->hour = f.hour;
    this->min = f.min;
    this->sec = f.sec;
    return *this;
}

fecha & fecha::operator=(const string & f) {
    stringToFecha(f);
    return *this;
}

bool fecha::operator==(const fecha & f) const {

    return ((this->year == f.year) && (this->mon == f.mon) && (this->mday == f.mday) && (this->hour == f.hour) &&
            (this->min == f.min) && (this->sec == f.sec));

}

bool fecha::operator<(const fecha & f)const {
    bool menor;

    if (this->year < f.year)
        menor = true;
    else {
        if (this->year > f.year)
            menor = false;
        else {
            if (this->mon < f.mon)
                menor = true;
            else {
                if (this->mon > f.mon)
                    menor = false;
                else {
                    if (this->mday < f.mday)
                        menor = true;
                    else {
                        if (this->mday > f.mday)
                            menor = false;
                        else {
                            if (this->hour < f.hour)
                                menor = true;
                            else {
                                if (this->hour > f.hour)
                                    menor = false;
                                else {
                                    if (this->min < f.min)
                                        menor = true;
                                    else {
                                        if (this->min > f.min)
                                            menor = false;
                                        else {
                                            if (this->sec < f.sec)
                                                menor = true;
                                            else
                                                menor = false;

                                        }
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return menor;
}

bool fecha::operator>(const fecha & f) const {
    bool mayor;

    if (this->year > f.year)
        mayor = true;
    else {
        if (this->year < f.year)
            mayor = false;
        else {
            if (this->mon > f.mon)
                mayor = true;
            else {
                if (this->mon < f.mon)
                    mayor = false;
                else {
                    if (this->mday > f.mday)
                        mayor = true;
                    else {
                        if (this->mday < f.mday)
                            mayor = false;
                        else {
                            if (this->hour > f.hour)
                                mayor = true;
                            else {
                                if (this->hour < f.hour)
                                    mayor = false;
                                else {
                                    if (this->min > f.min)
                                        mayor = true;
                                    else {
                                        if (this->min < f.min)
                                            mayor = false;
                                        else {
                                            if (this->sec > f.sec)
                                                mayor = true;
                                            else
                                                mayor = false;
                                        }
                                    }


                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return mayor;
}

bool fecha::operator<=(const fecha & f)const {
    bool menor_igual;

    if (this->year > f.year)
        menor_igual = false;
    else {
        if (this->mon < f.mon)
            menor_igual = false;
        else {
            if (this->mday > f.mday)
                menor_igual = false;
            else {
                if (this->hour > f.hour)
                    menor_igual = false;
                else {
                    if (this->min > f.min)
                        menor_igual = false;
                    else {
                        if (this->sec > f.sec)
                            menor_igual = false;
                        else
                            menor_igual = true;
                    }
                }
            }

        }
    }

    return menor_igual;
}

bool fecha::operator>=(const fecha & f) const {
    bool mayor_igual;

    if (this->year < f.year)
        mayor_igual = false;
    else {
        if (this->mon < f.mon)
            mayor_igual = false;
        else {
            if (this->mday > f.mday)
                mayor_igual = false;
            else {
                if (this->hour > f.hour)
                    mayor_igual = false;
                else {
                    if (this->min > f.min)
                        mayor_igual = false;
                    else {
                        if (this->sec > f.sec)
                            mayor_igual = false;
                        else
                            mayor_igual = true;
                    }
                }
            }

        }
    }
    return mayor_igual;
}

bool fecha::operator!=(const fecha & f) const {
    return (
            (this->year != f.year) || (this->mon != f.mon) 
            || (this->mday != f.mday) || (this->hour != f.hour) 
            || (this->min != f.min) || (this->sec != f.sec)
            );
}

ostream& operator<<(ostream& os, const fecha & f) {

    os << f.toString();
    return os;
}

