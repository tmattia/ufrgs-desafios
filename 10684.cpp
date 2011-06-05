#include <iostream>

using namespace std;

int main() {

    int n;
    int v[10000];
    int maxsofar, maxendinghere;

    while (true) {

        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        maxsofar = 0;
        maxendinghere = 0;
        for (int i = 0; i < n; i++) {
            maxendinghere = max(maxendinghere + v[i], 0);
            maxsofar = max(maxsofar, maxendinghere);
        }

        if (maxsofar > 0) {
            cout << "The maximum winning streak is " << maxsofar << "." << endl;
        } else {
            cout << "Losing streak." << endl;
        }
    }


    return 0;
}
