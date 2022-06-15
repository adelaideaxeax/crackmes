#include <stdio.h>

int ndigits_fast(unsigned long num) {
    if (num < 10) { return 1; }
    if (num < 100) { return 2; }
    if (num < 1000) { return 3; }
    if (num < 10000) { return 4; }
    if (num < 100000) { return 5; }
    if (num < 1000000) { return 6; }
    if (num < 10000000) { return 7; }
    if (num < 100000000) { return 8; }
    if (num < 1000000000) { return 9; }
    if (num < 10000000000) { return 10; }
    if (num < 100000000000) { return 11; }
    if (num < 1000000000000) { return 12; }
    if (num < 10000000000000) { return 13; }
    if (num < 100000000000000) { return 14; }
    if (num < 1000000000000000) { return 15; }
    if (num < 10000000000000000) { return 16; }
    if (num < 100000000000000000) { return 17; }
    if (num < 1000000000000000000) { return 18; }
    return 19;
}

int main(void) {
    unsigned long key = 1;
    while (1) {
        int final = 0;
        int ndig = ndigits_fast(key);
        unsigned long divres = 0;
        unsigned long divnum = key;

        for (int i = 0; i < ndig; i++) {
            divres = divnum;
            divnum /= 10;
            final += divres - (divnum * 10);
        }

        if (final == 0x32) {
            char input[2] = { 0 };
            printf("\n[+] Valid key: %lu    continue [y/n]: ", key);
            fflush(stdout);
            fgets(input, 2, stdin);
            if (input[0] == 'n') {
                break;
            }
            putchar('\n');
        }
        key++;

        printf("\rTrying key: %lu..", key);
    }
    return 0;
}
