#include "iri.cpp"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include "structs.h"
#include "funciones.h"

using namespace std;


int main() {

    int N=20;
    int i = 0;
    int cantidad_aumentar = 5;

    //pacientes
    Paciente *array = new Paciente[N];
    string pathPac = "Pacientes.csv";

    bool check = abrirPaciente(pathPac, array, N, cantidad_aumentar);
    if(!(check)){
        cout<<"no se pudo abrir y crear la lista";
    }

    //contactos
    Contacto *ArrContacto = new Contacto[N];
    string pathCont = "Contactos.csv";

    check = abrirContacto(pathCont, ArrContacto, N, cantidad_aumentar);
    if(!(check)){
        cout<<"no se pudo abrir y crear la lista";
    }

    //consultas
    Consultas *ArrConsultas = new Consultas[N];
    string pathCons = "Consultas.csv";

    check = abrirConsultas(pathCons, ArrConsultas, N, cantidad_aumentar);
    if(!(check)){
        cout<<"no se pudo abrir y crear la lista";
    }

    //medicos
    Medico *ArrMed = new Medico[N];
    string pathMed = "Medicos.csv";

    check = abrirMedico(pathMed, ArrMed, N, cantidad_aumentar);
    if(!(check)){
        cout<<"no se pudo abrir y crear la lista";
    }





    return EXIT_SUCCESS;
}
