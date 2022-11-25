#include "funciones.h"

bool abrirPaciente(string path, Paciente *&array, int &N, int cantidad_aumentar){
    if( array == nullptr){
        return false;
    }

    fstream pac;
    pac.open(path, ios::in);
    
    if (!(pac.is_open())){
      cout<< "no se abrio el archivo" <<endl;
            return false;
    }
    else
        cout<< "se abrio el archivo" << endl;

    int i = 0;
    string dummy;
    char coma;

    getline(pac, dummy); //leo el header

    while(pac){
        if(i==N-1){
                resizePac(array, N, cantidad_aumentar); 
        }
        pac >> array[i].DNI >> coma;
        getline(pac,array[i].nombre, ',' ); 
        getline(pac,array[i].apellido, ',' ); 
        getline(pac,array[i].sexo, ',' ); 
        getline(pac,array[i].natalicio, ',' ); 
        getline(pac,array[i].estado, ',' ); 
        getline(pac,array[i].id_os); 
        i++;

    }

    pac.close();
    return true;

}