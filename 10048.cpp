#include <iostream>

using namespace std;

int main() {

    int n, m, q;
    int o, d, c;
    int s, t, p;

    int g[100][100];
    bool visited[100];
    int heap[100];
    bool added[100];
    int current, nodo, size;
    int capacidade[100][100];
    bool done[100];
    int pred[100];
    int viagens;

    int fas = 0;

    int trip = 0;
    int best;

    while (true) {

        cin >> n >> m >> q;
        //cout << n << " " << m << " " << q << endl;

        if (n == 0 && m == 0 && q == 0) break;
        if (fas != 0) cout << endl;

        trip++;

        for (int i = 0; i < n; i++) {
            done[i] = false;
            for (int j = 0; j < n; j++) {
                g[i][j] = 0;
                capacidade[i][j] = 1000000;
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> o >> d >> c;
            g[o-1][d-1] = c;
            g[d-1][o-1] = c;
        }

        cout << "Case #" << trip << endl;
        for (int z = 0; z < q; z++) {

            cin >> s >> t;

            if (!done[s-1]) {

                for (int i = 0; i < n; i++) {
                    visited[i] = false;
                    heap[i] = -1;
                    added[i] = false;
                    pred[i] = -1;
                }

                done[s-1] = true;

                capacidade[s-1][s-1] = 0;

                size = 0;
                current = 0;
                heap[s-1] = capacidade[s-1][s-1];
                size++;

                while (current < size) {
                    nodo = 0;
                    best = 1000000;
                    for (int i = 0; i < n; i++) {
                        if (heap[i] < best && heap[i] >= 0) {
                            nodo = i;
                            best = heap[i];
                        }
                    }
                    current++;
                    for (int i = 0; i < n; i++) {
                        if (g[nodo][i] > 0 && !visited[i]) {
                            capacidade[s-1][i] = min(max(g[nodo][i], capacidade[s-1][nodo]), capacidade[s-1][i]);
                            pred[i] = nodo;

                            heap[i] = capacidade[s-1][i];
                            size++;
                        }
                    }
                    visited[nodo] = true;
                    heap[nodo] = -1;
                } 
            }

            viagens = max(0, capacidade[s-1][t-1]);

            if (viagens == 1000000) cout << "no path" << endl;
            else cout << viagens << endl;

        }
        fas++;
    }

    return 0;

}
