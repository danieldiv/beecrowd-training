#include "problemas.hpp"

// construtor
Problemas::Problemas() {}

// variacoes 1632
void Problemas::variacoes() {
	int tam = 1, aux;

	string val, vetor = "AaEeIiOoSs";
	vector<int> vec;

	cin >> tam;

	for (int i = 0; i < tam; i++) {
		cin >> val;
		aux = 1;

		for (int j = 0; j < val.size(); j++)
			aux *= (vetor.find(val[j]) != string::npos) ? 3 : 2;
		vec.push_back(aux);
	}
	for (int val : vec) cout << val << endl;
}

// sobrenome nao eh facil 3358
void Problemas::sobrenomeNaoEFacil() {
	int N, i = 0, j, aux;
	string sobrenome;
	string vogal = "aeiouAEIOU";

	vector<string> vec;

	cin >> N;

	while (i++ < N) {
		cin >> sobrenome;
		aux = 0;

		for (j = 0; j < sobrenome.size(); j++) {
			if (!(vogal.find(sobrenome[j]) != string::npos)) {
				if (++aux >= 3) break;
			} else aux = 0;
		}
		if (aux >= 3)
			vec.push_back(sobrenome.append(" nao eh facil"));
		else
			vec.push_back(sobrenome.append(" eh facil"));
	}
	for (string val : vec) cout << val << endl;
}

// espiral quadrada 1868
void Problemas::espiralQuadrada() {
	int N, i, j, aux;
	int meio, linha, coluna;

	while ((cin >> N), N != 0) {
		char **matriz = (char **)malloc(N * sizeof(char *));

		for (i = 0; i < N; i++) {
			matriz[i] = (char *)malloc(N * sizeof(char));
			for (j = 0; j < N; j++) {
				matriz[i][j] = 'O';
			}
		}
		meio = (N / 2);
		matriz[meio][meio] = 'X';

		printMatriz(matriz, N);

		if (N > 1) {
			linha = coluna = meio;
			aux = 3;

			while (aux <= N) {
				// direita
				matriz[linha][coluna] = 'O';
				matriz[linha][++coluna] = 'X';
				printMatriz(matriz, N);

				// aux - 2 cima
				for (i = 0; i < aux - 2; i++) {
					matriz[linha][coluna] = 'O';
					matriz[--linha][coluna] = 'X';
					printMatriz(matriz, N);
				}

				// aux - 1 esquerda
				for (i = 0; i < aux - 1; i++) {
					matriz[linha][coluna] = 'O';
					matriz[linha][--coluna] = 'X';
					printMatriz(matriz, N);
				}

				// aux - 1 baixo
				for (i = 0; i < aux - 1; i++) {
					matriz[linha][coluna] = 'O';
					matriz[++linha][coluna] = 'X';
					printMatriz(matriz, N);
				}

				// aux - 1 direita
				for (i = 0; i < aux - 1; i++) {
					matriz[linha][coluna] = 'O';
					matriz[linha][++coluna] = 'X';
					printMatriz(matriz, N);
				}
				aux += 2;
			}
		}
	}
}

// imprime matriz
void Problemas::printMatriz(char **matriz, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << matriz[i][j];
		cout << endl;
	}
	cout << "@" << endl;
}

// numeros ma sorte recarregados 3300
void Problemas::numerosMaSorteRecarregados() {
	string numero, aux = "13";

	cin >> numero;
	cout << numero;

	cout << numero.find(aux) << endl;

	if (!(numero.find(aux) != string::npos)) cout << " NO";
	cout << " es de Mala Suerte" << endl;
}

// hudinho e o seu trabalho 3311
void Problemas::hudinhoEOSeuTrabalho() {
	int N;
	char aux;
	string nome;

	map<int, vector<string>> alfabeto;
	map<int, vector<string>>::iterator itr;

	vector<string> vec;

	cin >> N;

	while (N-- > 0) {
		cin >> nome;
		aux = tolower(nome[0]);

		itr = alfabeto.find((int)aux);

		if (itr != alfabeto.end()) {
			itr->second.push_back(nome);
		} else {
			vec.clear();
			vec.push_back(nome);
			alfabeto[(int)aux] = vec;
		}
	}

	for (itr = alfabeto.begin(); itr != alfabeto.end(); ++itr)
		for (string v : itr->second) cout << v << endl;
}

// imagem 1516
void Problemas::imagem() {
	int i, j, k;
	int N, M;
	int A, B; // A eh multiplo de N, B eh multiplo de M

	vector<vector<string>> vecStr;
	vector<string> vec;

	char **matriz;
	string str;

	while ((cin >> N, cin >> M), N != 0 && M != 0) {
		matriz = (char **)malloc(N * sizeof(char *));

		for (i = 0; i < N; i++) {
			matriz[i] = (char *)malloc(M * sizeof(char));
			for (j = 0; j < M; j++) cin >> matriz[i][j];
		}
		cin >> A;
		cin >> B;
		vec.clear();

		for (i = 0; i < N; i++) {
			str = "";

			for (j = 0; j < M; j++)
				for (k = 0; k < B / M; k++) str += matriz[i][j];

			for (k = 0; k < A / N; k++) vec.push_back(str);
		}
		vecStr.push_back(vec);
	}

	for (vector<string> vec : vecStr) {
		for (string str : vec) cout << str << endl;
		cout << endl;
	}
}