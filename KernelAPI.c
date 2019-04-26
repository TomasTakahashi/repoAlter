#include "KernelAPI.h"

//void CREATE(){}
//
//void DROP(){}
//
//void DESCRIBE(){}

t_paqueteSELECT* selectf(){

	char valor_key[20];
	char nombre_tabla[20];

	printf("\nIngrese nombre de la tabla: ");
	scanf("%s", &nombre_tabla);
	printf("\nIngrese el valor de la key: ");
	scanf("%s", &valor_key);

	t_paqueteSELECT* paquete = crear_paqueteSELECT(SELECT,nombre_tabla,valor_key);
	loggear_paqueteSELECT(paquete, "SELECT");

	return paquete;
}

t_paqueteINSERT* insert(){

	char valor_key[20];
	char nombre_tabla[20];
	char value[100];
	char timestamp[10];

	printf("\nIngrese nombre de la tabla: ");
	scanf("%s", &nombre_tabla);
	printf("\nIngrese el valor de la key: ");
	scanf("%s", &valor_key);
	printf("\nIngrese el value: ");
	scanf("%s", &value);
	printf("\nIngrese el timestamp: ");
	scanf("%s", &timestamp);

	t_paqueteINSERT* paquete = crear_paqueteINSERT(INSERT,nombre_tabla,valor_key, value, timestamp);
	loggear_paqueteINSERT(paquete, "INSERT");

	return paquete;
}

//void JOURNAL(){}
//
//void RUN(){}
//
//void ADD(){}

//----------------------------------------------------CREACION DE PAQUETES

t_paqueteSELECT* crear_paqueteSELECT(op_code cod_op,char *nombretabla,char * valor_key) //Agregado
{
	t_paqueteSELECT* paquete = malloc(sizeof(t_paqueteSELECT));

	paquete->codigo_operacion = cod_op;
	for(int i=0;i<20;i++){
		paquete->nombre_tabla[i] = nombretabla[i];
	}
	for(int i=0;i<20;i++){
		paquete->valor_key[i] = valor_key[i];
	}
	crear_bufferSELECT(paquete);

	return paquete;
}

t_paqueteINSERT* crear_paqueteINSERT(op_code cod_op,char *nombretabla,char * valor_key, char * value, char * timestamp) //Agregado
{
	t_paqueteINSERT* paquete = malloc(sizeof(t_paqueteINSERT));

	paquete->codigo_operacion = cod_op;
	for(int i=0;i<20;i++){
		paquete->nombre_tabla[i] = nombretabla[i];
	}
	for(int i=0;i<20;i++){
		paquete->valor_key[i] = valor_key[i];
	}
	for(int i=0;i<20;i++){
		paquete->value[i] = valor_key[i];
	}
	for(int i=0;i<20;i++){
		paquete->timestamp[i] = valor_key[i];
	}
	crear_bufferINSERT(paquete);

	return paquete;
}

//----------------------------------------------------LOGGEO DE PAQUETES

void loggear_paqueteSELECT(t_paqueteSELECT* paquete, char tipo_paquete[10]){

	t_log* logger = iniciar_logger();
	log_info(logger, "Nuevo paquete creado");
	log_info(logger, tipo_paquete);
	log_info(logger, paquete->nombre_tabla);
	log_info(logger, paquete->valor_key);
}

void loggear_paqueteINSERT(t_paqueteINSERT* paquete, char tipo_paquete[10]){

	t_log* logger = iniciar_logger();
	log_info(logger, "Nuevo paquete creado");
	log_info(logger, tipo_paquete);
	log_info(logger, paquete->nombre_tabla);
	log_info(logger, paquete->value);
	log_info(logger, paquete->timestamp);
}

//------------------------CREAR BUFFER

void crear_bufferSELECT(t_paqueteSELECT* paquete)
{
	paquete->buffer = malloc(sizeof(t_buffer));
	paquete->buffer->size = 0;
	paquete->buffer->stream = NULL;
}

void crear_bufferINSERT(t_paqueteINSERT* paquete)
{
	paquete->buffer = malloc(sizeof(t_buffer));
	paquete->buffer->size = 0;
	paquete->buffer->stream = NULL;
}
