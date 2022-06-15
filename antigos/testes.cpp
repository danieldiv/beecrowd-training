// void _1237() {
// 	char *p1, *p2;
// 	char *p, *aux;

// 	size_t len;

// 	int inicio = 0, fim = 1;
// 	int maior = 0, contador, quant;

// 	// while (!feof(stdin)) {
// 	while (scanf != EOF) {
// 		p1 = (char *)malloc(60);
// 		p2 = (char *)malloc(60);
// 		maior = 0;

// 		fgets(p1, 60, stdin);
// 		fgets(p2, 60, stdin);

// 		inicio = 0;
// 		fim = 1;

// 		contador = 0;
// 		for (int i = 0; (inicio + fim) <= strlen(p2); i++) {
// 			aux = (char *)malloc(60);

// 			strncpy(aux, p2 + inicio, fim);

// 			p = strstr(p1, aux);

// 			if (p != NULL) {
// 				maior = (maior < strlen(aux)) ? strlen(aux) : maior;
// 			} else {
// 				inicio = (i == 0) ? i + 1 : inicio + 1;
// 				fim = 0;
// 			}
// 			fim++;
// 		}
// 		printf("%d\n", maior);
// 	}
// }

/* Quick sort algorithm to sort strings */
// #include <unistd.h>
// #include <string.h>
// #include <stdio.h>
// // #include
// //#include "quicksort.h"

// /* Swaps position of strings in array (char**) */
// void swap(const char **a, const char **b) {
// 	const char *temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// void quicksort(char const *arr[], unsigned int length) {
// 	unsigned int i, piv = 0;
// 	if (length <= 1)
// 		return;

// 	for (i = 0; i < length; i++) {
// 		// if curr str < pivot str, move curr into lower array and  lower++(pvt)
// 		if (strcmp(arr[i], arr[length - 1]) < 0) 	//use string in last index as pivot
// 			swap(arr + i, arr + piv++);
// 	}
// 	//move pivot to "middle"
// 	swap(arr + piv, arr + length - 1);

// 	//recursively sort upper and lower
// 	quicksort(arr, piv++);			//set length to current pvt and increase for next call
// 	quicksort(arr + piv, length - piv);
// }
// #include <stdio.h>
// int main(int argc, char **argv) {
// 	char const *arr[] = { "this", "is", "a", "test", "of", "quicksort", "with", "strings" };
// 	quicksort(arr, sizeof(arr) / sizeof(*arr));
// 	//write(1, arr, sizeof(arr) / sizeof(*arr));
// 	char out[50];
// 	int i = 0;
// 	for (; i < 8; i++) {
// 		// cout << arr[i] << endl;
// 		sprintf(out, "%s", arr[i]);
// 		printf("%s\n", out);
// 		//puts(arr[i]);
// 	}
// 	// write(1, out, sizeof(out));

// }