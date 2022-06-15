#include "sapHungary.hpp"

SapHungary::SapHungary() {}

void SapHungary::desafioC() {
	Pilha p;
	FPVazia(&p);

	ItemPilha item;

	char palavra[60];
	scanf(" %[^\n]", palavra);

	int cont = 0;
	char c;
	int aux = 0;

	while (cont < strlen(palavra)) {
		c = palavra[cont];

		if (aux == 0) {
			item.val = c;
			Push(&p, item);
			aux = 1;
		} else {
			cout << c;
			aux = 0;
		}
		cont++;
	}
	PImprime(&p);
}

void SapHungary::desafioI() {
	// V = ((H*C)/2) * L

	float N, H, C, L;
	float V;

	float B;
	float metros;

	while (cin >> N >> H >> C >> L) {
		// cout << N << H << C << L << endl;

		V = (((H * C) / 2) * L);
		// B = (H * C) / 2;
		// B = B * L;
		V *= N;
		// metros = V / 100 /

			// cout << V << endl;
		printf("%.4f\n", V);
	}
}

void SapHungary::desafioJ() {
	int N, cont, ano_recebeu, quant_ano, maior;
	int primeiro;
	char palavra[100], planeta[100];

	const char sep[] = " ";
	char *tokens;

	while (cin >> N, N != 0) {
		char primeiro_planeta[100];

		primeiro = 5000;

		while (N-- > 0) {
			scanf(" %[^\n]", palavra);

			cont = 0;
			tokens = strtok(palavra, sep);

			while (tokens != NULL) {
				if (cont == 0) strcpy(planeta, tokens);
				else if (cont == 1) ano_recebeu = atoi(tokens);
				else if (cont == 2) quant_ano = atoi(tokens);

				tokens = strtok(NULL, sep);
				cont++;
			}

			if (ano_recebeu - quant_ano < primeiro) {
				primeiro = ano_recebeu - quant_ano;
				strcpy(primeiro_planeta, planeta);
			}
		}
		cout << primeiro_planeta << endl;
	}
}

void SapHungary::desafioB() {
	int N, cont;
	int H = 0, M = 0, S;

	cin >> H >> M >> S;

	vector<vector<int>> vec;
	vector<int> aux;

	int v1 = 0, v2 = 0;
	int aux1 = M, aux2 = S;

	for (int i = 0; i < H; i++) {
		if (i > 0) {
			v1 = aux1 / H;
			v2 = aux2 / H;

			aux1 += M;
			aux2 += S;
		}

		aux.clear();
		if (aux1 == aux2) {
			aux.push_back(i);
			aux.push_back(v1);
			aux.push_back(v2);

			vec.push_back(aux);
		}
	}

	cout << vec.size() << endl;
	for (vector<int> v : vec) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
}

void SapHungary::desafioF() {
	float X, cont = 1;
	string str, strAux;

	cin >> X;

	vector<int> vec;

	float valor;

	while (cont < 100000000) {
		valor = cont * X;
		if (valor == (int)valor) {

			str = to_string((int)cont);
			strAux = "";

			for (int i = 1; i < str.length();i++) strAux += str[i];
			strAux += str[0];

			if (strAux.compare(to_string((int)valor)) == 0) vec.push_back(cont);
		}
		cont++;
	}

	if (vec.size() == 0)
		cout << "No solution" << endl;
	else {
		for (int v : vec) {
			cout << v << endl;
		}
	}
}