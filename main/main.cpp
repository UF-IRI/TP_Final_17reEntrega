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

    //fstream cons,cont,med
    //string dummy;
    //string coma;
    int N=20;
    int i = 0;
    int cantidad_aumentar = 5;

    Paciente *array = new Paciente[N];
    string pathPac = "Pacientes.csv";

    bool check = abrirPaciente(pathPac, array, N, cantidad_aumentar);
    if(!(check)){
        cout<<"no se pudo abrir y crear la lista";
    }

    Contacto *ArrContacto = new Contacto[N];
    string pathCont = "Contactos.csv";

    check = abrirContacto(pathCont, ArrContacto, N, cantidad_aumentar);
    if(!(check)){
        cout<<"no se pudo abrir y crear la lista";
    }



    return EXIT_SUCCESS;
}
