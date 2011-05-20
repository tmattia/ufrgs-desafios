#include <iostream>
#include <stdlib.h>

using namespace std;

int compare(const void *a, const void *b) {
    return ( *(int*)b - *(int*)a );
}

int main() {

    int t, pessoas;

    int w[101];

    int dp[53][22502];
    int l, soma;
    int best, z;

    // le o numero de casos
    cin >> t;

    for (int i = 0; i < t; i++) {

        // le o numero de pessoas
        cin >> pessoas;

        soma = 0;
        // le o peso das pessoas
        for (int j = 0; j < pessoas; j++) {
            cin >> w[j];
            soma += w[j];
        }

        qsort(w, pessoas, sizeof(int), compare);

        if (pessoas > 0) {

            l = pessoas/2;
            if (pessoas%2 == 1) {
                l++;
            }

            for (int j = 0; j < 53; j++) {
                for (int k = 0; k < 22502; k++) {
                    dp[j][k] = 0;
                }
            }

            dp[1][w[0]] = 1;

            for (int j = 1; j < l; j++) {
                for (int m = 0; m < soma+1; m++) {
                    if (dp[j][m] > 0) { // ateh essa linha eh wrong answer
                        for (int k = dp[j][m]; k < pessoas; k++) { // RUN TIME ERROR
                            if (dp[j+1][m+w[k]] == 0) {
                                dp[j+1][m+w[k]] = k+1;
                            }
                        }
                    }
                }
            }


            best = soma;
            z = 0;

            for (int j = 0; j < soma+1; j++) {
                if ( ( (pessoas%2 == 1 && dp[l-1][j] > 0) || dp[l][j] > 0) && (abs(soma-2*j) < best) ) {
                    best = abs(soma-2*j);
                    z = j;
                }
            }

            if (z < soma-z) {
                cout << z << " " << soma-z << endl;
            } else {
                cout << soma-z << " " << z << endl;
            }
        } else {
            cout << "0 0" << endl;
        }

        if (i+1 != t) {
            cout << endl;
        }
    }

    return 0;

}
