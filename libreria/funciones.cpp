#include "funciones.h"

bool abrirPaciente(string path, Paciente *&array, int &N, int cantidad_aumentar){
    if(array == nullptr){
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
       getline(cont,ArrContacto[i].DNI, ',' ); 
       getline(cont,ArrContacto[i].telefono, ',' ); 
       getline(cont,ArrContacto[i].celular , ',' ); 
       getline(cont,ArrContacto[i].direccion, ',' ); 
       getline(cont,ArrContacto[i].mail); 
       i++;

    }

    cont.close();
    return true;

}

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



void resizePac(Paciente *&array, int &N, int cantidad_aumentar) 
{
    if(array == nullptr){
        cout<<"Error"<<endl;
        return;
    }
    N = N + cantidad_aumentar;
	int i = 0;
	Paciente *aux = new Paciente[N];
	while (i < N - cantidad_aumentar){
        aux[i] = array[i];
		i++;
    }

    delete[] array;
	array = aux;
	return;
}

void resizeCont(Contacto *&array, int &N, int cantidad_aumentar) 
{
    if(array == nullptr){
        cout<<"Error"<<endl;
        return;
    }

    N = N + cantidad_aumentar;
	int i = 0;
	Contacto *aux = new Contacto[N];
	while (i < N - cantidad_aumentar){
        aux[i] = array[i];
		i++;
    }

    delete[] array;
	array = aux;
	return;
		
}

void resizeCons(Consultas *&array, int &N, int cantidad_aumentar) 
{
    if(array == nullptr){
        cout<<"Error"<<endl;
        return;
    }

    N = N + cantidad_aumentar;
	int i = 0;
	Consultas *aux = new Consultas[N];
	while (i < N - cantidad_aumentar){
        aux[i] = array[i];
		i++;
    }

    delete[] array;
	array = aux;
	return;
}

void resizeMed(Medico *&array, int &N, int cantidad_aumentar) 
{
    N = N + cantidad_aumentar;
	int i = 0;
	Medico *aux = new Medico[N];
	while (i < N - cantidad_aumentar){
        aux[i] = array[i];
		i++;
    }

    delete[] array;
	array = aux;
	return;
}


void copiarConsMed(Consultas*& ArrConsultas, int &i, Medico*& ArrMed, int &j)
{
	ArrConsultas[i].medico.activo = ArrMed[j].activo;
	ArrConsultas[i].medico.apellido = ArrMed[j].apellido;
	ArrConsultas[i].medico.especialidad = ArrMed[j].especialidad;
	ArrConsultas[i].medico.matricula = ArrMed[j].matricula;
	ArrConsultas[i].medico.nombre = ArrMed[j].nombre;
	ArrConsultas[i].medico.telefono = ArrMed[j].telefono;
	return;
}

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

    //double max = 0.00;


}


int Contactar()
 {
    int aux;
    //cout << "Cual fue la respuesta del paciente?" << endl; //la respuesta la hace un random
    aux = rand()% (4-1) + 1;
   //cout << "Respuesta del paciente:" << aux << endl;
    return aux;
 }



 bool creoListas(Paciente *&array, int &N){
    
    int i = 0;
    if(array == nullptr){
        cout<<"Error"<<endl;
        return false;
    }

    time_t now;
    time(&now);
    int diferencia;

    double fecha = 0.00; //no hace falta inicializar
    fecha = array[i].UltimaConsulta.fecha_turno.tm_year * 10000 + array[i].UltimaConsulta.fecha_turno.tm_mon *100 + array[i].UltimaConsulta.fecha_turno.tm_mday;

    for(i=0; i<N; i++){
       diferencia = difftime(now,fecha); //calculo de los años
       
       if(array[i].estado == "fallecido" || diferencia >= 10){ //si esta muerto o pasaron mas de 10 años
            if(array[i].TieneCons == true &&  array[i].TieneCont == true && array[i].TieneMed_enPac == true){
            //imprimir en el archivo de archivados
            }
       }

       else if (array[i].estado == "internado" || fecha >= now){ //si esta internado o tiene un turno a futuro
            if(array[i].TieneCons == true &&  array[i].TieneCont == true && array[i].TieneMed_enPac == true){
            //imprimir en el archivo de activos
            }
       }

       else
            if (array[i].TieneCons == true &&  array[i].TieneCont == true && array[i].TieneMed_enPac == true){ //los que tenemos que contactar
            int answer = Contactar();
            
            switch(answer){
                case 1: //muerto
                    //imprimir en el archivo de archivados
                    break;

                case 2: //not back
                    //imprimir en el archivo de archivados
                    break;

                case 3: //quiere volver
                    //imprimir en el archivo de activos
                    break;

                case 4: //not found
                    //imprimir en el archivo de no encontrados
                    break;

                default:
                    cout<<"ERROR al contactar"<<endl;
                    break;
            }

        }

    }

    return true;

}