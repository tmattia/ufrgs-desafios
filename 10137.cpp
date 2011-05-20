#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	long n;
	double media, soma, posdif, negdif, dif, change;

	while (true) {
		cin >> n;
		if (n == 0) break;
		
		double v[n];

		soma = 0;
		for (long i = 0; i < n; i++) {
			cin >> v[i];
			soma += v[i];
		}
		media = soma / n;

		negdif = 0;
		posdif = 0;
		dif = 0;
		for (long i = 0; i < n; i++) {
			dif = (double) (long) ((v[i] - media) * 100.0) / 100.0;
			if (dif < 0) negdif += dif;
			else posdif += dif;
		}

		change = (-negdif > posdif) ? -negdif : posdif;
		printf("$%.2lf\n", change);
	}

	return 0;
}
