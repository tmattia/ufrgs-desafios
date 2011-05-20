#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_REG 10
#define MAX_RAM 1000

#define HALT 100

// registers
int REG[MAX_REG];

// ram
int RAM[MAX_RAM];

// instruction pointer
int instr_pointer;

// instruction count
int instr_num;

bool interpret() {
    int instr;
    instr = RAM[instr_pointer];
    instr_num++;

    if (instr == HALT) return false;

    // decode and execute instruction
    int cmd, d, s;
    cmd = instr / 100;
    d = (instr % 100) / 10;
    s = instr % 10;
    switch(cmd) {
        case 0:
            // 0ds means goto the location in register d unless register s contains 0
            if (REG[s] != 0) {
                instr_pointer = REG[d];
            } else {
                instr_pointer++;
            }
            break;
        case 9:
            // 9sa means set the value in RAM whose address is in register a to the value of register s
            RAM[REG[s]] = REG[d];
            instr_pointer++;
            break;
        case 8:
            // 8da means set register d to the value in RAM whose address is in register a
            REG[d] = RAM[REG[s]];
            instr_pointer++;
            break;
        case 7:
            // 7ds means multiply register d by the value of register s
            REG[d] = (REG[d] * REG[s]) % 1000;
            instr_pointer++;
            break;
        case 6:
            // 6ds means add the value of register s to register d
            REG[d] = (REG[d] + REG[s]) % 1000;
            instr_pointer++;
            break;
        case 5:
            // 5ds means set register d to the value of register s
            REG[d] = REG[s];
            instr_pointer++;
            break;
        case 4:
            // 4dn means multiply register d by n
            REG[d] = (REG[d] * s) % 1000;
            instr_pointer++;
            break;
        case 3:
            // 3dn means add n to register d
            REG[d] = (REG[d] + s) % 1000;
            instr_pointer++;
            break;
        case 2:
            // 2dn means set register d to n (between 0 and 9)
            REG[d] = s;
            instr_pointer++;
            break;
    }

    return true;
}


int main() {
    // number of cases
    int cases;

    // current case
    int c;

    // instruction
    char instr[5];

    scanf("%d", &cases);
    fgets(instr, sizeof(instr), stdin);
    fgets(instr, sizeof(instr), stdin);

    for (c = 0; c < cases; c++) {
        int k = 0;

        // initialize instruction counter
        instr_num = 0;

        // initialize empty registers
        for (k = 0; k < MAX_REG; k++) REG[k] = 0;

        // initialize empty ram
        for (k = 0; k < MAX_RAM; k++) RAM[k] = 0;

        // initialize ram from input file
        k = 0;
        while (fgets(instr, sizeof(instr), stdin) != NULL) {
            if (instr[0] == '\n') break;
            RAM[k] = (instr[0] - '0') * 100 + (instr[1] - '0') * 10 + (instr[2] - '0');
            k++;
        }

        // interpret instructions
        instr_pointer = 0;
        instr_num = 0;
        while(interpret());
        if (c != 0) printf("\n");
        printf("%d\n", instr_num);
    }
    return 0;
}
