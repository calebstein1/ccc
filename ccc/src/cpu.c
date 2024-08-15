#include <stdint.h>
#include <sys/time.h>

#include "globals.h"
#include "cpu.h"

// RAM, Program Counter, and Stack Pointer
uint8_t prg_ram[0xffff];
uint8_t *pc = &prg_ram[0xff00];
uint8_t sp = 0xff;

// CPU Registers
uint8_t a, x, y;
uint8_t p;

uint8_t shutdown = 0;

void start_cpu() {
    struct timeval p_time = {};
    uint32_t l_cycle = 0;

    while (!shutdown) {
        l_cycle = p_time.tv_usec;
        gettimeofday(&p_time, NULL);
        if (l_cycle == p_time.tv_usec) continue;

        (*eval_func[*pc++])();
    }
}

void stop_cpu() {
    shutdown = 1;
}
