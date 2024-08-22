#include <stdio.h>

#include "globals.h"
#include "cpu.h"
#include "loader.h"

int main(int argc, char **argv) {
    if (!argv[1] || load_prg(argv[1])) {
        printf("Welcome to CCC v%s\n\nRun 'help' at the prompt to list available commands\n\n", CCC_VER);
    }
    start_cpu();

    return 0;
}
