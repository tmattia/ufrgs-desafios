#include <iostream>

using namespace std;

int main() {
    int n, l, r;
    char c[9], d;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cin >> c;
        for (int j = 0; j < 5; j++) {
            r = (j % 2 == 1) ? n : 1;
            for (int k = 0; k < r; k++) {
                for (int i = 0; i < 9; i++) {
                    if (c[i] == '\0') break;

                    if (i > 0) cout << " ";

                    switch(j) {
                        case 0:
                            cout << " ";
                            d = (c[i] == '1' || c[i] == '4') ? ' ' : '-';
                            for (int m = 0; m < n; m++) cout << d;
                            cout << " ";
                            break;

                        case 1:
                            d = (c[i] == '4' || c[i] == '5' || c[i] == '6' || c[i] == '8' || c[i] == '9' || c[i] == '0') ? '|' : ' ';
                            cout << d;
                            for (int m = 0; m < n; m++) cout << " ";
                            d = (c[i] == '5' || c[i] == '6') ? ' ' : '|';
                            cout << d;
                            break;

                        case 2:
                            cout << " ";
                            d = (c[i] == '1' || c[i] == '7' || c[i] == '0') ? ' ' : '-';
                            for (int m = 0; m < n; m++) cout << d;
                            cout << " ";
                            break; 

                        case 3:
                            d = (c[i] == '2' || c[i] == '6' || c[i] == '8' || c[i] == '0') ? '|' : ' ';
                            cout << d;
                            for (int m = 0; m < n; m++) cout << " ";
                            d = (c[i] == '2') ? ' ' : '|';
                            cout << d;
                            break;

                        case 4:
                            cout << " ";
                            d = (c[i] == '1' || c[i] == '4' || c[i] == '7') ? ' ' : '-';
                            for (int m = 0; m < n; m++) cout << d;
                            cout << " ";
                            break; 
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
