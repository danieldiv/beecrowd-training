#ifndef STRINGS_HPP
#define STRINGS_HPP

#define loopStr(str) for (int d_inc = 0; d_inc < str.length(); d_inc++)
#define tolowerStr(str) loopStr(str) str[d_inc] = tolower(str[d_inc])

#include <string>
#include <cctype>
#include <map>

#include "arquivo.hpp"

class Strings {
private:
public:
	Strings();

	void variacoes();
	void sobrenomeNaoEFacil();
	void numerosMaSorteRecarregados();

	void espiralQuadrada();
	void caminhaMatriz(char **, int *linha, int *coluna, int contLinha, int contCol, int tam, int N, string str);
	void printMatriz(char **matriz, int N, int linha, string str);

	void hudinhoEOSeuTrabalho();
	void imagem();

	void cartaNatalCriptografada();
	void descriptografaCarta(string str, map<string, char> vogais);
	void descriptografa(string *str, string simbolo, char vogal);

	void tecladoZoeiro();
	void numerosAhmoc();

	void correcaoTexto();
	void correcao(string *str, string target, string valor);

	void substituicaoTag();
	void ultimaCriancaBoa();
};

#endif