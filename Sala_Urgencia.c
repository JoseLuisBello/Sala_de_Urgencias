#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct paciente{//estructura de datos del paciente
    int prioridad;
    int dolencia;
    char Nombre[30];
    int edad;
};

struct Nodo{//estrunctura para un bagon de la cola
    struct paciente pacientes;
    struct Nodo *sig;
};

typedef struct Nodo TNodo;
typedef struct Nodo *TLiga;

struct Cola{//estructura de la cola
    TLiga Inicio;
    TLiga Fin;
};

typedef struct Cola TCola;
typedef struct Cola *TLigaC;

void inicializa_Cola(TLigaC *lc){
    *lc = NULL;
}
void prioridadI(){
    printf("\nOpcion (1)\n");
    printf("\tEstado convulsivo.\n");
    printf("\tPérdida o deterioro súbito de la conciencia. \n");
    printf("\tTrauma Craneoencefálico con alteración neurológica.\n");
    printf("\tTrauma en columna con déficit neurológico.\n");
    printf("\tTrauma ocular.\n");
    printf("\tVisión borrosa o disminución súbita de Agudeza Visual.\n");
    printf("\tPérdida súbita de la visión.\n");
    printf("\tTrauma con lesión del pabellón auricular.\n");
    printf("\tTrauma facial con fractura ósea.\n");
    printf("\tParo cardiovascular.\n");
}
void prioridadII(){
    printf("\nOpcion (2)\n");
    printf("\tTrauma en columna sin déficit neurológico.\n");
    printf("\tConvulsión en paciente con diagnostico conocido.\n");
    printf("\tSíncope con recuperación total de conciencia y sin déficit neurológico.\n");
    printf("\tDolor ocular intenso con ojo rojo y afectación de agudeza visual.\n");
    printf("\tVisión doble. \n");
    printf("\tCuerpo extraño con visión conservada.\n");
    printf("\tCuerpo extraño en el oído con secreción de sangre.\n");
    printf("\tTrauma acústico con secreción sanguinolenta.\n");
    printf("\tTrauma dental.\n");
    printf("\tDolor torácico súbito intenso.\n");
}
void prioridadIII(){
    printf("\nOpcion (3)\n");
    printf("\tDesvanecimiento sin alteración neurológica.\n");
    printf("\tDolor ocular intenso sin ojo rojo y sin afectación de agudeza visual.\n");
    printf("\tPresencia de sangre del ojo por trauma sin alteración visual.\n");
    printf("\tCuerpo extraño en el oído sin dolor, molestia o sangrado.\n");
    printf("\tSordera progresiva.\n");
    printf("\tHerida en paladar blando.\n");
    printf("\tTrauma nasal sin dificultad respiratoria.\n");
    printf("\tHerida en mejilla.\n");
    printf("\tDolor torácico que aumenta con la inspiración.\n");
    printf("\tDolor torácico asociado a fiebre.\n");
}
void prioridadIV(){
    printf("\nOpcion (4)\n");
    printf("\tTrastorno de sensibilidad en extremidades asociadas a ansiedad.\n");
    printf("\tInflamación de los párpados sin celulitis.\n");
    printf("\tTrauma sin lesión del pabellón auricular.\n");
    printf("\tSensación de oído tapado.\n");
    printf("\tMasa en cuello de aparición aguda.\n");
    printf("\tSensación de cuerpo extraño en faringe.\n");
    printf("\tHipertensión arterial compensada.\n");
    printf("\tDolor torácico no irradiado.\n");
    printf("\tArritmia compensada.\n");
    printf("\tPaciente asmática sin crisis.\n");
}
void prioridadV(){
    printf("\nOpcion (5)\n");
    printf("\tSensación de mareo o inestabilidad sin alteración hemodinámica o ansiedad.\n");
    printf("\tTemblor crónico.\n");
    printf("\tConjuntivitis de varios días.\n");
    printf("\tInfección del oído crónica.\n");
    printf("\tSecreción en el oído patológica crónica.\n");
    printf("\tRinitis crónica, congestión nasal y fiebre.\n");
    printf("\tFaringitis.\n");
    printf("\tAmigdalitis.\n");
    printf("\tFalla cardiaca compensada.\n");
    printf("\tRinitis crónica, congestión nasal y fiebre.\n");
}
int prioridad(){
    int opcion;
    printf("Lea cuidadosamente y selecciones la opcion con la cual se relaciona el padecimiento\n");
    do{
        prioridadI();
        prioridadII();
        prioridadIII();
        prioridadIV();
        prioridadV();
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > 5);
    return opcion;
}
struct paciente datos(TLiga lc){
    printf("Ingrese el Nombre del paciente:\t");
    fgets(lc->pacientes.Nombre, 30, stdin);
    fflush(stdin);
    printf("Ingrese la edad del paciente\t");
    scanf("%d", &lc->pacientes.edad);
    lc->pacientes.prioridad = prioridad();
    return lc->pacientes;
}
TLiga CreaNodo(){
    TLiga nuevo = (TLiga)malloc(sizeof(TNodo));
    if (nuevo != NULL){
        nuevo->pacientes = datos(nuevo);
        nuevo->sig = NULL;
    }
    return nuevo;
}
void inserta(TLigaC lc){
    TLiga nuevo;
    nuevo = CreaNodo();
    if (nuevo != NULL){
        if (lc->Inicio == NULL)
            lc->Inicio = nuevo;   
        lc->Fin->sig = nuevo;
        lc->Fin = nuevo;
    }
}
