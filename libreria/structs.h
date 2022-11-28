#ifndef STRUCTS_H
#define STRUCTS_H
#include <string>
#include <ctime>
using namespace std;

typedef struct{
    string matricula;
    string nombre;
    string apellido;
    string telefono;
    string especialidad;
    bool activo;
} Medico;

typedef struct {
    string DNI;
    tm fecha_solicitado;
    tm fecha_turno;
    bool presento;
    Medico medico; //conectado a traves de matricula 
    bool TieneMed;
} Consultas;

typedef struct{
    string DNI;
    string telefono;
    string celular;
    string direccion;
    string mail;
} Contacto;

typedef struct {
    string DNI;
    string nombre;
    string apellido;
    string sexo;
    string natalicio;
    string estado;
    string id_os;
    Contacto contacto;
    Consultas UltimaConsulta; 
    string archivado;
    bool TieneCons;
    bool TieneCont;
    bool TieneMed_enPac;
} Paciente;

#endif