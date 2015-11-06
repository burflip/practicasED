#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <string>
#include <vector>
#include <iostream> 

#include "crimen.h"
#include "conjunto.h"

typedef crimen entrada;
typedef unsigned int size_type;

conjunto::conjunto() {
    this->vc.clear();
}

conjunto::conjunto(const conjunto & d) {
    this->vc.clear();
    for (unsigned int i = 0; i < d.size(); i++) {
        this->vc.push_back(d.getAt(i));
    }
        
}

pair <conjunto::entrada, bool> conjunto::find(const long int & id) const {
    pair < conjunto::entrada, bool> par;
    crimen c;
    par.second = false;
    

    if (this->cheq_rep()) {
        for (unsigned int i = 0; i < vc.size() && !par.second; i++) {
            if (vc.at(i).getID() == id) {
                par.second = true;
                c = vc.at(i);
            }
        }

        par.first = c;
    }
    
    return par;
}

crimen conjunto::getAt(int i) const {
    crimen c;
    if(vc.size() < (unsigned)i) {
        c = vc.at(i);
    }
    return c;
}


string conjunto::zeroFill(const string & s, unsigned int n) const
{
    string filled = s;
    int diff = n - s.size();
    for(int i = 0; i<diff; i++){
        filled = "0"+filled;
    }
    return filled;
}
conjunto conjunto::findIUCR(const string & iucr) const {
    conjunto c;
    string zfIUCR = zeroFill(iucr,4);
    for (unsigned int i = 0; i < this->vc.size(); i++) {
        int j = 0;
        if (vc.at(i).getIUCR() == zfIUCR) {
            c.insert(vc.at(i));
            j++;
        }

    }
    cout << c << endl;
    return c;
}

conjunto conjunto::findDESCR(const string & descr) const {
    conjunto c;

    for (unsigned int i = 0; i < this->vc.size(); i++) {
        int j = 0;
        if (this->getAt(i).getDescription() == descr) {
            c.insert(vc.at(i));
            j++;
        }
    }
    
    
    return c;

}

bool conjunto::insert(const conjunto::entrada & e) {

    bool insertado = false;
    vector<conjunto::entrada>::iterator it = vc.begin();


    if (vc.empty()) {
        vc.push_back(e);
        insertado = true;
    } else {
        if (!find(e.getID()).second) {

            while (it != vc.end() && !insertado) {
                if ((*it).getID() > e.getID()) {
                    vc.insert(it, e);
                    insertado = true;
                } else
                    it++;
            }

        }

        if (!insertado) {
            vc.push_back(e);
            insertado = true;
        }

    }

    return insertado;
}

bool conjunto::erase(const long int & id) {
    bool borrado = false;


    for (unsigned int i = 0; i < vc.size() && !borrado; i++) {
        if (vc.at(i).getID() == id) {
            vc.erase(vc.begin() + i);
            borrado = true;
        }
    }

    return borrado;

}

/** @brief Borra una crimen con identificador dado por e.getID() en el vc.


Busca la entrada con id en el conjunto (o e.getID() en el segundo caso) y si la encuentra la borra

@param[in] entrada con e.getID() que geremos borrar, el resto de los valores no son tenidos en cuenta
@return true si la entrada se ha podido borrar con éxito. False en caso contrario
@post Si esta en el conjunto su tamaño se decrementa en 1.
 */

bool conjunto::erase(const conjunto::entrada & e) {
    bool borrado;

    for (unsigned int i = 0; i < vc.size() && !borrado; i++) {
        if (vc.at(i).getID() == e.getID()) {
            vc.erase(vc.begin() + i);
            borrado = true;
        }
    }

    return borrado;


}

conjunto & conjunto::operator=(const conjunto & org) {
    this->vc.clear();
    
    for (unsigned int i = 0; i < org.size(); i++){
        this->vc.push_back(org.getAt(i));
    }
        

    return *this;
}

size_type conjunto::size() const {
    return vc.size();
}

bool conjunto::empty() const {
    return vc.empty();
}
/** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
 */

// Devuelve si los ID son todos menores o iguales y que son mayores que 0.

bool conjunto::cheq_rep() const {
    bool inv = false;
    int size= vc.size();
    for (int i = 0; i < size-1; i++) {
        if ((vc.at(i).getID() < vc.at(i + 1).getID()) && vc.at(i).getID() > 0)
            inv = true;
    }

    return inv;

}

ostream & operator<<(ostream & sal, const conjunto & D) {
    for (unsigned int i = 0; i < D.size(); i++)
        sal << D.getAt(i) << endl;

    return sal;
}

#endif	// CONJUNTO_H

