#include <iostream>
#include <stdlib.h>

using namespace std;

int visited[11100];
int g[11100][4];

void kill_path(int b) {
    int cur = b;
    int tam = 1;
    int next, last;

    while (cur != b) {
        visited[cur] = true;
        next = -1;
        last = cur;
        for (int i = 3; i >= 0; i--) {
            if (g[cur][i] >= 0 && g[cur][i] != last) {
                next = g[cur][i];
                g[cur][i] = -1;
                tam++;
                break;
            }
        }
        cur = next;
        if (next == -1) {
            return;
        }
    }
}


int find_cycle(int b) {
    int cur = b;
    int tam = 0;
    int next, last;
    bool started = false;

    last = b;

    while (cur != b || !started) {
        started = true;
        visited[cur] = true;
        next = -1;
        for (int i = 0; i < 4; i++) {
            //cout << "AVALIANDO: " << cur << " " << i << " " << g[cur][i] << " " << last << endl;
            if (g[cur][i] >= 0 && g[cur][i] != last) {
                next = g[cur][i];
                g[cur][i] = -1;
                tam++;
                break;
            }
        }
        //cout << "NEXT: " << next << endl;
        last = cur;
        cur = next;
        if (next == -1) {
            kill_path(b);
            return -1;
        }
    }
    return tam;
}

int main() {

    int w, h;
    char c;
    int nodos;
    int t;

    int begin;
    int current;

    int ciclos;
    int larger;

    int resp;

    t = 0;

    while (true) {

        cin >> w >> h;

        if (w == 0 && h == 0) break;

        t++;
        nodos = (w-1)*h + w*(h-1);

        for (int i = 0; i < nodos; i++) {
            visited[i] = false;
            for (int j = 0; j < 4; j++) {
                switch(j) {
                    case 0: g[i][j] = i-w; break;
                    case 1: g[i][j] = i-w+1; break;
                    case 2: g[i][j] = i+w-1; break;
                    case 3: g[i][j] = i+w; break;
                }
            }
        }

        for (int i = 0; i < w-1; i++) {
            g[i][0] = -1;
            g[i][1] = -1;
        }

        for (int i = w-1; i < nodos; i += (2*w-1)) {
            g[i][0] = -1;
            g[i][2] = -1;
        }

        for (int i = 2*w-2; i < nodos; i += (2*w-1)) {
            g[i][1] = -1;
            g[i][3] = -1;
        }

        for (int i = (2*w-1)*(h-1); i < nodos; i++) {
            g[i][2] = -1;
            g[i][3] = -1;
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> c;
                switch (c) {
                    case '\\':
                        //cout << "\\ " << i << " " << j << " ";
                        if (j == 0) {
                            //cout << ((2*w-1)*i+j) << " 2 ";
                            g[(2*w-1)*i+j][2] = -1;
                        } else if (j == w-1) {
                            //cout << ((2*w-1)*i+j-1) << " 1 ";
                            g[(2*w-1)*i+j-1][1] = -1;
                        } else {
                            //cout << ((2*w-1)*i+j) << " 2 ";
                            //cout << ((2*w-1)*i+j-1) << " 1 ";
                            g[(2*w-1)*i+j][2] = -1;
                            g[(2*w-1)*i+j-1][1] = -1;
                        }

                        if (i == 0) {
                            //cout << ((2*w-1)*(i+1)-(w-j)) << " 1 ";
                            g[(2*w-1)*(i+1)-(w-j)][1] = -1;
                        } else if (i == h-1) {
                            //cout << ((2*w-1)*i-(w-j)) << " 2 ";
                            g[(2*w-1)*i-(w-j)][2] = -1;
                        } else {
                            //cout << ((2*w-1)*(i+1)-(w-j)) << " 1 ";
                            //cout << ((2*w-1)*i-(w-j)) << " 2 ";
                            g[(2*w-1)*(i+1)-(w-j)][1] = -1;
                            g[(2*w-1)*i-(w-j)][2] = -1;
                        }
                        //cout << endl;

                        break;
                    case '/':
                        //cout << "/ " << i << " " << j << " ";
                        if (j == 0) {
                            //cout << ((2*w-1)*i+j) << " 0 ";
                            g[(2*w-1)*i+j][0] = -1;
                        } else if (j == w-1) {
                            //cout << ((2*w-1)*i+j-1) << " 3 ";
                            g[(2*w-1)*i+j-1][3] = -1;
                        } else {
                            //cout << ((2*w-1)*i+j) << " 0 ";
                            //cout << ((2*w-1)*i+j-1) << " 3 ";
                            g[(2*w-1)*i+j][0] = -1;
                            g[(2*w-1)*i+j-1][3] = -1;
                        }

                        if (i == 0) {
                            //cout << ((2*w-1)*(i+1)-(w-j)) << " 0 ";
                            g[(2*w-1)*(i+1)-(w-j)][0] = -1;
                        } else if (i == h-1) {
                            //cout << ((2*w-1)*i-(w-j)) << " 3 ";
                            g[(2*w-1)*i-(w-j)][3] = -1;
                        } else {
                            //cout << ((2*w-1)*(i+1)-(w-j)) << " 0 ";
                            //cout << ((2*w-1)*i-(w-j)) << " 3 ";
                            g[(2*w-1)*(i+1)-(w-j)][0] = -1;
                            g[(2*w-1)*i-(w-j)][3] = -1;
                        }
                        //cout << endl;

                        break;
                }
            }
        }

        ciclos = 0;
        larger = 0;  

        for (int i = 0; i < nodos; i++) {
            if (!visited[i]) {
                //cout << "CHAMANDO: " << i << endl;
                resp = find_cycle(i);
                if (resp > 0) {
                    ciclos++;
                    if (resp > larger) {
                        larger = resp;
                    }
                }
            }
        }


        cout << "Maze #" << t << ":" << endl;
        if (ciclos > 0) {
            cout << ciclos << " Cycles; the longest has length " << larger << "." << endl;
        } else {
            cout << "There are no cycles." << endl;
        }
        cout << endl;

    }

    return 0;

}
