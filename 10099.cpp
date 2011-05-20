#include <iostream>

using namespace std;

int main() {

    int n, m;
    int o, d, c;
    int s, t, p;

    int g[100][100];
    bool visited[100];
    int heap[100];
    bool added[100];
    int current, nodo, size;
    int capacidade[100];
    int pred[100];
    int viagens;

    int trip = 0;
    int best;

    while (true) {

        cin >> n >> m;

        if (n == 0 && m == 0) break;

        trip++;

        for (int i = 0; i < n; i++) {
            visited[i] = false;
            heap[i] = -1;
            added[i] = false;
            capacidade[i] = 0;
            pred[i] = -1;
            for (int j = 0; j < n; j++) {
                g[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            cin >> o >> d >> c;
            g[o-1][d-1] = c-1;
            g[d-1][o-1] = c-1;
        }

        cin >> s >> t >> p;

        capacidade[s-1] = 100000;

        size = 0;
        current = 0;
        heap[s-1] = capacidade[s-1];
        size++;

        while (current < size) {
            nodo = 0;
            best = 0;
            for (int i = 0; i < n; i++) {
                if (heap[i] > best) {
                    nodo = i;
                    best = heap[i];
                }
            }
            current++;
            for (int i = 0; i < n; i++) {
                if (g[nodo][i] > 0 && !visited[i]) {
                    capacidade[i] = max(min(g[nodo][i], capacidade[nodo]), capacidade[i]);
                    pred[i] = nodo;

                    heap[i] = capacidade[i];
                    size++;
                }
            }
            visited[nodo] = true;
            heap[nodo] = -1;
        } 

        viagens = 0;

        while (p > 0) {
            p -= capacidade[t-1];
            viagens++;
        }

        cout << "Scenario #" << trip << endl;
        cout << "Minimum Number of Trips = " << viagens << endl;
        cout << endl;

    }

    return 0;

}
