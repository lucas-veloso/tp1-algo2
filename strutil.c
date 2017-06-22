#include "strutil.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// esta funcion copia un string desde una posicion inicial hacia una final
char* string_copy(const char* str,size_t start, size_t stop){
	char *token = calloc(stop - start + 1,sizeof(char));
	if(!token) return NULL;
    *token = '\0';
    return memcpy(token, str + start, stop - start);
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
	
	if(sep == '\0') return NULL; // precondicion de la funcion
	size_t TINIC = 2; // tamanio inicial del arreglo dinamico
    size_t start = 0; // posicion en la cual va a empezar a guardar el string 
    size_t stop = 0; // posicion en la que se encuentre un separador
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
	if(!array) return NULL;
    array[toks] = token;
    toks++;

    //agrego NULL en la ultima posicion del arreglo
    array[toks] = NULL;
    return array;
}

char* join(char** strv, char sep){
	
	/* casos borde */
	if(!strv[0] || (strv[0] == '\0' && !strv[1])){ 
		char* strvacio = (char*) calloc(1,1);
		*strvacio = '\0';	
		return strvacio;
	}

	size_t tam = 0; /* tamanio a ocupar de string */
	size_t pos = 0; /* posicion en al cual voy a guardar caracteres */
	
	/* obtener tamanio */
	for(size_t i = 0; strv[i] != NULL; i++){
		tam += strlen(strv[i]) + 1;
	}

	char* result = malloc(tam * sizeof(char));
	if (!result) return NULL;

	/* recorro el arreglo de string
	appendeando los strings y agreg
	andoles el seperador hasta que 
	encuentro la posicion que 
	contiene al vector nulo */
	for(size_t i=0;strv[i];i++){
		for(size_t j=0;strv[i][j];j++){
			result[pos] = strv[i][j];
			pos++;
		}
		result[pos] = sep;
		pos++;
	}

	/* agrego el \0 en la ultima pos */
	result[pos-1] = '\0';	
	return result;
}	

void free_strv(char* strv[]){
	for(size_t i=0;strv[i];i++)
		free(strv[i]);
	free(strv);
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
	printf("%s\n",arr[11]);
	char* trs = join(arr,',');
	printf("%s\n",trs);
	free_strv(arr);
	free(trs);   
	return 0;

}