#include <algorithm>  // copy()
#include <fstream>    // fstream
#include <iostream>   // cout
#include <iterator>   // istream_iterator, ostream_iterator, back_inserter
#include <sstream>    // istringstream
#include <string>     // string
#include <vector>     // vector
using namespace std;


string value(int card) {
    int v = card % 13;
    switch (v) {
        case 0: return "Ace";
        case 10: return "Jack";
        case 11: return "Queen";
        case 12: return "King";
        default:
            stringstream ss;
            ss << v + 1;
            return ss.str();
    }
}

string suit(int card) {
    int v = (card - 1) / 13;
    switch (v) {
        case 0: return "Clubs";
        case 1: return "Diamonds";
        case 2: return "Hearts";
        case 3: return "Spades";
    }
    return "";
}

int main()
{
    // read number of test cases
    int cases;
    cin >> cases;
    for (int c = 0; c < cases; c++) {
        if (c != 0) cout << endl;

        // initialize empty cards deck
        vector<int> deck(52);
        vector<int> old_deck(52);
        for (int i = 0; i < 52; i++) deck[i] = i + 1;

        // read number of known shuffles
        int shuffles_count;
        cin >> shuffles_count;

        string ignore;
        getline(cin, ignore);

        // read each shuffle
        vector < vector<int> > shuffles;
        for (int s = 0; s < shuffles_count; s++) {
            vector<int> shuffle(52);
            for (int i = 0; i < 52; i++) scanf("%d", &shuffle[i]);
            shuffles.push_back(shuffle);
        }

        // shuffle cards according to shuffle's order
        for (int s = 0; s < shuffles_count; s++) {
            int cs;
            cin >> cs;
            for(int i = 0; i < 52; i++) old_deck[i] = deck[i];
            for (int i = 0; i < 52; i++) deck[i] = old_deck[shuffles[cs - 1][i] - 1];
        }

        // output shuffled deck
        for (int i = 0; i < 52; i++) {
            cout << value(deck[i]) << " of " << suit(deck[i]) << endl;
        }
    }
}
