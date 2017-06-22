#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* obtener_nombre_archivo(char* noriginal, size_t n){
   size_t tam = strlen(noriginal) + 6; // tamanio 
   char* fname = calloc(tam,1);
   if(!fname) return NULL;
   snprintf(fname,tam,"%s_%04zu",noriginal,n);
   return fname;
}

int main(int argc, char *argv[]){
   
   if (argc != 3) {
	   fprintf(stderr, "cantidad de argumentos argumentos incorrectos");
	   exit(EXIT_FAILURE);
   }

   size_t tamArchivo = 0;
   sscanf(argv[2],"%zu",&tamArchivo);


   if(tamArchivo==0){
		fprintf(stderr, "el numero de caracteres por linea no puede ser 0");
		exit(EXIT_FAILURE);
   }

   FILE *stream;
   FILE *destino = NULL;   
   stream = fopen(argv[1], "r");
   if (!stream) {
	   perror("fopen");
	   exit(EXIT_FAILURE);
   }

	size_t longLinea = 0;
	size_t caracteresEscribidos = 0;
	size_t numeroArchivosCreados = 0;
	size_t aux = 0;
	char* line = NULL;
  	char* nombreArchivo = NULL;


	while (getline(&line, &longLinea, stream) != -1) {
		size_t lenLinea = strlen(line);
		// printf("longitud de linea :%zu, longitud de archivo: %zu\n",lenLinea,tamArchivo);
		while ( aux < lenLinea ){
			if(!destino){
				nombreArchivo = obtener_nombre_archivo(argv[1],numeroArchivosCreados);
				numeroArchivosCreados++;
				destino = fopen(nombreArchivo,"a+");
			}
			if(lenLinea - aux < tamArchivo - caracteresEscribidos){
				fwrite(line + aux,sizeof(char),lenLinea - aux,destino);
				caracteresEscribidos += lenLinea - aux;
				aux = lenLinea;
			}
			else{
				fwrite(line + aux,sizeof(char),tamArchivo - caracteresEscribidos,destino);
				aux += tamArchivo - caracteresEscribidos;
				fclose(destino);
				destino = NULL;
				caracteresEscribidos = 0;
			}
		}
		aux = 0;
 	}
free(line);
fclose(stream);
if(destino) fclose(destino);
if(nombreArchivo) free(nombreArchivo);
exit(EXIT_SUCCESS);
}