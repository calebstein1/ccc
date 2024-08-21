#include <stdio.h>
#include <string.h>

#include "globals.h"
#include "shell.h"
#include "cpu.h"
#include "loader.h"

int main(int argc, char **argv) {
    if (!argv[1] || load_prg(argv[1])) {
        puts("Welcome to CCC v0.0.1\n\nRun 'help' at the prompt to list available commands\n");
        while (!prg_loaded) {
            fputs("$ ", stdout);
            shell_prompt();
        }
    }
    if (argv[2] && strcmp(argv[2], "-d") == 0) {
        debug = 1;
    }
    start_cpu();

    return 0;
}
