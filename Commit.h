/* 
 * File:   Commit.h
 * Author: Juan Carlos Castillo Alcántara / Ismael Luque Cañada
 */

#ifndef COMMIT_H
#define COMMIT_H


#include "Fichero.h"
#include "fecha.h"
#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Commit {
private:
    string codigo;
    Fecha marcaDeTiempo;
    string mensaje;
    list<Fichero*> ficherosModificados;
    
public:
    Commit();
    Commit(const Commit &c)
            :codigo(c.codigo)
            ,marcaDeTiempo(c.marcaDeTiempo)
            ,mensaje(c.mensaje)
            ,ficherosModificados(c.ficherosModificados){}
    ~Commit();
    
    //Inserta un fichero en la lista ficherosModificados
    void insertaModificado(Fichero *f);
    
    //Devuelve un vector de punteros a los ficheros de la lista ficherosModificados
    vector<Fichero*> getFicheros();
    
    //Comprueba si el fichero nombre existe en la lista ficherosModificados
    bool tieneFichero(string nombre);
    
    //Borra un el fichero nombre de la lista ficherosModificados
    bool borraFichero(string nombre);
    
    //Devuelve el tamaño de la lista ficherosModificados
    unsigned int numFicheros();
    
    //Muestra por pantalla la información de un commit
    void muestraCommit();
    
    void SetMensaje(string mensaje);
    string GetMensaje() const;
    
    void SetMarcaDeTiempo(Fecha marcaDeTiempo);
    Fecha GetMarcaDeTiempo() const;
    
    void SetCodigo(string codigo);
    string GetCodigo() const;
    
    void setFicherosModificados(list<Fichero*> ficherosModificados);
    list<Fichero*> getFicherosModificados() const;
    
    

};

#endif /* COMMIT_H */

