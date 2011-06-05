/*#include <iostream>

using namespace std;

long long int total;
int viz[100][2];

void calcula(int max, int f, int s) {
    // cout << "calcula: " << max << " " << f << " " << s << endl;
    if (s > 0) {
        if (viz[f][0] <= max) {
            if (viz[f][1] <= max) {
                calcula(max, viz[f][0], viz[f][1]);
            } else {
                calcula(max, viz[f][0], 0);
            }
        } else {
            total++;
        }
        if (viz[s][0] <= max) {
            if (viz[s][1] <= max) {
                calcula(max, viz[s][0], viz[s][1]);
            } else {
                calcula(max, viz[s][0], 0);
            }
        } else {
            total++;
        }
    } else if (f > 0) {
        if (viz[f][0] <= max) {
            if (viz[f][1] <= max) {
                calcula(max, viz[f][0], viz[f][1]);
            } else {
                calcula(max, viz[f][0], 0);
            }
        } else {
            total++;
        }
    }
}

int main() {

    int s1, s2;
    for (int i = 0; i < 78; i++) {
        s1 = i + 2; s2 = i + 3;
        if (s1 <= 100) {
            viz[i][0] = s1;
            if (s2 <= 100) {
                viz[i][1] = s2;
            } else {
                viz[i][1] = -1;
            }
        } else if (s2 <= 100) {
            viz[i][0] = s2;
            viz[i][1] = -1;
        } else {
            viz[i][0] = -1;
            viz[i][1] = -1;
        }

    }

    int n;

    while (cin >> n) {

        total = 0;
        if (n == 1) {
            calcula(n, 1, 0);
        } else {
            calcula(n, 1, 2);
        }
        cout << "resposta[" << n << "] = " << total << ";" << endl;

    }

    return 0;

}*/


#include <iostream>

using namespace std;

int main() {

    int resposta[77];

    resposta[1] = 1;
    resposta[2] = 2;
    resposta[3] = 2;
    resposta[4] = 3;
    resposta[5] = 4;
    resposta[6] = 5;
    resposta[7] = 7;
    resposta[8] = 9;
    resposta[9] = 12;
    resposta[10] = 16;
    resposta[11] = 21;
    resposta[12] = 28;
    resposta[13] = 37;
    resposta[14] = 49;
    resposta[15] = 65;
    resposta[16] = 86;
    resposta[17] = 114;
    resposta[18] = 151;
    resposta[19] = 200;
    resposta[20] = 265;
    resposta[21] = 351;
    resposta[22] = 465;
    resposta[23] = 616;
    resposta[24] = 816;
    resposta[25] = 1081;
    resposta[26] = 1432;
    resposta[27] = 1897;
    resposta[28] = 2513;
    resposta[29] = 3329;
    resposta[30] = 4410;
    resposta[31] = 5842;
    resposta[32] = 7739;
    resposta[33] = 10252;
    resposta[34] = 13581;
    resposta[35] = 17991;
    resposta[36] = 23833;
    resposta[37] = 31572;
    resposta[38] = 41824;
    resposta[39] = 55405;
    resposta[40] = 73396;
    resposta[41] = 97229;
    resposta[42] = 128801;
    resposta[43] = 170625;
    resposta[44] = 226030;
    resposta[45] = 299426;
    resposta[46] = 396655;
    resposta[47] = 525456;
    resposta[48] = 696081;
    resposta[49] = 922111;
    resposta[50] = 1221537;
    resposta[51] = 1618192;
    resposta[52] = 2143648;
    resposta[53] = 2839729;
    resposta[54] = 3761840;
    resposta[55] = 4983377;
    resposta[56] = 6601569;
    resposta[57] = 8745217;
    resposta[58] = 11584946;
    resposta[59] = 15346786;
    resposta[60] = 20330163;
    resposta[61] = 26931732;
    resposta[62] = 35676949;
    resposta[63] = 47261895;
    resposta[64] = 62608681;
    resposta[65] = 82938844;
    resposta[66] = 109870576;
    resposta[67] = 145547525;
    resposta[68] = 192809420;
    resposta[69] = 255418101;
    resposta[70] = 338356945;
    resposta[71] = 448227521;
    resposta[72] = 593775046;
    resposta[73] = 786584466;
    resposta[74] = 1042002567;
    resposta[75] = 1380359512;
    resposta[76] = 1828587033;

    int n;

    while (cin >> n) {

        cout << resposta[n] << endl;

    }

    return 0;

}
