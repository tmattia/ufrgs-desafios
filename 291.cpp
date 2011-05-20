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

int m[5][5] = {
    { 0, 1, 1, 0, 1 },
    { 1, 0, 1, 0, 1 },
    { 1, 1, 0, 1, 1 },
    { 0, 0, 1, 0, 1 },
    { 1, 1, 1, 1, 0 }
};

bool visited[5][5] = {
    { true, false, false, false, false },
    { false, true, false, false, false },
    { false, false, true, false, false },
    { false, false, false, true, false },
    { false, false, false, false, true }
};

int total_solutions = 0;

void construct_candidates(int a[], int k, int c[], int *ncandidates)
{
    *ncandidates = 0;

    int current = a[k - 1];
    for (int i = 0; i < 5; i++) {
        if (!visited[current][i] and m[current][i]) {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }
}

bool is_a_solution(int a[], int k)
{
    return (k == 8);
}

void process_solution(int a[], int k)
{
    for (int i = 0; i < 8; i++) {
        cout << a[i] + 1;
    }
    cout << "2" << endl;
}

void backtrack(int a[], int k)
{
    int c[8];
    int ncandidates;

    if (is_a_solution(a, k)) {
        process_solution(a, k);
    } else {
        k = k + 1;
        construct_candidates(a, k, c, &ncandidates);
        for (int i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            visited[a[k - 1]][c[i]] = true;
            visited[c[i]][a[k - 1]] = true;
            backtrack(a, k);
            visited[a[k - 1]][c[i]] = false;
            visited[c[i]][a[k - 1]] = false;
        }
    }
}


int main()
{
    int a[8];
    a[0] = 0;
    backtrack(a, 0);

    return 0;
}
