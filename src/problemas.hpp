#ifndef PROBLEMAS_HPP
#define PROBLEMAS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

#include "arquivo.hpp"

using namespace std;

class Problemas {
private:
public:
	Problemas();

	void variacoes();
	void sobrenomeNaoEFacil();
	void numerosMaSorteRecarregados();

	void espiralQuadrada();
	void printMatriz(char **matriz, int N);

	void hudinhoEOSeuTrabalho();
	void imagem();
};

#endif