#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Arquivo {
private:
public:
	Arquivo();

	void salvarValores(vector<string> valor);
	void salvarValores(vector<vector<string>> valor);
};

#endif