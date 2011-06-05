#include <iostream>

using namespace std;

int main() {

    int n;
    int m[100][100];
    int linhas[100][100][100];
    int colunas[100][100][100];

    int current, best, y;

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                linhas[i][j][k] = 0;
                colunas[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> current;
            m[i][j] = current;
            linhas[i][j][j] = current;
            for (int k = 0; k < j; k++) {
                linhas[i][k][j] = linhas[i][k][j-1] + current;
            }
            //   colunas[i][j][j] = current;
            //   for (int k = 0; k < j; k++) {
            //    colunas[i][j][k] = colunas[i][j-1][k] + current;
            //   }
        }
    }

    // for (int i = 0; i < n; i++) {
    //  for (int j = 0; j < n; j++) {
    //   for (int k = 0; k < n; k++) {
    //    cout << linhas[i][j][k] << " ";
    //   }
    //   cout << endl;
    //  }
    //  cout << endl;
    // }

    // for (int i = 0; i < n; i++) {
    //  for (int j = 0; j < n; j++) {
    //   cout << m[i][j] << " ";
    //  }
    //  cout << endl;
    // }

    best = 0;
    int a, b, c, d;
    for (int i = 0; i < n; i++) { //o.x
        for (int j = 0; j < n; j++) { //o.y
            for (int k = i; k < n; k++) { //d.x
                for (int l = j; l < n; l++) { //d.y
                    y = 0;
                    for (int m = i; m <= k; m++) {
                        y += linhas[m][j][l];
                    }
                    if (y > best) {
                        best = y;
                        a = i;
                        b = j;
                        c = k;
                        d = l;
                    }
                }
            }
        }
    }
    cout << best << endl;

    return 0;
}
