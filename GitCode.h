/* 
 * File:   GitCode.h
 * Author: Juan Carlos Castillo Alcántara / Ismael Luque Cañada
 */

#ifndef GITCODE_H
#define GITCODE_H

#include "fecha.h"
#include "Fichero.h"
#include "Commit.h"
#include "Excepciones.h"
#include <string>
#include <exception>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class GitCode {
private:
    string fileFichero;
    string fileCommits;
    vector<Fichero> ficheros;
    list<Commit> commits;
public:
    GitCode(string aFich="ficheros2.txt",string aCommit="commits.txt");
    virtual ~GitCode();
    
    //Funciones para cargar los ficheros dentro de las listas 
    void cargaFicheros();
    void cargaCommits();

    
    Commit getCommit(string code);
    vector<Commit> getCommFechas(Fecha f1, Fecha f2);
    vector<Commit> getCommFichero(string nombre);
    void eliminaFichero(string nombre);
    
    //Función para mostrar por pantalla la lista de ficheros
    void mostrarFicheros(vector<Fichero> &vficheros);
    
    //Función para mostrar por pantalla la lista de commits
    void mostrarCommits(vector<Commit> &vcommits);
    
};

#endif /* GITCODE_H */

