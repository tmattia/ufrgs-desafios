#include <iostream>

using namespace std;

int main() {
	unsigned long int b, e;
	while (cin >> b >> e) {
		unsigned long int pb, pe;
		pb = b;
		pe = e;
		
		unsigned long int c, d;
		int maxconta = 0;
		int conta;

		if (b > e) {
			d = e;
			e = b;
			b = d;
		}

		for (unsigned long int i = b; i <= e; i++) {
			conta = 0;
			c = i;
			while (c != 1) {
				if (c % 2 == 1) {
					c = (c*3) + 1;
				} else {
					c = c / 2;
				}
				conta++;
			}
			conta++;
			if (conta > maxconta) maxconta = conta;
		}
		
		cout << pb << " " << pe << " " << maxconta << endl;
	}
	
	return 0;
}
