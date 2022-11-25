#include "funciones.h"

bool abrirConsultas(string path, Consultas *&ArrConsultas, int &N, int cantidad_aumentar){
     if(ArrConsultas == nullptr){
        return false;
    }

    fstream cons;
    cons.open(path, ios::in);

     if (!(cons.is_open())){
      cout<< "no se abrio el archivo" <<endl;
            return false;
    }
    else
        cout<< "se abrio el archivo" << endl;

    int i = 0;
    string dummy;
    char coma;
    string auxSoli_dia, auxSoli_mes, auxSoli_year;
    string auxTurno_dia, auxTurno_mes, auxTurno_year;
    


    getline(cons, dummy); //leo el header
    
    while(cons){
        if(i==N-1){
                resizeCons(ArrConsultas, N, cantidad_aumentar); 
        }
    cons >> ArrConsultas[i].DNI >> coma;
    getline(cons,auxSoli_dia, '/' ); 
    getline(cons,auxSoli_mes, '/' ); 
    getline(cons,auxSoli_year, ','); 
    getline(cons,auxTurno_dia, '/' ); 
    getline(cons,auxTurno_mes, '/' ); 
    getline(cons,auxTurno_year, ','); 
    cons >> ArrConsultas[i].presento >> coma;
    getline(cons,ArrConsultas[i].medico.matricula); 

    ArrConsultas[i].fecha_solicitado.tm_mday = stod(auxSoli_dia);
    ArrConsultas[i].fecha_solicitado.tm_mon = stod(auxSoli_mes);
    ArrConsultas[i].fecha_solicitado.tm_year = stod(auxSoli_year);

    ArrConsultas[i].fecha_turno.tm_mday = stod(auxTurno_dia);
    ArrConsultas[i].fecha_turno.tm_mon = stod(auxTurno_mes);
    ArrConsultas[i].fecha_turno.tm_year = stod(auxTurno_year);
    i++;

    }

    cons.close();
    return true;

}