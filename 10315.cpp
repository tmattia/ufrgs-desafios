#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define TIE   0
#define BLACK 1
#define WHITE 2

#define HEARTS   0
#define SWORDS   1
#define CLUBS    2
#define DIAMONDS 3

#define HIGH_CARD       0
#define PAIR            1
#define TWO_PAIRS       2
#define THREE_OF_A_KIND 3
#define STRAIGHT        4
#define FLUSH           5
#define FULL_HOUSE      6
#define FOUR_OF_A_KIND  7
#define STRAIGHT_FLUSH  8


int value(char *card);
int suit(char *card);
int hand(vector<int> values, vector<int> suits);

bool is_straight(vector<int> values);
bool is_flush(vector<int> suits);
bool is_four_of_a_kind(vector<int> values);
bool is_full_house(vector<int> values);
bool is_three_of_a_kind(vector<int> values);
bool is_two_pairs(vector<int> values);
bool is_pair(vector<int> values);

vector<int> count_repeated(vector<int> values);
int max_repeated(vector<int> values, int n);
int min_repeated(vector<int> values, int n);

int highest_card(vector<int> black_values, vector<int> white_values);
int highest_pair(vector<int> black_values, vector<int> white_values);
int second_highest_pair(vector<int> black_values, vector<int> white_values);
int highest_three_of_a_kind(vector<int> black_values, vector<int> white_values);
int highest_four_of_a_kind(vector<int> black_values, vector<int> white_values);


int value(char *card) {
    switch (card[0]) {
        case 'T': return 10; break;
        case 'J': return 11; break;
        case 'Q': return 12; break;
        case 'K': return 13; break;
        case 'A': return 14; break;
        default: return (int) card[0] - 48; break;
    }
}

int suit(char *card) {
    switch(card[1]) {
        case 'H': return HEARTS; break;
        case 'S': return SWORDS; break;
        case 'C': return CLUBS; break;
        case 'D': return DIAMONDS; break;
        default: return -1; break;
    }
}

int hand(vector<int> values, vector<int> suits) {
    if (is_straight(values) && is_flush(suits)) return STRAIGHT_FLUSH;
    else if (is_four_of_a_kind(values)) return FOUR_OF_A_KIND;
    else if (is_full_house(values)) return FULL_HOUSE;
    else if (is_flush(suits)) return FLUSH;
    else if (is_straight(values)) return STRAIGHT;
    else if (is_three_of_a_kind(values)) return THREE_OF_A_KIND;
    else if (is_two_pairs(values)) return TWO_PAIRS;
    else if (is_pair(values)) return PAIR;
    else return HIGH_CARD;
}


bool is_straight(vector<int> values) {
    sort(values.begin(), values.end());
    for (int i = 0; i < 4; i++) if (values[i] != values[i + 1] - 1) return false;
    return true;
}

bool is_flush(vector<int> suits) {
    for (int i = 0; i < 4; i++) if (suits[i] != suits[i + 1]) return false;
    return true;
}

bool is_four_of_a_kind(vector<int> values) {
    vector<int> repeated = count_repeated(values);
    for (int i = 0; i < repeated.size(); i++) if (repeated[i] == 4) return true;
    return false;
}

bool is_full_house(vector<int> values) {
    bool two = false;
    bool three = false;
    vector<int> repeated = count_repeated(values);
    for (int i = 0; i < repeated.size(); i++) {
        if (repeated[i] == 3) three = true;
        else if (repeated[i] == 2) two = true;
    }
    return two and three;
}

bool is_three_of_a_kind(vector<int> values) {
    vector<int> repeated = count_repeated(values);
    for (int i = 0; i < repeated.size(); i++) if (repeated[i] == 3) return true;
    return false;
}

bool is_two_pairs(vector<int> values) {
    bool pair1 = false;
    bool pair2 = false;
    vector<int> repeated = count_repeated(values);
    for (int i = 0; i < repeated.size(); i++) {
        if (repeated[i] == 2) {
            if (!pair1) pair1 = true;
            else pair2 = true;
        }
    }
    return pair1 and pair2;
}

bool is_pair(vector<int> values) {
    vector<int> repeated = count_repeated(values);
    for (int i = 0; i < repeated.size(); i++) if (repeated[i] == 2) return true;
    return false;
}


vector<int> count_repeated(vector<int> values) {
    vector<int> repeated(15);
    for (int i = 0; i < values.size(); i++) repeated[values[i] - 1]++;
    return repeated;
}

int max_repeated(vector<int> values, int n) {
    int m = 0;
    vector<int> repeated = count_repeated(values);
    for (int i = 0; i < repeated.size(); i++) {
        if (repeated[i] == n) m = max(m, i + 1);
    }
    return m;
}

int min_repeated(vector<int> values, int n) {
    int m = 100;
    vector<int> repeated = count_repeated(values);
    for (int i = 0; i < repeated.size(); i++) {
        if (repeated[i] == n) m = min(m, i + 1);
    }
    return m;
}


int highest_card(vector<int> black_values, vector<int> white_values) {
    vector<int> black_rep = count_repeated(black_values);
    vector<int> white_rep = count_repeated(white_values);
    int diff = 0;
    int winner = TIE;
    for (int i = 0; i < white_rep.size(); i++) {
        diff = black_rep[i] - white_rep[i];
        if (diff > 0) winner = BLACK;
        else if (diff < 0) winner = WHITE;
    }
    return winner;
}

int highest_pair(vector<int> black_values, vector<int> white_values) {
    int black_pair = max_repeated(black_values, 2);
    int white_pair = max_repeated(white_values, 2);
    if (black_pair > white_pair) return BLACK;
    else if (black_pair < white_pair) return WHITE;
    return TIE;
}

int second_highest_pair(vector<int> black_values, vector<int> white_values) {
    int black_pair = min_repeated(black_values, 2);
    int white_pair = min_repeated(white_values, 2);
    if (black_pair > white_pair) return BLACK;
    else if (black_pair < white_pair) return WHITE;
    return TIE;
}

int highest_three_of_a_kind(vector<int> black_values, vector<int> white_values) {
    int black_three = max_repeated(black_values, 3);
    int white_three = max_repeated(white_values, 3);
    if (black_three > white_three) return BLACK;
    else if (black_three < white_three) return WHITE;
    return TIE;
}

int highest_four_of_a_kind(vector<int> black_values, vector<int> white_values) {
    int black_four = max_repeated(black_values, 4);
    int white_four = max_repeated(white_values, 4);
    if (black_four > white_four) return BLACK;
    else if (black_four < white_four) return WHITE;
    return TIE;
}


int main() {
    char b1[2], b2[2], b3[2], b4[2], b5[2], w1[2], w2[2], w3[2], w4[2], w5[2];
    while(cin >> b1 >> b2 >> b3 >> b4 >> b5 >> w1 >> w2 >> w3 >> w4 >> w5) {
        vector<int> black_values;
        black_values.push_back(value(b1));
        black_values.push_back(value(b2));
        black_values.push_back(value(b3));
        black_values.push_back(value(b4));
        black_values.push_back(value(b5));

        vector<int> black_suits;
        black_suits.push_back(suit(b1));
        black_suits.push_back(suit(b2));
        black_suits.push_back(suit(b3));
        black_suits.push_back(suit(b4));
        black_suits.push_back(suit(b5));

        vector<int> white_values;
        white_values.push_back(value(w1));
        white_values.push_back(value(w2));
        white_values.push_back(value(w3));
        white_values.push_back(value(w4));
        white_values.push_back(value(w5));

        vector<int> white_suits;
        white_suits.push_back(suit(w1));
        white_suits.push_back(suit(w2));
        white_suits.push_back(suit(w3));
        white_suits.push_back(suit(w4));
        white_suits.push_back(suit(w5));

        int white_hand = hand(white_values, white_suits);
        int black_hand = hand(black_values, black_suits);

        int winner;
        if (white_hand > black_hand) winner = WHITE;
        else if (white_hand < black_hand) winner = BLACK;
        else {
            switch (black_hand) {
                case HIGH_CARD:
                case FLUSH:
                case STRAIGHT:
                case STRAIGHT_FLUSH:
                    winner = highest_card(black_values, white_values);
                    break;
                case PAIR:
                    winner = highest_pair(black_values, white_values);
                    if(winner == TIE) winner = highest_card(black_values, white_values);
                    break;
                case TWO_PAIRS:
                    winner = highest_pair(black_values, white_values);
                    if (winner == TIE) {
                        winner = second_highest_pair(black_values, white_values);
                        if (winner == TIE) winner = highest_card(black_values, white_values);
                    }
                    break;
                case THREE_OF_A_KIND:
                case FULL_HOUSE:
                    winner = highest_three_of_a_kind(black_values, white_values);
                    break;
                case FOUR_OF_A_KIND:
                    winner = highest_four_of_a_kind(black_values, white_values);
                    break;
            }
        }

        if (winner == WHITE) printf("White wins.\n");
        else if (winner == BLACK) printf("Black wins.\n");
        else printf("Tie.\n");
    }

    return 0;
}
