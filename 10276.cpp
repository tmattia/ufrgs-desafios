#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    bool squares[3000];
    int pegs[50];

    for (int i = 0; i < 3000; i++)
        squares[i] = false;

    for (int i = 0; i < 55; i++) {
        squares[i*i] = true;
    }

    int t;
    int size;

    int current;
    bool shifted;

    cin >> t;

    for (int i = 0; i < t; i++) {

        cin >> size;

        for (int j = 0; j < size; j++)
            pegs[j] = -1;

        current = 1;

        while (true) {
            shifted = false;
            for (int j = 0; j < size; j++) {
                if (pegs[j] == -1 || squares[pegs[j] + current]) {
                    pegs[j] = current;
                    current++;
                    shifted = true;
                    break;
                }
            }
            if (!shifted) {
                break;
            }
        }

        cout << (--current) << endl;

    }

    return 0;
}
