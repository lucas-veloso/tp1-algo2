#include "strutil.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


// esta funcion copia un string desde una posicion inicial hacia una final
char* string_copy(const char* str,size_t start, size_t stop){
	char *token = malloc(stop - start + 1);
	if(!token) return NULL;
    *token = '\0';
    memcpy(token, str + start, stop - start);
    return token;
}

// esta funcion incrementa el tamanio del arreglo en caso de ser necesario
char** redim_array(char** arr, size_t* tinicial, size_t toks){
	if(toks >= *tinicial-1){
        	*tinicial *= 2;
        	arr = realloc(arr,*tinicial * sizeof(char*));
        	if(!arr) return NULL;
        }
    return arr;
} 

char **split(const char *str, char sep){
	
	if(sep = '\0') return NULL; // precondicion de la funcion
	size_t TINIC = 2; // tamanio inicial del arreglo dinamico
    size_t start = 0; // posicion en la cual va a empezar a guardar el string 
    size_t stop; // posicion en la que se encuentre un separador
    size_t toks = 0; // cantidad de strings 
	char** array = malloc(TINIC * sizeof(char*));
	if(!array) return NULL;

	// cuando str llege al \0 va a dejar de iterar
    for (stop = 0; str[stop]; stop++){
        if (str[stop] == sep) {
        	char* token = string_copy(str,start,stop);
        	if(!token) return NULL;
            start = stop + 1;
            array = redim_array(array,&TINIC,toks);
            if(!array) return NULL;
            array[toks] = token;
            toks++;
            }
    }
    
    //copio los elementos que quedan hasta el final
	char* token = string_copy(str,start,stop);
	if(!token) return NULL;
    array = redim_array(array,&TINIC,toks);
    array[toks] = token;
    toks++;

    //agrego NULL en la ultima posicion del arreglo
    array[toks] = NULL;
	if(!array) return NULL;
    return array;
}


int main( int argc, char* argv[] ){
	const char* str = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
	char** arr = split(str,',');
	printf("%s",arr[0]);
	printf("%s",arr[1]);
	printf("%s",arr[2]);
	printf("%s",arr[3]);
	printf("%s",arr[4]);
	printf("%s",arr[5]);
	printf("%s",arr[6]);
	printf("%s",arr[7]);
	printf("%s",arr[8]);
	printf("%s",arr[9]);
	printf("%s",arr[10]);
	printf("%s",arr[11]);
	printf("%s",arr[12]);
	free(arr);   
	return 0;

}