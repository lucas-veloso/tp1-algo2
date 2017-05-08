#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// char* obtener_nombre_archivo(char* noriginal, size_t n){
//    char* fname = malloc(strlen(noriginal) + 1);
//    char* narchivo = malloc(5);
//    snprintf(narchivo,5,"%zu",n);
//    if(!fname) return NULL;
//    strcpy(fname,noriginal);
//    strcat(fname,"_");
//    strcat(fname,narchivo);
//    return fname;
// }

// void print_col(char* line, int n,size_t mem,size_t longlinea){ 
// 	if (longlinea - mem <= n){
// 		printf("%s",line + mem);
// 		return;
// 	}
//    	printf("%.*s\n",n,line + mem);   	  
//    	print_col(line,n,mem + n,longlinea);
// }



int main(int argc, char *argv[]){
   
   if (argc != 3) {
       fprintf(stderr, "cantidad de argumentos argumentos incorrectos");
       exit(EXIT_FAILURE);
   }

   int len2 = 0;
   sscanf(argv[2],"%i",&len2);

   if(len2==0){
        fprintf(stderr, "el numero de caracteres por linea no puede ser 0");
 	    exit(EXIT_FAILURE);
   }

   FILE *stream;   
   stream = fopen(argv[1], "r");
   if (!stream) {
       perror("fopen");
       exit(EXIT_FAILURE);
   }

   char *line = NULL;
   size_t len = 0;

   while (getline(&line, &len, stream) != -1) {
   	   // size_t longlinea = strlen(line);
   	   line+=3;
	   printf("%s",line); 
	}

free (line);
fclose(stream);
exit(EXIT_SUCCESS);
}