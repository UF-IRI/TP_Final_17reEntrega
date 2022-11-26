#include "funciones.h"

void unificar(Paciente *&array, Contacto *&ArrContacto, Consultas *&ArrConsultas, Medico *&ArrMed, int &N){

    int i, j;
    ArrConsultas[i].TieneMed = false;
    array[i].TieneCont = false;
    array[i].TieneCons = false;

    for (i = 0; i < N; i++) { //recorre Consulta
        for (j = 0; j < N; j++) { //recorre medicos
            if (ArrConsultas[i].medico.matricula == ArrMed[j].matricula) 
            {
                copiarConsMed(ArrConsultas, i, ArrMed, j);
                ArrConsultas[i].TieneMed = true;
            }
        }
    }

}