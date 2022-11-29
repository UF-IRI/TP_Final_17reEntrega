#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include "structs.h"
using namespace std;

//leer archivos
bool abrirPaciente(string path, Paciente *&array, int N, int cantidad_aumentar);
bool abrirContacto(string path, Contacto *&ArrContacto, int N, int cantidad_aumentar);
bool abrirConsultas(string path, Consultas *&ArrConsultas, int N, int cantidad_aumentar);
bool abrirMedico(string path, Medico *&ArrMed, int N, int cantidad_aumentar);

void resizePac(Paciente *&array, int &N, int cantidad_aumentar); 
void resizeCont(Contacto *&array, int &N, int cantidad_aumentar); 
void resizeCons(Consultas *&array, int &N, int cantidad_aumentar); 
void resizeMed(Medico *&array, int &N, int cantidad_aumentar); 

//crear lista grande --> unificar falta terminar
void unificar(Paciente *&array, Contacto *&ArrContacto, Consultas *&ArrConsultas, Medico *&ArrMed, int N);
void copiarConsMed(Consultas*& ArrConsultas, int i, Medico*& ArrMed, int j);
void copiarPacCons(Paciente*& array, int i, Consultas*& ArrConsultas, int j, double max);
void copiarPacCont(Paciente *&array, int i, Contacto *&ArrContacto, int j);

int Contactar();
bool crearSalida(string path, fstream fp);
bool creoListas(Paciente *&array, int N); //falta sacar la excepcion

#endif

    