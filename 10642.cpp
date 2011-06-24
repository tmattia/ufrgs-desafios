#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;
    int ox, oy, dx, dy;

    long long int po, pd;

    long long int somatorio[100001];
    long long int soma = 0;
    for (int i = 0; i < 100001; i++) {
        soma += i;
        somatorio[i] = soma;
    }

    cin >> n;

    for (int j = 0; j < n; j++) {
        cin >> ox >> oy >> dx >> dy;

        po = somatorio[ox+oy]+ox;
        pd = somatorio[dx+dy]+dx;

        if (po > pd) {
            cout << "Case " << (j+1) << ": " << ( po - pd ) << endl;
        } else {
            cout << "Case " << (j+1) << ": " << ( pd - po ) << endl;
        }

    }

    return 0;

}

