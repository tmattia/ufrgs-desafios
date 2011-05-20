#include <algorithm>  // copy()
#include <fstream>    // fstream
#include <iostream>   // cout
#include <iterator>   // istream_iterator, ostream_iterator, back_inserter
#include <sstream>    // istringstream
#include <string>     // string
#include <vector>     // vector
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while(cases--) {
        // get grid size (m lines x n columns)
        int m, n;
        cin >> m >> n;

        // intialize grid
        char grid[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                grid[i][j] = tolower(grid[i][j]);
            }
        }

        // get words
        int words;
        cin >> words;
        while (words--) {
            char word[50];
            cin >> word;

            int word_len = 0;
            for (int i = 0; i < 50; i++) {
                word[i] = tolower(word[i]);
                if (!word[i]) {
                    word_len = i;
                    break;
                }
            }

            // find word in grid
            bool found = false;
            for (int i = 0; i < m; i++) {
                if (found) {
                    break;
                }
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == word[0]) {
                        // test up-down
                        found = true;
                        for (int x = 0; x < word_len; x++) {
                            if (i + x >= m or grid[i + x][j] != word[x]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            break;
                        }

                        // test left-right
                        found = true;
                        for (int x = 0; x < word_len; x++) {
                            if (j + x >= n or grid[i][j + x] != word[x]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            break;
                        }

                        // test topleft-bottomright
                        found = true;
                        for (int x = 0; x < word_len; x++) {
                            if (j + x >= n or i + x >= n or grid[i + x][j + x] != word[x]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            break;
                        }


                        // test down-up
                        found = true;
                        for (int x = 0; x < word_len; x++) {
                            if (i - x < 0 or grid[i - x][j] != word[x]) {
                                found = false;
                                break;
                            }
                        }
                        if(found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            break;
                        }

                        // test right-left
                        found = true;
                        for (int x = 0; x < word_len; x++) {
                            if (j - x < 0 or grid[i][j - x] != word[x]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            break;
                        }

                        // test bottomright-topleft
                        found = true;
                        for (int x = 0; x < word_len; x++) {
                            if (j - x < 0 or i - x < 0 or grid[i - x][j - x] != word[x]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            break;
                        }

                        // test topright-bottomleft
                        found = true;
                        for (int x = 0; x < word_len; x++) {
                            if (j - x < 0 or i + x >= n or grid[i + x][j - x] != word[x]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            break;
                        }


                        // test bottomleft-topright
                        found = true;
                        for (int x = 0; x < word_len; x++) {
                            if (j + x >= m or i - x < 0 or grid[i - x][j + x] != word[x]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            cout << i + 1 << " " << j + 1 << endl;
                            break;
                        }
                    }
                }
            }
        }

        // output blank line between cases
        if (cases > 0) {
            cout << endl;
        }
    }

    return 0;
}
