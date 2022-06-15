#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int atoi_res;
    size_t slen;
    char c;
    int check, slen_check;

    if (argc != 2) {
        fprintf(stderr, "wrong");
        exit(0);
    }

    check = 0;
    slen_check = 0;

    while (1) {
        slen = strlen(argv[1]);
        if (slen <= slen_check) {
            break;
        }

        c = argv[1][slen_check];
        atoi_res = atoi(&c);

        check = check + atoi_res;
        slen_check++;
    }

    if (check == 0x32) {
        puts("good");
        exit(0);
    }

    puts("bad");

    return 0;
}
