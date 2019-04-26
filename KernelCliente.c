#include "KernelCliente.h"

int main(void){

	t_log* logger = iniciar_logger();

	t_config* config = leer_config();

	int conexion;

	iniciar_conexion(logger, config, conexion);//Iniciar conexion

	armar_paquete(conexion);//Primero pide tipo de paquete, luego lo arma desde "KernelAPI, despues lo envia

	//Eliminar paquete con la funcion (ya creada) eliminar_paquete(paquete)

//	terminar_conexion(logger, config, conexion);//Cerrar conexion

}

void armar_paquete(int conexion){

	int cod_ingresado;
	t_paqueteSELECT* paqueteSELECT;
	t_paqueteINSERT* paqueteINSERT;

	printf("\n0.CREATE\n1.DROP\n2.DESCRIBE\n3.SELECT\n4.INSERT\n5.JOURNAL\n6.RUN\n7.ADD\n");
	printf("\nIngrese el Codigo de operacion correspondiente");
	scanf("\n%d", &cod_ingresado);

	switch(cod_ingresado){
			case 3:
				paqueteSELECT = selectf();
				printf("\n%s",paqueteSELECT -> nombre_tabla);
				printf("\n%s",paqueteSELECT -> valor_key);
				enviar_paqueteSELECT(paqueteSELECT, conexion);
				break;
			case 4:
				paqueteINSERT = insert();
				printf("\n%s",paqueteINSERT -> nombre_tabla);
				printf("\n%s",paqueteINSERT -> valor_key);
				printf("\n%s",paqueteINSERT -> value);
				printf("\n%s",paqueteINSERT -> timestamp);
				enviar_paqueteINSERT(paqueteINSERT, conexion);
				break;
			default:
				printf("Operacion desconocida.");
				break;
	}
}




