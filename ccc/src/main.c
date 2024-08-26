#include <stdio.h>
#include <pthread.h>

#include "display.h"
#include "cpu.h"
#include "loader.h"
#include "colors.h"

int main(int argc, char **argv) {
    pthread_t cpu_thread;

    (void)argc;

    if (!argv[1] || load_prg(argv[1])) {
        printf("\t\t  %s***************************%s\n", CYANB, RESET);
        printf("\t\t  %s* %s  ____    ____    ____%s  *%s\n", CYANB, YELLOW, CYANB, RESET);
        printf("\t\t  %s* %s / ___|  / ___|  / ___|%s *%s\n", CYANB, YELLOW, CYANB, RESET);
        printf("\t\t  %s* %s| |     | |     | |%s     *%s\n", CYANB, YELLOW, CYANB, RESET);
        printf("\t\t  %s* %s| |___  | |___  | |___%s  *%s\n", CYANB, YELLOW, CYANB, RESET);
        printf("\t\t  %s* %s \\____|  \\____|  \\____|%s *%s\n", CYANB, YELLOW, CYANB, RESET);
        printf("\t\t  %s*                         *%s\n", CYANB, RESET);
        printf("\t\t  %s***************************%s\n\n", CYANB, RESET);
        printf("\t\tWelcome to %sCCC %s%s%s\n\n\tRun %shelp%s at the prompt to list available commands\n\n", YELLOWB, REDB, CCC_VER, RESET, GREENB, RESET);
    } else {
        c_state = PRG_RN;
    }

    pthread_create(&cpu_thread, NULL, start_cpu, NULL);
    start_gpu();
    pthread_join(cpu_thread, NULL);

    return 0;
}
