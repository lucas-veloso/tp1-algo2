#include <stdlib.h>
#include <stdio.h>

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/
void aux(int* arreglo, size_t i, size_t k, size_t n, double* suma);

double* obtener_promedio_movil(int* arreglo, size_t n, size_t k){
	double* prom = 0;
	double suma = 0;
	for(size_t i=0;i<k;i++){
		suma+= arreglo[i];
	}
	if(k==n) return *suma / k;
	for(int j=0;j<n;j++){
		if(j-k>0) suma-=arreglo[j-k - 1];
		if(j+k<n) suma+=arreglo[j+k];
		if (suma > *prom) prom = &suma;
	} 
	return prom / k;
}


// void aux(int* arreglo, size_t i, size_t k, size_t n, double* suma){
// 	while(k>0)
// 	{
// 		if(i == 0) suma += arreglo[i+k];
// 		else if(i == n) suma += arreglo[i-k];
// 		else
// 		{
// 			suma += arreglo[i+k];
// 			suma += arreglo[i-k];
// 		}
// 		aux(arreglo,i,k-1,n,suma);
// 	}
// 	suma+=arreglo[i];
// 	return;
// }

int main(void)
{
	// int arr[5] = {1,2,3,4,5};
	// obtener_promedio_movil(arr,5,2);
}
