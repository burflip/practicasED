/* 
 * conjunto.h
 * 
 * Copyright  (C) Juan F. Huete
 */

#ifndef __CONJUTO_H
#define __CONJUTO_H
#include <string>
#include <vector>
#include <iostream> 

#include "crimen.h"

using namespace std;

//! Clase conjunto

/*! Métodos--> conjunto:: conjunto(), insert(), find(),  findIUCR(), findDESCR(), erase(), size(), empty()

 * Tipos--> conjunto::entrada, conjunto::size_type

 * Descripción

 * Un conjunto es un contenedor que permite almacenar en orden creciente un conjunto de elementos no repetidos.  En nuestro caso el conjunto va a tener un subconjunto restringido de métodos (inserción de elementos, consulta de un elemento, etc). Este conjunto "simulará" un conjunto de la stl, con algunas claras diferencias pues, entre otros,  no estará dotado de la capacidad de iterar (recorrer) a través de sus elementos.

 * Asociado al conjunto, tendremos el tipo  \code conjunto::entrada \endcode que permite hacer referencia al elemento  almacenados en cada una de las posiciones del conjunto, en nuestro caso delitos (crimenes). Para esta entrada el requisito es que tenga definidos el operador< y operator=

 * Además encontraremos el tipo \code conjunto::size_type \endcode que permite hacer referencia al número de elementos en el conjunto.

 * El número de elementos en el conjunto puede variar dinámicamente; la gestión de la memoria es automática. 
 
 Ejemplo de su uso:
\code
...
conjunto DatosChicago, agresion;
crimen cr;

conjunto.insert(cr);
...
agresion = conjunto.findDESCR("BATTERY");

if (!agresion.empty()){
 cout <<"Tenemos "<< agresion.size() << " agresiones" << endl;
 cout << agresion << endl;
} else "No hay agresiones en el conjunto" << endl;
...
\endcode
 @todo Implementa esta clase, junto con su documentación asociada
 */



template <class CMP>

class conjunto {
public:
    /** @brief entrada permite hacer referencia al elemento  almacenados en cada una de las posiciones del conjunto
     */
    typedef crimen entrada;
    /** @brief size_type numero de elementos en el conjunto
     */
    typedef unsigned int size_type;
    /** @brief constructor primitivo. 
	
     */
    conjunto();
    //declaraciones previa de los iteradores
    class iterator;
    class const_iterator;
    class arrest_iterator; // Iterador sobre los delitos que implicaron un arresto (Arrest==true)
    class const_arrest_iterator;
    class description_iterator; // Iterador sobre los delitos que concuerdan con la descripcion
    class const_description_iterator;

    /** @brief constructor de copia
    @param[in] d conjunto a copiar
     */
    conjunto<CMP>(const conjunto<CMP> & d);



    crimen getAt(int i) const;
    /** @brief busca un crimen en el conjunto
    @param id identificador del crimen  buscar
    @return Si existe una entrada en el conjunto devuelve un iterador a lo posicion donde está el elemento. Si  no se encuentra devuelve end()
    @post no modifica el conjunto.
    \code Ejemplo
       

    if (C.find(12345)!=C.end() ) cout << "Esta" ;
    else cout << "No esta";
    \endcode
     */

    conjunto<CMP>::iterator find(const long int & id);
    /** @brief busca un crimen en el conjunto
    @param id identificador del crimen  buscar
    @return Si existe una entrada en el conjunto devuelve un iterador a lo posicion donde está el elemento. Si  no se encuentra devuelve end()
    @post no modifica el conjunto.
    \code Ejemplo
       

    if (C.find(12345)!=C.end() ) cout << "Esta" ;
    else cout << "No esta";
    \endcode
     */
    conjunto<CMP>::const_iterator find(const long int & id)const;

    /** @brief busca un crimen en el conjunto
    @param c crimen a buscar
    @return Si existe una entrada en el conjunto devuelve un iterador a lo posicion donde está el elemento. Si  no se encuentra devuelve end()
    @post no modifica el conjunto.
     */
    conjunto<CMP>::const_iterator find(const crimen & c) const;
    /** @brief busca un crimen en el conjunto
    @param c crimen a buscar
    @return Si existe una entrada en el conjunto devuelve un iterador a lo posicion donde está el elemento. Si  no se encuentra devuelve end()
     */
    conjunto<CMP>::iterator find(const crimen & c);

    string zeroFill(const string & s, unsigned int n) const;
    /** @brief busca los crimenes con el mismo codigo IUCR
    @param icur identificador del crimen  buscar
    @return Devuelve un  conjunto con todos los crimenes con el codigo IUCR. Si no existe ninguno devuelve el conjunto vacio.
    @post no modifica el conjunto.
    \verbatim Uso
    vector<crimen> C, A;
    ....
    A = C.findIUCR("0460");
    \endverbatim
     */
    conjunto<CMP> findIUCR(const string & iucr) const;

    /** @brief busca los crimenes que contienen una determinada descripcion 
            @param descr string que representa la descripcion del delito buscar
            @return Devuelve un  conjunto con todos los crimenes  que contengan descr en su descripcionR. Si no existe ninguno devuelve el conjunto vacio.
            @post no modifica el conjunto.
            \verbatim Uso
            vector<crimen> C, A;
            ....
            A = C.findDESCR("BATTERY");
            \endverbatim
     */
    conjunto<CMP> findDESCR(const string & descr) const;

    /** @brief Inserta una entrada en el conjunto
    @param e entrada a insertar
    @return true si la entrada se ha podido insertar con éxito. False en caso contrario
    @post 	 Si e no esta en el conjunto, el size() sera incrementado en 1.
     */
    bool insert(const conjunto<CMP>::entrada & e);



    /** @brief Borra el delito dado un identificacador.

    Busca la entrada con id en el conjunto  y si la encuentra la borra

    @param[in] id a borrar
    @return true si la entrada se ha podido borrar con éxito. False en caso contrario
    @post Si esta en el conjunto su tamaño se decrementa en 1.
     */

    bool erase(const long int & id);


    /** @brief Borra una crimen con identificador dado por e.getID() en el conjunto.


    Busca la entrada con id en el conjunto (o e.getID() en el segundo caso) y si la encuentra la borra

    @param[in] entrada con e.getID() que geremos borrar, el resto de los valores no son tenidos en cuenta
    @return true si la entrada se ha podido borrar con éxito. False en caso contrario
    @post Si esta en el conjunto su tamaño se decrementa en 1.
     */

    bool erase(const conjunto<CMP>::entrada & e);


    /** @brief operador de asignación
    @param[in] org conjunto  a copiar.
     Crea un conjunto duplicado exacto de org.
     */
    conjunto<CMP> & operator=(const conjunto<CMP> & org);

    /** @brief numero de entradas en el conjunto
    @post  No se modifica el conjunto.
     */

    size_type size() const;


    /** @brief Chequea si el conjunto esta vacio
       @return true si size()==0, false en caso contrario.
     */
    bool empty() const;

    conjunto(iterator ini, iterator fin);
    /**
     * @brief Devuelve un iterador apuntando al elemento inmediatamente anterior a x, o vc.begin();
     * @param x Elemento sobre el que trabajar
     * @return conjunto<CMP>::iterator it
     */
    conjunto<CMP>::iterator lower_bound(const entrada & x);
    /**
     * @brief Devuelve un iterador constante apuntando al elemento inmediatamente anterior a x, o vc.begin();
     * @param x Elemento sobre el que trabajar
     * @return conjunto<CMP>::const_iterator it
     */
    conjunto<CMP>::const_iterator lower_bound(const entrada & x)const;
    /**
     * @brief Devuelve un iterador apuntando al elemento inmediatamente posterior a x, o vc.end();
     * @param x Elemento sobre el que trabajar
     * @return conjunto<CMP>::iterator it
     */
    conjunto<CMP>::iterator upper_bound(const entrada & x);
    /**
     * @brief Devuelve un iterador constante apuntando al elemento inmediatamente posterior a x, o vc.end();
     * @param x Elemento sobre el que trabajar
     * @return conjunto<CMP>::const_iterator it
     */
    conjunto<CMP>::const_iterator upper_bound(const entrada & x)const;
    // ================================= ITERADORES ========================================/

    /**@brief devuelve iterador al inicio del conjunto
     */
    iterator begin();

    /**@brief devuelve iterador al final (posición siguiente al último del conjunto
     */
    iterator end();

    /** @brief class iterator
     * forward iterador sobre el conjunto, LECTURA
     *  iterator() ,operator*(), operator++, operator++(int) operator=, operator==, operator!=
     * */
    class iterator {
    public:
        /**
         * @brief Constructor por defecto
         */
        iterator();
        /**
         * @brief Constructor de copia
         * @param it
         */
        iterator(const iterator & it);

        /**
         * @brief Sobrecarga del puntero, devuelve un crimen
         * @return conjunto<CMP>::entrada
         */
        const conjunto<CMP>::entrada & operator*() const;

        /**
         * Sobrecarga del operador +. Aumenta la posición del iterador en i posiciones.
         * @param i
         * @return iterator Referencia al iterador
         */
        iterator & operator+(int i);
        /**
         * @brief Sobrecarga del operador ++ para ++it; Aumenta la posición del iterador en 1.
         * @param 
         * @return iterator Referencia al iterador
         */
        iterator operator++(int);
        /**
         * @brief Sobrecarga del operador ++ para it++; Aumenta la posición del iterador en 1.
         * @return iterator Referencia al iterador
         */
        iterator & operator++();
        /**
         * @brief Sobrecarga del operador -. Disminuye el iterador en i posiciones.
         * @param i Posiciones a disminuir
         * @return iterator Referencia al iterador
         */
        iterator & operator-(int i);
        /**
         * @brief Sobrecarga del operador -- para --it; Disminuye el iterador en una posición.
         * @param 
         * @return iterator Referencia al iterador
         */
        iterator operator--(int);
        /**
         * @brief Sobrecarga del operador -- para it--; Disminuye el iterador en una posición.
         * @return iterator Referencia al iterador
         */
        iterator & operator--();
        /**
         * @brief Sobrecarga del operador de comparación.
         * @param it
         * @return true si son iguales, false si no.
         */
        bool operator==(const iterator & it);
        /**
         * @brief Sobrecarga del operador de comparación.
         * @param it
         * @return false si son iguales, true si no.
         */
        bool operator!=(const iterator & it);
        /**
         * @brief Sobrecarga del operador de asignación. Iguala la posición de un iterador a la de otro.
         * @param it
         * @return iterator referencia a this.
         */
        iterator & operator=(const iterator & it);

    private:
        friend class conjunto<CMP>;
        vector<entrada>::iterator itv;
        conjunto<CMP> *puntero;
    };

    /** @brief  
     @return Devuelve el const_iterator a la primera posición del conjunto.
    @post no modifica el diccionario
     */

    const_iterator cbegin();
    /** @brief iterador al final
     @return Devuelve el iterador constante a la  posición final del conjunto.
    @post no modifica el diccionario
     */
    const_iterator cend();

    /** @brief class const_iterator
     * forward iterador constante sobre el diccionario, Lectura 
     *  const_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
     * */
    class const_iterator {
    public:
        /**
         * @brief Constructor por defecto
         */
        const_iterator();
        /**
         * @brief Constructor de copia.
         * @param it
         */
        const_iterator(const const_iterator & it);
        /** @brief Convierte iterator en const_iterator
         */
        const_iterator(const iterator & it);
        /**
         * @brief Sobrecarga del puntero, devuelve un crimen
         * @return conjunto<CMP>::entrada
         */
        const conjunto<CMP>::entrada & operator*() const;

        /**
         * Sobrecarga del operador +. Aumenta la posición del iterador en i posiciones.
         * @param i
         * @return const_iterator Referencia al iterador
         */
        const_iterator & operator+(int i);
        /**
         * @brief Sobrecarga del operador ++ para ++it; Aumenta la posición del iterador en 1.
         * @param
         * @return const_iterator Referencia al iterador
         */
        const_iterator operator++(int);
        /**
         * @brief Sobrecarga del operador ++ para it++; Aumenta la posición del iterador en 1.
         * @return const_iterator Referencia al iterador
         */
        const_iterator & operator++();
        /**
         * @brief Sobrecarga del operador -. Disminuye el iterador en i posiciones.
         * @param i Posiciones a disminuir
         * @return const_iterator Referencia al iterador
         */
        const_iterator & operator-(int i);
        /**
         * @brief Sobrecarga del operador -- para --it; Disminuye el iterador en una posición.
         * @param
         * @return const_iterator Referencia al iterador
         */
        const_iterator operator--(int);
        /**
         * @brief Sobrecarga del operador -- para it--; Disminuye el iterador en una posición.
         * @return const_iterator Referencia al iterador
         */
        const_iterator & operator--();
        /**
         * @brief Sobrecarga del operador de comparación.
         * @param it
         * @return true si son iguales, false si no.
         */
        bool operator==(const const_iterator & it);
        /**
         * @brief Sobrecarga del operador de comparación.
         * @param it
         * @return false si son iguales, true si no.
         */
        bool operator!=(const const_iterator & it);
        /**
         * @brief Sobrecarga del operador de asignación. Iguala la posición de un iterador a la de otro.
         * @param it
         * @return const_iterator referencia a this.
         */
        const_iterator & operator=(const const_iterator & it);
    private:

        vector<entrada>::const_iterator c_itv;
        friend class conjunto<CMP>;
        conjunto<CMP> * punt_const;
    };


private:
    vector<crimen> vc; // vector ORDENADO por crimen.id que almacena los elementos del conjunto
    CMP comp;
    /** \invariant
 
    IR: rep ==> bool
 
   \li Para todo i, 0 <= i < vc.size() se cumple
           vc[i].ID > 0;
   \li Para todo i, 0 <= i <= D.dic.size()-1 se cumple
           vc[i].ID< vc[i+1].ID

     */


    /** @brief Chequea el Invariante de la representacion 
        @return true si el invariante es correcto, falso en caso contrario
     */
    bool cheq_rep() const;

    //  declaracion del operator<< como metodo amigo
    friend ostream & operator<<(ostream & sal, const conjunto<CMP> & D);

    // Clases amigas  ....
    friend class iterator;
    friend class const_iterator;



};


/** @brief imprime todas las entradas del conjunto 
@post  No se modifica el conjunto.
 */
template <class CMP>
ostream & operator<<(ostream & sal, const conjunto<CMP> & D);

#include "conjunto.hxx"

#endif
