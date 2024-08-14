#include <stdint.h>
#include <sys/time.h>

#include "globals.h"
#include "cpu.h"

// RAM, Program Counter, and Stack Pointer
uint8_t prg_ram[0xffff] = {};
uint8_t *pc = &prg_ram[0x8000];
uint8_t *sp = &prg_ram[0x1ff];

// CPU Registers
uint8_t a = 0x0, x = 0x0, y = 0x0;
uint8_t p = 0x0;

void start_cpu() {
    struct timeval p_time = {};
    uint32_t l_cycle = 0;

    while (1) {
        l_cycle = p_time.tv_usec;
        gettimeofday(&p_time, NULL);
        if (l_cycle == p_time.tv_usec) continue;

        if (*pc != 0x0) {
            (*eval_func[*pc++])();
        } else {
            break;
        }
    }
}
