#ifndef KERNELAPI_H_
#define KERNELAPI_H_

#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>

//---------------------ESTRUCTURA PAQUETES

typedef struct
{
	int size;
	void* stream;
} t_buffer;

typedef enum
{
	CREATE, //Agregado
	DROP, //Agregado
	DESCRIBE, //Agregado
	SELECT, //Agregado
	INSERT, //Agregado
	JOURNAL, //Agregado
	RUN, //Agregado
	ADD //Agregado
}op_code; //TIPO DE PAQUETE

typedef struct
{
	op_code codigo_operacion;
	char nombre_tabla[20];
	char valor_key[20];
	t_buffer* buffer;
} t_paqueteSELECT;

typedef struct
{
	op_code codigo_operacion;
	char nombre_tabla[20];
	char valor_key[20];
	char value[20];
	char timestamp[20];
	t_buffer* buffer;
} t_paqueteINSERT;

////---------------------HEAD API

//void CREATE();
//void DROP();
//void DESCRIBE();

t_paqueteSELECT* selectf();
t_paqueteSELECT* crear_paqueteSELECT();
void loggear_paqueteSELECT(t_paqueteSELECT* paquete, char tipo_paquete[10]);

t_paqueteINSERT* insert();
t_paqueteINSERT* crear_paqueteINSERT();
void loggear_paqueteINSERT(t_paqueteINSERT* paquete, char tipo_paquete[10]);

//void JOURNAL();
//void RUN();
//void ADD();

#endif /* KERNELAPI_H_ */
