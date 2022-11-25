#include "funciones.h"

bool abrirContacto(string path, Contacto *&ArrContacto, int &N, int cantidad_aumentar){
    if(ArrContacto == nullptr){
        return false;
    }

    fstream cont;
    cont.open(path, ios::in);
    
    if (!(cont.is_open())){
      cout<< "no se abrio el archivo" <<endl;
            return false;
    }
    else
        cout<< "se abrio el archivo" << endl;

    int i = 0;
    string dummy;
    char coma;

    getline(cont, dummy); //leo el header

    while(cont){
        if(i==N-1){
                resizeCont(ArrContacto, N, cantidad_aumentar); 
        }
       cont >> ArrContacto[i].DNI >> coma;
       getline(cont,ArrContacto[i].telefono, ',' ); 
       getline(cont,ArrContacto[i].celular , ',' ); 
       getline(cont,ArrContacto[i].direccion, ',' ); 
       getline(cont,ArrContacto[i].mail); 
       i++;

    }

    cont.close();
    return true;

}

