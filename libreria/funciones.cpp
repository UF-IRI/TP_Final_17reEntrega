#include "funciones.h"



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
     if(array == nullptr){
        cout<<"Error"<<endl;
        return;
    }

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


bool abrirPaciente(string path, Paciente *&array, int N, int cantidad_aumentar){
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
        cout << "se abrio el archivo" << endl;

    int i = 0;
    string dummy;
    char coma;

    getline(pac, dummy); //leo el header

    while(pac){
        if(i==N-1){
                resizePac(array, N, cantidad_aumentar); 
        }
        pac >> array[i].DNI >> coma;
        pac >> array[i].nombre >> coma;
        pac >> array[i].apellido >> coma;
        pac >> array[i].sexo >> coma;
        pac >> array[i].natalicio >> coma;
        pac >> array[i].estado >> coma;
        getline(pac,array[i].id_os); 
        i++;

    }

    pac.close();
    return true;

}

bool abrirContacto(string path, Contacto *&ArrContacto, int N, int cantidad_aumentar){
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
        cout << "se abrio el archivo" << endl;

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

bool abrirConsultas(string path, Consultas *&ArrConsultas, int N, int cantidad_aumentar){
     if(ArrConsultas == nullptr){
        return false;
    }

    fstream cons;
    cons.open(path, ios::in);

     if (!(cons.is_open())){
      cout << "no se abrio el archivo" <<endl;
            return false;
    }
    else
        cout << "se abrio el archivo" << endl;

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

bool abrirMedico(string path, Medico *&ArrMed, int N, int cantidad_aumentar){
    if(ArrMed == nullptr){
        return false;
    }

    fstream med;
    med.open(path, ios::in);
    
    if (!(med.is_open())){
      cout << "no se abrio el archivo" <<endl;
            return false;
    }
    else
        cout << "se abrio el archivo" << endl;

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


void copiarConsMed(Consultas*& ArrConsultas, int i, Medico*& ArrMed, int j) //no es necesario hacer una funcion para esto, pero al hacerla le podemos hacer un unit-test para verificar que funcione
{
	if(ArrMed == nullptr || ArrConsultas == nullptr){
        cout<<"Error"<<endl;
        return;
    }
    ArrConsultas[i].medico = ArrMed[j];
	return;
}

void copiarPacCons(Paciente*& array, int i, Consultas*& ArrConsultas, int j, double &max) //no es necesario hacer una funcion para esto, pero al hacerla le podemos hacer un unit-test para verificar que funcione
{
    if(array == nullptr || ArrConsultas == nullptr){
        cout<<"Error"<<endl;
        return;
    }

    double aux = ArrConsultas[j].fecha_turno.tm_year * 10000 + ArrConsultas[j].fecha_turno.tm_mon *100 + ArrConsultas[j].fecha_turno.tm_mday;
    if (aux > max)
    {

      array[i].UltimaConsulta = ArrConsultas[j];
      max = aux;

    }
    
    return;

}

void copiarPacCont(Paciente *&array, int i, Contacto *&ArrContacto, int j) //no es necesario hacer una funcion para esto, pero al hacerla le podemos hacer un unit-test para verificar que funcione
{
    if(array == nullptr || ArrContacto == nullptr){
        cout<<"Error"<<endl;
        return;
    }
    array[i].contacto = ArrContacto[j];
    return;

}

void unificar(Paciente *&array, Contacto *&ArrContacto, Consultas *&ArrConsultas, Medico *&ArrMed, int N){
    
    if(array == nullptr || ArrContacto == nullptr || ArrConsultas == nullptr || ArrMed == nullptr){
        cout<<"Error"<<endl;
        return;
    }

    int i, j;
    for(i=0; i<N; i++){
        ArrConsultas[i].TieneMed = false;
        array[i].TieneCont = false;
        array[i].TieneCons = false;
    }
    

    for (i = 0; i < N; i++) { //recorre Consulta
        for (j = 0; j < N; j++) { //recorre medicos
            if (ArrConsultas[i].medico.matricula == ArrMed[j].matricula) 
            {
                copiarConsMed(ArrConsultas, i, ArrMed, j);
                ArrConsultas[i].TieneMed = true;
            }
        }
    }

    
    for (i=0 ;i<N ;i++){ //recorre pacientes
        double max = 0.00; //se reinicia cuando cambiamos de paciente
        for(j=0; j<N ;j++){ //recorre las otras listas
        
            if(array[i].DNI == ArrContacto[j].DNI){
                copiarPacCont(array,i, ArrContacto,j); 
                array[i].TieneCont =true; 
                    
            }

            if(array[i].DNI == ArrConsultas[j].DNI){
                copiarPacCons(array, i, ArrConsultas, j, max);
                array[i].TieneCons = true; 
                if(ArrConsultas[i].TieneMed == true){
                    array[i].TieneMed_enPac = true; 
                }  
            }
        }
    }

}


int Contactar(){
    int aux;
    //cout << "Cual fue la respuesta del paciente?" << endl; //la respuesta la hace un random
    aux = rand()% (4-1) + 1;
    //cout << "Respuesta del paciente:" << aux << endl;
    return aux;
}

void actualizarObSocial(Paciente *&array, int i){ //es con randoms porque como lo llamamos dentro de una funcion no se puede ingresar nada por teclado
    int cambio;
    cambio = rand()% (1 - 0)+ 1;
    int aux;
   
    if(cambio == 1){
        aux = rand()% (7-1) + 1;

        switch(aux){
            case 1:
                array[i].id_os = "Medicus";
                break;
            case 2:
                array[i].id_os = "Italiano";
                break;
            case 3:
                array[i].id_os = "Espanyol";
                break;
            case 4:
                array[i].id_os = "Aleman";
                break;
            case 5:
                array[i].id_os = "OSDE";
                break;
            case 6:
                array[i].id_os = "IOSFA";
                break;
            case 7:
                array[i].id_os = "Swiss Medical";
                break;
            default:
                cout<<"ERROR"<<endl;
                break;
        }
    }
    
    return;
}


bool creoListas(Paciente *&array, int N){
    
    int i = 0;
    if(array == nullptr){
        cout<<"Error"<<endl;
        return false;
    }

    fstream arch, act, nf; //archivados, activos, not found
    string pathArch = "Archivados.csv";
    string pathAct = "Activos.csv";
    string pathNF = "NoEncontrados.csv";

    //archivo archivados
    arch.open(pathArch, ios::out);
    if (!(arch.is_open())){
      cout<< "no se creo el archivo" <<endl;
            return false;
    }
    else
        cout<< "se creo el archivo" << endl;

    //archivo activos
    act.open(pathAct, ios::out);
    if (!(act.is_open())){
      cout<< "no se creo el archivo" <<endl;
            return false;
    }
    else
        cout<< "se creo el archivo" << endl;

    //archivo no encontrados
    nf.open(pathNF, ios::out);
    if (!(nf.is_open())){
      cout<< "no se creo el archivo" <<endl;
            return false;
    }
    else
        cout<< "se creo el archivo" << endl;

    //imprimimos los headers
    char coma = ',';
    arch << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Sexo" << coma << "Natalicio" << coma << "Estado - Paciente" << coma << "Obra_Social" << coma << "Estado - Archivo" << endl;
    act  << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Sexo" << coma << "Natalicio" << coma << "Estado - Paciente" << coma << "Obra_Social" << coma << "Estado - Archivo" << coma << "Contacto - Telefono" << coma << "Contacto - Celular" << coma << "Medico - Matricula" << coma << "Medico - Nombre" << coma << "Medico - Apellido" << coma << "Medico - Telefono" << coma << "Medico - Especialidad" << coma << "Medico - Activo?" <<endl;
    nf   << "DNI" << coma << "Nombre" << coma << "Apellido" << coma << "Sexo" << coma << "Natalicio" << coma << "Estado - Paciente" << coma << "Obra_Social" << coma << "Estado - Archivo" <<endl;


    int j = 0;
    int l = 0;
    int q = 0;

    //algoritmo de busqueda
    time_t now;
    time(&now);
    int diferencia;

    
    for(i=0; i<N; i++){

        double fecha; //no hace falta inicializar
        fecha = (array[i].UltimaConsulta.fecha_turno.tm_year *365*24*3600) + (array[i].UltimaConsulta.fecha_turno.tm_mon *30*24*3600) + (array[i].UltimaConsulta.fecha_turno.tm_mday *24*3600); //convertimos la fecha a segundos
    
        diferencia = difftime(now,fecha); //calculo de los años
        
        if(array[i].TieneCons == true &&  array[i].TieneCont == true && array[i].TieneMed_enPac == true){
            
            if(array[i].estado == "fallecido" || diferencia >= 315360000.00){ //si esta muerto o pasaron mas de 10 años (en segundos)
                array[j].archivado = "ARCHIVADO";
                arch << array[j].DNI << coma << array[j].nombre << coma << array[j].apellido << coma << array[j].sexo << coma << array[j].natalicio << coma << array[j].estado << coma << array[j].id_os << array[j].archivado << endl;
                j++;  
            
            }

            else if (array[i].estado == "internado" || fecha >= now){ //si esta internado o tiene un turno a futuro
                array[l].archivado = "RETORNA";
                actualizarObSocial(array, l); //tiene que actualizar la obra social?
                act << array[l].DNI << coma << array[l].nombre << coma << array[l].apellido << coma << array[l].sexo << coma << array[l].natalicio << coma << array[l].estado << coma << array[l].id_os << array[l].archivado << coma << array[l].contacto.telefono << coma << array[l].contacto.celular << coma << array[l].UltimaConsulta.medico.matricula << coma << array[l].UltimaConsulta.medico.nombre << coma << array[l].UltimaConsulta.medico.apellido << coma << array[l].UltimaConsulta.medico.telefono << coma << array[l].UltimaConsulta.medico.especialidad << coma << array[l].UltimaConsulta.medico.activo <<endl;               
                l++;
            }

            else {
                int answer = Contactar();
                switch(answer){
                    case 1: //muerto
                        array[j].archivado = "ARCHIVADO";
                        arch << array[j].DNI << coma << array[j].nombre << coma << array[j].apellido << coma << array[j].sexo << coma << array[j].natalicio << coma << array[j].estado << coma << array[j].id_os << array[j].archivado << endl;
                        j++;    
                        break;

                    case 2: //not back
                        arch << array[j].DNI << coma << array[j].nombre << coma << array[j].apellido << coma << array[j].sexo << coma << array[j].natalicio << coma << array[j].estado << coma << array[j].id_os << endl;
                        j++; 
                        break;

                    case 3: //quiere volver
                        array[l].archivado = "RETORNA";
                        actualizarObSocial(array, l); //tiene que actualizar la obra social?
                        act << array[l].DNI << coma << array[l].nombre << coma << array[l].apellido << coma << array[l].sexo << coma << array[l].natalicio << coma << array[l].estado << coma << array[l].id_os << array[l].archivado << endl;
                        l++;  
                        break;

                    case 4: //not found
                        array[q].archivado = "NO_ENCONTRADO";
                        nf << array[q].DNI << coma << array[q].nombre << coma << array[q].apellido << coma << array[q].sexo << coma << array[q].natalicio << coma << array[q].estado << coma << array[q].id_os << endl;
                        q++; 
                        break;

                    default:
                        cout<<"ERROR al contactar"<<endl;
                        break;
                }
            }
        
        }
    }

    arch.close();
    act.close();
    nf.close();
    return true;

}