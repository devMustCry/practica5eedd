/* 
 * File:   Commit.cpp
 * Author: Juan Carlos Castillo Alcántara / Ismael Luque Cañada
 */

#include "Commit.h"

Commit::Commit():marcaDeTiempo(){
    codigo="";
    mensaje="";
}


Commit::~Commit() {
    ficherosModificados.clear();
}


void Commit::insertaModificado(Fichero *f){
    ficherosModificados.push_back(f);
}


vector<Fichero*> Commit::getFicheros(){
    vector<Fichero*> vmod;
    list<Fichero*>::iterator it=ficherosModificados.begin();
    while(it!=ficherosModificados.end()){
        vmod.push_back((*it));
        it++;
    }
       
    return vmod;
}

bool Commit::tieneFichero(string nombre) {
    list<Fichero*>::iterator it=ficherosModificados.begin();
    while(it!=ficherosModificados.end()){
        if((*it)->GetNombre() == nombre){
            return true;
        }
        it++;
    }
    return false;
}

bool Commit::borraFichero(string nombre) {
    list<Fichero*>::iterator it=ficherosModificados.begin();
    while(it!=ficherosModificados.end()){
        if((*it)->GetNombre()==nombre){
            ficherosModificados.erase(it);
            return true;
        }
        it++;
    }
    return false;
}

unsigned int Commit::numFicheros() {
    return ficherosModificados.size();
}
void Commit::muestraCommit() {
    cout << "Codigo del commit: " << this->GetCodigo() << endl;
    cout << "Fecha de ultima mod: " << this->GetMarcaDeTiempo().verDia() << "/" << this->GetMarcaDeTiempo().verMes();
    cout << "/" << this->GetMarcaDeTiempo().verAnio() << "-" << this->GetMarcaDeTiempo().verHora() << ":" << this->GetMarcaDeTiempo().verMin() << endl;
    cout << "Mensaje del commit: " << this->GetMensaje() << endl;
    cout << " " << endl;
   
}



void Commit::SetMensaje(string mensaje) {
    this->mensaje = mensaje;
}
string Commit::GetMensaje() const {
    return mensaje;
}


void Commit::SetMarcaDeTiempo(Fecha marcaDeTiempo) {
    this->marcaDeTiempo = marcaDeTiempo;
}
Fecha Commit::GetMarcaDeTiempo() const {
    return marcaDeTiempo;
}


void Commit::SetCodigo(string codigo) {
    this->codigo = codigo;
}
string Commit::GetCodigo() const {
    return codigo;
}


void Commit::setFicherosModificados(list<Fichero*> ficherosModificados) {
    this->ficherosModificados = ficherosModificados;
}
list<Fichero*> Commit::getFicherosModificados() const{
    return ficherosModificados;
}
