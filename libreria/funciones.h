#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include "structs.h"
using namespace std;

bool abrirPaciente(string path, Paciente *&array, int &N, int cantidad_aumentar);
bool abrirContacto(string path, Contacto *&ArrContacto, int &N, int cantidad_aumentar);

void resizePac(Paciente *&array, int &N, int cantidad_aumentar); 
void resizeCont(Contacto *&array, int &N, int cantidad_aumentar); 

#endif