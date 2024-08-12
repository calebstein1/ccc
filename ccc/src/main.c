#include <stdio.h>

#include "globals.h"
#include "cpu.h"
#include "prg.h"

int main(int argc, char **argv) {
    if (argc != 2) {
        fputs("Please supply a single program file\n", stderr);
        return -1;
    }
    if (load_prg(argv[1])) {
        fputs("Failed to load program\n", stderr);
        return -1;
    }

    run_prg();

    printf("a: %d\nx: %d\ny: %d\n", a, x, y);
    return 0;
}
