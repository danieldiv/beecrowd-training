#ifndef SAPHUNGARY_HPP
#define SAPHUNGARY_HPP

#define loopStr(str) for (int d_inc = 0; d_inc < str.length(); d_inc++)
#define tolowerStr(str) loopStr(str) str[d_inc] = tolower(str[d_inc])

#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <iostream>

#include "pilha.hpp"

using namespace std;

#include "arquivo.hpp"

class SapHungary {
private:
public:
	SapHungary();

	void desafioB();
	void desafioC();
	void desafioF();
	void desafioI();
	void desafioJ();
};

#endif