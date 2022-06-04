#include "strings.hpp"

// construtor
Strings::Strings() {}

// variacoes 1632
void Strings::variacoes() {
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
void Strings::sobrenomeNaoEFacil() {
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
void Strings::espiralQuadrada() {
	int N, i, j, aux;
	int meio, linha, coluna;
	string str;

	while ((cin >> N), N != 0) {
		char **matriz = (char **)malloc(N * sizeof(char *));

		str.assign("");
		for (i = 0; i < N; i++) str.append("O");

		for (i = 0; i < N; i++) {
			matriz[i] = (char *)malloc(N * sizeof(char));
			for (j = 0; j < N; j++) matriz[i][j] = 'O';
		}
		meio = (N / 2);
		matriz[meio][meio] = 'X';

		printMatriz(matriz, N, meio, str);

		if (N > 1) {
			linha = coluna = meio;
			aux = 3;

			while (aux <= N) {
				matriz[linha][coluna] = 'O';
				matriz[linha][++coluna] = 'X';
				printMatriz(matriz, N, linha, str);

				caminhaMatriz(matriz, &linha, &coluna, -1, 0, aux - 2, N, str);
				caminhaMatriz(matriz, &linha, &coluna, 0, -1, aux - 1, N, str);
				caminhaMatriz(matriz, &linha, &coluna, 1, 0, aux - 1, N, str);
				caminhaMatriz(matriz, &linha, &coluna, 0, 1, aux - 1, N, str);

				aux += 2;
			}
		}
	}
}

// caminha pela matriz trocando o O por X
void Strings::caminhaMatriz(char **matriz, int *linha, int *coluna, int contLinha, int contCol, int tam, int N, string str) {
	for (int i = 0; i < tam; i++) {
		matriz[(*linha)][(*coluna)] = 'O';
		matriz[(*linha) + contLinha][(*coluna) + contCol] = 'X';

		(*linha) += contLinha;
		(*coluna) += contCol;

		printMatriz(matriz, N, *linha, str);
	}
}

// imprime matriz
void Strings::printMatriz(char **matriz, int N, int linha, string str) {
	int i, j;

	for (i = 0; i < N; i++) {
		if (linha != i)
			cout << str;
		else {
			for (j = 0; j < N; j++)
				cout << matriz[i][j];
		}
		cout << endl;
	}
	cout << "@" << endl;
}

// numeros ma sorte recarregados 3300
void Strings::numerosMaSorteRecarregados() {
	string numero, aux = "13";

	cin >> numero;
	cout << numero;

	cout << numero.find(aux) << endl;

	if (!(numero.find(aux) != string::npos)) cout << " NO";
	cout << " es de Mala Suerte" << endl;
}

// hudinho e o seu trabalho 3311
void Strings::hudinhoEOSeuTrabalho() {
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
void Strings::imagem() {
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

// carta de natal criptografada 3038
void Strings::cartaNatalCriptografada() {
	string F;
	int p = 0;

	map<string, char> vogais;

	vogais.insert({ "@", 'a' });
	vogais.insert({ "&", 'e' });
	vogais.insert({ "!", 'i' });
	vogais.insert({ "*", 'o' });
	vogais.insert({ "#", 'u' });

	while (getline(cin, F))
		descriptografaCarta(F, vogais);
}

// descriptografa uma string para as vogais corretas
void Strings::descriptografaCarta(string str, map<string, char> vogais) {
	map<string, char>::iterator itr;

	for (itr = vogais.begin(); itr != vogais.end(); ++itr)
		descriptografa(&str, itr->first, itr->second);
	cout << str << endl;
}

// utilizado pela funcao descriptografaCarta
void Strings::descriptografa(string *str, string simbolo, char vogal) {
	int p = 0;

	while (p <= (*str).size()) {
		p = (*str).find(simbolo);
		if (p != string::npos) (*str)[p] = vogal;
	}
}

// teclado zoeiro 2692 - nao resolvido
void Strings::tecladoZoeiro() {
	int N, M;
	char s1, s2;
	string transformacao;

	map<char, char> letras;
	map<char, char>::iterator itr;

	cin >> N;
	cin >> M;

	while (N-- > 0) {
		cin >> s1;
		cin >> s2;

		letras.insert({ s1, s2 });
		letras.insert({ s2, s1 });
	}

	cin.ignore();
	while (M-- > 0) {
		getline(cin, transformacao);

		for (int i = 0; i < transformacao.length(); i++) {
			itr = letras.find(transformacao[i]);

			if (itr != letras.end())
				transformacao[i] = itr->second;
		}
		cout << transformacao << endl;
	}
}

// numeros de ahmoc 2049
void Strings::numerosAhmoc() {
	string N, sequencia, aux;
	int cont = 0, count = 0;

	while (cin >> N, N != "0") {
		cin >> sequencia;

		if (count++ > 0) cout << endl;

		aux = "Instancia ";
		aux.append(to_string(++cont)).append("\n");
		aux += (sequencia.find(N) != string::npos) ? "verdadeira\n" : "falsa\n";

		cout << aux;
	}
}

// correcao de texto 3088
void Strings::correcaoTexto() {
	string str;

	while (getline(cin, str)) {
		correcao(&str, " ,", "#");
		correcao(&str, " .", "*");

		correcao(&str, "#", ",");
		correcao(&str, "*", ".");

		cout << str << endl;
	}
}

// recebe uma strign e substitui o alvo pelo valor
void Strings::correcao(string *str, string target, string valor) {
	size_t found = (*str).find(target);

	while (found != string::npos) {
		(*str).replace(found, target.length(), valor);
		found = (*str).find(target);
	}
}

// substituicao de tag 1254
void Strings::substituicaoTag() {
	string tag, str, aux;
	string numero;

	size_t abre, fecha, found;

	while (getline(cin, tag), getline(cin, numero), getline(cin, str)) {
		abre = str.find("<");
		aux.assign(str);

		tolowerStr(str);
		tolowerStr(tag);

		while (abre != string::npos) {
			fecha = str.find(">", abre + 1);

			if (fecha != string::npos) {
				found = str.find(tag, abre + 1);

				while (found != string::npos && found < fecha) {
					str.replace(found, tag.length(), numero);
					aux.replace(found, tag.length(), numero);

					found = str.find(tag, found + 1);
					fecha = str.find(">", abre + 1);
				}
			} else break;
			abre = str.find("<", fecha + 1);
		}
		cout << aux << endl;
	}
}

void Strings::ultimaCriancaBoa() {
	string nome, ultima = "";
	string nomeAux, ultimaAux = "";

	while (getline(cin, nome)) {
		nomeAux.assign(nome);

		tolowerStr(nomeAux);

		if (nomeAux.compare(ultimaAux) > 0) {
			ultimaAux.assign(nomeAux);
			ultima.assign(nome);
		}
	}
	cout << ultima << endl;
}