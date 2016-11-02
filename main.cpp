/* 
 * File:   main.cpp
 * Author: Juan Carlos Castillo Alcántara / Ismael Luque Cañada
 */

#include "Fichero.h"
#include "Commit.h"
#include "fecha.h"
#include "GitCode.h"
#include "Excepciones.h"
#include <list>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;



int main() {
    
    GitCode git("ficheros2.txt","commits.txt");
     
    
    /************************************************************************************************/
    //Dado el codigo de un commit, mostrar por pantalla su información
    try{
        string cod="4ri1dx4h";
        cout << "Buscamos el commit con codigo: " << cod << endl;
    
        Commit a=git.getCommit(cod);
    
        //Mostramos la información del commit por pantalla
        a.muestraCommit();
    }catch(Excepciones &e){
        cout << e.errorCodigo() << endl;
    }
    
    
    
    /*******************************************************************************/
    //Mostrar los commits realizados entre dos fechas dadas
    
    //Introducimos los datos de la priemra fecha
    try{
        unsigned int dia,mes,anio,hora,minuto;
        dia=21;
        mes=3;
        anio=1997;
        hora=20;
        minuto=30;   

        //Introducimos los datos de la segunda fecha
        unsigned int dia2,mes2,anio2,hora2,minuto2;
        dia2=12;
        mes2=12;
        anio2=1999;
        hora2=13;
        minuto2=15;

        try{
            Fecha f1(dia,mes,anio,hora,minuto);
            Fecha f2(dia2,mes2,anio2,hora2,minuto2);
            
            cout << "*********************************************************************************" << endl;
            cout << "Buscamos los commits entre las fechas " << dia << "/" << mes << "/" << anio << " y " << dia2 << "/" << mes2 << "/" << anio2 << endl;


            vector<Commit> vfechas=git.getCommFechas(f1,f2);

            //Mostramos por pantalla el vector con los commits realizados en ese período
            git.mostrarCommits(vfechas);
            
        }catch(Excepciones &e){
            cout << e.errorFechas();
        }   
        
    }catch(ErrorFechaIncorrecta &e){
        cout << e.what();
    }
    
        
    
    /****************************************************************************************/
    //Dado el nombre de un fichero mostrar todos los commits en los que ha sido modificado
    try{
        string nom="casaque";
        cout << "*********************************************************************************" << endl;
        cout << "El fichero " << nom << " ha sido modificado en los commits: " << endl;

        vector<Commit> vmod=git.getCommFichero(nom);

        git.mostrarCommits(vmod);
        
    }catch(Excepciones &e){
        cout << e.errorBuscaFichero();
    }
    
    return 0;
}

