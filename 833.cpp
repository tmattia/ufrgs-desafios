#include <iostream>
#include <cmath>

using namespace std;

struct ponto {
    int x, y;
};

struct line {
    ponto p1, p2;
};

int main() {

    int t;
    int n, p;

    float a, b;
    float newy, dist;

    int curx, cury;
    int nextx, nexty;

    line ls[1000];
    ponto ps[1000];

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> ls[j].p1.x >> ls[j].p1.y >> ls[j].p2.x >> ls[j].p2.y;
        }

        cin >> p;
        for (int j = 0; j < p; j++) {
            cin >> ps[j].x >> ps[j].y;

            curx = ps[j].x;
            cury = ps[j].y;

            while (cury > 0) {
                dist = 10000000;
                for (int k = 0; k < n; k++) {
                    if (curx < max(ls[k].p1.x, ls[k].p2.x) && curx > min(ls[k].p1.x, ls[k].p2.x)) {
                        a = ((float) ls[k].p2.y - ls[k].p1.y) / (ls[k].p2.x - ls[k].p1.x);
                        b = ls[k].p1.y - a * ls[k].p1.x;

                        newy = a*ps[j].x + b;
                        if (newy < cury) {
                            if (cury - newy < dist) {
                                dist = cury - newy;
                                if (ls[k].p1.y < ls[k].p2.y) {
                                    nextx = ls[k].p1.x;
                                    nexty = ls[k].p1.y;
                                } else {
                                    nextx = ls[k].p2.x;
                                    nexty = ls[k].p2.y;
                                }
                            }
                        }
                    }
                }
                if (dist != 10000000) {
                    curx = nextx;
                    cury = nexty;
                } else {
                    cury = 0;
                }
            }

            cout << curx << endl;

        }

        if (i != t-1) {
            cout << endl;
        }
    }

    return 0;

}
