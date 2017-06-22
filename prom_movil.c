#include <stdlib.h>
#include <stdio.h>

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

int* obtener_sumas(int* arreglo,size_t n){
	int* vector = malloc(sizeof(int) * n);
	int aux = 0;
	for(size_t i=0;i<n;i++){
		aux+=arreglo[i];
		vector[i] = aux;
	}
	return vector;
}

double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
	
	int* vectar = obtener_sumas(arreglo,n);
	double* vpmovil = calloc(sizeof(double), n);
	int pmovil = 0;
	double divisor = 0;
		
	for(size_t i=0;i<k;i++) divisor++; // casteo el valor de k a un double
	if(n==k){
		for(size_t i=0;i < n;i++) vpmovil[i] = vectar[n-1] / divisor;
	}
	else{
		for(size_t i=0;i < n;i++){
		 	if(i < n - k){
		 		if (divisor < 2 * k + 1){ 
		 		divisor++;
				pmovil = vectar[i+k];
		 		}
		 		else{
		 		pmovil = vectar[i+k] - vectar[i-k-1];
		 		}
			}
		 	else{	
				if(i-k > 1000 && i+k>n){
					printf("%zu\n", i - k);
					pmovil = vectar[n-1];
				}
				else{	
		 		divisor--;
		 		pmovil = vectar[i] - vectar[i-k-1];
				}
		 	}	
			vpmovil[i] = pmovil / divisor;
		}
	}
	free(vectar);
	return vpmovil;
}






// int main(void)
// {
// 	// int arr[6] = {1,3,12,6,17,9};
// 	// double* vectar = obtener_promedio_movil(arr,6,4);
// 	// for(size_t i = 0;i<6;i++){
// 	// 	printf("%f\n",vectar[i]);
// 	// }
// 	// free(vectar);
// }
