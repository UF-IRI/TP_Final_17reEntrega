#include "gmock/gmock.h"
#include "funciones.h"

namespace Randoms {
	TEST(TestContactar, expected) {
        
        int aux = Contactar();
        EXPECT_LE(aux,4);
        EXPECT_GE(aux,1);

	}

    TEST(TestContactar, borde) {
        
        int aux = Contactar();
        EXPECT_NE(aux,5);
        EXPECT_NE(aux,0);
        EXPECT_NE(aux,6);
        EXPECT_NE(aux,00);

	}
   
} //es un random que devuelve un numero entre 1 y 4

namespace Resize {
	TEST(TestResize1, ResizePacientes) {
		//declaro 2 arrays el de aca y el que testeo 
     
		Paciente array[3];

        array[0].DNI = "878091772";
        array[0].nombre = "Dagmar";
        array[0].apellido = "Benedict";
        array[0].sexo = "F";
        array[0].natalicio = "1/2/1959";
        array[0].estado = "fallecido";
        array[0].id_os = "Italiano";

        array[1].DNI = "873726724";
        array[1].nombre = "Freeman";
        array[1].apellido = "Willbond";
        array[1].sexo = "M";
        array[1].natalicio = "9/22/2010";
        array[1].estado = "internado";
        array[1].id_os = "Espanyol";

        array[2].DNI = "269125060";
        array[2].nombre = "Laurene";
        array[2].apellido = "Rumsey";
        array[2].sexo = "F";
        array[2].natalicio = "2/27/1951";
        array[2].estado = "n/c";
        array[2].id_os = "OSDE";

        int S = 0;
        Paciente* test= new Paciente[S];
        
        resizePac(test, S, 4);
        
        test[0].DNI = "878091772";
        test[0].nombre = "Dagmar";
        test[0].apellido = "Benedict";
        test[0].sexo = "F";
        test[0].natalicio = "1/2/1959";
        test[0].estado = "fallecido";
        test[0].id_os = "Italiano";

        test[1].DNI = "873726724";
        test[1].nombre = "Freeman";
        test[1].apellido = "Willbond";
        test[1].sexo = "M";
        test[1].natalicio = "9/22/2010";
        test[1].estado = "internado";
        test[1].id_os = "Espanyol";

        test[2].DNI = "269125060";
        test[2].nombre = "Laurene";
        test[2].apellido = "Rumsey";
        test[2].sexo = "F";
        test[2].natalicio = "2/27/1951";
        test[2].estado = "n/c";
        test[2].id_os = "OSDE";   

        for(int i = 0; i < 3; i++){
            EXPECT_EQ(array[i].nombre, test[i].nombre);    
            EXPECT_EQ(array[i].apellido, test[i].apellido);    
            EXPECT_EQ(array[i].sexo, test[i].sexo);    
            EXPECT_EQ(array[i].natalicio, test[i].natalicio);    
            EXPECT_EQ(array[i].estado, test[i].estado);    
            EXPECT_EQ(array[i].id_os, test[i].id_os);    
        }

		delete[] test;
    	test = NULL;
		
	}

	TEST(TestResize2, ResizeContactos) {
     
		Contacto array[3];

        array[0].DNI = "967597385";
        array[0].telefono = "+41 203 339 0504";
        array[0].celular = "+57 722 907 7201";
        array[0].direccion = "Pine View";
        array[0].mail = "strillow0@is.gd";

        array[1].DNI = "398310454";
        array[1].telefono = "+86 913 129 4605";
        array[1].celular = "+62 268 398 6125";
        array[1].direccion = "Lakewood Gardens";
        array[1].mail = "hsubhan1@marketwatch.com";

        array[2].DNI = "747423510";
        array[2].telefono = "+1 696 710 1121";
        array[2].celular = "+1 619 549 4324";
        array[2].direccion = "Thackeray";
        array[2].mail = "mbeaty2@ucoz.ru";

        int K = 0;
        Contacto* test= new Contacto[K];
        
        resizeCont(test, K, 3);
       
        test[0].DNI = "967597385";
        test[0].telefono = "+41 203 339 0504";
        test[0].celular = "+57 722 907 7201";
        test[0].direccion = "Pine View";
        test[0].mail = "strillow0@is.gd";

        test[1].DNI = "398310454";
        test[1].telefono = "+86 913 129 4605";
        test[1].celular = "+62 268 398 6125";
        test[1].direccion = "Lakewood Gardens";
        test[1].mail = "hsubhan1@marketwatch.com";

        test[2].DNI = "747423510";
        test[2].telefono = "+1 696 710 1121";
        test[2].celular = "+1 619 549 4324";
        test[2].direccion = "Thackeray";
        test[2].mail = "mbeaty2@ucoz.ru";

        for(int i = 0; i < 3; i++){
            EXPECT_EQ(array[i].DNI, test[i].DNI);    
            EXPECT_EQ(array[i].telefono, test[i].telefono);    
            EXPECT_EQ(array[i].celular, test[i].celular);    
            EXPECT_EQ(array[i].direccion, test[i].direccion);    
            EXPECT_EQ(array[i].mail, test[i].mail);        
        }

		delete[] test;
    	test = NULL;

	}

	TEST(TestResize3, ResizeMedicos) {
       
        Medico array[3];

        array[0].matricula = "04-723-0907";
        array[0].nombre = "Araldo";
        array[0].apellido = "Grafom";
        array[0].telefono = "827-190-3137";
        array[0].especialidad = "farmacologia";
        array[0].activo = true;

        array[1].matricula = "50-314-2346";
        array[1].nombre = "Trevar";
        array[1].apellido = "Cess";
        array[1].telefono = "600-230-3473";
        array[1].especialidad = "oncologia";
        array[1].activo = true;
        
        array[2].matricula = "61-294-6573";
        array[2].nombre = "Patin";
        array[2].apellido = "Itzchaky";
        array[2].telefono = "113-697-7977";
        array[2].especialidad = "reumatologia";
        array[2].activo = false;


        int N = 0;
        Medico *test= new Medico[N];
        
        resizeMed(test, N, 4);

        test[0].matricula = "04-723-0907";
        test[0].nombre = "Araldo";
        test[0].apellido = "Grafom";
        test[0].telefono = "827-190-3137";
        test[0].especialidad = "farmacologia";
        test[0].activo = true;

        test[1].matricula = "50-314-2346";
        test[1].nombre = "Trevar";
        test[1].apellido = "Cess";
        test[1].telefono = "600-230-3473";
        test[1].especialidad = "oncologia";
        test[1].activo = true;
        
        test[2].matricula = "61-294-6573";
        test[2].nombre = "Patin";
        test[2].apellido = "Itzchaky";
        test[2].telefono = "113-697-7977";
        test[2].especialidad = "reumatologia";
        test[2].activo = false;

        for(int i = 0; i < 3; i++){
            EXPECT_EQ(array[i].matricula, test[i].matricula);    
            EXPECT_EQ(array[i].nombre, test[i].nombre);    
            EXPECT_EQ(array[i].apellido, test[i].apellido); 
            EXPECT_EQ(array[i].telefono, test[i].telefono);    
            EXPECT_EQ(array[i].especialidad, test[i].especialidad);    
            EXPECT_EQ(array[i].activo, test[i].activo);        
        }

		delete[] test;
    	test = NULL;

	}
	
	TEST(TestResize4, ResizeConsultas) {
       
        Consultas array[3];

        array[0].DNI = "432584544";
        array[0].fecha_solicitado.tm_mday = 01;
        array[0].fecha_solicitado.tm_mon=11;
        array[0].fecha_solicitado.tm_year=2001;
        array[0].fecha_turno.tm_mday = 19;
        array[0].fecha_turno.tm_mon = 12;
        array[0].fecha_turno.tm_year = 2001;
        array[0].presento = true;
        array[0].medico.matricula = "00-334-0838";

        array[1].DNI = "867584849";
        array[1].fecha_solicitado.tm_mday = 26;
        array[1].fecha_solicitado.tm_mon = 01;
        array[1].fecha_solicitado.tm_year = 2009;
        array[1].fecha_turno.tm_mday = 20;
        array[1].fecha_turno.tm_mon = 02;
        array[1].fecha_turno.tm_year = 2009;
        array[1].presento = true;
        array[1].medico.matricula = "23-279-3287";
       
        array[2].DNI = "692767686";
        array[2].fecha_solicitado.tm_mday = 16;
        array[2].fecha_solicitado.tm_mon = 06;
        array[2].fecha_solicitado.tm_year = 1993;
        array[2].fecha_turno.tm_mday = 14;
        array[2].fecha_turno.tm_mon = 07;
        array[2].fecha_turno.tm_year = 1993;
        array[2].presento = false;
        array[2].medico.matricula = "12-340-2259";

        int N = 0;
        Consultas* test= new Consultas[N];
        
        resizeCons(test, N, 3);

        test[0].DNI = "432584544";
        test[0].fecha_solicitado.tm_mday = 01;
        test[0].fecha_solicitado.tm_mon=11;
        test[0].fecha_solicitado.tm_year=2001;
        test[0].fecha_turno.tm_mday = 19;
        test[0].fecha_turno.tm_mon = 12;
        test[0].fecha_turno.tm_year = 2001;
        test[0].presento = true;
        test[0].medico.matricula = "00-334-0838";

        test[1].DNI = "867584849";
        test[1].fecha_solicitado.tm_mday = 26;
        test[1].fecha_solicitado.tm_mon = 01;
        test[1].fecha_solicitado.tm_year = 2009;
        test[1].fecha_turno.tm_mday = 20;
        test[1].fecha_turno.tm_mon = 02;
        test[1].fecha_turno.tm_year = 2009;
        test[1].presento = true;
        test[1].medico.matricula = "23-279-3287";
       
        test[2].DNI = "692767686";
        test[2].fecha_solicitado.tm_mday = 16;
        test[2].fecha_solicitado.tm_mon = 06;
        test[2].fecha_solicitado.tm_year = 1993;
        test[2].fecha_turno.tm_mday = 14;
        test[2].fecha_turno.tm_mon = 07;
        test[2].fecha_turno.tm_year = 1993;
        test[2].presento = false;
        test[2].medico.matricula = "12-340-2259";

        for(int i = 0; i < 3; i++){
            EXPECT_EQ(array[i].DNI, test[i].DNI);    
            EXPECT_EQ(array[i].fecha_solicitado.tm_mday, test[i].fecha_solicitado.tm_mday);   
            EXPECT_EQ(array[i].fecha_solicitado.tm_mon, test[i].fecha_solicitado.tm_mon); 
            EXPECT_EQ(array[i].fecha_solicitado.tm_year, test[i].fecha_solicitado.tm_year);  
            EXPECT_EQ(array[i].fecha_turno.tm_mday, test[i].fecha_turno.tm_mday);    
            EXPECT_EQ(array[i].fecha_turno.tm_mon, test[i].fecha_turno.tm_mon);    
            EXPECT_EQ(array[i].fecha_turno.tm_year, test[i].fecha_turno.tm_year);    
            EXPECT_EQ(array[i].presento, test[i].presento);    
            EXPECT_EQ(array[i].medico.matricula, test[i].medico.matricula);
                 
        }

		delete[] test;
    	test = NULL;

	}

}

namespace Copiar {
 
	TEST(TestCopiar1, PacCont) {
        
       
       Contacto *ArrContacto = new Contacto[4];
       Paciente *array = new Paciente[3];
       
       ArrContacto[0].telefono= "54(597)7485488";
       ArrContacto[0].celular= "+54(101)9850920";
       ArrContacto[0].direccion= "Katie";
       ArrContacto[0].mail= "fgurnell2n@taobao.com";

       ArrContacto[1].telefono= "54(298)5694666";
       ArrContacto[1].celular= "+54(599)1977718";
       ArrContacto[1].direccion= "Sommers";
       ArrContacto[1].mail= "dcounter2o@blogspot.com";

       copiarPacCont(array, 1, ArrContacto, 0);
	   copiarPacCont(array, 0, ArrContacto, 1);

       
        EXPECT_EQ(array[1].DNI, ArrContacto[0].DNI);    
        EXPECT_EQ(array[1].contacto.telefono, ArrContacto[0].telefono);    
        EXPECT_EQ(array[1].contacto.celular, ArrContacto[0].celular);    
        EXPECT_EQ(array[1].contacto.direccion, ArrContacto[0].direccion);    
        EXPECT_EQ(array[1].contacto.mail, ArrContacto[0].mail); 

		EXPECT_EQ(array[0].DNI, ArrContacto[1].DNI);    
        EXPECT_EQ(array[0].contacto.telefono, ArrContacto[1].telefono);    
        EXPECT_EQ(array[0].contacto.celular, ArrContacto[1].celular);    
        EXPECT_EQ(array[0].contacto.direccion, ArrContacto[1].direccion);    
        EXPECT_EQ(array[0].contacto.mail, ArrContacto[1].mail);    

		delete[] array;
    	array = NULL;

		delete[] ArrContacto;
    	ArrContacto = NULL;

	}

	TEST(TestCopiar2, MedCons) {
        
       Consultas *ArrConsultas = new Consultas[4];
       Medico *ArrMed = new Medico[3];
	   
	   ArrMed[0].activo = true;
	   ArrMed[0].nombre = "Jacinta";
	   ArrMed[0].apellido = "Ralston";
	   ArrMed[0].especialidad = "geriatria";
	   ArrMed[0].matricula = "03-957-5455";
	   ArrMed[0].telefono = "+54(929)89112253";

	   ArrMed[1].activo = false;
	   ArrMed[1].nombre = "Victor";
	   ArrMed[1].apellido = "Drew";
	   ArrMed[1].especialidad = "toxicologia";
	   ArrMed[1].matricula = "04-726-6430";
	   ArrMed[1].telefono = "+54(014)44587898";

       copiarConsMed(ArrConsultas, 2, ArrMed, 1);
	   copiarConsMed(ArrConsultas, 3, ArrMed, 0);
	   
	   EXPECT_EQ(ArrConsultas[2].medico.activo, ArrMed[1].activo);    
	   EXPECT_EQ(ArrConsultas[2].medico.apellido, ArrMed[1].apellido);    
	   EXPECT_EQ(ArrConsultas[2].medico.especialidad, ArrMed[1].especialidad);   
	   EXPECT_EQ(ArrConsultas[2].medico.matricula, ArrMed[1].matricula);    
	   EXPECT_EQ(ArrConsultas[2].medico.nombre, ArrMed[1].nombre);    
	   EXPECT_EQ(ArrConsultas[2].medico.telefono, ArrMed[1].telefono);    
    
	   EXPECT_EQ(ArrConsultas[3].medico.activo, ArrMed[0].activo);    
	   EXPECT_EQ(ArrConsultas[3].medico.apellido, ArrMed[0].apellido);    
	   EXPECT_EQ(ArrConsultas[3].medico.especialidad, ArrMed[0].especialidad);   
	   EXPECT_EQ(ArrConsultas[3].medico.matricula, ArrMed[0].matricula);    
	   EXPECT_EQ(ArrConsultas[3].medico.nombre, ArrMed[0].nombre);    
	   EXPECT_EQ(ArrConsultas[3].medico.telefono, ArrMed[0].telefono);    
	
		delete[] ArrConsultas;
    	ArrConsultas = NULL;

		delete[] ArrMed;
    	ArrMed = NULL;

	}

    TEST(TestCopiar3, PacCons) {
        
       
       Consultas *ArrConsultas = new Consultas[4];
       Paciente *array = new Paciente[5];
       
	    ArrConsultas[0].fecha_solicitado.tm_mday = 01;
        ArrConsultas[0].fecha_solicitado.tm_mon = 11;
        ArrConsultas[0].fecha_solicitado.tm_year = 2001;
        ArrConsultas[0].fecha_turno.tm_mday = 19;
        ArrConsultas[0].fecha_turno.tm_mon = 12;
        ArrConsultas[0].fecha_turno.tm_year = 2001;
        ArrConsultas[0].presento = true;
        ArrConsultas[0].medico.matricula = "00-334-0838";

        ArrConsultas[1].fecha_solicitado.tm_mday = 26;
        ArrConsultas[1].fecha_solicitado.tm_mon = 01;
        ArrConsultas[1].fecha_solicitado.tm_year = 2009;
        ArrConsultas[1].fecha_turno.tm_mday = 20;
        ArrConsultas[1].fecha_turno.tm_mon = 02;
        ArrConsultas[1].fecha_turno.tm_year = 2009;
        ArrConsultas[1].presento = true;
        ArrConsultas[1].medico.matricula = "23-279-3287";
       
	   double max = 0.00;

       copiarPacCons(array, 3, ArrConsultas, 0, max);

	   max = 0.00;
	   copiarPacCons(array, 2, ArrConsultas, 1, max);
	   
	   EXPECT_EQ(array[3].UltimaConsulta.fecha_solicitado.tm_mday, ArrConsultas[0].fecha_solicitado.tm_mday);   
	   EXPECT_EQ(array[3].UltimaConsulta.fecha_solicitado.tm_mon, ArrConsultas[0].fecha_solicitado.tm_mon); 
	   EXPECT_EQ(array[3].UltimaConsulta.fecha_solicitado.tm_year, ArrConsultas[0].fecha_solicitado.tm_year);  
	   EXPECT_EQ(array[3].UltimaConsulta.fecha_turno.tm_mday, ArrConsultas[0].fecha_turno.tm_mday);    
	   EXPECT_EQ(array[3].UltimaConsulta.fecha_turno.tm_mon, ArrConsultas[0].fecha_turno.tm_mon);    
	   EXPECT_EQ(array[3].UltimaConsulta.fecha_turno.tm_year, ArrConsultas[0].fecha_turno.tm_year);    
	   EXPECT_EQ(array[3].UltimaConsulta.presento, ArrConsultas[0].presento);    
	   EXPECT_EQ(array[3].UltimaConsulta.medico.matricula, ArrConsultas[0].medico.matricula);
          
	   EXPECT_EQ(array[2].UltimaConsulta.fecha_solicitado.tm_mday, ArrConsultas[1].fecha_solicitado.tm_mday);   
	   EXPECT_EQ(array[2].UltimaConsulta.fecha_solicitado.tm_mon, ArrConsultas[1].fecha_solicitado.tm_mon); 
	   EXPECT_EQ(array[2].UltimaConsulta.fecha_solicitado.tm_year, ArrConsultas[1].fecha_solicitado.tm_year);  
	   EXPECT_EQ(array[2].UltimaConsulta.fecha_turno.tm_mday, ArrConsultas[1].fecha_turno.tm_mday);    
	   EXPECT_EQ(array[2].UltimaConsulta.fecha_turno.tm_mon, ArrConsultas[1].fecha_turno.tm_mon);    
	   EXPECT_EQ(array[2].UltimaConsulta.fecha_turno.tm_year, ArrConsultas[1].fecha_turno.tm_year);    
	   EXPECT_EQ(array[2].UltimaConsulta.presento, ArrConsultas[1].presento);    
	   EXPECT_EQ(array[2].UltimaConsulta.medico.matricula, ArrConsultas[1].medico.matricula); 
    
		delete[] ArrConsultas;
        ArrConsultas = NULL;

		delete[] array;
    	array = NULL;
	}
}



