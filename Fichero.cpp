/* 
 * File:   Fichero.cpp
 * Author: Juan Carlos Castillo Alcántara / Ismael Luque Cañada
 */

#include "Fichero.h"

Fichero::Fichero() {
    nombre="";
    ubicacion="";
    tamBytes=0;
}



// Funciones Set
void Fichero::SetTamBytes(int tamBytes) {
    this->tamBytes = tamBytes;
}
void Fichero::SetUbicacion(string ubicacion) {
    this->ubicacion = ubicacion;
}
void Fichero::SetNombre(string nombre) {
    this->nombre = nombre;
}


// Funciones Get
int Fichero::GetTamBytes() const {
    return tamBytes;
}
string Fichero::GetUbicacion() const {
    return ubicacion;
}
string Fichero::GetNombre() const {
    return nombre;
}

void Fichero::muestraFcihero() {
    cout << "Nombre del fichero: " << this->GetNombre() << endl;
    cout << "Ubicación del fichero: " << this->GetUbicacion() << endl;
    cout << "Tamaño en bytes: " << this->GetTamBytes() << endl;
    cout << " " << endl;
}
