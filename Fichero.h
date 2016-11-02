/* 
 * File:   Fichero.h
 * Author: Juan Carlos Castillo Alcántara / Ismael Luque Cañada
 */

#ifndef FICHERO_H
#define FICHERO_H

#include <string>
#include <iostream>
using namespace std;

class Fichero {
private:
    string nombre;
    string ubicacion;
    int tamBytes;
public:
    Fichero();
    
    Fichero(const Fichero &f)
            :nombre(f.nombre)
            ,ubicacion(f.ubicacion)
            ,tamBytes(f.tamBytes){}
    
    void SetTamBytes(int tamBytes);
    void SetUbicacion(string ubicacion);
    void SetNombre(string nombre);
    
    int GetTamBytes() const;
    string GetUbicacion() const;
    string GetNombre() const;
    
    //Muestra por pantalla la información de un objeto Fichero
    void muestraFcihero();

};


#endif /* FICHERO_H */