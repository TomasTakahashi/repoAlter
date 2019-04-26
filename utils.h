#ifndef UTILS_H_
#define UTILS_H_

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>

#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>

#include "KernelAPI.h"

//void enviar_mensaje(char* mensaje, int socket_cliente);
//void agregar_a_paquete(t_paquete* paquete, void* valor, int tamanio);
//void enviar_paquete(t_paquete* paquete, int socket_cliente);
//void eliminar_paquete(t_paquete* paquete);



t_log* iniciar_logger(void);
t_config* leer_config(void);


void enviar_paqueteSELECT(t_paqueteSELECT* paquete, int socket_cliente);
void enviar_paqueteINSERT(t_paqueteINSERT* paquete, int socket_cliente);
//void leer_consola(t_log* logger);

//t_paquete* armar_paquete(op_code cod_op,char *nombretabla, int valor_key);

//void _leer_consola_haciendo(void(*accion)(char*));
//
//void iniciarCliente(void); //Agregado


#endif /* UTILS_H_ */
