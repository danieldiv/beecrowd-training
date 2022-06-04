#include "iniciante.hpp"

Iniciante::Iniciante() {}

// o maior 1013
void Iniciante::oMaior() {
	int a, b, c, x;

	cin >> a, cin >> b, cin >> c;

	x = MAIOR_AB(a, b);
	cout << MAIOR_AB(x, c) << " eh o maior" << endl;
}