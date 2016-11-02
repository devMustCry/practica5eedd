/* 
 * File:   Excepciones.h
 * Author: Juan Carlos Castillo Alcántara / Ismael Luque Cañada
 */

#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>
using namespace std;

class Excepciones:public exception {
public:
    const char* errorVector() const throw(){
        return "\nError: Posición del array fuera de rango";
    }
    
    const char* errorCodigo() const throw(){
        return "\nEl código no pertenece a ningún commit";
    }
    
    const char* errorFechas() const throw(){
        return "\nNo se han realizado commits en ese periodo de tiempo";
    }
    
    const char* errorBuscaFichero() const throw(){
        return "\nNo existe el fichero";
    }
};


#endif /* EXCEPCIONES_H */

