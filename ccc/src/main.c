#include <stdio.h>
#include <string.h>

#include "globals.h"
#include "cpu.h"
#include "loader.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        fputs("Please supply a single program file\n", stderr);
        return -1;
    }
    if (load_os()) {
        fputs("Failed to load OS\n", stderr);
        return -1;
    }
    if (load_prg(argv[1])) {
        fputs("Failed to load program\n", stderr);
        return -1;
    }
    if (argv[2] && strcmp(argv[2], "-d") == 0) {
        debug = 1;
    } else if (argv[2] && strcmp(argv[2], "-65") == 0) {
        m6502 = 1;
    }
    start_cpu();
    print_registers();

    return 0;
}
