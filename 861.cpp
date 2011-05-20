#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define DEBUG false

long total_solutions;

void construct_candidates(int a[], int k, int n, int kr, int c[], int *ncandidates)
{
    bool valid_move;
    int li, ci, lin, cin;

    *ncandidates = 0;

    if (k == 0) {
        for (int i = 0; i < n * n; i++) {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    } else {
        int x = (k) / n > 0 ? (abs(n - k)+1)*n + (n - 1) : k;
        for (int i = 0; i < (n - abs(k - n + 1)); i++) {
            c[*ncandidates] = x + (n-1)*i;
            *ncandidates = *ncandidates + 1;
        }
    }
}

bool is_a_solution(int a[], int k, int n, int kr)
{
    if (DEBUG and k == kr) for (int i = 0; i < k; i++) cout << a[i] << " ";
    if (DEBUG and k == kr) cout << endl;
    cout << "Testando: ";
    for(int i = 0; i < k; i++) cout << a[i] << " ";
    cout << endl;
    return (k == kr);
}

void process_solution(int a[], int k, int n, int kr)
{
    total_solutions++;
}

void backtrack(int a[], int k, int n, int kr)
{
    int c[n * n];
    int ncandidates;

    if (is_a_solution(a, k, n, kr)) {
        process_solution(a, k, n, kr);
    } else {
        construct_candidates(a, k, n, kr, c, &ncandidates);
        k = k + 1;
        for (int i = 0; i < ncandidates; i++) {
            a[k - 1] = c[i];
            backtrack(a, k, n, kr);
        }
    }
}

int main()
{
    int n, k;
    while (!cin.eof()) {
        cin >> n >> k;
        if (n == 0 and k == 0) {
            break;
        }
        if (k > ((2 * n) - 2)) {
            cout << "1" << endl;
        } else {
            total_solutions = 0;
            int a[k];
            backtrack(a, 0, n, k);
            cout << total_solutions << endl;
        }
    }
    return 0;
}
