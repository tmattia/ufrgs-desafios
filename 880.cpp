#include <iostream>
#include <cmath>

using namespace std;

#define maxpos 100000

int main() {

    int n;

    int offset;

    long long int start[100];
    int c = 0;
    int begin = 0;

    long long int somatorio[maxpos+1];
    long long int soma = 1;
    for (int i = 1; i < maxpos+1; i++) {
        soma += (i-1);
        somatorio[i] = soma;
        if (i % 1000 == 1) {
            start[c] = soma;
            c++;
        }
    }

    int pos;

    while (cin >> n) {

        for (int i = 0; i < 100; i++) {
            if (n < start[i]) {
                begin = i-1;
                break;
            }
        }

        for (int i = (begin*500); i < maxpos+1; i++) {
            if (n < somatorio[i]) {
                soma = i-1;
                break;
            }
        }

        offset = n - somatorio[soma];

        cout << soma-offset << "/" << 1+offset << endl;

    }

    return 0;

}

