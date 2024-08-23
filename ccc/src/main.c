#include <stdio.h>
#include <pthread.h>

#include "display.h"
#include "cpu.h"
#include "loader.h"

int main(int argc, char **argv) {
    if (!argv[1] || load_prg(argv[1])) {
        printf("Welcome to CCC v%s\n\nRun 'help' at the prompt to list available commands\n\n", CCC_VER);
    } else {
        c_state = PRG_RN;
    }

    pthread_t cpu_thread;
    pthread_t gpu_thread;
    pthread_create(&cpu_thread, NULL, start_cpu, NULL);
    start_gpu();
    pthread_join(cpu_thread, NULL);

    return 0;
}
