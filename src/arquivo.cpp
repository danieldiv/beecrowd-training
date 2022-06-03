#include "arquivo.hpp"

Arquivo::Arquivo() {}

void Arquivo::salvarValores(vector<string> valor) {
	ofstream outfile;

	outfile.open("saida.txt");

	if (outfile.is_open() && outfile.good()) {
		for (string s : valor) outfile << s.c_str() << endl;
		outfile.close();
	}
}

void Arquivo::salvarValores(vector<vector<string>> valor) {
	ofstream outfile;

	outfile.open("saida.txt");

	if (outfile.is_open() && outfile.good()) {
		for (vector<string> vec : valor) {
			for (string str : vec)
				outfile << str.c_str() << endl;
			outfile << endl;
		}
		outfile.close();
	}
}
