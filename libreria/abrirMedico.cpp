#include "funciones.h"
    
bool abrirMedico(string path, Medico *&ArrMed, int &N, int cantidad_aumentar){
    if(ArrMed == nullptr){
        return false;
    }

    fstream med;
    med.open(path, ios::in);
    
    if (!(med.is_open())){
      cout<< "no se abrio el archivo" <<endl;
            return false;
    }
    else
        cout<< "se abrio el archivo" << endl;

    int i = 0;
    string dummy;
    char coma;

    getline(med, dummy); //leo el header

    while(med){
        if(i==N-1){
                resizeMed(ArrMed, N, cantidad_aumentar); 
        }
        getline(med,ArrMed[i].matricula, ',' ); 
        getline(med,ArrMed[i].nombre, ',' ); 
        getline(med,ArrMed[i].apellido, ',' ); 
        getline(med,ArrMed[i].telefono, ',' ); 
        getline(med,ArrMed[i].especialidad, ',' ); 
        med >> ArrMed[i].activo;
        i++;

    }

    med.close();
    return true;

}
}