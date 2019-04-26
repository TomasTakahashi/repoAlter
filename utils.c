#include "utils.h"

t_log* iniciar_logger() {
	return log_create("KernelCliente.log", "KernelCliente", 1, LOG_LEVEL_INFO);
}

t_config* leer_config() {
	return config_create("KernelCliente.config");
}

//t_paquete* crear_paquete(op_code cod_op,char *nombretabla,char * valor_key) //Agregado
//{
//	t_paquete* paquete = malloc(sizeof(t_paquete));
//	paquete->codigo_operacion = cod_op;
//	for(int i=0;i<20;i++){
//		paquete->nombre_tabla[i] = nombretabla[i];
//	};
//	for(int i=0;i<20;i++){
//		paquete->valor_key[i] = valor_key[i];
//	};
//	crear_buffer(paquete);
//	return paquete;
//}

//t_paquete* armar_paquete() { //Original
//	t_paquete* paquete = crear_paquete();
//	t_log* logger = iniciar_logger();
//
//	void _agregar(char* leido) {
//
//		agregar_a_paquete(paquete, leido, strlen(leido) + 1);
//		log_info(logger, leido);
//	}
//
//	_leer_consola_haciendo((void*) _agregar);
//
//	return paquete;
//}

//void leer_consola(t_log* logger) {
//	void loggear(char* leido) {
//		log_info(logger, leido);
//	}
//
//	_leer_consola_haciendo((void*) loggear);
//}
//
//void _leer_consola_haciendo(void(*accion)(char*)) {
//	char* leido = readline(">");
//
//	while(strncmp(leido, "", 1) != 0) {
//		accion(leido);
//		leido = readline(">");
//	}
//
//	free(leido);
//}

//void agregar_a_paquete(t_paquete* paquete, void* valor, int tamanio)
//{
//	paquete->buffer->stream = realloc(paquete->buffer->stream, paquete->buffer->size + tamanio + sizeof(int));
//
//	memcpy(paquete->buffer->stream + paquete->buffer->size, &tamanio, sizeof(int));
//	memcpy(paquete->buffer->stream + paquete->buffer->size + sizeof(int), valor, tamanio);
//
//	paquete->buffer->size += tamanio + sizeof(int);
//}
//
//
void enviar_paqueteSELECT(t_paqueteSELECT* paquete, int socket_cliente)
{
	int bytes = paquete->buffer->size + 2*sizeof(int);
	void* a_enviar = serializar_paqueteSELECT(paquete, bytes);

	send(socket_cliente, a_enviar, bytes, 0);

	free(a_enviar);
}

void enviar_paqueteINSERT(t_paqueteINSERT* paquete, int socket_cliente)
{
	int bytes = paquete->buffer->size + 2*sizeof(int);
	void* a_enviar = serializar_paqueteINSERT(paquete, bytes);

	send(socket_cliente, a_enviar, bytes, 0);

	free(a_enviar);
}


void* serializar_paqueteSELECT(t_paqueteSELECT* paquete, int bytes)
{
	void * magic = malloc(bytes);
	int desplazamiento = 0;

	memcpy(magic + desplazamiento, &(paquete->codigo_operacion), sizeof(int));
	desplazamiento+= sizeof(int);
	memcpy(magic + desplazamiento, &(paquete->buffer->size), sizeof(int));
	desplazamiento+= sizeof(int);
	memcpy(magic + desplazamiento, paquete->buffer->stream, paquete->buffer->size);
	desplazamiento+= paquete->buffer->size;

	return magic;
}

void* serializar_paqueteINSERT(t_paqueteINSERT* paquete, int bytes)
{
	void * magic = malloc(bytes);
	int desplazamiento = 0;

	memcpy(magic + desplazamiento, &(paquete->codigo_operacion), sizeof(int));
	desplazamiento+= sizeof(int);
	memcpy(magic + desplazamiento, &(paquete->buffer->size), sizeof(int));
	desplazamiento+= sizeof(int);
	memcpy(magic + desplazamiento, paquete->buffer->stream, paquete->buffer->size);
	desplazamiento+= paquete->buffer->size;

	return magic;
}
//
//void eliminar_paquete(t_paquete* paquete)
//{
//	free(paquete->buffer->stream);
//	free(paquete->buffer);
//	free(paquete);
//}
//
//void liberar_conexion(int socket_cliente)
//{
//	close(socket_cliente);
//}
//
//void terminar_conexion(){
//	eliminar_paquete(paquete);
//	log_destroy(logger);
//	config_destroy(config);
//	close(conexion);
//}
