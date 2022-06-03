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

// 		if (p1[strlen(p1) - 1] == '\n') p1[strlen(p1) - 1] = 0;
// 		if (p2[strlen(p2) - 1] == '\n') p2[strlen(p2) - 1] = 0;

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