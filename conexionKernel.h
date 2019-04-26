#ifndef CONEXIONKERNEL_H_
#define CONEXIONKERNEL_H_

#include<netdb.h>
#include<string.h>

#include<commons/log.h>
#include<commons/string.h>
#include<commons/config.h>

void iniciar_conexion(t_log* logger, t_config* config, int conexion);
int crear_conexion(char *ip, char* puerto);
void liberar_conexion(int socket_cliente);
void terminar_conexion(t_log* logger, t_config* config, int conexion);

#endif /* CONEXIONKERNEL_H_ */
