#include <iostream>

using namespace std;

int main() {
	int m, n, t = 1;
	char c;

	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		if (t > 1) cout << endl;

		int v[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				v[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> c;
				if (c != '*') continue;
				v[i][j] -= 10;
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						if (k+i >= 0 && k+i < m && l+j >= 0 && l+j < n) {
							v[k+i][l+j]++;
						}
					}
				}
			}
		}

		cout << "Field #" << t << ":" << endl;
		t++;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] < 0) {
					cout << "*";
				} else {
					cout << v[i][j];
				}
			}
			cout << endl;
		}
	}

	return 0;
}
