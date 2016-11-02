/* 
 * File:   GitCode.cpp
 * Author: Juan Carlos Castillo Alcántara / Ismael Luque Cañada
 */

#include "GitCode.h"

GitCode::GitCode(string aFich,string aCommit):fileFichero(aFich),fileCommits(aCommit){
    cargaFicheros();
    cargaCommits();
}

GitCode::~GitCode() {
    ficheros.clear();
    commits.clear();
}

void GitCode::cargaFicheros(){
    Fichero fich;
    string lineaActual;
        try{
            ifstream inputStream;
            inputStream.exceptions(ifstream::failbit | ifstream::badbit);
            inputStream.open(fileFichero);
            // Extraemos la cabecera del fichero
            inputStream >> lineaActual;

            while (!inputStream.eof()) {
                inputStream >> lineaActual;
                // Parseamos la linea
                auto pos = lineaActual.find(';');
                auto ruta = lineaActual.substr(0, pos);
                auto tama = lineaActual.substr(pos + 1, lineaActual.length());
                // Separamos la ubicacion del nombre del fichero
                pos = ruta.find_last_of('/');
                auto fubicacion = ruta.substr(0, pos + 1);
                auto fnombre = ruta.substr(pos + 1, ruta.length());
                // Convertimos el string a int
                auto ftamaBytes = std::stoi(tama);

                //Modificamos los atributos del objeto Fichero con los obtenidos en la linea
                fich.SetNombre(fnombre);
                fich.SetUbicacion(fubicacion);
                fich.SetTamBytes(ftamaBytes);
                
                //Metemos el objeto Fichero en la lista doblemente enlazada
                ficheros.push_back(fich);

                }
                inputStream.close();
            }
        catch (ifstream::failure &e){
            cerr << "Excepcion leyendo de fichero: " << e.what() << endl;
        }
}

void GitCode::cargaCommits(){
    string cadena;
    try{
        ifstream ficheroCommit;
        ficheroCommit.exceptions(ifstream::failbit | ifstream::badbit);
        ficheroCommit.open(fileCommits);

        while (!ficheroCommit.eof()) {
            Commit com;
            Fecha a;
            //Leemos la línea
            getline(ficheroCommit,cadena);

            // Parseamos la linea separándola por los ';'
            auto pos = cadena.find(';');
            //fcodigo modificará el atributo codigo del obejto Commit
            auto fcodigo = cadena.substr(0, pos);

            //fmarca modificará el atributo marcaDeTiempo del objeto Commit
            auto fmarca = cadena.substr(pos+1, cadena.length());
            auto pos2 = fmarca.find(';');
            fmarca = fmarca.substr(0,pos2);
            
            
            //fmensaje modificará el atributo mensaje del objeto Commit
            auto fmensaje=cadena.substr((pos+1)+(pos2+1), cadena.length());
            auto pos3 = fmensaje.find(';');
            fmensaje=fmensaje.substr(0,pos3);



            //Parseamos la parte de la línea donde se encuentran las posiciones del vector de ficheros separadas por comas
            pos=(pos+1)+(pos2+1)+(pos3+1);
            auto files = cadena.substr(pos, cadena.length());
            //Utilizamos s para evitar pasarnos del final de la línea
            int s=0;
            auto coma=0;
            
            
            vector<Fichero*> vficheros;
            vector<Fichero>::iterator it=ficheros.begin();
            while(it!=ficheros.end()){
                Fichero* pFich=&(*it);
                vficheros.push_back(pFich);
                it++;
            }
            
            while(s<files.length()&& coma!=-1){
                coma=files.find(',');
                //Indice alamacena posiciones del vector de ficheros
                auto indice=files.substr(0,coma);
                //Substring para coger lo que nos queda de línea
                files=files.substr(coma+1,files.length());

                //Pasamos el indice a entero
                int x=std::stoi(indice);
                
                com.insertaModificado(vficheros[x-1]);
            }

            //Recorremos fmarca para convertirla a tipo Fecha
            auto fanio=fmarca.substr(0,4);
            int _anio=std::stoi(fanio);
            
            
            auto fmes=fmarca.substr(4,2);
            int _mes=std::stoi(fmes);
            
            
            auto fdia=fmarca.substr(6,2);
            int _dia=std::stoi(fdia);
            
            
            auto fhora=fmarca.substr(8,2);
            int _hora=std::stoi(fhora);
            
            
            auto fminuto=fmarca.substr(10,2);
            int _minuto=std::stoi(fminuto);
            
            
            a.asignarDia(_dia,_mes,_anio);
            a.asignarHora(_hora,_minuto);
            

            //Modificamos los atributos del objeto Commit con los obtenidos en la linea
            com.SetCodigo(fcodigo);
            com.SetMarcaDeTiempo(a);
            com.SetMensaje(fmensaje);


            //Metemos el objeto Commit en la lista doblemente enlazada de commits
            commits.push_back(com);

        }

        ficheroCommit.close();


    }catch (ifstream::failure &e){
        cerr << "Excepcion leyendo de fichero: " << e.what() << endl;
    }
}

//Función que dado un código de un commit devuelva este si existe
Commit GitCode::getCommit(string code){
    list<Commit>::iterator it=commits.begin();
    while(it!=commits.end()){
        if((*it).GetCodigo()==code){
            return (*it);
        }
        it++;
    }
    throw Excepciones();
}

//Función que dadas dos fechas nos devuelva un vector con los commits realizados en ese período
vector<Commit> GitCode::getCommFechas(Fecha f1, Fecha f2){
    vector<Commit> vfechas;
    
    list<Commit>::iterator it=commits.begin();
    while(it!=commits.end()){
        if(f1<(*it).GetMarcaDeTiempo() && (*it).GetMarcaDeTiempo()<f2){
            vfechas.push_back((*it));
        }
        it++;
    }
    
    if(vfechas.size()==0) throw Excepciones();
    
    return vfechas;
    
}


//Función que dado el nombre de un fichero nos devuelva un vector con los commits en los que se ha modificado
vector<Commit> GitCode::getCommFichero(string nombre){
    vector<Commit> vmod;
    list<Commit>::iterator it=commits.begin();
    while(it!=commits.end()){
        if((*it).tieneFichero(nombre)){
            vmod.push_back((*it));
        }
        it++;
    }
    if(vmod.size()==0) throw Excepciones();
            
    return vmod;
}


//Función que dado el nombre de un fichero lo borre del sistema
void GitCode::eliminaFichero(string nombre){
    list<Commit>::iterator it=commits.begin();
    while(it!=commits.end()){
        if((*it).borraFichero(nombre)){
            if((*it).numFicheros()==0){
                commits.erase(it);
            }
        }
        it++;
    }
}

void GitCode::mostrarFicheros(vector<Fichero>& vficheros) {
    for(unsigned int i=0;i<vficheros.size();i++){
        Fichero a=vficheros[i];
        a.muestraFcihero();
    }
} 

void GitCode::mostrarCommits(vector<Commit>& vcommits) {
    for(unsigned int i=0;i<vcommits.size();i++){
        Commit a=vcommits[i];
        a.muestraCommit();       
    }
}

